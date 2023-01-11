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
#include "Station.h"

using namespace std;

namespace sdds {
	size_t Station::m_widthField{};
	int Station::id_generator{};

	Station::Station(const std::string& str) {
		Utilities util{};
		bool more = true;
		size_t pos = 0u;

		m_id = ++id_generator;

		if (more) {
			m_itemName = util.extractToken(str, pos, more);
		}
		if (more) {
			m_serialNum = stoul(util.extractToken(str, pos, more));
		}
		if (more) {
			m_stockNum = stoul(util.extractToken(str, pos, more));
		}

		if (m_widthField < util.getFieldWidth()) {
			m_widthField = util.getFieldWidth();
		}

		if (more) {
			m_description = util.extractToken(str, pos, more);
		}
	}

	const std::string& Station::getItemName() const {
		return m_itemName;
	}

	size_t Station::getNextSerialNumber() {
		return m_serialNum++;
	}

	size_t Station::getQuantity() const {
		return m_stockNum;
	}

	void Station::updateQuantity() {
		if (m_stockNum > 0) {
			m_stockNum -= 1;
		}
	}

	void Station::display(std::ostream& os, bool full) const {
		os << setw(3) << setfill('0') << m_id << " | " << setfill(' ');
		os << left << setw(m_widthField) << m_itemName << "  | " << right;
		os << setw(6) << setfill('0') << m_serialNum << " | "  << setfill(' ');

		if (full) {
			os << setw(4) << m_stockNum << " | ";
			os << left << m_description << right;
		}
		os << endl;
	}
}


