#include <string>
#include <iostream>
using std::string;

class SimilarityChecker {
public:
	int getLengthPoint(const string& input1, const string& input2)
	{		
		int lengthLongWord = std::max(input1.length(), input2.length());
		int lengthShortWord = std::min(input1.length(), input2.length());
		if (isMaxPoint(input1, input2)) return LengthMaxScore;
		if (isMinPoint(input1, input2)) return LengthMinScore;


		int gap = lengthLongWord - lengthShortWord;
		return (1 - gap/lengthShortWord) * LengthMaxScore;
	}


private:
	static constexpr int LengthMaxScore = 60;
	static constexpr int LengthMinScore = 0;


	bool isMinPoint(const std::string& input1, const  std::string& input2)
	{
		int lengthLongWord = std::max(input1.length(), input2.length());
		int lengthShortWord = std::min(input1.length(), input2.length());

		if (lengthLongWord >= lengthShortWord * 2) return true;

		return false;
	}

	bool isMaxPoint(const string& input1, const string& input2)
	{
		int length1 = input1.length();
		int length2 = input2.length();

		if (length1 == length2) return true;

		return false;
	}
};