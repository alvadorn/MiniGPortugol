#ifndef __LEX_ANALYZER_H__
#define __LEX_ANALYZER_H__

#include <string>
#include <vector>
#include <list>
#include "text/processor.h"

namespace MiniGPortugol {

	class LexAnalyzer {
	private:
		TextProcessor processor;
		std::vector<std::string> keywords;
		bool loadKeywords();

	public:
		LexAnalyzer(char []);
		~LexAnalyzer();

	};

}

#endif // __LEX_ANALYZER_H__
