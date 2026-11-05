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
                adjMatrix[j][i] = 0; // Karena ini adalah graf tak berarah
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
};

int main() {
    graph graphh(5); // Membuat graf dengan 5 titik
    graphh.addEdge(0, 1);
    graphh.addEdge(0, 2);
    graphh.addEdge(1, 3);
    graphh.addEdge(1, 4);
    graphh.addEdge(2, 3);
    graphh.addEdge(3, 4);
    graphh.printadjmatrix();
    return 0;
}