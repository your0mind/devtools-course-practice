// Copyright 2018 Grishin Anton

#include <gtest/gtest.h>
#include "include/currency_converter.h"

class CurrencyConverterTest : public ::testing::Test {
 protected:
    double epsilon = 0.001;
};

TEST_F(CurrencyConverterTest, Can_Create_With_Dollar_And_Euro) {
    // Arrange
    double usd = 26.0;
    double eur = 20.0;

    // Act
    CurrencyConverter currency(usd, eur);

    // Assert
    EXPECT_NEAR(usd, currency.getUsdPrice(), CurrencyConverterTest::epsilon);
    EXPECT_NEAR(eur, currency.getEurPrice(), CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest, Can_Create_Via_Copying) {
    // Arrange
    CurrencyConverter currency(26.0, 20.0);

    // Act
    CurrencyConverter expected_currency = currency;

    // Assert
    EXPECT_EQ(expected_currency, currency);
}

TEST_F(CurrencyConverterTest, Can_Set_Usd) {
    // Arrange
    CurrencyConverter currency;
    double usd = 20.0;

    // Act
    currency.setUsdPrice(usd);

    // Assert
    EXPECT_NEAR(usd, currency.getUsdPrice(), CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest, Can_Set_Eur) {
    // Arrange
    CurrencyConverter currency;
    double eur = 26.0;

    // Act
    currency.setEurPrice(eur);

    // Assert
    EXPECT_NEAR(eur, currency.getEurPrice(), CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest, Currency_Is_Equal_To_Itself) {
    // Arrange
    CurrencyConverter currency(26.0, 14.0);

    // Act & Assert
    EXPECT_TRUE(currency == currency);
}

TEST_F(CurrencyConverterTest, Equal_Currency_Are_Equal) {
    // Arrange
    CurrencyConverter currency1(26.0, 14.0);
    CurrencyConverter currency2(26.0, 14.0);

    // Act & Assert
    EXPECT_EQ(currency1, currency2);
}


TEST_F(CurrencyConverterTest, Different_Currency_Not_Equal) {
    // Arrange
    CurrencyConverter currency1(26.0, 14.0);
    CurrencyConverter currency2(26.1, 14.1);

    // Act & Assert
    EXPECT_TRUE(currency1 != currency2);
}
