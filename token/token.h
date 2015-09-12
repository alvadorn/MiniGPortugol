#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>
#include "tokentype.h"

namespace MiniGPortugol {
	class AbstractToken {
	public:
		AbstractToken();
		virtual ~AbstractToken();
		virtual void print();
	protected:
		std::string lexeme;
	};

	class UnmappedToken : public AbstractToken {
	private:
	public:
		UnmappedToken(std::string);
		~UnmappedToken();
		void print();
	};

	class TypedToken : public AbstractToken {
	private:
		TokenType t_type;
		int position;
	public:
		TypedToken(std::string&, TokenType, int);
		~TypedToken();
		void print();
	};
}

#endif // __TOKEN_H__
