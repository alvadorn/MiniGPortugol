#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>
#include "tokentype.h"

namespace MiniGPortugol {
	class Token {
	private:
		std::string lexeme;
		TokenType token_type;
	public:
		Token(std::string, TokenType);
		~Token();
		std::string getLexeme();
	};
}

#endif // __TOKEN_H__
