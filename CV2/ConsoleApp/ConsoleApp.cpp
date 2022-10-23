#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "textCounter.hpp"


int main(int argc, char const* const* argv)
{
	if (argc == 1) {
		std::string buffer;
		while (std::getline(std::cin, buffer)) {
			countText(buffer);
		}
	}
	else {
		for (int i = 1; i < argc; i++) {
			std::ifstream is(argv[i]);
			std::string buffer;
			while (std::getline(is, buffer)) {
				countText(buffer);
			}
		}
	}
	std::cout
		<< "znaku: " << OutputValues.charCount - 1 << "\n" //The -1 is a somewhat rude way to fix the last row not being ended by a newline character
		<< "slov: " << OutputValues.wordCount << "\n"
		<< "vet: " << OutputValues.sentenceCount << "\n"
		<< "radku: " << OutputValues.rowCount << "\n"
		<< "cisel: " << OutputValues.numCount << "\n"
		<< "soucet: " << OutputValues.numSum
		<< std::endl;
	OutputValues.ClearOutput();
	return 0;
}
