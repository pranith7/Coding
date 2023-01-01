#include<bits/stdc++.h>
using namespace std;

/*
    This is a function that uses backtracking to solve the graph coloring problem. The graph coloring 
    problem is a problem in which we need to color the nodes of a graph such that no two adjacent nodes
    have the same color. The function takes in a graph represented as a 2D bool array graph, where 
    graph[i][j] is true if there is an edge between nodes i and j, and false otherwise. It also takes
    in two integers, m and n, where m is the number of colors available and n is the number of nodes in the graph.

    The function first initializes an array color of size n to all zeros, which will be used to store the colors
    of the nodes. It then calls the solve function, which is a recursive function that attempts to color the nodes
    of the graph. The solve function takes in four arguments: the current node being colored node, the color array, m and n.

    The solve function first checks if it has reached the last node. If it has, it returns true, indicating that a
    valid coloring of the graph has been found. If it has not reached the last node, it tries to color the current
    node with each of the available colors in turn. For each color, it first checks if it is a safe color for the 
    current node using the isSafe function. If the color is safe, it assigns it to the current node and calls itself
    recursively on the next node. If the recursive call returns true, it returns true as well, indicating that a 
    valid coloring has been found. If the recursive call returns false, it resets the color of the current node to
    zero and tries the next color. If no safe color can be found for the current node, the function returns false, 
    indicating that a valid coloring cannot be found. If the  
*/

bool isSafe(int node, int color[],bool graph[101][101],int n,int col)
{
    for(int i=0;i<n;i++)
    {
        if(i!=node and graph[i][node] == 1 and color[i]==col)
            return false;
    }
    return true;
}

bool solve(int node,int color[],int m,int n,bool graph[101][101])
{
    if(node==n)
        return true;
    for(int i=1;i<=m;i++)
    {
        if(isSafe(node,color,graph,n,i))
        {
            color[node] = i;
            if(solve(node+1,color,m,n,graph))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring( bool graph[101][101],int m,int n)
{
    int color[n] = {0}; //Creating Array of colors
    if(solve(0,color,m,n,graph)) return true;
    return false;
}

int main()
{
  
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout <<graphColoring(graph, m, n) << endl;
    }
    return 0;
}