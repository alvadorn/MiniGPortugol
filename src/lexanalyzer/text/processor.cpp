#include "processor.h"
#include <iostream>
#include <sstream>

MiniGPortugol::LexAnalyzer::TextProcessor::TextProcessor(char *filename) {
	file = fopen(filename, "r");
	line = 1;
	column = 0;
}

MiniGPortugol::LexAnalyzer::TextProcessor::~TextProcessor() {
	fclose(file);
}

void MiniGPortugol::LexAnalyzer::TextProcessor::readline() {
	if (!feof(file)) {
		fgets(buffer, 2048, file);
	}
}
