#ifndef __KEYWORDS_H__
#define __KEYWORDS_H__

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "../token/tokentype.h"

namespace MiniGPortugol {

    namespace Keywords {

        enum KeywordType { has_next, has_before, only, both};

        const std::vector<std::string> reserved_words = { "algoritmo", "caractere", "e",
        "enquanto", "entao", "faca", "falso","fim", "fim-enquanto", "fim-se",
        "fim-variaveis","inicio", "inteiro", "literal", "logico", "nao", "ou",
        "real","se", "senao","variaveis", "verdadeiro" };

        bool isReserved(std::string stream);

        bool isSymbol(std::string stream);

        bool isNumber(std::string stream);
    }
}


#endif // __KEYWORDS_H__
