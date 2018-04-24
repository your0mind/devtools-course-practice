// Copyright 2018 Lalykin Oleg

#include <gtest/gtest.h>

#include "include/elasticity-of-demand.h"

TEST(Lalykin_Oleg_Elasticity_Of_Demand, constructor_Q1) {
	// Arrange
	double Q1 = 4000.0;
	double  Q2 = 2000.0;
	double P1 = 4.0;
	double  P2 = 5.0;

	// Act
	Elasticity E(Q1, Q2, P1, P2);

	// Assert
	EXPECT_EQ(E.GetQ1(), Q1);
}

TEST(Lalykin_Oleg_Elasticity_Of_Demand, set_method_Q1) {
	// Arrange
	double Q1 = 4000.0;
	double  Q2 = 2000.0;
	double P1 = 4.0;
	double  P2 = 5.0;

	// Act
	Elasticity E(Q1, Q2, P1, P2);
	E.SetQ1(0.22516);
	// Assert
	EXPECT_EQ(E.GetQ1(), 0.22516);
}


TEST(Lalykin_Oleg_Elasticity_Of_Demand, answer_elastic) {
	// Arrange
	double Q1 = 4000.0;
	double  Q2 = 2000.0;
	double P1 = 4.0;
	double  P2 = 5.0;

	// Act
	Elasticity E(Q1, Q2, P1, P2);
	E.PriceElasticity(Q1, Q2, P1, P2);
	// Assert
	EXPECT_EQ("demand is elastic", E.answer());
}

TEST(Lalykin_Oleg_Elasticity_Of_Demand,calculate_coeff) {
	// Arrange
	double Q1 = 4000.0;
	double  Q2 = 2000.0;
	double P1 = 4.0;
	double  P2 = 5.0;

	// Act
	Elasticity E(Q1,Q2,P1,P2);
	
	// Assert
	EXPECT_EQ(3, E.PriceElasticity(Q1, Q2, P1, P2));
}

