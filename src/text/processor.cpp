#include "processor.h"
#include <iostream>
#include <sstream>

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
	bool comment = false;
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
		else if (line[i] == '/' && line[i+1] == '/') {
			comment = true;
			break;
		}
	}

	std::string token = line.substr(start, i);

	if (comment) {
		line.clear();
		token = "//";
	} else {

		line.erase(0, i);
	}

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
	


	if (!file.eof() && tokens.size() == 0) {
		char buffer[1001];
		file.getline(buffer, 1000, '\n');
		std::string to_string = buffer;
		std::stringstream stream(to_string);
		std::string buffer2;
		while (stream >> buffer2)
			tokens.push_back(buffer2);
	} else if(file.eof())
		return false;

	line = tokens.front();
	if (line == "//")
		tokens.clear();
	else
		tokens.pop_front();

	return true;
}
