// Copyright 2018 Sharov Ivan

#ifndef MODULES_WAGES_INCLUDE_WAGES_H_
#define MODULES_WAGES_INCLUDE_WAGES_H_

typedef enum {
    January = 1, February, March, April, May, June,
    July, August, September, October, November, December
} Month;

class Wages {
 public:
    Wages();
    Wages(const double salary, const double administrativeLeaveHours,
        const double overtime, Month month);
    Wages(const Wages& wages);

    double getSalary() const;
    double getAdministrativeLeaveHours() const;
    double getOvertime() const;
    Month getMonth() const;

    void setSalary(const double salary);
    void setAdministrativeLeaveHours(const double administrativeLeaveHours);
    void setOvertime(const double overtime);
    void setMonth(Month month);

    bool controlMROT(const double field);
    bool controlField(const double field);
    bool controlMonth(Month month);
    void controlOvertime(const double overtime);
    void controlAdministrativeLeaveHours(const double administrativeLeaveHours);
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
    Month current_month_;
};

#endif   //  MODULES_WAGES_INCLUDE_WAGES_H_
