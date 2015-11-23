#ifndef __TOKEN_TYPE_H__
#define __TOKEN_TYPE_H__

#include <string>

namespace MiniGPortugol {
	typedef enum t_type { T_RESERVED = 0, T_IDENTIFIER, T_NUMBER, T_CHARACTER,
		T_RES_OR_ID, T_SYMBOL } TokenType;

	const std::string TokenTypeName[] = { "reservado", "identificador", "numero" };
}

#endif // __TOKEN_TYPE_H__
