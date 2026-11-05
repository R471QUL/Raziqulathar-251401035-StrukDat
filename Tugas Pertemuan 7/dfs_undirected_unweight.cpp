#include <iostream>
#include <vector>
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

        void addEdge(int i, int j) {
            if (i >= 0 && i < numbervertex && j >= 0 && j < numbervertex) {
                adjMatrix[i][j] = 1;
                adjMatrix[j][i] = 1; // Karena ini adalah graf tak berarah
            } else {
                cout << "Indeks tidak valid!" << endl;
            }
        }

        void printadjmatrix() {
            for (int i = 0; i < numbervertex; i++) {
                for (int j = 0; j < numbervertex; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        void dfs(int startvertex) {
            vector<bool> visited(numbervertex, false);
            dfsUtil(startvertex, visited);
            }

            void dfsUtil(int currentvertex, vector<bool>& visited) {
                visited[currentvertex] = true;
                cout << "visited: " << currentvertex << endl;

                for (int i = 0; i < numbervertex; i++) {
                    if (adjMatrix[currentvertex][i] == 1 && !visited[i]) {
                        dfsUtil(i, visited);
                    }
                }
            }
};

int main() {
    graph graphh(8); // Membuat graf dengan 8 titik
    graphh.addEdge(0, 1);
    graphh.addEdge(0, 2);
    graphh.addEdge(1, 3);
    graphh.addEdge(1, 4);
    graphh.addEdge(2, 5);
    graphh.addEdge(3, 6);
    graphh.addEdge(5, 7);

    graphh.printadjmatrix();
    cout << endl;

    graphh.dfs(0);
    return 0;
}