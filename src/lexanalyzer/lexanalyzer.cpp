#include "lexanalyzer.h"
#include <cstdint>
#include <cstdio>
#include <iostream>

MiniGPortugol::LexAnalyzer::LexAnalyzer(char filename[]) {
	std::cout << "Loading keywords" << std::endl;
	if (!loadKeywords()) {
			exit(1);
	}
	std::cout << "Initializing LexAnalyzer" << std::endl;
	processor = new TextProcessor(filename);
}

MiniGPortugol::LexAnalyzer::~LexAnalyzer() {
	delete processor;
	keywords.clear();
}

bool MiniGPortugol::LexAnalyzer::loadKeywords() {
	FILE *keyword_file = fopen("keywords.txt", "r");
	if (keyword_file == NULL) {
		std::cout << "Can't open keywords file" << std::endl;
		return false;
	}
	std::string buffer = "";
	while(!feof(keyword_file)) {
		char read = fgetc(keyword_file);
		if (read != '\n') {
			buffer += read;
		} else {
			keywords.push_back(buffer);
			buffer = "";
		}
	}
	fclose(keyword_file);
	return true;
}
