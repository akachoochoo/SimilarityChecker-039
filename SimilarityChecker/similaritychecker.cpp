#include <string>
using std::string;

class SimilarityChecker {
public:
	int getSimilarity(string& input1, string& input2)
	{		
		if (isMax(input1, input2)) return LengthMaxScore;

		return LengthMinScore;
	}

	bool isMax(std::string& input1, std::string& input2)
	{
		bool retFlag = true;

		int length1 = input1.length();
		int length2 = input2.length();

		if (length1 == length2) return true;		
	}
private:
	static constexpr int LengthMaxScore = 60;
	static constexpr int LengthMinScore = 0;
};