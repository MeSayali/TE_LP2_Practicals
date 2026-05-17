#include <bits/stdc++.h>
using namespace std;
// Note : Graph is undirected
class Graph
{
    vector<vector<int>> matrix;
    int totalVertices;

public:
    Graph(int n) : matrix(n, vector<int>(n, 0)), totalVertices(n) {}
    friend class Traversal;
    void addEdges()
    {

        int totalEdges;
        cout << "Enter total number of edges: ";
        cin >> totalEdges;

        while (totalEdges > 0)
        {
            int source, destination;
            cout << "\nEnter source and destination: ";
            cin >> source >> destination;
            if (source < totalVertices && destination < totalVertices)
            {
                matrix[source][destination] = 1;
                matrix[destination][source] = 1;
            }
            totalEdges--;
        }
    }

    void printGraph()
    {
        for (int i = 0; i < totalVertices; i++)
        {
            for (int j = 0; j < totalVertices; j++)
            {
                cout << " " << matrix[i][j];
            }
            cout << endl;
        }
    }
};

class Traversal
{
    Graph obj;

public:
    Traversal(Graph o) : obj(o) {}
    // Application DFS: Cycle detection in Network
    //  Implementation of Spanning Tree Protocol(STP) --> Cycle detection in physical network of LAN
    //  There exist a alternate path to already visited node but it is not parent
    bool DfsRec(vector<vector<int>> &matrix, vector<bool> &vis, int s, int parent, vector<int> &res)
    {
        vis[s] = true;
        res.push_back(s);
        for (int i = 0; i < obj.totalVertices; i++)
        {
            cout << "\nChecking for: " << s << "-->" << i;
            if (vis[i] == false && matrix[s][i] == 1)
            {
                cout << " :- Not creating cycle";
                bool ans = DfsRec(matrix, vis, i, s, res);
                return ans;
            }
            else if (matrix[s][i] == 1 && vis[i] == true && i != parent) // cycle found
            {
                cout << " :- Creating cycle";
                return true;
            }
        }
        return false;
    }
    void DFS()
    {
        vector<bool> visited(obj.totalVertices, false);
        vector<int> res;
        int start;
        bool ans;
        cout << "Enter start vertex: ";
        cin >> start;
        if (start < obj.totalVertices)
        {
            ans = DfsRec(obj.matrix, visited, start, -1, res);
        }
        if (ans == true)
        {
            cout << "\n\nCycle deteced in Physical Network using STP protocol. Remove a node to make Tree!!\n";
        }
        else
        {
            cout << "\nNo Cycle detected. Good to go with current network topology.\n";
            cout << "\nDFS Result: ";
            for (int i = 0; i < res.size(); i++)
            {
                cout << " " << res[i];
            }
            cout << "\n";
        }
    }

    // Application of BFS: Check if graph is bipartite or not
    //  void BFSRec(vector<vector<int>> &matrix, vector<bool> &vis, int s, vector<int> &res, queue<int> &q)
    //  {
    //      if (q.empty())
    //          return;
    //      res.push_back(s);
    //      vis[s] = true;
    //      q.pop();

    //     for (int i = 0; i < obj.totalVertices; i++)
    //     {
    //         // cout<<"s: "<<s<<" i: "<<i<<endl;
    //         if (vis[i] == false && matrix[s][i] == 1)
    //         {
    //             // cout<<"\npushing: "<<i<<endl;
    //             vis[i] = true;
    //             q.push(i);
    //         }
    //     }

    //     if (!q.empty())
    //     {
    //         int next = q.front();

    //         BFSRec(matrix, vis, next, res, q);
    //     }
    // }

    bool isBipartiteRecursive(vector<vector<int>> &matrix, vector<int> &color, queue<int> &q, int V)
    {
        if (q.empty())
        {
            return true; // All visited in this component, bipartite so far
        }

        int u = q.front();
        q.pop();

        // Explore neighbors
        for (int v = 0; v < V; ++v)
        {
            if (matrix[u][v] == 1)
            { // If there's an edge
                if (color[v] == 0)
                {                         // If neighbor 'v' is uncolored
                    color[v] = -color[u]; // Assign opposite color
                    q.push(v);
                }
                else if (color[v] == color[u])
                {                 // If neighbor has the same color
                    return false; // Not bipartite!
                }
            }
        }

        // Recurse with the updated queue
        return isBipartiteRecursive(matrix, color, q, V);
    }

    void BFS()
    {
        vector<int> color(obj.totalVertices, 0); // 0: uncolored, 1: color 1, -1: color 2
        queue<int> q;

        for (int i = 0; i < obj.totalVertices; ++i)
        {
            if (color[i] == 0)
            { // If vertex i is not colored (part of a new component)
                q.push(i);
                color[i] = 1; // Start coloring with color 1
                if (!isBipartiteRecursive(obj.matrix, color, q, obj.totalVertices))
                {
                    cout << "\nFound a non-bipartite component";
                    return;
                }
            }
        }
        cout << "\nGiven graph is bipartite\n";
    }
};

int main()
{
    int tV;
    cout << "\nEnter total number of vertices: ";
    cin >> tV;

    Graph obj(tV);
    obj.addEdges();
    obj.printGraph();
    Traversal o(obj);
    // o.DFS();
    o.BFS();

    return 0;
}
