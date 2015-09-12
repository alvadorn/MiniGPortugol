#ifndef __LEX_ANALYZER_H__
#define __LEX_ANALYZER_H__

#include <string>
#include <vector>
#include "../token/token.h"
#include "../text/processor.h"

namespace MiniGPortugol {

	class LexAnalyzer {
	private:
		TextProcessor *processor;
		std::string lexeme;
		std::vector<AbstractToken *> tokens;
		void printRecognizeTable();

	public:
		void start();
		std::string getLexeme();
		LexAnalyzer(char []);
		~LexAnalyzer();
	};

}

#endif // __LEX_ANALYZER_H__
