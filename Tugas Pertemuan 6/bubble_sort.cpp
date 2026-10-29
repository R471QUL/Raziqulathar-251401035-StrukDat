#include <iostream>
using namespace std;

int main() {
    int data[] = {5, 4, 3, 2, 1};
    int n = 5;
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (data[j] > data[j+1]) {
                swap(data[j], data[j+1]);
            }
        }
    }
    
    cout << "hasil bubble sort: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    return 0;
}