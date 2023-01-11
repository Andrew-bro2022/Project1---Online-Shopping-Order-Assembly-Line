//	Milestone #3
// Name:	Yuchi Zheng
// Seneca Student ID:	025 848 151
// Seneca email:	yzheng103@myseneca.ca
// Date of completion: 2nd, December, 2022
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef SDDS_CUSTOMER_ORDER_H
#define SDDS_CUSTOMER_ORDER_H
#include <iostream>
#include <vector>
#include "Station.h"

namespace sdds {
   class CustomerOrder {
		struct Item {
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};

		std::string m_name{};	
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{nullptr};	

		static size_t m_widthField;

	public:
		CustomerOrder() {}
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder& toCopy);
		CustomerOrder& operator=(const CustomerOrder& toAssign) = delete;
		CustomerOrder(CustomerOrder&& toMove) noexcept;
		CustomerOrder& operator=(CustomerOrder&& toMove) noexcept;
		~CustomerOrder();

		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
   };
}
#endif // !SDDS_CUSTOMER_ORDER_H
