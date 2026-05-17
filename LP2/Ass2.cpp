#include <bits/stdc++.h>
using namespace std;

// Structure for each node
struct Node
{
    int x, y;   // Position
    int g, h, f; // Costs
};

// Manhattan Distance Heuristic
int heuristic(int x, int y, int goalX, int goalY)
{
    return abs(x - goalX) + abs(y - goalY);
}

// Display Maze
void displayMaze(vector<vector<int>> &maze)
{
    cout << "\nMaze:\n";

    for(int i = 0; i < maze.size(); i++)
    {
        for(int j = 0; j < maze[0].size(); j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    int m = 5;

    /*
        0 -> Free Path
        1 -> Obstacle
    */

    vector<vector<int>> maze =
    {
        {0,0,0,0,0},
        {1,1,0,1,0},
        {0,0,0,1,0},
        {0,1,1,0,0},
        {0,0,0,0,0}
    };

    int startX = 0;
    int startY = 0;

    int goalX = 4;
    int goalY = 4;

    displayMaze(maze);

    // Visited Array
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    /*
        Min Heap Priority Queue

        pair.first  -> f value
        pair.second -> Node
    */

    priority_queue<
        pair<int, Node>,
        vector<pair<int, Node>>,
        greater<pair<int, Node>>
    > pq;

    // Start Node
    Node start;

    start.x = startX;
    start.y = startY;

    start.g = 0;

    start.h = heuristic(startX, startY, goalX, goalY);

    start.f = start.g + start.h;

    pq.push({start.f, start});

    // Directions
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    cout << "\nA* Traversal:\n";

    while(!pq.empty())
    {
        // Get node with minimum f value
        Node curr = pq.top().second;
        pq.pop();

        int x = curr.x;
        int y = curr.y;

        // Skip visited node
        if(visited[x][y])
            continue;

        visited[x][y] = true;

        cout << "\nVisited: (" << x << "," << y << ")";
        cout << "  g=" << curr.g;
        cout << "  h=" << curr.h;
        cout << "  f=" << curr.f;

        // Goal reached
        if(x == goalX && y == goalY)
        {
            cout << "\n\nGoal Reached!\n";
            return 0;
        }

        // Explore neighbours
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Valid Cell Check
            if(nx >= 0 && nx < n &&
               ny >= 0 && ny < m &&
               maze[nx][ny] == 0 &&
               !visited[nx][ny])
            {
                Node next;

                next.x = nx;
                next.y = ny;

                // Cost from start
                next.g = curr.g + 1;

                // Heuristic value
                next.h = heuristic(nx, ny, goalX, goalY);

                // Total cost
                next.f = next.g + next.h;

                pq.push({next.f, next});
            }
        }
    }

    cout << "\nGoal Not Reachable!\n";

    return 0;
}
