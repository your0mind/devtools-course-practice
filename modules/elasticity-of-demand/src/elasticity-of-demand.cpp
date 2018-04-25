// Copyright 2018 Lalykin Oleg

#include "include/elasticity-of-demand.h"
#include <math.h>
Elasticity::Elasticity(): coeff(0),ans("") {}


double Elasticity::GetCoeff() { return coeff; }
std::string Elasticity::GetAns() { return ans; }

// коэффициент ценовой эластичности спро≠са
double Elasticity::PriceElasticity(double Q1, double Q2, double P1, double P2)
{
    //Q1 и Q2 Ч первоначальный и текущий объем спроса; P1 и –2 Ч первоначальна€ и текуща€ цена
    coeff = fabs(((Q2 - Q1)/ (Q2 + Q1) ) * ((P2 + P1)/(P2 - P1)));
    return coeff;
};
// коэффициент эластичности спроса по доходу
double Elasticity::IncomeElasticity(double Q1, double Q2, double Y1, double Y2)
{
   //Q1 и Q2 Ч первоначальный и новый объемы спроса; Y1и Y2 Ч первоначальный и новый уровни дохода
   coeff = ((Q2 - Q1) / (Q2 + Q1)) * ((Y2 + Y1) / (Y2 - Y1));
   return coeff;
};
// коэффициент перекрестной эластичности
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
   if (coeff <= 0) ans = "inferior goods";//товары низ≠шей категории  
}
void Elasticity::CrossAnswer()
{
   if (coeff > 0) ans = "goods are interchangeable";//товары взаимозамен€емы
   if (coeff < 0) ans = "mutually complementary goods";//взаимодополн€ющие друг друга товары
   if (coeff == 0) ans = "goods independent of each other";//независимыми друг от друга товары
}
