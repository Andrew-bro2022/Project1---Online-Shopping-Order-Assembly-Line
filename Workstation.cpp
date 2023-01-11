//	Milestone #3
// Name:	Yuchi Zheng
// Seneca Student ID:	025 848 151
// Seneca email:	yzheng103@myseneca.ca
// Date of completion: 2nd, December, 2022
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include "Workstation.h"

using namespace std;

std::deque<sdds::CustomerOrder> g_pending;
std::deque<sdds::CustomerOrder> g_completed;
std::deque<sdds::CustomerOrder> g_incomplete;

namespace sdds {
   Workstation::Workstation(const std::string& str):Station(str) {}

   void Workstation::fill(std::ostream& os) {
      if (m_orders.size()) {    //without   if (m_orders.size()) {}, cause empty front() call      
         m_orders.front().fillItem(*this, os);
      }
   }

   bool Workstation::attemptToMoveOrder() {
      bool done{false};

      if (m_orders.size()) {  // empty m_orders and m_orders.front() cause error
         if (m_orders.front().isItemFilled(getItemName()) || !getQuantity()) {

            if (m_pNextStation) {
               m_pNextStation->m_orders.push_back(std::move(m_orders.front()));//copy delete in customer copy constructor
            }
            else {
               //complete
               if (m_orders.front().isOrderFilled()) {
                  g_completed.push_back(std::move(m_orders.front()));//;
               }
               //incomplete
               else {
                  g_incomplete.push_back(std::move(m_orders.front()));//
               }
            }

            m_orders.pop_front();//entering the back and exiting the front. delete current m_order in current workstation
            done = true;
         }
      }
      return done;
   }

   void Workstation::setNextStation(Workstation* station) {
      if (station) {
         m_pNextStation = station;
      }
   }

   Workstation* Workstation::getNextStation() const {
      return m_pNextStation;
   }

   void Workstation::display(std::ostream& os) const {
      os << getItemName() << " --> ";
      if (m_pNextStation != nullptr) {
         os << m_pNextStation->getItemName() << endl;
      }
      else {
         os << "End of Line" << endl;
      }
   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
      m_orders.push_back(std::move(newOrder));
      return *this;
   }



}