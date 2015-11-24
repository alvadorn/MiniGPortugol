#include "processor.h"
#include <iostream>
#include <sstream>

MiniGPortugol::TextProcessor::TextProcessor(char *filename) {
	file = fopen(filename, "r");

	if (file == NULL) {
			std::cout << "Can\'t open source file!" << std::endl;
			exit(1);
	}

	line = 1;
	column = 0;
	read2buffer();
}

MiniGPortugol::TextProcessor::~TextProcessor() {
	fclose(file);
}

void MiniGPortugol::TextProcessor::read2buffer() {
	if (!feof(file)) {
		int i = 0;
		while(!feof(file)) {
			char c = fgetc(file);
			buffer[i++] = c;
			if (c == '\n') {
				buffer[i++] = '\0';
				//std::cout << "Printing buffer: " << buffer << std::endl;
				break;
			}
		}
		//fgets(buffer, 2048, file);
		this->column = 0;
	}
}

uint64_t MiniGPortugol::TextProcessor::getLine() {
	return this->line;
}

uint64_t MiniGPortugol::TextProcessor::getColumn() {
	return this->column;
}

char MiniGPortugol::TextProcessor::rollback() {
	if (column > 0) {
		this->column--;
	}
	return buffer[this->column];
}

char MiniGPortugol::TextProcessor::nextChar() {
	if (column <= 2048) {
		last = buffer[this->column++];
		//std::cout << "Column is: " << column << std::endl;
	} else {
		//std::cout << "What the hell im doing, the column is: " << column << std::endl;
		read2buffer();
		column = 0;
		last = nextChar();
	}
	if (last == '\n') {
		//std::cout << "I need to read more" << std::endl;
		line++;
		read2buffer();
		this->column = 0;
	}
	return last;
}
