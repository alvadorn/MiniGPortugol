#ifndef __KEYWORDS_H__
#define __KEYWORDS_H__

#include <string>
#include <vector>
#include <algorithm>

namespace MiniGPortugol {

    namespace Keywords {
        const std::vector<std::string> reserved_words = { "algoritmo", "caractere", "e",
        "enquanto", "entao", "faca", "falso","fim", "fim-enquanto", "fim-se",
        "fim-variaveis","inicio", "inteiro", "literal", "logico", "nao", "ou",
        "real","se", "senao","variaveis", "verdadeiro" };

        bool isReserved(std::string stream);
    }
}


#endif // __KEYWORDS_H__
