#include "lexanalyzer.h"
#include "keywords.h"
#include "../token/tokentype.h"
#include <cstdint>
#include <iostream>

MiniGPortugol::LexAnalyzer::LexAnalyzer(char filename[]) {
	processor = new TextProcessor(filename);
	std::cout << "Initializing LexAnalyzer" << std::endl;

}

MiniGPortugol::LexAnalyzer::~LexAnalyzer() {
	delete processor;
}

std::string MiniGPortugol::LexAnalyzer::getLexeme() {
	return this->lexeme;
}

void MiniGPortugol::LexAnalyzer::start() {

	int typed_counter = 0;

	while ( (this->lexeme = processor->nextToken()) != "") {
		bool reserv = Keywords::isReserved(lexeme);
		AbstractToken *object;
		if ( Keywords::isReserved(lexeme) ) {
			object = new TypedToken(lexeme, (TokenType) reserved, typed_counter++);
		} else {
			object = new UnmappedToken(lexeme);
		}
		tokens.push_back(object);

		std::cout << lexeme << " >> " << reserv <<std::endl;
	}
	std::cout << tokens.size() << std::endl;
	this->printRecognizeTable();
}

void MiniGPortugol::LexAnalyzer::printRecognizeTable() {
	std::cout << "---------------------------" << std::endl;
	std::cout << "Reconhecimento dos tokens" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Lexemas\t\t\tToken" << std::endl;

	for (AbstractToken *t : tokens) {
		t->print();
	}
}
