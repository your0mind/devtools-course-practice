// Copyright 2018 Krasikova Ekaterina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Krasikova_Ekaterina_ComplexNumberTest, Can_assign_to_itself) {
    ComplexNumber z(1.0, 1.0);

    EXPECT_NO_THROW(z=z);
}
