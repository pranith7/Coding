#include <iostream>
#include <vector>
using namespace std;

/*
    This is a basic implementation of cycle detection in an undirected graph using Depth First Search. 
    The isCyclic() function returns true if there is a cycle in the graph, and false otherwise. The dfs()
     function is called recursively for each vertex of the graph, and it keeps track of visited and recursion stack vertices to detect a cycle. 
    In this example, the graph is represented as an array of vectors, where each vector stores the 
    adjacent vertices of a vertex. You could also use an adjacency matrix to represent the graph.
*/
const int N = 100000;
vector<int> g[N];
bool vis[N];
bool recStack[N];

bool dfs(int v) {
    vis[v] = true;
    recStack[v] = true;

    for (int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (!vis[u] && dfs(u)) return true;
        else if (recStack[u]) return true;
    }

    recStack[v] = false;
    return false;
}

bool isCyclic() {
    for (int i = 0; i < N; i++) {
        vis[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < N; i++)
        if (dfs(i))
            return true;
    return false;
}

int main() {
    // Add edges to the graph
    g[0].push_back(1);
    g[1].push_back(0);
    g[1].push_back(2);
    g[2].push_back(1);
    g[2].push_back(0);
    g[0].push_back(2);
    g[2].push_back(3);

    if (isCyclic())
        cout << "Graph contains a cycle." << endl;
    else
        cout << "Graph doesn't contain a cycle." << endl;

    return 0;
}
