#include "symbols_table.h"
#include <algorithm>
#include <iostream>

MiniGPortugol::SymbolsTable::SymbolsTable() {
	last_position = 1;
}

MiniGPortugol::SymbolsTable::~SymbolsTable() {

}

void MiniGPortugol::SymbolsTable::newToken(std::string& lexeme, TokenType type,
	uint64_t line, uint64_t column) {
	Token token(lexeme, type);

	auto it = std::find_if(tokens.begin(), tokens.end(),
		[lexeme](Token v) -> bool { return v.getLexeme() == lexeme; });


	if (it == tokens.end()) {
		if (type != T_SYMBOL) {
			token.setPosition(last_position++);
		}
		tokens.push_back(token);
	} else {
		token.setPosition(it->getPosition());
	}

	printGeneralInfo(token);
}

void MiniGPortugol::SymbolsTable::printGeneralInfo(Token &t) {
	std::cout << t.getLexeme() << "\t\t\t" << "<";
	if (t.getType() == T_SYMBOL) {
		std::cout << t.getLexeme() << ">" << std::endl;
	} else {
		std::cout << TokenTypeName[t.getType()] << "," << t.getPosition()
		 	<< ">" << std::endl;
	}

}
