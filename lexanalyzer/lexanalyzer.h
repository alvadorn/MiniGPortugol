#ifndef __LEX_ANALYZER_H__
#define __LEX_ANALYZER_H__

#include <string>
#include "../text/processor.h"

namespace MiniGPortugol {
	
	class LexAnalyzer {
	private:
		TextProcessor *processor;
		std::string token;

	public:
		void start();
		std::string getToken();
		LexAnalyzer(char []);
		~LexAnalyzer();
	};

}

#endif // __LEX_ANALYZER_H__