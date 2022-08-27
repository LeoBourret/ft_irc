#include <cctype>
#include <algorithm>

#include "utils.hpp"

std::string strToUpper(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(),
					[](unsigned char c){ return std::toupper(c); }
					);
	return s;
}

std::string strToLower(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(),
					[](unsigned char c){ return std::tolower(c); }
				  );
	return s;
}

std::string	strReplaceAll(std::string str, std::string const toReplace, std::string const content) {
	for (size_t pos = str.find(toReplace, 0); pos != std::string::npos; pos = str.find(toReplace, pos + 1)) {
		str.replace(pos, toReplace.size(), content);
	}
	return str;
}
