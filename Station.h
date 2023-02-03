// Station.h
// Name:	Yuchi Zheng

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
#include "Utilities.h"

namespace sdds {
	class Station {
		int m_id{};
		std::string m_itemName{};
		size_t m_serialNum{};
		size_t m_stockNum{};
		std::string m_description{};

		static size_t m_widthField;
		static int id_generator;

	public:
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif // !SDDS_STATION_H

