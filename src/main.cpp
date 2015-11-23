#include <iostream>
#include "globals.h"
#include "lexanalyzer/lexanalyzer.h"

int main(int argc, char *argv[]) {

	if (argc != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
	}

	MiniGPortugol::LexAnalyzer lexAnalyzer(argv[1]);
	lexAnalyzer.analyze();
	//lexAnalyzer.printInformation();
	return 0;
}
