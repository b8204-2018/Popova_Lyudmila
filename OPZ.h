#ifndef OPZ_OPZ_H
#define OPZ_OPZ_H

#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <map>

using namespace std;

bool IsNum(char c);
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

class Task{
    vector <char> stack;
public:
    char signs[4] = {'+', '-', '*', '/'};
    string Conversion(string &str);
    static int Priority(char a);
};

class Calculation: public Task{
public:
    virtual int result(int a, int b) = 0;
};

class Sum: public Calculation {
public:
    int result(int a, int b) override;
};

class Sub: public Calculation {
public:
    int result(int a, int b) override;
};

class Mul: public Calculation{
public:
    int result(int a, int b) override;
};

class Div: public Calculation{
public:
    int result(int a, int b) override;
};

class Solution: public Task{
    map <char, Calculation*> array;
public:
    void Association();
    int Process(string &s);
    string GetNumbers(string &s);
};

#endif //OPZ_OPZ_H
