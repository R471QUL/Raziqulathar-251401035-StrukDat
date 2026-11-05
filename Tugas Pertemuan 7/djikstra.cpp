#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Graph{
    private:
        int V;
        vector<vector<int>> adjMatrix;

    public:
        Graph(int jumlahVertex){
            V = jumlahVertex;
            adjMatrix.resize(V, vector<int>(V, 0));
        }

    void addEdge (int u, int v, int weight) {
            adjMatrix[u][v] = weight;
            adjMatrix[v][u] = weight; // graf tak berarah
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

    // Mencetak jalur dari asal ke titik tujuan secara rekursif
    void printPath(vector<int>& parent, int tujuan) {
        if (parent[tujuan] == -1) {
            cout << tujuan;
            return;
        }
        printPath(parent, parent[tujuan]);
        cout << " -> " << tujuan;
    }

    void dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> selesai(V, false);

        dist[start] = 0;

        for (int count = 0; count < V; count++) {
            int u = minkey(dist, selesai);

            if (u == -1) break; // sisa titik tidak terjangkau

            selesai[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] && !selesai[v] &&
                    dist[u] != INT_MAX &&
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    parent[v] = u;
                }
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

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    graph.dijkstra(0);

    return 0;
}