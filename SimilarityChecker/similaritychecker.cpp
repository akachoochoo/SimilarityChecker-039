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
		return (lengthShortWord - gap) * LengthMaxScore / lengthShortWord;
	}

	double getAlphabetPoint(const string& input1, const string& input2)
	{
		set<char> alphaSet1(input1.begin(), input1.end());
		set<char> alphaSet2(input2.begin(), input2.end());

		
		// TotalCnt = 합집합의 크기
		set<char> totalSet = alphaSet1;
		totalSet.insert(alphaSet2.begin(), alphaSet2.end());
		int TotalCnt = totalSet.size();

		// SameCnt = 교집합의 크기
		int SameCnt = 0;
		for (char c : alphaSet1) {
			if (alphaSet2.count(c)) SameCnt++;
		}

		// 점수 계산
		return (TotalCnt == 0) ? 0 : ((double)SameCnt / TotalCnt) * AlphabetMaxScore;		
	}

private:
	static constexpr int AlphabetMaxScore = 40;
	static constexpr int LengthMaxScore = 60;
	static constexpr int MinScore = 0;

	bool isSameAlphabetUsed(const std::string& input1, const std::string& input2) {
		set<char> set1(input1.begin(), input1.end());
		set<char> set2(input2.begin(), input2.end());
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