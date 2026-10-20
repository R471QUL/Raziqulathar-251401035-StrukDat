#include <iostream>
using namespace std;

//membuat fungsi linear search
int linearSearch(int data[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (data[i] == target) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

int main() {
    int data[] = {4, 8, 12, 16, 20, 24, 28};
    int n = 7;
    int target = 20;

    int hasil = linearSearch(data, n, target);

    if (hasil != -1) {
        cout << "data ditemukan pada indeks: " << hasil << endl;
    } else {
        cout << "data tidak ditemukan" << endl;
    }

    return 0;
}