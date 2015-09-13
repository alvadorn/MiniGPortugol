#include "keywords.h"
#include <cstdio>

bool MiniGPortugol::Keywords::isReserved(std::string stream) {

    auto it = std::find(reserved_words.begin(),
    reserved_words.end(), stream);

    return it != reserved_words.end();
}

bool MiniGPortugol::Keywords::isSymbol(std::string stream) {
	if (stream == ":=" || stream == ";" || stream == ":" || stream == ",")
		return true;
	return false;
}

bool MiniGPortugol::Keywords::isNumber(std::string stream) {
	int some_int;
	double some_double;

	int isNumber = std::sscanf(stream.c_str(), "%d", &some_int) ||
		std::sscanf(stream.c_str(), "%lf", &some_double);

	return isNumber;
}
