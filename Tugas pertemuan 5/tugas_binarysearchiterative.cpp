#include <iostream>
using namespace std;

// Binary search iteratif
int binarySearch(int data[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == target) {
            return mid;           // ditemukan
        } else if (target < data[mid]) {
            right = mid - 1;      // cari di bagian kiri
        } else {
            left = mid + 1;       // cari di bagian kanan
        }
    }

    return -1;                    // tidak ditemukan
}

int main() {
    int n;
    cout << "Masukkan jumlah data nilai mahasiswa: ";
    cin >> n;

    int data[100];
    cout << "Masukkan " << n << " nilai (urut ascending, dari kecil ke besar):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    int target;
    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> target;

    int hasil = binarySearch(data, n, target);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks: " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}