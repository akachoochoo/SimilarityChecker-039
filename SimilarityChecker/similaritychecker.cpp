#include <string>
#include <iostream>
using std::string;

class SimilarityChecker {
public:
	int getSimilarity(string& input1, string& input2)
	{		
		if (isMax(input1, input2)) return LengthMaxScore;
		if (isMin(input1, input2)) return LengthMinScore;

		return LengthMinScore;
	}

	bool isMin(std::string& input1, std::string& input2)
	{
		int lengthLongWord = std::max(input1.length(), input2.length());
		int lengthShortWord = std::min(input1.length(), input2.length());		
		
		if (lengthLongWord >= lengthShortWord * 2) return true;
		
		return false;
	}

	bool isMax(std::string& input1, std::string& input2)
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