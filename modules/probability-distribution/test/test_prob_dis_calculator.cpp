// Copyright 2018 Lalykin Oleg

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/prob_dis_calculator.h"


using ::testing::internal::RE;
using std::vector;
using std::string;

class ProbDisCalculatorTest : public ::testing::Test {
 protected:
     // virtual void SetUp() {}

     void Act(vector<string> args_) {
         vector<const char*> options;

         options.push_back("appname");
         for (size_t i = 0; i < args_.size(); ++i) {
             options.push_back(args_[i].c_str());
         }

         const char** argv = &options.front();
         int argc = static_cast<int>(args_.size()) + 1;

         output_ = app_(argc, argv);
     }

     void Assert(std::string expected) {
         EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
     }

private:
    ProbDisCalculator app_;
    string output_;
};

TEST_F(ProbDisCalculatorTest, Do_f) {
    vector<string> args = {"2", "0.2", "2", "+","0"};

    Act(args);
   
    Assert("ERROR: Should be nn3 arguments\\..*");
}

TEST_F(ProbDisCalculatorTest, Can_Get_Zeroth_Raw_Moment) {
    vector<string> args = {"2",
        "1", "3", 
        "0.2", "0.8", 
        "RawMoment","0"};

    Act(args);
   
    Assert("RawMoment = 1");
}
TEST_F(ProbDisCalculatorTest, Can_Get_Second_Raw_Moment) {
    vector<string> args = { "3",
        "1", "3","5", 
        "0.2", "0.5", "0.3",
        "RawMoment","2"};

    Act(args);

    Assert("RawMoment = 12.2");
}
TEST_F(ProbDisCalculatorTest, Can_Get_Zeroth_Central_Moment) {
    vector<string> args = { "3",
        "1", "3","5",
        "0.2", "0.5", "0.3",
        "CentralMoment","0" };

    Act(args);

    Assert("CentralMoment = 1");
}
TEST_F(ProbDisCalculatorTest, Can_Get_First_Central_Moment) {
    vector<string> args = { "3",
        "1", "3","5",
        "0.2", "0.5", "0.3",
        "CentralMoment","1" };

    Act(args);

    Assert("CentralMoment = 0");
}
TEST_F(ProbDisCalculatorTest, Can_Get_Variance) {
    vector<string> args = { "3",
        "1", "3","5",
        "0.2", "0.5", "0.3",
        "Variance","1" };

    Act(args);

    Assert("Variance = 1.96");
}

TEST_F(ProbDisCalculatorTest, Can_Get_Expected_Value) {
    vector<string> args = { "3",
        "1", "3","5",
        "0.2", "0.5", "0.3",
        "Expected","1" };

    Act(args);

    Assert("Expected = 3.2");
}
//TEST_F(ProbDisCalculatorTest, Can_Detect_Wrong_Number_Format) {
//    vector<string> args = { "1", "pi", "2", "4", "1", "6","+" };
//
//    Act(args);
//
//    Assert("Wrong number format!.*");
//}
//
//TEST_F(ProbDisCalculatorTest, Can_Detect_Wrong_Operation_Format) {
//    vector<string> args = { "1", "3", "2", "4", "1", "6", "Baga" };
//
//    Act(args);
//
//    Assert("Wrong operation format!");
//}
//
//
//TEST_F(ProbDisCalculatorTest, Can) {
//
//    std::vector<double> values = { 1.0, 3.0, 5.0 };
//    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
//    vector<string> args = { "1", "3", "2", "4", "1", "6", "Baga" };
//
//    Act(args);
//
//    Assert("Wrong operation format!");
//}
//TEST_F(ProbDisCalculatorTest, Can_Add_Complexs) {
//    vector<string> args = { "2.0", "3.5", "1.5", "4.0", "+" };
//
//    Act(args);
//
//    Assert("Real = 3.5 Imaginary = 7.5");
//}
//
//TEST_F(ProbDisCalculatorTest, Can_Diff_Complexs) {
//    vector<string> args = { "13", "7.6", "26", "-14", "-" };
//
//    Act(args);
//
//    Assert("Real = -13 Imaginary = 21.6");
//}
//
//TEST_F(ProbDisCalculatorTest, Can_Mult_Complexs) {
//    vector<string> args = { "0", "-3.6", "17.4", "21", "*" };
//
//    Act(args);
//
//    Assert("Real = 75.6 Imaginary = -62.64");
//}
//
//TEST_F(ProbDisCalculatorTest, Can_Divide_Complexs) {
//    vector<string> args = { "27", "30", "15", "20", "/" };
//
//    Act(args);
//
//    Assert("Real = 1.608 Imaginary = -0.144");
//}
//
//TEST_F(ProbDisCalculatorTest, Can_Detect_Divide_By_Zero) {
//    vector<string> args = { "27", "30", "0", "0", "/" };
//
//    Act(args);
//
//    Assert("Can't divide by zero");
//}