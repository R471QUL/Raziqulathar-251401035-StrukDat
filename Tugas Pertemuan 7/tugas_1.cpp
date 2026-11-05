#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

class graph {
    private:
        int numbervertex;
        vector<vector<int>> adjMatrix;

    public:
        graph(int banyaktitik) {
            numbervertex = banyaktitik;
            adjMatrix.resize(banyaktitik, vector<int>(banyaktitik, 0));
        }

        // Menambah edge antara dua vertex (huruf A-F), graf tak berarah
        void addEdge(char a, char b) {
            int i = toupper(a) - 'A';
            int j = toupper(b) - 'A';

            if (i >= 0 && i < numbervertex && j >= 0 && j < numbervertex) {
                adjMatrix[i][j] = 1;
                adjMatrix[j][i] = 1;
            } else {
                cout << "Vertex tidak valid! Gunakan huruf A-F." << endl;
            }
        }

        void printadjmatrix() {
            cout << "  ";
            for (int i = 0; i < numbervertex; i++) {
                cout << char('A' + i) << " ";
            }
            cout << endl;

            for (int i = 0; i < numbervertex; i++) {
                cout << char('A' + i) << " ";
                for (int j = 0; j < numbervertex; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        void bfs(char start) {
            int s = toupper(start) - 'A';

            if (s < 0 || s >= numbervertex) {
                cout << "Vertex awal tidak valid!" << endl;
                return;
            }

            vector<bool> visited(numbervertex, false);
            queue<int> antrian;

            visited[s] = true;
            antrian.push(s);

            while (!antrian.empty()) {
                int current = antrian.front();
                antrian.pop();
                cout << char('A' + current) << " ";

                for (int i = 0; i < numbervertex; i++) {
                    if (adjMatrix[current][i] == 1 && !visited[i]) {
                        visited[i] = true;
                        antrian.push(i);
                    }
                }
            }
            cout << endl;
        }
};

int main() {
    graph g(6); // 6 vertex: A, B, C, D, E, F

    int jumlahEdge;
    cout << "Masukkan jumlah edge: ";
    cin >> jumlahEdge;

    cout << "Masukkan tiap edge (dua vertex, contoh: A B):" << endl;
    for (int i = 0; i < jumlahEdge; i++) {
        char a, b;
        cout << "Edge ke-" << i + 1 << ": ";
        cin >> a >> b;
        g.addEdge(a, b);
    }

    cout << "\nAdjacency Matrix:" << endl;
    g.printadjmatrix();

    char awal;
    cout << "\nMasukkan vertex awal: ";
    cin >> awal;

    cout << "Urutan BFS: ";
    g.bfs(awal);

    return 0;
}