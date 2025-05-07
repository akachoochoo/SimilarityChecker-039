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

TEST(SimilarityChecker, CheckLengthPartial1) {
	int expected = 20;
	SimilarityChecker app;
	string input1 = "AAABB";
	string input2 = "BAA";

	int actual = app.getSimilarity(input1, input2);

	EXPECT_EQ(expected, actual);
}

TEST(SimilarityChecker, CheckLengthPartial2) {
	int expected = 30;
	SimilarityChecker app;
	string input1 = "AA";
	string input2 = "AAE";

	int actual = app.getSimilarity(input1, input2);

	EXPECT_EQ(expected, actual);
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
};