#include "gtest/gtest.h"
#include "OPZ.h"

TEST(OPZ, RPN1){
    Solution sol;
    string s = "8*3";
    s = sol.Conversion(s);
    EXPECT_EQ(s, "8 3*");
}

TEST(OPZ, Solve1){
    Solution sol;
    string s = "8*3";
    s = sol.Conversion(s);
    EXPECT_EQ(sol.Process(s), 24);
}

TEST(OPZ, RPN2){
    Solution sol;
    string s = "(16-4+2+1)/(5+5-3-2)";
    s = sol.Conversion(s);
    EXPECT_EQ(s, "16 4- 2+ 1+ 5 5+ 3- 2-/");
}

TEST(OPZ, Solve2){
    Solution sol;
    string s = "(16-4+2+1)/(5+5-3-2)";
    s = sol.Conversion(s);
    EXPECT_EQ(sol.Process(s), 3);
}

TEST(OPZ, RPN3){
    Solution sol;
    string s = "3*(4+5)-1/(2+2)";
    s = sol.Conversion(s);
    EXPECT_EQ(s, "3 4 5+* 1 2 2+/-");
}

TEST(OPZ, Solve3){
    Solution sol;
    string s = "3*(4+5)-1/(2+2)";
    s = sol.Conversion(s);
    EXPECT_EQ(sol.Process(s), 27);
}

TEST(OPZ, DivisionByZero) {
    Solution sol;
    string s = "5/0";
    s = sol.Conversion(s);
    EXPECT_THROW(sol.Process(s), Div_Zero);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}