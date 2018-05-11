// Copyright 2018 Vyunov Roman

#include <gtest/gtest.h>

#include "../modules/DebtServiceCosts/include/DebtService.h"

TEST(Vyunov_Roman_DebtService_test, Can_Throw_Exception_Incorrect_Amount) {
    // Arrange

    // Act

    // Assert
    ASSERT_ANY_THROW(new DebtService(-1.0, 2.0, 3.0, ONE_PAYMENT_AT_THE_END));
}

TEST(Vyunov_Roman_DebtService_test, Can_Throw_Exception_Incorrect_Term) {
    // Arrange

    // Act

    // Assert
    ASSERT_ANY_THROW(new DebtService(1.0, -2.0, 3.0, ONE_PAYMENT_AT_THE_END));
}

TEST(Vyunov_Roman_DebtService_test, Can_Throw_Exception_Incorrect_Rate) {
    // Arrange

    // Act

    // Assert
    ASSERT_ANY_THROW(new DebtService(1.0, 2.0, -3.0, ONE_PAYMENT_AT_THE_END));
}
