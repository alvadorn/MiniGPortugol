#ifndef __T_PROCESSOR_H__
#define __T_PROCESSOR_H__

#include <cstdint>
#include <cstdio>

namespace MiniGPortugol {
	namespace LexAnalyzer {
		class TextProcessor {
		private:
			uint64_t line;
			uint64_t column;
			char buffer[2049];
			void readline();
			FILE *file;
		public:
			char nextChar();
			void rollback();
			uint64_t actualLineNumber();
			uint64_t actualColumnNumber();
		};
	}
	/*class TextProcessor {
	private:
		std::string line;
		std::ifstream file;
		std::list<std::string> tokens;
		bool nextLine();
		bool isSymbol(char);
		bool isSpace(char);

	public:
		TextProcessor(char *filename);
		~TextProcessor();

		std::string nextToken();
	};*/
}


#endif // __T_PROCESSOR_H__
