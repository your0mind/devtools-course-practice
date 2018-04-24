// Copyright 2018 Lalykin Oleg

#ifndef MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_
#define MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_

#include <string>
class Elasticity {
public:
    Elasticity();
    Elasticity(double Q1, double Q2, double P1, double P2);
    
    
    double PriceElasticity(double Q1,double Q2,double P1,double P2);//коэффициент ценовой эластичности спро­са
    double IncomeElasticity(double Q1, double Q2, double Y1, double Y2);//коэффициент эластичности спроса по доходу
    double CrossElasticity(double Q1X, double Q2X, double P1Y, double P2Y);//коэффициент перекрестной эластичности

    double coeff;
    std::string ans;

    void PriceAnswer();
    void IncomeAnswer();
    void CrossAnswer();
    
    double GetQ1();
    double GetQ2();
    double GetP1();
    double GetP2();
    
    void SetQ1(const double _Q1);
    void SetQ2(const double _Q2);
    void SetP1(const double _P1);
    void SetP2(const double _P2);
private:
    
     double Q1;
     double Q2;
     double P1;
     double P2;
};

#endif  //  MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_
