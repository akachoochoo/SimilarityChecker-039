#include "gmock/gmock.h"
#include "similaritychecker.cpp"
#include <string>
using std::string;

TEST(SimilarityChecker, CheckLengthMax){
	int expected = 60;
	SimilarityChecker app;
	string input1 = "ASD";
	string input2 = "DSA";

	int actual = app.getSimilarity(input1, input2);
	
	EXPECT_EQ(expected, actual);
}

TEST(SimilarityChecker, CheckLengthMin) {
	int expected = 0;
	SimilarityChecker app;
	string input1 = "A";
	string input2 = "BB";

	int actual = app.getSimilarity(input1, input2);

	EXPECT_EQ(expected, actual);
}

TEST(SimilarityChecker, CheckLengthPartial) {
	int expected = 0;
	SimilarityChecker app;
	string input1 = "AAABB";
	string input2 = "BAA";

	int actual = app.getSimilarity(input1, input2);

	EXPECT_EQ(expected, actual);
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
};