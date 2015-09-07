#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>
#include "tokentype.h"

namespace MiniGPortugol {
	class AbstractToken {
	public:
		AbstractToken();
		virtual ~AbstractToken();
	};

	class UnmappedToken : public AbstractToken {
	private:
		std::string t_name;
	public:
		UnmappedToken(std::string);
		~UnmappedToken();
	};

	class TypedToken : public AbstractToken {
	private:
		std::string t_name;
		TokenType t_type;
	public:
		TypedToken(TokenType, std::string);
		~TypedToken();
	};
}

#endif // __TOKEN_H__