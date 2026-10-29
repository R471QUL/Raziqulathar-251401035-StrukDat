#include <iostream>
using namespace std;

int main() {
    int data[] = {5, 4, 3, 2, 1};
    int n = 5;
    
    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j+i] = key;
    }

    
    cout << "hasil insertion sort: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    
    return 0;
}