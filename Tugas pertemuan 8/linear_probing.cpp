#include<iostream>
#include<vector>
using namespace std;

const int TABLE_SIZE = 10;
const int KOSONG = -1; // penanda slot belum terisi

class HashTable {
private:
vector<int> table;

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

public:
HashTable() {
    table.resize(TABLE_SIZE, KOSONG);
}

void insert(int key) {
    int index = hashFunction(key);
    int awal = index;

    // Linear probing: jika slot terisi, cek slot berikutnya (melingkar)
    while (table[index] != KOSONG) {
        index = (index + 1) % TABLE_SIZE;

        // Sudah kembali ke posisi awal berarti tabel penuh
        if (index == awal) {
            cout << "Tabel penuh, " << key << " tidak bisa dimasukkan!" << endl;
            return;
        }
    }

    table[index] = key;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << ": ";

        if (table[i] == KOSONG) {
            cout << "kosong" << endl;
        } else {
            cout << table[i] << endl;
        }
    }
}
};

int main() {
    HashTable ht;

    ht.insert(23);
    ht.insert(43);
    ht.insert(13);
    ht.insert(35);

    ht.display();

    return 0;
}