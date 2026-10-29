#include <iostream>
#include <string>
using namespace std;

// Menampilkan isi array pada satu langkah
void tampilkan(string data[], int n) {
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// Insertion sort untuk string (A-Z) dengan tampilan proses pergeseran
void insertionSort(string data[], int n) {
    for (int i = 1; i < n; i++) {
        string key = data[i];
        int j = i - 1;

        cout << "\nLangkah " << i << " (menyisipkan \"" << key << "\"):" << endl;

        // Geser elemen yang lebih besar dari key ke kanan
        while (j >= 0 && data[j] > key) {
            cout << "  Geser \"" << data[j] << "\" dari indeks " << j
                 << " ke indeks " << j + 1 << endl;
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;
        cout << "  Sisipkan \"" << key << "\" di indeks " << j + 1 << endl;
        cout << "  Hasil: ";
        tampilkan(data, n);
    }
}

int main() {
    int n;
    string data[100];

    cout << "Masukkan jumlah kata: ";
    cin >> n;

    cout << "Masukkan " << n << " kata:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Kata ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    cout << "\nData awal: ";
    tampilkan(data, n);

    insertionSort(data, n);

    cout << "\nHasil akhir (A-Z): ";
    tampilkan(data, n);

    return 0;
}