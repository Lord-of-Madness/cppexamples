#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>


struct WCounter {
	enum wordState { noWord, number, word };
	wordState wS = noWord;
	bool sentenceState = false;
	//bool rowState = false;
	int currentNum = 0;
	int pocetZnaku = 0;
	int pocetRadek = 0;
	int pocetSlov = 0;
	int pocetVet = 0;
	int numCount = 0;
	int numSum = 0;
	void count(char const ch);
}OutputCisla;


inline void WCounter::count(char const ch) {

	switch (ch)
	{
	case ' ':
	case '\t':
	case '\n':
		if (wS == word) {
			pocetSlov++;
			wS = noWord;
			if (!sentenceState)sentenceState = true;
			//rowState = true;
		}
		else if (wS == number) {
			numCount++;
			numSum+=currentNum;
			currentNum = 0;
			wS = noWord;
			//rowState = true;
		}
		break;
	case '!':
	case '?':
	case '.':
		if (wS == word) {
			pocetSlov++;
			wS = noWord;
			if (!sentenceState)sentenceState = true;
			//rowState = true;
		}
		else if (wS == number) {
			numCount++;
			numSum += currentNum;
			currentNum = 0;
			wS = noWord;
			//rowState = true;
		}
		if (sentenceState) {
			pocetVet++;
			sentenceState = false;
		}
		break;
	default:
		if (isalpha(ch))wS = word; 
		else if(isdigit(ch)){
			wS = number;
			currentNum *= 10;
			currentNum += ch-'0';
		}
		else if (wS == number) { 
			numCount++;
			numSum += currentNum;
			currentNum = 0;
			wS = noWord;
		}
}
}


void ZpracovaniDat(std::string const data) {
	//pocetZnaku
	OutputCisla.pocetZnaku += (int)data.length() +1;
	if (data.length() != 0)OutputCisla.pocetRadek++;
	//count the rest
	for (const char& c : data) {
		OutputCisla.count(c);
	}
	OutputCisla.count('\n');//to end the line



	//std::for_each(data, data + charammount, count);

	//sum whats summable
	/*std::istringstream ss(data);
	std::string word;
	int number;
	while (ss >> word)
	{
		std::istringstream maybenumber(word);
		if (maybenumber >> number)
		{
			//OutputCisla.count++; //Numbers according to the specification might not be inteagers
			OutputCisla.numSum += number;
		}
	}*/
}



int main(int argc, char const* const* argv)
{
	if (argc == 1) {
		std::string buffer;
		while (std::getline(std::cin, buffer)) {
			//std::cout << buffer;
			ZpracovaniDat(buffer);
		}
		/*char buffer[256];
		while (!std::cin.eof()) {
			std::cin.getline(buffer, 256);
			//std::cout << buffer;//Debug purposes
			ZpracovaniDat(buffer);
		}*/

	}
	else {
		for (int i = 1; i < argc; i++) {
			std::ifstream is(argv[i]);
			std::string buffer;
			while (std::getline(is, buffer)) {
				//std::cout << buffer;
				ZpracovaniDat(buffer);
			}
		}
	}
	

	std::cout
		<< "znaku: " << OutputCisla.pocetZnaku -1 << "\n" //The -1 is a somewhat rude way to fix the last row not being ended by a newline character
		<< "slov: " << OutputCisla.pocetSlov << "\n"
		<< "vet: " << OutputCisla.pocetVet << "\n"
		<< "radku: " << OutputCisla.pocetRadek << "\n"
		<< "cisel: " << OutputCisla.numCount << "\n"
		<< "soucet: " << OutputCisla.numSum
		<< std::endl;

	return 0;
}
