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
	void countText(std::string const& data);
};
#endif