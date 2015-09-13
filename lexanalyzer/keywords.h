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

        /*const std::map<std::string, std::vector<std::string>> reserved = {
            { "has_next", { "algoritmo"}
        }, {"only", { "real", "fim-se", "falso" } }
    };*/

        const std::map<TokenType, std::map<KeywordType, std::vector<std::string>>> keywords = {
            { reserved, {
                { has_next,
                    { "algoritmo", "logico" }
                },
                { only,
                    { "real", "fim-se", "falso" }
                },
                { both,
                    {"e", "ou" }
                },
                { has_before,
                    { "" }
                }
                }
            }
        };

        const std::vector<std::string> reserved_words = { "algoritmo", "caractere", "e",
        "enquanto", "entao", "faca", "falso","fim", "fim-enquanto", "fim-se",
        "fim-variaveis","inicio", "inteiro", "literal", "logico", "nao", "ou",
        "real","se", "senao","variaveis", "verdadeiro" };

        bool isReserved(std::string stream);
    }
}


#endif // __KEYWORDS_H__
