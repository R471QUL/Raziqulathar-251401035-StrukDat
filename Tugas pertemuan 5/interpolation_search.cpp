#include <iostream>
using namespace std;

int interpolationSearch(int data[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high && target >= data[low] && target <= data[high]) {
        // Jika sisa elemen tinggal satu
        if (low == high) {
            if (data[low] == target) return low;
            return -1;
        }

        // Rumus interpolasi untuk memperkirakan posisi target
        int pos = low + ((double)(target - data[low]) / (data[high] - data[low])) * (high - low);

        if (data[pos] == target) {
            return pos;
        } else if (data[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    // Interpolation search butuh data terurut dan sebaran nilainya merata
    int data[] = {4, 8, 12, 16, 20, 24, 28};
    int n = 7;
    int target = 20;

    int hasil = interpolationSearch(data, n, target);

    if (hasil != -1) {
        cout << "data ditemukan pada indeks: " << hasil << endl;
    } else {
        cout << "data tidak ditemukan" << endl;
    }

    return 0;
}