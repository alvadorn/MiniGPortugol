#ifndef __LEX_ANALYZER_H__
#define __LEX_ANALYZER_H__

#include <string>
#include "../text/processor.h"

namespace MiniGPortugol {
	
	class LexAnalyzer {
	private:
		std::string token;

	public:
		std::string getToken();
		LexAnalyzer();
		~LexAnalyzer();
	};

}

#endif // __LEX_ANALYZER_H__