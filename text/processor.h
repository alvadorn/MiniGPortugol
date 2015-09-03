#ifndef __T_PROCESSOR_H__
#define __T_PROCESSOR_H__

#include <string>
#include <sstream>

namespace MiniGPortugol {

	class TextProcessor {
	private:
		std::string line;
		std::ifstream file;

	public:
		TextProcessor(char *filename);
		~TextProcessor();
	};
}


#endif // __T_PROCESSOR_H__