//	Milestone #3
// Name:	Yuchi Zheng
// Seneca Student ID:	025 848 151
// Seneca email:	yzheng103@myseneca.ca
// Date of completion: 2nd, December, 2022
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <fstream>
#include "Workstation.h"

namespace sdds {
   class LineManager {
      std::vector<Workstation*> m_activeLine;
      size_t m_cntCustomerOrder{};
      Workstation* m_firstStation{};

   public:
      LineManager(const std::string& file, const std::vector<Workstation*>& stations);
      void reorderStations();
      bool run(std::ostream& os);
      void display(std::ostream& os) const;
   };
}
#endif // !SDDS_LINEMANAGER_H
