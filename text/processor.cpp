#include "processor.h"

MiniGPortugol::TextProcessor::TextProcessor(char *filename) {
	file.open(filename);
}

MiniGPortugol::TextProcessor::~TextProcessor() {

}