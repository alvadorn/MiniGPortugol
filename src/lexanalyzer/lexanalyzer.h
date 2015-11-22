#ifndef __LEX_ANALYZER_H__
#define __LEX_ANALYZER_H__

#include <string>
#include <vector>
#include <list>
#include "text/processor.h"
#include "../symbols/tokentype.h"
#include "../symbols/symbols_table.h"
#include "states.h"

namespace MiniGPortugol {

	class LexAnalyzer {
	private:
		TextProcessor *processor;
		SymbolsTable symbols;
		States state_machine;
		std::vector<std::string> keywords;
		bool loadKeywords();
		Symbol typeOfChar(char);
		void skipComment();
	public:
		LexAnalyzer(char *);
		~LexAnalyzer();
		void analyze();
		MiniGPortugol::TokenType typeRecognized(const uint8_t);
	};

}

#endif // __LEX_ANALYZER_H__
