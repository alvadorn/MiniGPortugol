#ifndef __LEX_ANALYZER_H__
#define __LEX_ANALYZER_H__

#include <string>
#include <vector>
#include <list>
#include "../token/token.h"
#include "../text/processor.h"

namespace MiniGPortugol {

	class LexAnalyzer {
	private:
		TextProcessor *processor;
		std::string lexeme;
		std::vector<AbstractToken *> tokens;
		std::list<TypedToken *> symbols;
		void printRecognizeTable();
		void printSymbolsTable();
		bool identifierExists(std::string&, int&);

	public:
		void start();
		std::string getLexeme();
		LexAnalyzer(char []);
		~LexAnalyzer();
	};

}

#endif // __LEX_ANALYZER_H__
