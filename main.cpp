#include <iostream>

using namespace std;

class Sort {
public:
    virtual void DoSorting(int* unsorted, int n) = 0;
};

class DTISort: public Sort {
public:
    void DoSorting(int* unsorted, int n){
            int right, left;
            int N = 2*n - 1;
            int* sorted = new int [N];
            int size = N/2;
            sorted[size] = unsorted[0];
            left = size; right = size;
            for (int i = 1; i <= size; i++) {
                bool flag = false;
                if (unsorted[i] <= sorted[left]) {
                    left--;
                    sorted[left] = unsorted[i];
                }
                else if (unsorted[i] >= sorted[right]) {
                    right++;
                    sorted[right] = unsorted[i];
                }
                else {
                    int j = left;
                    int l = left;
                    int r = right;
                    while (!flag) {
                        j = (l + r)/2;
                        if (sorted[j] < unsorted[i]) {
                            l = j + 1;
                        }
                        else if (sorted[j] > unsorted[i]) {
                            r = j - 1;
                        }
                        if ((unsorted[i] <= sorted[j + 1]) && (unsorted[i] >= sorted[j])) {
                            flag = true;
                        }
                    }
                    if (j - left < right - j) {
                        for (int k = left; k <= j; k++) {
                            sorted[k - 1] = sorted[k];
                        }
                        left--;
                        sorted[j] = unsorted[i];
                    }
                    else {
                        for (int k = right; k >= j + 1; k--) {
                            sorted[k + 1] = sorted[k];
                        }
                        right++;
                        sorted[j + 1] = unsorted[i];
                    }
                }
            }

            int p = 0;
            for (int z = left; z <= right; z++) {
                unsorted[p] = sorted[z];
                p++;
            }
    };

};

void Print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
};

void SortArray(Sort &sort, int* arr, int n){
    cout << "Before sorting: ";
    Print(arr, n);
    sort.DoSorting(arr, n);
    cout << "After sorting: ";
    Print(arr, n);
}

int main() {
    int n = 7;
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        a[i] = rand()%50;
    }
    DTISort Sort1;
    SortArray(Sort1, a, n);
    return 0;
}