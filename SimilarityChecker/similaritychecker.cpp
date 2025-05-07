#include <string>
#include <iostream>
using std::string;

class SimilarityChecker {
public:
	int getSimilarity(const string& input1, const string& input2)
	{		
		int lengthLongWord = std::max(input1.length(), input2.length());
		int lengthShortWord = std::min(input1.length(), input2.length());
		if (isMax(input1, input2)) return LengthMaxScore;
		if (isMin(input1, input2)) return LengthMinScore;


		int gap = lengthLongWord - lengthShortWord;
		return (1 - gap/lengthShortWord) * LengthMaxScore;
	}

	bool isMin(const std::string& input1, const  std::string& input2)
	{
		int lengthLongWord = std::max(input1.length(), input2.length());
		int lengthShortWord = std::min(input1.length(), input2.length());		
		
		if (lengthLongWord >= lengthShortWord * 2) return true;
		
		return false;
	}

	bool isMax(const string& input1, const string& input2)
	{
		int length1 = input1.length();
		int length2 = input2.length();

		if (length1 == length2) return true;	

		return false;
	}

private:
	static constexpr int LengthMaxScore = 60;
	static constexpr int LengthMinScore = 0;
};