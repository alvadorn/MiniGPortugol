#include "token.h"


MiniGPortugol::AbstractToken::AbstractToken() {

}

MiniGPortugol::AbstractToken::~AbstractToken() {

}

MiniGPortugol::UnmappedToken::UnmappedToken(std::string t_name) {
	this->t_name = t_name;
}

MiniGPortugol::UnmappedToken::~UnmappedToken() {
	
}

MiniGPortugol::TypedToken::TypedToken(TokenType t_type, std::string t_name) {
	this->t_type = t_type;
	this->t_name = t_name;
}

MiniGPortugol::TypedToken::~TypedToken() {

}