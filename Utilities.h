//	Milestone #3
// Name:	Yuchi Zheng
// Seneca Student ID:	025 848 151
// Seneca email:	yzheng103@myseneca.ca
// Date of completion: 2nd, December, 2022
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <string>

namespace sdds {
	class Utilities {
		size_t m_widthField{ 1 };
		static char m_delimiter;

	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		std::string trim(std::string& s);

		//class functions
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif // !UTILITIES_H
