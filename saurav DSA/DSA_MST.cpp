#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/* ----------- Kruskal's Algorithm ----------- */
struct Edge {
    int u, v, weight;
};

// Comparator function
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

int findParent(vector<int>& parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

void unionSets(vector<int>& parent, int u, int v) {
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);
    parent[pu] = pv;
}

void Kruskal(vector<Edge> edges, int n) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n);
    for(int i = 0; i < n; i++)
        parent[i] = i;

    cout << "\nKruskal's MST edges:\n";
    int total = 0;

    for(size_t i = 0; i < edges.size(); i++){
        Edge e = edges[i];

        int u = findParent(parent, e.u);
        int v = findParent(parent, e.v);

        if(u != v){
            cout << e.u << " - " << e.v << " : " << e.weight << "\n";
            total += e.weight;
            unionSets(parent, u, v);
        }
    }

    cout << "Total weight of MST: " << total << "\n";
}

/* ----------- Prim's Algorithm ----------- */
void Prim(const vector<vector<int> >& graph, int n) {
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> mstSet(n, false);

    key[0] = 0;

    for(int count = 0; count < n - 1; count++){
        int u = -1;
        int minKey = INT_MAX;

        for(int i = 0; i < n; i++){
            if(!mstSet[i] && key[i] < minKey){
                minKey = key[i];
                u = i;
            }
        }

        if(u == -1) break;
        mstSet[u] = true;

        for(int v = 0; v < n; v++){
            if(graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nPrim's MST edges:\n";
    int total = 0;

    for(int i = 1; i < n; i++){
        if(parent[i] != -1){
            cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
            total += graph[i][parent[i]];
        }
    }

    cout << "Total weight of MST: " << total << "\n";
}

/* ----------- Main Function ----------- */
int main(){
    int choice, n;

    cout << "Enter number of vertices: ";
    cin >> n;

    if(n <= 0){
        cout << "Invalid number of vertices!\n";
        return 0;
    }

    vector<vector<int> > graph(n, vector<int>(n));
    vector<Edge> edges;

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];

            if(i < j && graph[i][j] != 0){
                Edge e;
                e.u = i;
                e.v = j;
                e.weight = graph[i][j];
                edges.push_back(e);
            }
        }
    }

    do{
        cout << "\n--- MST Menu ---\n";
        cout << "1. Kruskal's Algorithm\n";
        cout << "2. Prim's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                Kruskal(edges, n);
                break;
            case 2:
                Prim(graph, n);
                break;
            case 3:
                cout << "Program Ended\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 3);

    return 0;
}

