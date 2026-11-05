#include <iostream>
#include <vector>
#include <climits>
#include <cctype>
using namespace std;

class Graph {
    private:
        int V;
        vector<vector<int>> adjMatrix;

    public:
        Graph(int jumlahVertex) {
            V = jumlahVertex;
            adjMatrix.resize(V, vector<int>(V, 0));
        }

        // Menambah jarak antar lokasi (graf tak berarah, berbobot)
        void addEdge(char a, char b, int jarak) {
            int u = a - 'A';
            int v = b - 'A';
            adjMatrix[u][v] = jarak;
            adjMatrix[v][u] = jarak;
        }

        // Mencari titik belum final dengan jarak terkecil
        int minkey(vector<int>& dist, vector<bool>& selesai) {
            int min = INT_MAX;
            int minindex = -1;

            for (int v = 0; v < V; v++) {
                if (!selesai[v] && dist[v] < min) {
                    min = dist[v];
                    minindex = v;
                }
            }
            return minindex;
        }

        // Algoritma Dijkstra dari titik start
        void dijkstra(int start, vector<int>& dist, vector<int>& parent) {
            dist.assign(V, INT_MAX);
            parent.assign(V, -1);
            vector<bool> selesai(V, false);

            dist[start] = 0;

            for (int count = 0; count < V; count++) {
                int u = minkey(dist, selesai);
                if (u == -1) break;

                selesai[u] = true;

                for (int v = 0; v < V; v++) {
                    if (adjMatrix[u][v] && !selesai[v] &&
                        dist[u] + adjMatrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + adjMatrix[u][v];
                        parent[v] = u;
                    }
                }
            }
        }

        // Mencetak rute dari asal ke tujuan secara rekursif
        void printPath(vector<int>& parent, int tujuan) {
            if (parent[tujuan] == -1) {
                cout << char('A' + tujuan);
                return;
            }
            printPath(parent, parent[tujuan]);
            cout << " -> " << char('A' + tujuan);
        }

        // Fitur 1 & 2: rute terpendek dari satu lokasi ke semua lokasi lain
        void tampilkanSemuaRute(char asal) {
            vector<int> dist, parent;
            int s = asal - 'A';
            dijkstra(s, dist, parent);

            cout << "Rute terpendek dari lokasi " << asal << ":" << endl;
            for (int i = 0; i < V; i++) {
                if (i == s) continue;
                cout << asal << " ke " << char('A' + i) << " : ";
                printPath(parent, i);
                cout << "  (total jarak: " << dist[i] << " km)" << endl;
            }
        }

        // Fitur 3: rekomendasi rute tercepat dari asal ke tujuan
        void rekomendasiRute(char asal, char tujuan) {
            int s = asal - 'A';
            int t = tujuan - 'A';

            if (s < 0 || s >= V || t < 0 || t >= V) {
                cout << "Lokasi tidak valid! Gunakan huruf A-F." << endl;
                return;
            }

            vector<int> dist, parent;
            dijkstra(s, dist, parent);

            if (dist[t] == INT_MAX) {
                cout << "Tidak ada rute dari " << asal << " ke " << tujuan << "." << endl;
                return;
            }

            cout << "Rute tercepat dari " << asal << " ke " << tujuan << ": ";
            printPath(parent, t);
            cout << endl;
            cout << "Total jarak: " << dist[t] << " km" << endl;
        }
};

int main() {
    Graph kota(6); // 6 lokasi: A, B, C, D, E, F

    kota.addEdge('A', 'B', 4);
    kota.addEdge('A', 'C', 2);
    kota.addEdge('B', 'C', 1);
    kota.addEdge('B', 'D', 5);
    kota.addEdge('B', 'E', 3);
    kota.addEdge('C', 'D', 8);
    kota.addEdge('C', 'E', 6);
    kota.addEdge('D', 'E', 2);
    kota.addEdge('D', 'F', 4);
    kota.addEdge('E', 'F', 3);

    // Rute terpendek dari A ke semua lokasi lain
    kota.tampilkanSemuaRute('A');

    // Rekomendasi rute berdasarkan input pengguna
    char asal, tujuan;
    cout << "\n=== Rekomendasi Rute ===" << endl;
    cout << "Masukkan lokasi asal (A-F): ";
    cin >> asal;
    cout << "Masukkan lokasi tujuan (A-F): ";
    cin >> tujuan;

    asal = toupper(asal);
    tujuan = toupper(tujuan);

    kota.rekomendasiRute(asal, tujuan);

    return 0;
}