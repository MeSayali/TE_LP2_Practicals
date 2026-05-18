package Pr2;

import java.util.*;

class State {
    int[][] board;
    int g, h, f;
    State parent;

    State(int[][] board, int g, State parent, int[][] goal) {
        this.board = board;
        this.g = g;
        this.h = heuristic(board, goal);
        this.f = g + h;
        this.parent = parent;
    }

    static int heuristic(int[][] board, int[][] goal) {
        int dist = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 0) {
                    for (int x = 0; x < 3; x++) {
                        for (int y = 0; y < 3; y++) {
                            if (board[i][j] == goal[x][y]) {
                                dist += Math.abs(i - x) + Math.abs(j - y);
                            }
                        }
                    }
                }
            }
        }
        return dist;
    }

    String key() {
        StringBuilder sb = new StringBuilder();
        for (int[] r : board)
            for (int v : r)
                sb.append(v);
        return sb.toString();
    }
}

public class AStar8PuzzleVerbose {

    static int[][] goal;

    static void printBoard(int[][] b) {
        for (int[] r : b) {
            for (int v : r)
                System.out.print(v + " ");
            System.out.println();
        }
    }

    static List<State> generateChildren(State s) {
        List<State> children = new ArrayList<>();
        int x = 0, y = 0;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (s.board[i][j] == 0) {
                    x = i;
                    y = j;
                }

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) {
                int[][] newBoard = new int[3][3];
                for (int i = 0; i < 3; i++)
                    newBoard[i] = s.board[i].clone();

                newBoard[x][y] = newBoard[nx][ny];
                newBoard[nx][ny] = 0;

                children.add(new State(newBoard, s.g + 1, s, goal));
            }
        }
        return children;
    }

    static void printPath(State s) {
        if (s == null) return;
        printPath(s.parent);
        printBoard(s.board);
        System.out.println("g=" + s.g + " h=" + s.h + " f=" + s.f);
        System.out.println("-----------");
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int[][] start = new int[3][3];
        goal = new int[3][3];

        System.out.println("Enter Initial State:");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                start[i][j] = sc.nextInt();

        System.out.println("Enter Goal State:");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                goal[i][j] = sc.nextInt();
       
        PriorityQueue<State> open =
                new PriorityQueue<>(Comparator.comparingInt(a -> a.f));

        Set<String> closed = new HashSet<>();

        open.add(new State(start, 0, null, goal));

        while (!open.isEmpty()) {

            State current = open.poll();

            System.out.println("\n==============================");
            System.out.println("States generated at g = " + (current.g + 1));
            System.out.println("==============================");

            if (current.h == 0) {
                System.out.println("\nGOAL FOUND! CHOSEN PATH:\n");
                printPath(current);
                return;
            }

            closed.add(current.key());
            List<State> children = generateChildren(current);

            State best = null;

            for (State child : children) {
                if (!closed.contains(child.key())) {

                    printBoard(child.board);
                    System.out.println("g = " + child.g +
                            ", h = " + child.h +
                            ", f = " + child.f);
                    System.out.println("----------------");

                    open.add(child);

                    if (best == null || child.f < best.f)
                        best = child;
                }
            }

            if (best != null) {
                System.out.println(">> Chosen State (minimum f):");
                printBoard(best.board);
                System.out.println("Chosen f = " + best.f);
            }
        }
        
        System.out.println("No solution found.");

        sc.close();
    }
}
