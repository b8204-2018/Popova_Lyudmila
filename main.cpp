#include "primer.h"

void print(double *arr) {
    if (arr[0] == 0) {
        cout << "No roots";
    } else {
        for (int i = 1; i <= arr[0]; i++) {
            cout << arr[i] << " ";
        }
    }
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("filepath as argument expected");
        return -1;
    }

    char **content = readFile(argv[1]);

    int type;
    string s;
    s = content[1];
    type = atoi(content[0]);

    Solution sol;
    sol.Association();

    if (s != ""){
        cout << "Example: " << s << " type: " << type << endl << "Solution: ";
        try{
            print(sol.solution(type, s));
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