#include "OPZ.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "gtest/gtest.h"

void print(int s){
    cout << s << endl;
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("filepath as argument expected");
        return -1;
    }

    char **content = readFile(argv[1]);

    string s = content[0];

    if (s != ""){
        Solution sol;
        sol.Association();
        s = sol.Conversion(s);
        cout << s << endl;
        try{
            print(sol.Process(s));
        }
        catch(Exception &err){
            cout << err.getError();
        }
        return 0;
    }
    else {
        return -2;
    }
}



