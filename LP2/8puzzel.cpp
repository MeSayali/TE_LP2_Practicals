#include <bits/stdc++.h>
using namespace std;

// Structure to store puzzle state
struct Node {

    vector<int> state; // puzzle state
    int g, h; // g = actual cost, h = heuristic cost
    string key; // string form of puzzle
};

// Comparator for priority queue
// Smaller f(n)=g+h gets higher priority
struct Compare {

    bool operator()(Node &a, Node &b) {

        return (a.g + a.h) > (b.g + b.h);
    }
};

// Function to print puzzle
void printState(const vector<int> &state) {

    for(int i = 0; i < 9; i++) {

        // Print blank space instead of 0
        if(state[i] == 0)
            cout << "_ ";
        else
            cout << state[i] << " ";

        // Next line after every 3 elements
        if((i + 1) % 3 == 0)
            cout << endl;
    }

    cout << endl;
}

// Manhattan Distance Heuristic Function
int manhattan(const vector<int> &s,
              const vector<int> &goal) {

    int dist = 0;

    // Check all tiles
    for(int i = 0; i < 9; i++) {

        // Ignore blank tile
        if(s[i] != 0) {

            int val = s[i];

            // Find correct position in goal state
            int gi = find(goal.begin(),
                          goal.end(),
                          val) - goal.begin();

            // Calculate Manhattan Distance
            dist += abs((i / 3) - (gi / 3))
                 + abs((i % 3) - (gi % 3));
        }
    }

    return dist;
}

int main() {

    cout << "Enter Initial State (3x3):\n";

    vector<int> start(9), goal(9);

    // Input initial state
    for(int i = 0; i < 9; i++) {

        cin >> start[i];
    }

    cout << "Enter Goal State (3x3):\n";

    // Input goal state
    for(int i = 0; i < 9; i++) {

        cin >> goal[i];
    }

    // Convert start state to string
    string startKey = "";

    for(int v : start) {

        startKey += char('0' + v);
    }

    // Priority Queue
    priority_queue<Node,
                   vector<Node>,
                   Compare> pq;

    // Visited states
    unordered_map<string, bool> visited;

    // Root node
    Node root;

    root.state = start;

    root.g = 0;

    root.h = manhattan(start, goal);

    root.key = startKey;

    pq.push(root);

    // Possible moves
    // UP, DOWN, LEFT, RIGHT
    int moves[4] = {-3, 3, -1, 1};

    // A* Algorithm starts
    while(!pq.empty()) {

        // Get best state
        Node cur = pq.top();

        pq.pop();

        // Skip visited state
        if(visited[cur.key]) {

            continue;
        }

        visited[cur.key] = true;

        // Print current state
        cout << "\nCurrent State:\n";

        printState(cur.state);

        // Print costs
        cout << "g(n) = " << cur.g
             << " , h(n) = " << cur.h
             << " , f(n) = "
             << cur.g + cur.h << endl;

        // Goal check
        if(cur.state == goal) {

            cout << "\nGoal Reached Successfully!\n";

            cout << "Total Cost = "
                 << cur.g << endl;

            return 0;
        }

        // Find blank tile position
        int z = find(cur.state.begin(),
                     cur.state.end(),
                     0) - cur.state.begin();

        // Generate child states
        for(int m = 0; m < 4; m++) {

            int nz = z + moves[m];

            // Boundary check
            if(nz < 0 || nz >= 9)
                continue;

            // Invalid left-right move check
            if((z % 3 == 2 && moves[m] == 1) ||
               (z % 3 == 0 && moves[m] == -1))
                continue;

            // Create new state
            vector<int> nextState = cur.state;

            // Swap blank tile
            swap(nextState[z], nextState[nz]);

            // Convert state to string
            string nextKey = "";

            for(int v : nextState) {

                nextKey += char('0' + v);
            }

            // Add if not visited
            if(!visited[nextKey]) {

                Node child;

                child.state = nextState;

                // Increase path cost
                child.g = cur.g + 1;

                // Calculate heuristic
                child.h = manhattan(nextState,
                                    goal);

                child.key = nextKey;

                // Push into queue
                pq.push(child);
            }
        }
    }

    // If no solution exists
    cout << "\nNo Solution Found!\n";

    return 0;
}