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

uint64_t MiniGPortugol::Token::getPosition() {
	return this->position;
}

void MiniGPortugol::Token::setPosition(uint64_t position) {
	this->position = position;
}

MiniGPortugol::TokenType MiniGPortugol::Token::getType() {
	return this->token_type;
}
