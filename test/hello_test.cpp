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

//ТЕСТ ОШИБОК
TEST_P(MoneyTest, ConstructorTest3) {
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

TEST(RegularTest, serialization_test) {
    Money test_money(10);
    test_money.serialization("file_in.txt");
    test_money.deserialization("file_out.txt");
    test_money.serialization("file_out.txt");
    EXPECT_EQ(test_money.get_value(), 1234.5);
}

//ТЕСТ ОПЕРАТОРОВ
TEST_P(MoneyTest, operator_test) {
    double value = GetParam();
    first_money = value;
    first_money = first_money + first_money;
    first_money = first_money + value;
    first_money = first_money - value;
    EXPECT_EQ(value*2, first_money.get_value());
}

TEST_P(MoneyTest, operator_next_test) {
    double value = GetParam();
    EXPECT_EQ((first_money == value), (first_money < value*2));
}

TEST_P(MoneyTest, operator_next_test2) {
    double value = GetParam();
    Money second_money(value*2);
    EXPECT_EQ((first_money < second_money), (first_money < second_money.get_value()));
}

TEST(Money_test, operator_next_test3) {
    Money money(10.50);

    EXPECT_EQ(money[0], '1');
    EXPECT_EQ(money[1], '0');
    EXPECT_EQ(money[2], '5');
    EXPECT_EQ(money[3], '0');
}

// Define the test parameters as a vector of values
INSTANTIATE_TEST_CASE_P(MoneyTests, MoneyTest, ::testing::Values(
    10.0, 20.5, 100.25)); // Add more values as needed
