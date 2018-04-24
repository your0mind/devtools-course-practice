// Copyright 2018 Lalykin Oleg

#include "include/elasticity-of-demand.h"
#include <math.h>

Elasticity::Elasticity(const double Q1, const double Q2, const double P1, const double P2): Q1(Q1), Q2(Q2) , P1(P1) , P2(P2) {}

double Elasticity::GetQ1() { return Q1; }
double Elasticity::GetQ2() { return Q2; }
double Elasticity::GetP1() { return P1; }
double Elasticity::GetP2() { return P2; }

void Elasticity::SetQ1(const double _Q1) { Q1=  _Q1;  }
void Elasticity::SetQ2(const double _Q2) { Q2 = _Q2; }
void Elasticity::SetP1(const double _P1) { P1 = _P1; }
void Elasticity::SetP2(const double _P2) { P2 = _P2; }


double Elasticity::PriceElasticity(double Q1, double Q2, double P1, double P2)
{
	coeff = fabs(((Q2 - Q1)/ (Q2 + Q1) ) / ((P2 - P1)/(P2 + P1)));
	return coeff;
};
double Elasticity::IncomeElasticity(double Q1, double Q2, double P1, double P2)
{
	return coeff;
};
double Elasticity::CrossElasticity(double Q1, double Q2, double P1, double P2)
{
	return coeff;
};

std::string Elasticity::answer()
{
	if (coeff > 1) return ("demand is elastic");
	if (coeff < 1) return ("demand is inelastic");
	if (coeff = 1) return ("unit elasticity");
}