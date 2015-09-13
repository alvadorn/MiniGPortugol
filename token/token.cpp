#include "token.h"
#include <iostream>


MiniGPortugol::AbstractToken::AbstractToken() {

}

MiniGPortugol::AbstractToken::~AbstractToken() {

}

void MiniGPortugol::AbstractToken::print() {
	std::cout << "nothing" << std::endl;
}

MiniGPortugol::UnmappedToken::UnmappedToken(std::string lexeme) {
	this->lexeme = lexeme;
}

MiniGPortugol::UnmappedToken::~UnmappedToken() {
}

void MiniGPortugol::UnmappedToken::print() {
	std::cout << lexeme << "\t\t\t" << "<" << lexeme << ">" << std::endl;
}

MiniGPortugol::TypedToken::TypedToken(std::string& lexeme, TokenType t_type,
int position) {
	this->t_type = t_type;
	this->lexeme = lexeme;
	this->position = position;
}

MiniGPortugol::TypedToken::~TypedToken() {

}

void MiniGPortugol::TypedToken::print() {
	std::cout << lexeme << "\t\t\t" << "<" << TokenTypeName[t_type] << "," <<
		position << ">" << std::endl;
}

int MiniGPortugol::TypedToken::getPosition() {
	return position;
}

int MiniGPortugol::TypedToken::getTokenType() {
	return t_type;
}

std::string& MiniGPortugol::TypedToken::getLexeme() {
	return lexeme;
}
