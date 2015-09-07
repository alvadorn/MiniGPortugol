#include "lexanalyzer.h"
#include <iostream>

MiniGPortugol::LexAnalyzer::LexAnalyzer(char filename[]) {
	processor = new TextProcessor(filename);
	std::cout << "Initializing LexAnalyzer" << std::endl;

}

MiniGPortugol::LexAnalyzer::~LexAnalyzer() {
	delete processor;
}

std::string MiniGPortugol::LexAnalyzer::getToken() {
	return this->token;
}

void MiniGPortugol::LexAnalyzer::start() {
	while ( (this->token = processor->nextToken()) != "") {
		std::cout << token << std::endl;
	}
}