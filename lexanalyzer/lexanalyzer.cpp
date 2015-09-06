#include "lexanalyzer.h"

MiniGPortugol::LexAnalyzer::LexAnalyzer(char filename[]) {
	processor = new TextProcessor(filename);

}

MiniGPortugol::LexAnalyzer::~LexAnalyzer() {

}

std::string MiniGPortugol::LexAnalyzer::getToken() {
	return this->token;
}

void MiniGPortugol::LexAnalyzer::start() {
	
}