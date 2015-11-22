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
	public:
		SymbolsTable();
		~SymbolsTable();
		void newToken(std::string&, TokenType);
	};
}

#endif // __SYMBOLS_TABLE__
