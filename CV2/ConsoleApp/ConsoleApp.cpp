#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>


struct {
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
}OutputCisla;


void count(char const ch) {

	switch (ch)
	{
	case ' ':
	case '\t':
		if (OutputCisla.wS == OutputCisla.word) {
			OutputCisla.pocetSlov++;
			OutputCisla.wS = OutputCisla.noWord;
			if (!OutputCisla.sentenceState)OutputCisla.sentenceState = true;
			//OutputCisla.rowState = true;
		}
		else if (OutputCisla.wS == OutputCisla.number) {
			OutputCisla.numCount++;
			OutputCisla.numSum+=OutputCisla.currentNum;
			OutputCisla.currentNum = 0;
			OutputCisla.wS = OutputCisla.noWord;
			//OutputCisla.rowState = true;
		}
		break;
	case '!':
	case '?':
	case '.':
		if (OutputCisla.wS == OutputCisla.word) {
			OutputCisla.pocetSlov++;
			OutputCisla.wS = OutputCisla.noWord;
			if (!OutputCisla.sentenceState)OutputCisla.sentenceState = true;
			//OutputCisla.rowState = true;
		}
		else if (OutputCisla.wS == OutputCisla.number) {
			OutputCisla.numCount++;
			OutputCisla.numSum += OutputCisla.currentNum;
			OutputCisla.currentNum = 0;
			OutputCisla.wS = OutputCisla.noWord;
			//OutputCisla.rowState = true;
		}
		if (OutputCisla.sentenceState) {
			OutputCisla.pocetVet++;
			OutputCisla.sentenceState = false;
		}
		break;
	default:
		if (isalpha(ch))OutputCisla.wS = OutputCisla.word; 
		else if(isdigit(ch)){
			OutputCisla.wS = OutputCisla.number;
			OutputCisla.currentNum *= 10;
			OutputCisla.currentNum += ch-'0';
		}
		else if (OutputCisla.wS == OutputCisla.word)OutputCisla.wS = OutputCisla.noWord;
}
}


void ZpracovaniDat(std::string const data) {
	//pocetZnaku
	OutputCisla.pocetZnaku += data.length();
	if (data.length() != 0)OutputCisla.pocetRadek++;
	//count the rest
	for (const char& c : data) {
		count(c);
	}
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
	//Pick input:
	std::ifstream is("Lorem.txt");
	//std::istream &is = std::cin;
	std::string buffer;
	while (std::getline(is, buffer)) {
		//std::cout << buffer;//Debug purposes
		ZpracovaniDat(buffer);
	}

	std::cout
		<< "znaku: " << OutputCisla.pocetZnaku << "\n"
		<< "radku:" << OutputCisla.pocetRadek << "\n"
		<< "slov:" << OutputCisla.pocetSlov << "\n"
		<< "vet:" << OutputCisla.pocetVet << "\n"
		<< "cisel:" << OutputCisla.numCount << "\n"
		<< "soucet:" << OutputCisla.numSum
		<< std::endl;

	return 0;
}

