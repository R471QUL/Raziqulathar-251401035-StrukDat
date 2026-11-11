#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

// Status tiap slot pada hash table
enum Status { KOSONG, TERISI, DIHAPUS };

struct Slot {
    long long nim;   // key
    string nama;     // value
    Status status;
};

class HashTable {
private:
    vector<Slot> table;

    // Hash pertama: menentukan posisi awal
    int hashFunction1(long long key) {
        return key % TABLE_SIZE;
    }

    // Hash kedua: menentukan ukuran langkah.
    // Dipilih dari {1, 3, 7, 9} (semuanya relatif prima dengan 10)
    // supaya penelusuran bisa menjangkau seluruh slot.
    int hashFunction2(long long key) {
        int langkah[4] = {1, 3, 7, 9};
        return langkah[key % 4];
    }

    // Mencari indeks slot milik key, -1 jika tidak ada
    int cari(long long key) {
        int h1 = hashFunction1(key);
        int h2 = hashFunction2(key);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = (h1 + i * h2) % TABLE_SIZE;

            if (table[index].status == KOSONG) {
                return -1; // slot kosong asli: key pasti tidak ada
            }
            if (table[index].status == TERISI && table[index].nim == key) {
                return index;
            }
            // DIHAPUS atau terisi key lain: lanjut ke langkah berikutnya
        }
        return -1;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i].nim = 0;
            table[i].nama = "";
            table[i].status = KOSONG;
        }
    }

    void insert(long long nim, string nama) {
        if (cari(nim) != -1) {
            cout << "Insert gagal: NIM " << nim << " sudah ada." << endl;
            return;
        }

        int h1 = hashFunction1(nim);
        int h2 = hashFunction2(nim);

        // Double hashing: index = (h1 + i * h2) % TABLE_SIZE
        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = (h1 + i * h2) % TABLE_SIZE;

            if (table[index].status != TERISI) {
                table[index].nim = nim;
                table[index].nama = nama;
                table[index].status = TERISI;
                cout << "Insert " << nim << " (" << nama << ") -> slot " << index;
                if (i > 0) cout << " (collision, percobaan ke-" << i + 1 << ")";
                cout << endl;
                return;
            }
        }

        cout << "Insert gagal: hash table penuh." << endl;
    }

    void search(long long nim) {
        int index = cari(nim);

        if (index == -1) {
            cout << "Search " << nim << " -> tidak ditemukan." << endl;
        } else {
            cout << "Search " << nim << " -> ditemukan di slot " << index
                 << ", nama: " << table[index].nama << endl;
        }
    }

    void remove(long long nim) {
        int index = cari(nim);

        if (index == -1) {
            cout << "Remove " << nim << " -> gagal, data tidak ditemukan." << endl;
        } else {
            table[index].status = DIHAPUS;
            cout << "Remove " << nim << " (" << table[index].nama
                 << ") -> slot " << index << " dihapus." << endl;
        }
    }

    void display() {
        cout << "Slot | NIM         | Nama" << endl;
        cout << "-----------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << "    | ";
            if (table[i].status == TERISI) {
                cout << table[i].nim << " | " << table[i].nama << endl;
            } else if (table[i].status == DIHAPUS) {
                cout << "(dihapus)" << endl;
            } else {
                cout << "(kosong)" << endl;
            }
        }
    }
};

int main() {
    HashTable ht;

    cout << "=== INSERT ===" << endl;
    ht.insert(251401035, "Andi");
    ht.insert(251401042, "Budi");
    ht.insert(251401055, "Citra");
    ht.insert(251401065, "Dina");
    ht.insert(251401078, "Eka");

    cout << "\n=== SEARCH ===" << endl;
    ht.search(251401055);
    ht.search(251401099);

    cout << "\n=== REMOVE ===" << endl;
    ht.remove(251401065);
    ht.remove(251401099);

    cout << "\n=== SEARCH SETELAH REMOVE ===" << endl;
    ht.search(251401078);
    ht.search(251401065);

    cout << "\n=== ISI HASH TABLE ===" << endl;
    ht.display();

    return 0;
}