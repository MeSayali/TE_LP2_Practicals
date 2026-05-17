#include <bits/stdc++.h>
using namespace std;

#define INF 9999

// ---------------- SELECTION SORT ----------------

void selectionSort()
{
    int n;

    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "\nEnter elements:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }

    cout << "\nSorted Array:\n";

    for(int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;
}

// ---------------- PRIM'S MST ----------------

void primsAlgo()
{
    int V;

    cout << "\nEnter total vertices: ";
    cin >> V;

    vector<vector<pair<int,int>>> adjList(V);

    for(int i = 0; i < V; i++)
    {
        int totalEdges;

        cout << "\nEnter total edges from vertex "
             << i << " : ";

        cin >> totalEdges;

        while(totalEdges--)
        {
            int v, w;

            cout << "Enter destination vertex: ";
            cin >> v;

            cout << "Enter weight: ";
            cin >> w;

            adjList[i].push_back({v, w});
            adjList[v].push_back({i, w});
        }
    }

    int start;

    cout << "\nEnter starting vertex: ";
    cin >> start;

    // {weight, {node,parent}}

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;

    vector<bool> visited(V, false);

    int totalCost = 0;

    pq.push({0, {start, -1}});

    cout << "\nEdges in MST:\n";

    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int weight = top.first;
        int node = top.second.first;
        int parent = top.second.second;

        if(visited[node])
            continue;

        visited[node] = true;

        if(parent != -1)
        {
            cout << parent
                 << " -> "
                 << node
                 << " Cost = "
                 << weight << endl;

            totalCost += weight;
        }

        for(auto neighbour : adjList[node])
        {
            int nextNode = neighbour.first;
            int nextWeight = neighbour.second;

            if(!visited[nextNode])
            {
                pq.push({nextWeight,
                        {nextNode, node}});
            }
        }
    }

    cout << "\nMinimum Cost = "
         << totalCost << endl;
}

// ---------------- DIJKSTRA ----------------

void dijkstraAlgo()
{
    int V, E;

    cout << "\nEnter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int,int>>> adjList(V);

    for(int i = 0; i < E; i++)
    {
        int u, v, w;

        cout << "\nEnter source vertex: ";
        cin >> u;

        cout << "Enter destination vertex: ";
        cin >> v;

        cout << "Enter weight: ";
        cin >> w;

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    int src;

    cout << "\nEnter source vertex: ";
    cin >> src;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> dist(V, INF);

    dist[src] = 0;

    pq.push({0, src});

    while(!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(cost > dist[node])
            continue;

        for(auto neighbour : adjList[node])
        {
            int nextNode = neighbour.first;
            int weight = neighbour.second;

            if(cost + weight < dist[nextNode])
            {
                dist[nextNode] =
                cost + weight;

                pq.push(
                {dist[nextNode], nextNode});
            }
        }
    }

    cout << "\nShortest Distances:\n";

    for(int i = 0; i < V; i++)
    {
        cout << src
             << " -> "
             << i
             << " = "
             << dist[i]
             << endl;
    }
}

// ---------------- MAIN MENU ----------------

int main()
{
    int choice;

    while(true)
    {
        cout << "\n\n===== GREEDY ALGORITHMS =====\n";

        cout << "1. Selection Sort\n";
        cout << "2. Prim's MST Algorithm\n";
        cout << "3. Dijkstra Algorithm\n";
        cout << "4. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                selectionSort();
                break;

            case 2:
                primsAlgo();
                break;

            case 3:
                dijkstraAlgo();
                break;

            case 4:
                return 0;

            default:
                cout << "\nInvalid Choice!";
        }
    }

    return 0;
}
