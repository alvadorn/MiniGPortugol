#include "processor.h"

MiniGPortugol::TextProcessor::TextProcessor(char *filename) {
	file.open(filename);
}

MiniGPortugol::TextProcessor::~TextProcessor() {
	file.close();
}

std::string MiniGPortugol::TextProcessor::nextToken() {
	if (line.length() > 0) {
		if (!nextLine()) 
			return "";
	}


	return "";
}

bool MiniGPortugol::TextProcessor::isSymbol(char c) {
	bool value = false;
	switch(c) {
		case '=':
			value = true;
			break;
		case ';':
			value = true;
			break;
		default:
			value = false;
			break;
	}

	return value; 
}

// If is possible to get a new line then true.
bool MiniGPortugol::TextProcessor::nextLine() {
	if (!file.eof()) {
		file >> line;
		return true;
	}
	return false;
}