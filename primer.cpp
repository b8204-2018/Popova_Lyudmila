#include "primer.h"

using namespace std;

char** readFile(const char *filepath) {
    FILE *f;
    f = fopen(filepath, "r");

    char **str = new char* [2];

    for (int i = 0; i <= 1; i++){
        str[i] = new char [20];
        fscanf(f, "%s", str[i]);
    }
    fclose(f);

    return str;
}

double* SimpleCalculation::FindResults(string &s) {
    unsigned long pos;
    double* num = new double[2];
    char signs[4] = {'+', '-', '*', '/'};
    pos = s.find_last_of(signs);
    if (s[pos - 1] == '(') {
        pos -= 2;
        s.replace(pos + 1, 1, "");
        s.replace(s.length() - 1, 1, "");
    }
    string snum = s.substr(0, pos);
    num[0] = atof(snum.c_str());
    snum = s.substr(pos + 1, s.length() - pos - 1);
    num[1] = atof(snum.c_str());
    return num;
}

double* SimpleCalculation::Calculate(string &s) {
    auto *numbers = FindResults(s);
    auto *res = new double[2];
    res[0] = 1;
    res[1] = result(numbers[0], numbers[1]);
    return res;
}

int Quadr::getType(){
    return QU_EQ;
}

int Sum::getType(){
    return SUM;
}

double Sum::result(double a, double b) {
    return (a + b);
}

int Sub::getType(){
    return SUB;
}

double Sub::result(double a, double b) {
    return (a - b);
}

int Mul::getType(){
    return MUL;
}

double Mul::result(double a, double b) {
    return (a * b);
}

int Div::getType(){
    return DIV;
}

double Div::result(double a, double b) {
    if (b == 0){
        throw Div_Zero();
    }
    else{
        return (a / b);
    }
}

bool ComplexCalculation::CheckNum(string c){
    for  (int i = 0; i < c.length(); i++) {
        if (c[i] != 0x2d && c[i] != 0x2b && (c[i] < 0x30 || c[i] > 0x39)) {
            return false;
        }
    }
    return true;
}

int* Quadr::GetCoef(string &s){
    unsigned long pos_x2, pos_x;
    int l = s.length() - 2;
    pos_x2 = s.find("x2");
    pos_x = s.find_last_of("x");
    int* coef = new int[3];
    string* scoef = new string [3];
    scoef[0] = s.substr(0, pos_x2);
    scoef[1] = s.substr(pos_x2 + 2, pos_x - pos_x2 - 2);
    scoef[2] = s.substr(pos_x + 1, l - pos_x - 1);
    if (!CheckNum(scoef[0]) || !CheckNum(scoef[1]) || !CheckNum(scoef[2])) {
        exit(10);
    }
    coef[0] = atoi(scoef[0].c_str());
    coef[1] = atoi(scoef[1].c_str());
    coef[2] = atoi(scoef[2].c_str());
    return coef;
}

double* ComplexCalculation::FindResults(string &s){
    int* coef = new int[3];
    double* root;
    coef = GetCoef(s);
    double D = (coef[1] * coef[1]) - (4 * coef[0] * coef[2]);
    if (D < 0) {
        root = new double[1];
        root[0] = 0;
    }
    else {
        root = new double[3];
        root[0] = 2;
        root[1] = (-coef[1] + sqrt(D))/(2 * coef[0]);
        root[2] = (-coef[1] - sqrt(D))/(2 * coef[0]);
    }
    return root;
}

void Solution::Association() {
    array.insert(make_pair(1, new Quadr));
    array.insert(make_pair(2, new Sum));
    array.insert(make_pair(3, new Sub));
    array.insert(make_pair(4, new Mul));
    array.insert(make_pair(5, new Div));
}

void Solution::NewOperation(Estim *estim) {
    int i = array.end()->first;
    array.insert(make_pair(i, estim));
}

double* ComplexCalculation::Calculate (string &s) {
    auto *numbers = FindResults(s);
    return numbers;
}

double* Solution::solution(int type, string &s) {
    auto *result = array.find(type)->second->Calculate(s);
    return result;
}
