#include "processor.h"
#include <iostream>

MiniGPortugol::TextProcessor::TextProcessor(char *filename) {
	file.open(filename);
	line = "";
}

MiniGPortugol::TextProcessor::~TextProcessor() {
	file.close();
}

// Captura a proxima stream no arquivo
std::string MiniGPortugol::TextProcessor::nextToken() {
	if (line.length() == 0) {
		if (!nextLine())
			return "";
	}

	unsigned int start = 0;
	unsigned int end = 0;
	unsigned int i;
	char last = -1;
	for (i = 0; i < line.length(); i++) {
		if (isSpace(line[i])) {
			if (i == 0) {
				last = ' ';
				start++;
				end++;
			} else if (isSpace(last) && start <= end) {
				if (start == end)
					start++;
				end++;
			}
		} else if (isSymbol(line[i]) && i != 0)
			break;
	}

	std::string token = line.substr(start, i);

	line.erase(0, i);

	return token;
}

// Verifica se o caracter lido e um simbolo delimitador
bool MiniGPortugol::TextProcessor::isSymbol(char c) {
	bool value = false;
	switch(c) {
		case ',':
			value = true;
			break;
		case ':':
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

// Verifica se o caractere e um espaco
bool MiniGPortugol::TextProcessor::isSpace(char c) {
	if (c == ' ')
		return true;
	return false;
}

// If is possible to get a new line then true.
bool MiniGPortugol::TextProcessor::nextLine() {
	if (!file.eof()) {
		file >> line;
		return true;
	}
	return false;
}
