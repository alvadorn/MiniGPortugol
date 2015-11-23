#include "symbols_table.h"
#include <algorithm>
#include <iostream>

MiniGPortugol::SymbolsTable::SymbolsTable() {
	last_position = 0;
}

MiniGPortugol::SymbolsTable::~SymbolsTable() {

}

void MiniGPortugol::SymbolsTable::newToken(std::string& lexeme, TokenType type,
	uint64_t line, uint64_t column) {
	uint64_t pos = tokens.size() + 1;
	Token token(lexeme, type);

	if (type != T_SYMBOL) {
		token.setPosition(pos);
	}

	auto it = std::find_if(tokens.begin(), tokens.end(),
		[lexeme](Token v) -> bool { return v.getLexeme() == lexeme; });

	if (it == tokens.end()) {
		tokens.push_back(token);
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
