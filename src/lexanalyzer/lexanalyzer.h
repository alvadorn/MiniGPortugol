#ifndef __LEX_ANALYZER_H__
#define __LEX_ANALYZER_H__

#include <string>
#include <vector>
#include <list>

namespace MiniGPortugol {

	class LexAnalyzer {
	private:
		std::vector<std::string> keywords;
		bool loadKeywords();

	public:
		LexAnalyzer(char []);
		~LexAnalyzer();

	};

}

#endif // __LEX_ANALYZER_H__
