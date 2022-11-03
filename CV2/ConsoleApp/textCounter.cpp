#include <string>
#include "textCounter.hpp"

void WCounter::count(char const ch) {

	switch (ch)
	{
	case ' ':
	case '\t':
	case '\n':
		if (wS == word) {
			wordCount++;
			wS = noWord;
			if (!sentenceState)sentenceState = true;
		}
		else if (wS == number) {
			numCount++;
			numSum += currentNum;
			currentNum = 0;
			wS = noWord;
		}
		break;
	case '!':
	case '?':
	case '.':
		if (wS == word) {
			wordCount++;
			wS = noWord;
			if (!sentenceState)sentenceState = true;
		}
		else if (wS == number) {
			numCount++;
			numSum += currentNum;
			currentNum = 0;
			wS = noWord;
		}
		if (sentenceState) {
			sentenceCount++;
			sentenceState = false;
		}
		break;
	default:
		if (isalpha(ch))wS = word;
		else if (isdigit(ch)) {
			wS = number;
			currentNum *= 10;
			currentNum += ch - '0';
		}
		else if (wS == number) {
			numCount++;
			numSum += currentNum;
			currentNum = 0;
			wS = noWord;
		}
	}
}

void WCounter::ClearOutput() {
	wS = noWord;
	sentenceState = false;
	currentNum = 0;
	charCount = 0;
	rowCount = 0;
	wordCount = 0;
	sentenceCount = 0;
	numCount = 0;
	numSum = 0;
}

void WCounter::countText(std::string const& data) {
	//charCount
	charCount += (int)data.length() + 1;
	//rowCount
	if (data.length() != 0)rowCount++;
	//count the rest
	for (const char& c : data) count(c);
	count('\n');//to end the last line
}