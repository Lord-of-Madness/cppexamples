#ifndef textCounter
#define textCounter

	struct WCounter {
		enum wordState { noWord, number, word };
		wordState wS = noWord;
		bool sentenceState = false;
		int currentNum = 0;
		int charCount = 0;
		int rowCount = 0;
		int wordCount = 0;
		int sentenceCount = 0;
		int numCount = 0;
		int numSum = 0;
		void count(char const ch);
		void ClearOutput();
	}OutputValues;


	inline void WCounter::count(char const ch) {

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

	void countText(std::string const &data) {
		//charCount
		OutputValues.charCount += (int)data.length() + 1;
		//rowCount
		if (data.length() != 0)OutputValues.rowCount++;
		//count the rest
		for (const char& c : data) {
			OutputValues.count(c);
		}
		OutputValues.count('\n');//to end the last line
	}

	inline void WCounter::ClearOutput() {
		wordState wS = noWord;
		sentenceState = false;
		currentNum = 0;
		charCount = 0;
		rowCount = 0;
		wordCount = 0;
		sentenceCount = 0;
		numCount = 0;
		numSum = 0;
	}
#endif