#include "gmock/gmock.h"
#include "similaritychecker.cpp"
#include <string>
using std::string;

class SimilarityCheckerFixture : public ::testing::Test
{
public:
	SimilarityChecker app;
	void doLengthTest(const string& input1, const string& input2, int expected) {
		EXPECT_EQ(expected, app.getLengthPoint(input1, input2));
	}
	void doAlphabetTest(const string& input1, const string& input2, int expected) {
		EXPECT_EQ(expected, app.getAlphabetPoint(input1, input2));
	}
};


TEST_F(SimilarityCheckerFixture, CheckLengthMax){
	doLengthTest("ASD", "DSA", 60);
	doAlphabetTest("ASD", "DSA", 40);
}

TEST_F(SimilarityCheckerFixture, CheckLengthMin) {
	doLengthTest("A", "BB", 0);
}

TEST_F(SimilarityCheckerFixture, CheckLengthPartial1) {	
	doLengthTest("AAABB", "BAA", 20);
}

TEST_F(SimilarityCheckerFixture, CheckLengthPartial2) {
	doLengthTest("AA", "AAE", 30);
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
};