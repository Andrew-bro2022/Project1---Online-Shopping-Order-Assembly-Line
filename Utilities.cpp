//	Milestone #3
// Name:	Yuchi Zheng
// Seneca Student ID:	025 848 151
// Seneca email:	yzheng103@myseneca.ca
// Date of completion: 2nd, December, 2022
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"

using namespace std;

namespace sdds {
	char Utilities::m_delimiter{};//class variable initial

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string token{}, restStr{};
		size_t n{};

		if (more) {
			n = str.find(m_delimiter, next_pos);// n 是从[0] 开始计算; static access

			if (n != std::string::npos) { //std::string::npos = -1
				if (n == next_pos) {
					more = false;
					throw "Error! A delimiter is found at next_pos";
				}
				else {
					token = str.substr(next_pos, (n - next_pos));//2nd parameter is length
					token = trim(token);

					next_pos = n + 1;
					/*restStr = str.substr(next_pos);
					restStr.empty() ? more = false : more = true;*/
					str[n] == '\n'? more = false : more = true;
				}
			}
			else {//can't find deli
				more = false;
				token = str.substr(next_pos);
				token = trim(token);
			}

			if (m_widthField < token.length()) {
				m_widthField = token.length();
			}
		}
		return token;
	}

	std::string Utilities::trim(std::string& s) {
		string temp{};

		size_t p = s.find_first_not_of(" \t");
		s.erase(0, p);

		p = s.find_last_not_of(" \t");
		if (string::npos != p) {
			temp = s.erase(p + 1);
		}
		return temp;
	}

	//class functions
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}

}