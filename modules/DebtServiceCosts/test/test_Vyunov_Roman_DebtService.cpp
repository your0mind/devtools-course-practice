// Copyright 2018 Vyunov Roman

#include <gtest/gtest.h>

#include "../modules/DebtServiceCosts/include/DebtService.h"

TEST(Vyunov_Roman_DebtService_test, Can_Create_Zero) {
    // Arrange


    // Act


    // Assert
    ASSERT_ANY_THROW(new DebtService(-1, 2, 3));
}
