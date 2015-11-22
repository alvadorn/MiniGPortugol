#include "symbols_table.h"

MiniGPortugol::SymbolsTable::SymbolsTable() {

}

MiniGPortugol::SymbolsTable::~SymbolsTable() {

}

void MiniGPortugol::SymbolsTable::newToken(std::string& lexeme, TokenType type) {
	Token token(lexeme, type);
	tokens.push_back(token);
}
