#ifndef __TOKEN_TYPE_H__
#define __TOKEN_TYPE_H__

#include <string>

namespace MiniGPortugol {
	enum TokenType { reserved = 0, identifier = 1, number = 2, unavailable = 3 };

	const std::string TokenTypeName[] = { "reservado", "identificador", "numero" };
}

#endif // __TOKEN_TYPE_H__
