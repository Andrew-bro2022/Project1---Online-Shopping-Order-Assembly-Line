//	Milestone #3
// Name:	Yuchi Zheng
// Seneca Student ID:	025 848 151
// Seneca email:	yzheng103@myseneca.ca
// Date of completion: 2nd, December, 2022
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iomanip>

#include "LineManager.h"

using namespace std;

namespace sdds {
   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
      try {
         vector<std::string> records{};
         std::vector<Workstation*> nextStations{};
         std::string record{}, stationToken1{}, stationToken2{};
         Utilities util{};
         bool more = true;
         size_t pos = 0u;                        
        
         //open file
         ifstream iFile(file);
         if (file.empty()) { throw string("ERROR: No filename provided in LineManager."); }
         if (!iFile) { throw string("Unable to open [") + file + "] file in LineManager."; }
         while (!iFile.eof()) {
            getline(iFile, record);
            records.push_back(std::move(record));
         }
         iFile.close();

         //load data 
         for_each(records.begin(), records.end(), [&](auto str) {
            more = true;
            pos = 0u;

            //first station(item) in record line
            if (more) {
               stationToken1 = util.extractToken(str, pos, more);

               auto iter = find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                  return ws->getItemName() == stationToken1;
                  });
               m_activeLine.push_back(*iter);
            }

            //second station(item) in record line
            if (more) {
               stationToken2 = util.extractToken(str, pos, more);

               auto iter = find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                  return ws->getItemName() == stationToken2;
                  });
               nextStations.push_back(*iter);

               m_activeLine.back()->setNextStation(*iter);
            }
            else {//last station
               nextStations.push_back(nullptr);      
               m_activeLine.back()->setNextStation();//defalut is set nullptr
            }
            });

         //found the first station(item) 
         for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
            if (find(nextStations.begin(), nextStations.end(), ws) == nextStations.end()) {
               m_firstStation = ws;
            }
            });
          
         //updates the total number of orders in the g_pending queue.
         m_cntCustomerOrder = g_pending.size();
      }
      catch (const std::string& msg) {
         throw msg;
      }
      catch (...) {
         throw std::string("Error in LineManager.");
      } 
   }

   void LineManager::reorderStations() {
      vector<Workstation*> temp;

      temp.push_back(m_firstStation);
      for (size_t i = 0; i < m_activeLine.size() - 1; i++) {
         temp.push_back(temp.back()->getNextStation());
      }

      m_activeLine.clear();
      m_activeLine = temp;
   }

   bool LineManager::run(std::ostream& os) {
      static size_t cnt{};

      os << "Line Manager Iteration: " << ++cnt << endl;

      if (g_pending.size()) {
         *m_firstStation += std::move(g_pending.front());//call operator in Workstation
         g_pending.pop_front();
      }

      for (size_t i = 0; i < m_activeLine.size(); i++) {
         m_activeLine[i]->fill(os);
      }

      for (size_t i = 0; i < m_activeLine.size(); i++) {
         m_activeLine[i]->attemptToMoveOrder();
      }

      return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder? true : false;
   }

   void LineManager::display(std::ostream& os) const {
      for (size_t i = 0; i < m_activeLine.size(); i++) {
         m_activeLine[i]->display(os);
      }
   }
}