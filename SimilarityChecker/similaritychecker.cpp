#include <string>
using std::string;

class SimilarityChecker {
public:
	int getSimilarity(string& input1, string& input2)
	{
		if (input1.length() > input2.length())
			if (input1.length() > (input2.length() * 2)) return 0;
		if (input1.length() < input2.length())
			if (input1.length() < (input2.length() * 2)) return 0;

		return 60;
	}
};