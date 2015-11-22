#include "token.h"
#include <iostream>


MiniGPortugol::Token::Token(std::string lexeme, TokenType token_type) {
	this->lexeme = lexeme;
	this->token_type = token_type;
}

MiniGPortugol::Token::~Token() {

}

std::string MiniGPortugol::Token::getLexeme() {
	return this->lexeme;
}
