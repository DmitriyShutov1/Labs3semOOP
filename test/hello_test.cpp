#include <gtest/gtest.h>
#include <string>
#include <algorithm>
#include "lib.h"

using namespace std;

TEST(vowel_count1, FirstTest) {
  string input = "abcde fghi postav 10 pj";
  int result = vowel_count(input);
  ASSERT_EQ(result, 5);
}

TEST(vowel_count1, SecondTest) {
  string input = "";
  int result = vowel_count(input);
  ASSERT_EQ(result, 0);
}

TEST(vowel_count1, TretuiTest) {
  string input = "    ";
  int result = vowel_count(input);
  ASSERT_EQ(result, 0);
}


TEST(vowel_count1, ChetvertiuTest) {
  string input = "bnhghn hngh  hhhn [[ 73273 '],.";
  int result = vowel_count(input);
  ASSERT_EQ(result, 0);
}

TEST(vowel_count1, PyatiuTest) {
  string input = "aee yui ooyu";
  int result = vowel_count(input);
  ASSERT_EQ(result, 10);
}

TEST(vowel_count1, ShestoyTest) {
  string input = "aeeh yuil ooyuk";
  int result = vowel_count(input);
  ASSERT_EQ(result, 10);
}
