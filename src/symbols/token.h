#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>
#include <cstdint>
#include "tokentype.h"

namespace MiniGPortugol {
	class Token {
	private:
		std::string lexeme;
		TokenType token_type;
		uint64_t position;
	public:
		Token(std::string, TokenType);
		~Token();
		std::string getLexeme();
		uint64_t getPosition();
		void setPosition(uint64_t);
	};
}

#endif // __TOKEN_H__
