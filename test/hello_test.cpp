#include <gtest/gtest.h>
#include <string>
#include "lib.h"

class MoneyTest : public ::testing::TestWithParam<double> {
protected:
    Money first_money;
    MoneyTest() : first_money(GetParam()) {
    }
};

//ТЕСТ КОНСТРУКТОРОВ
TEST_P(MoneyTest, ConstructorTest1) {
    double value = GetParam();
    EXPECT_EQ(value, first_money.get_value());
}

TEST_P(MoneyTest, ConstructorTest2) {
    Money second_money(first_money);
    double value = GetParam();
    EXPECT_EQ(second_money.get_value(), value);
}

TEST(SimpleTest, ConstructorTest3) {
    std::string s = "123.561";
    ASSERT_THROW({
        Money second_money(s);
    }, const char*);
}

TEST(SimpleTest, ConstructorTest4) {
    std::string s = "123.56";
    Money second_money(s);
    EXPECT_EQ(second_money.get_value(), 123.56);
}

TEST(SimpleTest, ConstructorTest5) {
    std::string s = "123.56";
    Money second_money(s);
    Money third_money(100);
    second_money = std::move(third_money);
    EXPECT_EQ(second_money.get_value(), 100);
}

TEST(SimpleTest, ConstructorTest6) {
    Money second_money{"123.56"};
    EXPECT_EQ(second_money.get_value(), 123.56);
}

TEST(SimpleTest, ConstructorTest7) {
    ASSERT_THROW({
        Money second_money{"123.561"};
    }, const char*);
}

//ТЕСТ ОШИБОК
TEST_P(MoneyTest, ConstructorTest8) {
    double value = GetParam();
    ASSERT_THROW({
        Money second_money(value + 0.001);
    }, const char*);
}

TEST_P(MoneyTest, SetTest) {
    double value = GetParam();
    ASSERT_THROW({
        first_money.set_value(value + 0.001);
    }, const char*);
}

TEST_P(MoneyTest, skbTest) {
    double value = GetParam();
    ASSERT_THROW({
        first_money[-20];
    }, const char*);
}

//ТЕСТ ФУНКЦИЙ
TEST_P(MoneyTest, function_test) {
    double value = GetParam() * 2;
    first_money.set_value(value);
    EXPECT_EQ(value, first_money.get_value());
}

TEST(SimpleTest, de_serialization_test) {
    Money test_money(10);
    test_money.serialization("file_in.txt");
    test_money.deserialization("file_out.txt");
    test_money.serialization("file_out.txt");
    EXPECT_EQ(test_money.get_value(), 1234.5);
}

//ТЕСТ ОПЕРАТОРОВ
TEST_P(MoneyTest, operator_test_1) {
    double value = GetParam();
    first_money = value;
    first_money = first_money + first_money;
    first_money = first_money + value;
    first_money = first_money - value;
    EXPECT_EQ(value*2, first_money.get_value());
}

TEST_P(MoneyTest, operator_test_2) {
    double value = GetParam();
    EXPECT_EQ((first_money == value), (first_money < value*2));
}

TEST_P(MoneyTest, operator_test_3) {
    double value = GetParam();
    Money second_money(value*2);
    EXPECT_EQ((first_money < second_money), (first_money < second_money.get_value()));
}

TEST(SimpleTest, operator_test_4) {
    Money money(10.50);

    EXPECT_EQ(money[0], '1');
    EXPECT_EQ(money[1], '0');
    EXPECT_EQ(money[2], '5');
    EXPECT_EQ(money[3], '0');
}



INSTANTIATE_TEST_CASE_P(MoneyTests, MoneyTest, ::testing::Values(
    10.0, 20.5, 100.25)); 
