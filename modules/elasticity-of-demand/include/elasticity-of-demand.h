// Copyright 2018 Lalykin Oleg

#ifndef MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_
#define MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_

#include <string>
class Elasticity {
public:
	Elasticity(double Q1, double Q2, double P1, double P2);


	double PriceElasticity(double Q1,double Q2,double P1,double P2);
	double IncomeElasticity(double Q1, double Q2, double P1, double P2);
	double CrossElasticity(double Q1, double Q2, double P1, double P2);
	double coeff;
	std::string answer();

	double GetQ1();
	double GetQ2();
	double GetP1();
	double GetP2();

	void SetQ1(const double _Q1);
	void SetQ2(const double _Q2);
	void SetP1(const double _P1);
	void SetP2(const double _P2);
private:
	//первоначальный и текущий объем спроса
	//ЕDР > 1 — спрос эластичен; чем выше этот показатель, тем эластичнее спрос. 
	//Если ЕDР < 1 — спрос неэластичен. 
	//ЕслиЕDР = 1, имеет место спрос с единичной эластичностью, т. е. сни­жение цены на 1 % приводит к росту объема спроса тоже на 1 %.
	// первоначальная и текущая цена
	//std::string unit elasticity
	//std::string demand is elastic
	//std::string demand is inelastic
	 double Q1; 
	 double Q2; 
	 double P1; 
	 double P2;
};

#endif  //  MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_
