#include "symbols_table.h"

MiniGPortugol::SymbolsTable::SymbolsTable() {

}

MiniGPortugol::SymbolsTable::~SymbolsTable() {

}

void MiniGPortugol::SymbolsTable::newToken(std::string& lexeme, TokenType type) {
	uint64_t pos = tokens.size() + 1;
	Token token(lexeme, type);

	if (type != SYMBOL) {
		token.setPosition(pos);
	}

	auto &it = std::find_if(tokens.begin(), tokens.end(),
		[](Token v) -> bool { return v.getLexeme() == lexeme; });

	if (it == tokens.end()) {
		tokens.push_back(token);
	}

}
