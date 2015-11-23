#include "processor.h"
#include <iostream>
#include <sstream>

MiniGPortugol::TextProcessor::TextProcessor(char *filename) {
	file = fopen(filename, "r");
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
				break;
			}
		}
	}
}

uint64_t MiniGPortugol::TextProcessor::getLine() {
	return this->line;
}

uint64_t MiniGPortugol::TextProcessor::getColumn() {
	return this->column;
}

char MiniGPortugol::TextProcessor::rollback() {
	this->column--;
	return buffer[this->column];
}

char MiniGPortugol::TextProcessor::nextChar() {
	if (column <= 2048) {
		last = buffer[this->column++];
	} else {
		read2buffer();
		column = 0;
		last = nextChar();
	}
	if (last == '\n') {
		line++;
		read2buffer();
		column = 0;
	}
	return last;
}
