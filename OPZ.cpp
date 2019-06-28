#include "OPZ.h"

char** readFile(const char *filepath) {
    FILE *f;
    f = fopen(filepath, "r");

    char **str = new char* [1];

    str[0] = new char [20];
    fscanf(f, "%s", str[0]);

    fclose(f);

    return str;
}

bool IsNum(char c) {
    return (c >= 0x30 && c <= 0x39);
}

string Solution::GetNumbers(string &str){
    int a, b;
    int pos = 0;
    string sub1, sub2;
    pos = str.find_first_of(signs);
    int pos1 = 0;
    pos1 = pos - 1;
    while ((pos1 != 0) && IsNum(str[pos1])){
        pos1--;
    }
    int k = pos1;
    for (int j = 0; j < pos - pos1; j++){
        sub1 += str[k];
        k++;
    }
    b = atoi(sub1.c_str());
    int pos2;
    pos2 = pos1 - 1;
    while ((pos2 != -1) && IsNum(str[pos2])){
        pos2--;
    }
    pos2++;
    k = pos2;
    for (int j = 0; j < pos1 - pos2; j++){
        sub2 += str[k];
        k++;
    }
    a = atoi(sub2.c_str());
    b = array.find(str[pos])->second->result(a, b);
    str.replace(pos2, pos - pos2 + 1, to_string(b));
    return str;
}

int Solution::Process(string &s) {
    int pos = 0;
    while (pos != -1){
        s = GetNumbers(s);
        pos = s.find_first_of(signs);
    }
    auto a = stoi(s);
    return a;
}

void Solution::Association() {
    array.insert(make_pair('+', new Sum));
    array.insert(make_pair('-', new Sub));
    array.insert(make_pair('*', new Mul));
    array.insert(make_pair('/', new Div));
}

string Task::Conversion(string &str) {
    string outstring;
    int k = 0;
    outstring = "";
    while(str[k]!='\0'){
        if(str[k] == ')'){
            while(stack.back() != '('){
                outstring += stack.back();
                stack.pop_back();
            }
            stack.pop_back();
        }
        if(IsNum(str[k])){
            outstring += str[k];
        }
        if(str[k] == '('){
            stack.push_back('(');
        }
        if(str[k] == '+' || str[k] == '-' || str[k] == '/' || str[k] == '*'){

            if(stack.empty()){
                stack.emplace_back(str[k]);
            }
            else if (Priority(stack.back()) < Priority((str[k]))){
                    stack.emplace_back(str[k]);
            }
            else{
                while(!stack.empty() && (Priority(stack.back()) >= Priority(str[k]))){
                    outstring += stack.back();
                    stack.pop_back();
                }

                stack.emplace_back(str[k]);
            }
            outstring += ' ';
        }
        k++;
    }
    while(!stack.empty()){
        outstring += stack.back();
        stack.pop_back();
    }
    return outstring;
}

int Task::Priority(char a) {
    switch(a){
        case '*':
        case '/':
            return 3;

        case '-':
        case '+':
            return 2;

        case '(':
            return 1;
    }
}

int Sum::result(int a, int b) {
    return (a + b);
}

int Sub::result(int a, int b) {
    return (a - b);
}

int Mul::result(int a, int b) {
    return (a * b);
}

int Div::result(int a, int b) {
    if (b == 0){
        throw Div_Zero();
    }
    else{
        return (a / b);
    }
}
