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
		fgets(buffer, 2048, file);
	}
}

uint64_t MiniGPortugol::TextProcessor::getLine() {
	return this->line;
}

uint64_t MiniGPortugol::TextProcessor::getColumn() {
	return this->column;
}

char MiniGPortugol::TextProcessor::rollback() {
	return this->last;
}

char MiniGPortugol::TextProcessor::nextChar() {
	if (column <= 2048) {
		last = buffer[this->column++];
	} else {
		read2buffer();
		column = 0;
		last = nextChar();
	}
	if (last == '\n')
		line++;
	return last;
}
