//	Milestone #3
// Name:	Yuchi Zheng
// Seneca Student ID:	025 848 151
// Seneca email:	yzheng103@myseneca.ca
// Date of completion: 2nd, December, 2022
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "CustomerOrder.h"

using namespace std;

namespace sdds {
   size_t CustomerOrder::m_widthField{};

   CustomerOrder::CustomerOrder(const std::string& str) {
      Utilities util{};
      bool more = true;
      size_t pos = 0u;

      if (more) {
         m_name = util.extractToken(str, pos, more);
      }
      if (more) {
         m_product = util.extractToken(str, pos, more);
      }

      //items load
      vector<std::string> strArr;
      while (more) {
         strArr.push_back(util.extractToken(str, pos, more));
      }
      m_cntItem = strArr.size();

      if (m_cntItem) {
         m_lstItem = new Item*[m_cntItem];

         for (size_t i = 0u; i < m_cntItem; i++) {
            m_lstItem[i] = new Item(strArr[i]);
         }
      }

      if (m_widthField < util.getFieldWidth()) {
         m_widthField = util.getFieldWidth();
      }
   }

   CustomerOrder::CustomerOrder(const CustomerOrder& toCopy) {
      throw std::string("ERROR: Cannot make copies.");
   }

   CustomerOrder::CustomerOrder(CustomerOrder&& toMove) noexcept {
      *this = std::move(toMove);
   }

   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& toMove) noexcept {
      if (this != &toMove) {
         //delete 
         for (size_t i = 0; i < m_cntItem; i++) {
            delete m_lstItem[i];
            m_lstItem[i] = nullptr;
         }
         delete[] m_lstItem;

         m_lstItem = toMove.m_lstItem;
         toMove.m_lstItem = nullptr;

         m_name = toMove.m_name;
         toMove.m_name.clear();

         m_product = toMove.m_product;
         toMove.m_product.clear();

         m_cntItem = toMove.m_cntItem;
         toMove.m_cntItem = 0;

         m_widthField = toMove.m_widthField;
         //toMove.m_widthField = 0;
      }
      return *this;
   }

   CustomerOrder::~CustomerOrder() {
      for (size_t i = 0u; i < m_cntItem; i++) {
         delete m_lstItem[i];
         m_lstItem[i] = nullptr;
      }

      delete[] m_lstItem;
      m_lstItem = nullptr;
   }

   bool CustomerOrder::isOrderFilled() const {
      size_t cnt{};

      for (size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_isFilled == true) {
            cnt++;
         }
      }
      return cnt == m_cntItem ? true:false;
   }

   bool CustomerOrder::isItemFilled(const std::string& itemName) const {
      size_t cntFound{}, cntFilled{};
      bool done{ false };

      for (size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName == itemName) {
            cntFound++;

            if (m_lstItem[i]->m_isFilled == true) {
               cntFilled++;
            }
         }
      }

      if (cntFound == cntFilled || cntFound == 0) {
         done = true;
      }
      return done;
   }

   void CustomerOrder::fillItem(Station& station, std::ostream& os) {
      bool done{ false };

      for (size_t i = 0; i < m_cntItem && !done; i++) {
         if (m_lstItem[i]->m_itemName == station.getItemName() ){//!m_lstItem[i]->m_isFilled

            if (!m_lstItem[i]->m_isFilled && station.getQuantity() > 0 ) {
           
               station.updateQuantity();
               m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
               m_lstItem[i]->m_isFilled = true;
               done = true;

               os << "    Filled " << m_name << ", " << m_product << " [" 
                  << m_lstItem[i]->m_itemName << ']' << endl;
            }
            else if (!m_lstItem[i]->m_isFilled && station.getQuantity() == 0) {
               os << "    Unable to fill " << m_name << ", " << m_product << " ["
                  << m_lstItem[i]->m_itemName << ']' << endl;
               //done = true;-> cause missing Rania output in loop12
            }
         }
      }
   }

   void CustomerOrder::display(std::ostream& os) const {
      os << m_name << " - " << m_product << endl;

      for (size_t i = 0; i < m_cntItem; i++) {
         os << '[' << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] " << setfill(' ');
         os << left << setw(m_widthField) << m_lstItem[i]->m_itemName << "   - " << right;
         if (m_lstItem[i]->m_isFilled) {
            os << "FILLED" << endl;
         }
         else {
            os << "TO BE FILLED" << endl;
         }
      } 
   }
}