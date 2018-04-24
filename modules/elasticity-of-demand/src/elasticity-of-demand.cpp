// Copyright 2018 Lalykin Oleg

#include "include/elasticity-of-demand.h"
#include <math.h>
Elasticity::Elasticity():Q1(0), Q2(0), P1(0), P2(0), coeff(0) {}
Elasticity::Elasticity(const double Q1, const double Q2, const double P1, const double P2): Q1(Q1), Q2(Q2) , P1(P1) , P2(P2),coeff(0) {}

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
	//Q1 и Q2 Ч первоначальный и текущий объем спроса; P1 и –2 Ч первоначальна€ и текуща€ цена
	coeff = fabs(((Q2 - Q1)/ (Q2 + Q1) ) * ((P2 + P1)/(P2 - P1)));
	return coeff;
};
double Elasticity::IncomeElasticity(double Q1, double Q2, double Y1, double Y2)
{
   //Q1 и Q2 Ч первоначальный и новый объемы спроса; Y1и Y2 Ч первоначальный и новый уровни дохода
   coeff = ((Q2 - Q1) / (Q2 + Q1)) * ((Y2 + Y1) / (Y2 - Y1));
   return coeff;
};
double Elasticity::CrossElasticity(double Q1X, double Q2X, double P1Y, double P2Y)
{
   //Q1X и Q2X Ч первоначальный и новый объемы спроса на то≠вар ’; –2Y и –1Y Ч первоначальна€ и нова€ цена товара Y
   coeff = ((Q2X - Q1X) / (Q2X + Q1X)) * ((P2Y + P1Y) / (P2Y - P1Y));
   return coeff;
};
void Elasticity::PriceAnswer()
{
	if (coeff > 1) ans = "demand is elastic";//спрос эластичен
	if (coeff < 1) ans = "demand is inelastic";//спрос неэластичен
	if (coeff == 1) ans = "unit elasticity";//единична€ эластичность
}
void Elasticity::IncomeAnswer()
{
   if (coeff > 0) ans = "normal goods";//нормальные товары
   if (coeff <= 0)ans = "inferior goods";//товары низ≠шей категории  
}
void Elasticity::CrossAnswer()
{
   if (coeff > 0)ans = "goods are interchangeable";//товары взаимозамен€емы
   if (coeff < 0)ans = "mutually complementary goods";//взаимодополн€ющие друг друга товары
   if (coeff == 0) ans = "goods independent of each other";//независимыми друг от друга товары
}
