#include <string>
#include <iostream>
#include <set>
using std::string;
using std::set;

class SimilarityChecker {
public:
	int getLengthPoint(const string& input1, const string& input2)
	{		
		int lengthLongWord = std::max(input1.length(), input2.length());
		int lengthShortWord = std::min(input1.length(), input2.length());
		if (isMaxPoint(input1, input2)) return LengthMaxScore;
		if (isMinPoint(input1, input2)) return MinScore;
		 
		int gap = lengthLongWord - lengthShortWord;
		return (1 - gap/lengthShortWord) * LengthMaxScore;
	}

	int getAlphabetPoint(const string& input1, const string& input2)
	{
		if (isSameAlphabetUsed(input1, input2)) return AlphabetMaxScore;

		return MinScore;
	}

private:
	static constexpr int AlphabetMaxScore = 40;
	static constexpr int LengthMaxScore = 60;
	static constexpr int MinScore = 0;

	bool isSameAlphabetUsed(const std::string& input1, const std::string& sinput2) {
		set<char> set1(input1.begin(), input1.end());
		set<char> set2(sinput2.begin(), sinput2.end());
		return set1 == set2;
	}

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