#ifndef __SYMBOLS_TABLE__
#define __SYMBOLS_TABLE__

#include <list>
#include <string>
#include "token.h"
#include "tokentype.h"

namespace MiniGPortugol {
	class SymbolsTable {
	private:
		std::list<Token> tokens;
		void printGeneralInfo(Token &);
		uint64_t last_position;
	public:
		SymbolsTable();
		~SymbolsTable();
		void newToken(std::string&, TokenType, uint64_t, uint64_t);
	};
}

#endif // __SYMBOLS_TABLE__
