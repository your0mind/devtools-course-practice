// Copyright 2018 Sharov Ivan

#include"include/Wages.h"
#include<string.h>
#include <string>

Wages::Wages() : salary_(10000), administrativeLeaveHours_(0),
    overtime_(0), month_(const_cast<char*>("January")) {}

Wages::Wages(const double salary, const double administrativeLeaveHours,
    const double overtime, char *month) {
    bool control;
    control = controlMROT(salary);
    if (control == true) salary_ = salary;
    else
        throw std::string("The salary can not be less than the minimum wage!");
    control = controlField(administrativeLeaveHours);
    if (control == true) administrativeLeaveHours_ = administrativeLeaveHours;
    else
        throw std::string("Administrative leave hours can not be negative!");
    control = controlField(overtime);
    if (control == true) overtime_ = overtime;
    else
        throw std::string("Overtime leave hours can not be negative!");
    control = controlMonth(month);
    if (control == true)  month_ = month;
    else
        throw std::string("Month is not defined!");
}

Wages::Wages(const Wages& wages) : salary_(wages.getSalary()),
    administrativeLeaveHours_(wages.getAdministrativeLeaveHours()),
    overtime_(wages.getOvertime()), month_(wages.getMonth()) {}

double Wages::getSalary() const {
    return salary_;
}

double Wages::getAdministrativeLeaveHours() const {
    return administrativeLeaveHours_;
}

double Wages::getOvertime() const {
    return overtime_;
}

char* Wages::getMonth() const {
    return month_;
}

void Wages::setSalary(const double salary) {
    salary_ = salary;
}

void Wages::setMonth(char *month) {
    month_ = month;
}

void Wages::setAdministrativeLeaveHours(const double administrativeLeaveHours) {
    administrativeLeaveHours_ = administrativeLeaveHours;
}
void Wages::setOvertime(const double overtime) {
    overtime_ = overtime;
}

bool Wages::controlField(const double field) {
    bool result = true;
    if (field < 0) result = false;
    return result;
}

bool Wages::controlMROT(const double field) {
    bool result = true;
    if (field < 9489) result = false;
    return result;
}

bool Wages::controlMonth(char *field) {
    bool result = false;
    if (!strcmp(field, "January")) result = true;
    if (!strcmp(field, "February")) result = true;
    if (!strcmp(field, "March")) result = true;
    if (!strcmp(field, "April")) result = true;
    if (!strcmp(field, "May")) result = true;
    if (!strcmp(field, "June")) result = true;
    if (!strcmp(field, "July")) result = true;
    if (!strcmp(field, "August")) result = true;
    if (!strcmp(field, "Semtember")) result = true;
    if (!strcmp(field, "October")) result = true;
    if (!strcmp(field, "November")) result = true;
    if (!strcmp(field, "December")) result = true;

    return result;
}

void Wages::controlOvertime(const double overtime) {
    int workDays = static_cast<int>(calculationActualWorkingDays());
    if (overtime > 3 * (static_cast<double>(workDays)))
        throw std::string("Exceeded the maximum number of overtime in month");
}

void Wages::
    controlAdministrativeLeaveHours(const double administrativeLeaveHours) {
    double workDays = getNumberWorkingDaysInCurrentMonth();
    if (administrativeLeaveHours > 8 * workDays)
       throw std:: string("Exceeding the administrative hours limit");
}

double Wages::getNumberWorkingDaysInCurrentMonth() {
    double result;
    char *month;
    month = getMonth();
    if (!strcmp(month, "January")) result = 17;
    else if (!strcmp(month, "February")) result = 19;
    else if (!strcmp(month, "March")) result = 20;
    else if (!strcmp(month, "April")) result = 21;
    else if (!strcmp(month, "May")) result = 20;
    else if (!strcmp(month, "June")) result = 20;
    else if (!strcmp(month, "July")) result = 22;
    else if (!strcmp(month, "August")) result = 23;
    else if (!strcmp(month, "Semtember")) result = 20;
    else if (!strcmp(month, "October")) result = 23;
    else if (!strcmp(month, "November")) result = 21;
    else if (!strcmp(month, "December")) result = 21;
    else
        throw std::string("Month is not defined");
    return result;
}

double Wages::calculationPaymentOvertime() {
    double result, hours, hourPayment, hours2Payment;
    hours = getOvertime();
    controlOvertime(hours);
    hourPayment = calculationHourPayment();
    if (hours < 3) {
        result = 1.5 * hourPayment*hours;
    } else {
        hours2Payment = hours - 2;
        result = 1.5 * hourPayment* 2.0 + 2.0 * hourPayment*hours2Payment;
    }

    return result;
}

double Wages::calculationActualWorkingDays() {
    double result, daysInMonth, hoursInAdministrativeLeave, workHours;
    daysInMonth = getNumberWorkingDaysInCurrentMonth();
    hoursInAdministrativeLeave = getAdministrativeLeaveHours();
    controlAdministrativeLeaveHours(hoursInAdministrativeLeave);
    workHours = 8 * daysInMonth - hoursInAdministrativeLeave;
    result = workHours / 8;
    return result;
}

double Wages::calculationWagesWithoutOvertime() {
    double result, workDays, daysInMonth, hoursInAdministrativeLeave, Salary;
    daysInMonth = getNumberWorkingDaysInCurrentMonth();
    hoursInAdministrativeLeave = getAdministrativeLeaveHours();
    controlAdministrativeLeaveHours(hoursInAdministrativeLeave);
    workDays = calculationActualWorkingDays();
    Salary = getSalary();
    result = Salary*(workDays / daysInMonth);
    return result;
}

double Wages::calculationFullWages() {
    double result, wagesWithoutOvertime, paymentOvertime;
    wagesWithoutOvertime = calculationWagesWithoutOvertime();
    paymentOvertime = calculationPaymentOvertime();
    result = wagesWithoutOvertime + paymentOvertime;
    return result;
}

double Wages::calculationHourPayment() {
    double Salary, Days, result;
    Salary = getSalary();
    Days = getNumberWorkingDaysInCurrentMonth();
    result = Salary / (8 * Days);
    return result;
}
