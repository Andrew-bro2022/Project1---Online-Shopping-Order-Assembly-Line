//	Workstation.h
// Name:	Yuchi Zheng


#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>

#include "Station.h"
#include "CustomerOrder.h"

extern   std::deque<sdds::CustomerOrder> g_pending;
extern   std::deque<sdds::CustomerOrder> g_completed;
extern   std::deque<sdds::CustomerOrder> g_incomplete;

namespace sdds{
   class Workstation :public Station {    
      std::deque<sdds::CustomerOrder> m_orders;
      Workstation* m_pNextStation{};      

   public:
      Workstation(const Workstation& toCopy) = delete;
      Workstation& operator=(const Workstation& toAssign) = delete;
      Workstation(Workstation&& toMove) = delete;
      Workstation& operator=(Workstation&& toMove) = delete;
      
      Workstation(const std::string& str);
      void fill(std::ostream& os);
      bool attemptToMoveOrder();
      void setNextStation(Workstation* station = nullptr);
      Workstation* getNextStation() const;
      void display(std::ostream& os) const;
      Workstation& operator+=(CustomerOrder&& newOrder);
   };

}

#endif // !SDDS_WORKSTATION_H

