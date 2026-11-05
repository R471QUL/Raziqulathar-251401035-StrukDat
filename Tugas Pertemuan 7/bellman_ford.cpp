#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph{
    private:
        int V;
        vector<Edge> edges;

    public:
        Graph(int jumlahVertex){
            V = jumlahVertex;
        }

    // Graf berarah: sisi hanya dari u ke v
    void addEdge (int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    // Mencetak jalur dari asal ke titik tujuan secara rekursif
    void printPath(vector<int>& parent, int tujuan) {
        if (parent[tujuan] == -1) {
            cout << tujuan;
            return;
        }
        printPath(parent, parent[tujuan]);
        cout << " -> " << tujuan;
    }

    void bellmanFord(int start) {
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);

        dist[start] = 0;

        // Relaksasi seluruh sisi sebanyak V - 1 kali
        for (int i = 1; i <= V - 1; i++) {
            bool berubah = false;

            for (Edge e : edges) {
                if (dist[e.src] != INT_MAX &&
                    dist[e.src] + e.weight < dist[e.dest]) {
                    dist[e.dest] = dist[e.src] + e.weight;
                    parent[e.dest] = e.src;
                    berubah = true;
                }
            }

            if (!berubah) break; // sudah stabil, berhenti lebih awal
        }

        // Putaran ke-V: jika masih ada yang berubah, berarti ada siklus negatif
        for (Edge e : edges) {
            if (dist[e.src] != INT_MAX &&
                dist[e.src] + e.weight < dist[e.dest]) {
                cout << "Graf memiliki siklus negatif!" << endl;
                return;
            }
        }

        cout << "Jarak terpendek dari titik " << start << ":" << endl;
        for (int i = 0; i < V; i++) {
            cout << start << " ke " << i << " : ";
            if (dist[i] == INT_MAX) {
                cout << "tidak terjangkau" << endl;
            } else {
                cout << dist[i] << "  (jalur: ";
                printPath(parent, i);
                cout << ")" << endl;
            }
        }
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1, 6);
    graph.addEdge(0, 3, 7);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, -4);
    graph.addEdge(2, 1, -2);
    graph.addEdge(3, 2, -3);
    graph.addEdge(3, 4, 9);
    graph.addEdge(4, 0, 2);
    graph.addEdge(4, 2, 7);

    graph.bellmanFord(0);

    return 0;
}