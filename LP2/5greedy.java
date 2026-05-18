package Pr3;

import java.util.Scanner;

class Product {
    String name;
    double price;

    Product(String name, double price) {
        this.name = name;
        this.price = price;
    }
}

public class ProductPriceSelectionSort {

    // Selection Sort based on product price
    static void selectionSort(Product[] products) {
        int n = products.length;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                if (products[j].price < products[minIndex].price) {
                    minIndex = j;
                }
            }

            // Swap products
            Product temp = products[minIndex];
            products[minIndex] = products[i];
            products[i] = temp;
        }
    }

    static void displayProducts(Product[] products) {
        System.out.println("--------------------------------");
        System.out.printf("%-15s %-10s%n", "Product", "Price");
        System.out.println("--------------------------------");

        for (Product p : products) {
            System.out.printf("%-15s Rs.%-10.2f%n", p.name, p.price);
        }
        System.out.println("--------------------------------");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of products: ");
        int n = sc.nextInt();
        sc.nextLine();

        Product[] products = new Product[n];

        for (int i = 0; i < n; i++) {
            System.out.print("\nEnter product name: ");
            String name = sc.nextLine();

            System.out.print("Enter product price: ");
            double price = sc.nextDouble();
            sc.nextLine();

            products[i] = new Product(name, price);
        }

        System.out.println("\nProducts Before Sorting:");
        displayProducts(products);

        selectionSort(products);

        System.out.println("\nProducts After Sorting (Low to High Price):");
        displayProducts(products);

        sc.close();
    }
}

package Pr3;

import java.util.Scanner;

public class MSTNetworkApplication {

    static final int INF = 999;

    static void primMST(int[][] graph, int n) {
        int[] visited = new int[n];
        int minCost = 0;

        visited[0] = 1; // start from node 0

        System.out.println("\nEdges in Minimum Spanning Tree:");
        System.out.println("--------------------------------");
        System.out.println("Edge\tCost");
        System.out.println("--------------------------------");

        for (int edges = 0; edges < n - 1; edges++) {
            int min = INF;
            int u = -1, v = -1;

            for (int i = 0; i < n; i++) {
                if (visited[i] == 1) {
                    for (int j = 0; j < n; j++) {
                        if (visited[j] == 0 && graph[i][j] < min) {
                            min = graph[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }

            visited[v] = 1;
            minCost += min;

            System.out.println(u + " - " + v + "\t" + min);
        }

        System.out.println("--------------------------------");
        System.out.println("Minimum Total Cost = " + minCost);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        int[][] graph = new int[n][n];

        System.out.println("Enter adjacency matrix (enter 999 if no edge):");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = sc.nextInt();
            }
        }

        primMST(graph, n);

        sc.close();
    }
}


package Pr3;
import java.util.*;

class Edge implements Comparable<Edge> {
    int src, dest, weight;

    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        weight = w;
    }

    public int compareTo(Edge other) {
        return this.weight - other.weight;
    }
}

public class KruskalMSTApplication {

    static int findParent(int v, int[] parent) {
        if (parent[v] == v)
            return v;

        return findParent(parent[v], parent);
    }

    static void kruskalMST(Edge[] edges, int vertices, int edgeCount) {

        Arrays.sort(edges);

        int[] parent = new int[vertices];

        for (int i = 0; i < vertices; i++)
            parent[i] = i;

        Edge[] result = new Edge[vertices - 1];

        int e = 0; // count of edges in MST
        int i = 0; // index for sorted edges

        int minCost = 0;

        while (e < vertices - 1) {

            Edge current = edges[i++];

            int sourceParent = findParent(current.src, parent);
            int destParent = findParent(current.dest, parent);

            if (sourceParent != destParent) {
                result[e++] = current;
                parent[sourceParent] = destParent;
                minCost += current.weight;
            }
        }

        System.out.println("\nSelected Roads in Minimum Spanning Tree:");
        System.out.println("---------------------------------------");
        System.out.println("City1 - City2 : Cost");
        System.out.println("---------------------------------------");

        for (i = 0; i < e; i++) {
            System.out.println(result[i].src + " - " +
                               result[i].dest + " : " +
                               result[i].weight);
        }

        System.out.println("---------------------------------------");
        System.out.println("Minimum Total Road Construction Cost = " + minCost);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of cities: ");
        int vertices = sc.nextInt();

        System.out.print("Enter number of possible roads: ");
        int edgesCount = sc.nextInt();

        Edge[] edges = new Edge[edgesCount];

        System.out.println("Enter roads in format: city1 city2 cost");

        for (int i = 0; i < edgesCount; i++) {
            int s = sc.nextInt();
            int d = sc.nextInt();
            int w = sc.nextInt();

            edges[i] = new Edge(s, d, w);
        }

        kruskalMST(edges, vertices, edgesCount);

        sc.close();
    }
}

package Pr3;

import java.util.Scanner;

public class ShortestPathApplication {

    static final int INF = 999;

    static int findMinVertex(int[] distance, boolean[] visited, int n) {
        int minVertex = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
                minVertex = i;
            }
        }
        return minVertex;
    }

    static void dijkstra(int[][] graph, int n, int source) {

        int[] distance = new int[n];
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            distance[i] = INF;
            visited[i] = false;
        }

        distance[source] = 0;

        for (int i = 0; i < n - 1; i++) {

            int u = findMinVertex(distance, visited, n);
            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && graph[u][v] != 0 &&
                        distance[u] != INF &&
                        distance[u] + graph[u][v] < distance[v]) {

                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }

        System.out.println("\nShortest distances from source location " + source + ":");
        System.out.println("--------------------------------------");
        System.out.println("Location\tDistance");
        System.out.println("--------------------------------------");

        for (int i = 0; i < n; i++) {
            System.out.println(source + " -> " + i + "\t\t" + distance[i]);
        }
        System.out.println("--------------------------------------");
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of locations: ");
        int n = sc.nextInt();

        int[][] graph = new int[n][n];

        System.out.println("Enter adjacency matrix (0 if no direct road):");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = sc.nextInt();
            }
        }

        System.out.print("Enter source location: ");
        int source = sc.nextInt();

        dijkstra(graph, n, source);

        sc.close();
    }
}
