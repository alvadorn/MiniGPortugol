#include "lexanalyzer.h"
#include "../symbols/tokentype.h"
#include <cstdint>
#include <cstdio>
#include <iostream>

MiniGPortugol::LexAnalyzer::LexAnalyzer(char *filename) {
	std::cout << "Loading keywords" << std::endl;
	if (!loadKeywords()) {
			exit(1);
	}
	std::cout << "Initializing LexAnalyzer" << std::endl;
	processor = new TextProcessor(filename);
}

MiniGPortugol::LexAnalyzer::~LexAnalyzer() {
	delete processor;
	keywords.clear();
}

bool MiniGPortugol::LexAnalyzer::loadKeywords() {
	FILE *keyword_file = fopen("keywords.txt", "r");
	if (keyword_file == NULL) {
		std::cout << "Can't open keywords file" << std::endl;
		return false;
	}
	std::string buffer = "";
	while(!feof(keyword_file)) {
		char read = fgetc(keyword_file);
		if (read != '\n') {
			buffer += read;
		} else {
			keywords.push_back(buffer);
			buffer = "";
		}
	}
	fclose(keyword_file);
	return true;
}

void MiniGPortugol::LexAnalyzer::analyze() {
	uint8_t state = 0;
	char c;
	std::string buffer = "";
	while ((c = processor->nextChar()) != EOF) {
		Symbol symbol = typeOfChar(c);
		if (c == '/') {
			if ((c = processor->nextChar()) == '/') skipComment();
		} else {
			state = state_machine.nextState(state, symbol);
			buffer += c;
			if (state_machine.isRecognizeState(state)) {

			}
		}
	}
}

Symbol MiniGPortugol::LexAnalyzer::typeOfChar(char c) {
	if (c == '(') return OPEN_PARENT;
	else if (c == ')') return CLOSE_PARENT;
	else if (c == ':') return COLON;
	else if (c == ',') return COMMA;
	else if (c == ';') return SEMICOLON;
	else if (c == '_') return UNDERSCORE;
	else if (c == '.') return DOT;
	else if (c == '<') return LESS_THAN;
	else if (c == '>') return GREATER_THAN;
	else if (c == '=') return EQUAL;
	else if (c == '\'') return APOSTROPHE;
	else if (c == '+') return MATH_OP;
	else if (c == '-') return MATH_OP;
	else if (c == '/') return MATH_OP;
	else if (c == '*') return MATH_OP;
	else if (c == '%') return MATH_OP;
	else if (c >= 'a' && c <= 'z') return LETTER;
	else if (c >= 'A' && c <= 'Z') return LETTER;
	else if (c >= '0' && c <= '9') return NUMBER;
	else return UNIDENTIFIED;
}

void MiniGPortugol::LexAnalyzer::skipComment() {
	while(processor->nextChar() != '\n');
}


MiniGPortugol::TokenType MiniGPortugol::LexAnalyzer::typeRecognized(const uint8_t state) {
  if (state == 1 || state == 3) return T_NUMBER;
  else if (state == 6) return T_CHARACTER;
  else if (state == 9) return T_RES_OR_ID;
  else return T_SYMBOL;
}
