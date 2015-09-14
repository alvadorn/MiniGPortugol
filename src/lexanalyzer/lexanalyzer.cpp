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
	for (auto *t : tokens)
		delete t;
	tokens.clear();
	symbols.clear();
}

std::string MiniGPortugol::LexAnalyzer::getLexeme() {
	return this->lexeme;
}


void MiniGPortugol::LexAnalyzer::printInformation() {
	this->printRecognizeTable();
	this->printSymbolsTable();
}

// Inicia o analizador lexico
void MiniGPortugol::LexAnalyzer::start() {

	int typed_counter = 1;

	while ( (this->lexeme = processor->nextToken()) != "") {

		if (lexeme == "//") continue;

		AbstractToken *object;
		if ( Keywords::isReserved(lexeme) ) {
			object = new TypedToken(lexeme, (TokenType) reserved, typed_counter++);
			symbols.push_back((TypedToken *) object);
		} else if ( !Keywords::isSymbol(lexeme)) {
			bool exist = false;
			if ( Keywords::isNumber(lexeme))
				object = new TypedToken(lexeme, (TokenType) number, typed_counter++);
			else {
				int position = -1;
				if ( !(exist = this->identifierExists(lexeme, position)) ) {
					position = typed_counter++;
				} 
				object = new TypedToken(lexeme, (TokenType) identifier, position);
			}
			if (!exist)
				symbols.push_back((TypedToken *) object);
		} else {
			object = new UnmappedToken(lexeme);
		}
		tokens.push_back(object);

	}

}

void MiniGPortugol::LexAnalyzer::printRecognizeTable() {
	std::cout << "---------------------------" << std::endl;
	std::cout << "Reconhecimento dos tokens" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Lexemas\t\t\tToken" << std::endl;

	for (auto *t : tokens) {
		t->print();
	}
}

void MiniGPortugol::LexAnalyzer::printSymbolsTable() {
	std::cout << "---------------------" << std::endl;
	std::cout << "Tabela de simbolos" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "Pos\t\t\tSimbolo\t\t\tTipo" << std::endl;

	for (auto *t : symbols) {
		std::cout << t->getPosition() << "\t\t\t" << t->getLexeme() << "\t\t\t" <<
			t->getTokenType() << std::endl;
	}
}

// Funcao verifica se o identificador ja foi utilizado caso ele seja uma variavel
bool MiniGPortugol::LexAnalyzer::identifierExists(std::string& stream, int& position) {
	for (auto *t : symbols) {
		if (t->getLexeme() == stream) {
			position = t->getPosition();
			return true;
		}
	}
	return false;
}