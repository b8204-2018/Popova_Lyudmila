#ifndef CALCULATOR_PRIMER_H
#define CALCULATOR_PRIMER_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <exception>
#include <cstring>
#include <stdio.h>

using namespace std;

#define QU_EQ 1
#define SUM 2
#define SUB 3
#define MUL 4
#define DIV 5

char **readFile(const char *filepath);

class Exception{
protected:
    string error;
public:
    Exception(string error): error(move(error)){};
    const char* getError() {
        return error.c_str();
    }
};

class Div_Zero: public Exception{
public:
    Div_Zero():Exception("Try to divide by zero"){};
};

class Estim {
public:
    virtual int getType() = 0;
    virtual double* Calculate (string &s) = 0;
    virtual double* FindResults(string &s) = 0;
};

class SimpleCalculation: public Estim {
public:
    double* Calculate (string &s) override;
    double* FindResults(string &s) override;
    virtual double result(double a, double b) = 0;
};

class ComplexCalculation: public Estim {
public:
    virtual int* GetCoef(string &s) = 0;
    bool CheckNum(string c);
    double* FindResults(string &s) override;
    double* Calculate (string &s) override;
};

class Quadr: public ComplexCalculation{
    int getType() override;
    int* GetCoef(string &s) override;
};

class Sum: public SimpleCalculation {
public:
    int getType() override;
    double result(double a, double b) override;
};

class Sub: public SimpleCalculation {
public:
    int getType() override;
    double result(double a, double b) override;
};

class Mul: public SimpleCalculation {
public:
    int getType();
    double result(double a, double b) override;
};

class Div: public SimpleCalculation {
public:
    int getType();
    double result(double a, double b) override;
};


class Solution {
    map <int, Estim*> array;
public:
    void Association();
    void NewOperation(Estim *estim);
    double *solution(int type, string &s);
};

#endif //CALCULATOR_PRIMER_H