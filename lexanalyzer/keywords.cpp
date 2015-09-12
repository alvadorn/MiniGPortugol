#include "keywords.h"

bool MiniGPortugol::Keywords::isReserved(std::string stream) {

    auto it = std::find(reserved_words.begin(),
    reserved_words.end(), stream);

    return it != reserved_words.end();
}
