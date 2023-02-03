// CustomerOrder.h
// Name: Yuchi Zheng

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
