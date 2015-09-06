#ifndef __T_PROCESSOR_H__
#define __T_PROCESSOR_H__

#include <string>
#include <fstream>

namespace MiniGPortugol {

	class TextProcessor {
	private:
		std::string line;
		std::ifstream file;
		bool nextLine();
		bool isSymbol(char c);

	public:
		TextProcessor(char *filename);
		~TextProcessor();

		std::string nextToken();
	};
}


#endif // __T_PROCESSOR_H__