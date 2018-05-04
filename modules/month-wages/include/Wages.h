// Copyright 2018 Sharov Ivan

#ifndef _WAGES_H
#define _WAGES_H

class Wages
{
 public:
    Wages();
    Wages(const double salary, const double administrativeLeaveHours, const double overtime, char *month);
    Wages(const Wages& wages);

    double getSalary() const;
    double getAdministrativeLeaveHours() const;
    double getOvertime() const;
    char* getMonth() const;

    void setSalary(const double salary);
    void setAdministrativeLeaveHours(const double administrativeLeaveHours);
    void setOvertime(const double overtime);
    void setMonth(char *month);

    bool controlMROT(const double field);
    bool controlField(const double field);
    double getNumberWorkingDaysInCurrentMonth();
    double calculationPaymentOvertime();
    double calculationActualWorkingDays();
    double calculationWagesWithoutOvertime();
    double calculationFullWages();
    double calculationHourPayment();

 private:
    double salary_;
    double administrativeLeaveHours_;
    double overtime_;
    char *month_;
};
#endif