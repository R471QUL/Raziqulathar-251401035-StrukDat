#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
    private:
    vector<pair<int, string>> table;
    vector<int> status;   // 0 = kosong, 1 = terisi, 2 = terhapus

    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    int hash2(int key) {
        return 7 - (key % 7);   // hasil 1..7, tidak pernah 0
    }

    public:
    HashTable() {
        table.resize(TABLE_SIZE);
        status.resize(TABLE_SIZE, 0);
    }

    void insert(int key, string value) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        int deletedIndex = -1;   // slot terhapus pertama yang ditemui

        while (true) {
            // key sudah ada -> update value
            if (status[index] == 1 && table[index].first == key) {
                table[index].second = value;
                return;
            }

            // simpan slot terhapus pertama untuk dipakai ulang
            if (status[index] == 2 && deletedIndex == -1) {
                deletedIndex = index;
            }

            // slot kosong -> key pasti belum ada, saatnya menyimpan
            if (status[index] == 0) {
                int target = (deletedIndex != -1) ? deletedIndex : index;
                table[target] = {key, value};
                status[target] = 1;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            // sudah satu putaran penuh
            if (index == initialIndex) break;
        }

        // tidak ada slot kosong, tapi mungkin ada slot terhapus
        if (deletedIndex != -1) {
            table[deletedIndex] = {key, value};
            status[deletedIndex] = 1;
        } else {
            cout << "Tabel penuh, gagal insert " << key << endl;
        }
    }

    void search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                cout << "Data ditemukan : " << table[index].second << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) break;
        }

        cout << "Data dengan key " << key << " tidak ditemukan" << endl;
    }

    void remove(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                status[index] = 2;
                cout << "Key " << key << " berhasil dihapus" << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) break;
        }

        cout << "Key " << key << " tidak ditemukan" << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " ";

            if (status[i] == 1)
                cout << table[i].first << " (" << table[i].second << ")" << endl;
            else if (status[i] == 2)
                cout << "DELETED" << endl;
            else
                cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(23, "Andi");
    ht.insert(43, "Budi");
    ht.insert(13, "Citra");
    ht.insert(35, "Dewi");

    cout << "Isi Hash Table : " << endl;
    ht.display();

    cout << "Mencari key 43 : " << endl;
    ht.search(43);

    cout << "Menghapus key 43 : " << endl;
    ht.remove(43);

    cout << "Hash Table setelah penghapusan : " << endl;
    ht.display();

    return 0;
}