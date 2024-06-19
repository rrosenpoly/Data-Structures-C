#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include<bits/stdc++.h>
using namespace std;

// define large constant representing infinity
# define INF 10000

// define pair of integers to represent edges of the graph
typedef pair<int, int>integerPair;

// Class representing the graph
class Graph
{
	int Vertices; // number of vertices in graph
	list< pair<int, int> >* adjList; // Adjacency list for each seperate vertex

public:
	Graph(int V); // constructor for graph

	void addEdge(int u, int v, int w); // To add edges to the graph

	void primMST(); // To find the minimum spanning tree
};

Graph::Graph(int Vertices) {
	this->Vertices = Vertices;
	adjList = new list<integerPair>[Vertices];
}

void Graph::addEdge(int u, int v, int w) {

	// Add edges between u and v with weight w
	adjList[u].push_back(make_pair(v, w));
	adjList[v].push_back(make_pair(u, w));
}

void Graph::primMST() {

	// Create a priority queue for string vertices and their respective key values
	priority_queue<integerPair, vector <integerPair>, greater<integerPair> > pq;

	int vertexSource = 0; // Starts from vertex 0

	// Creating vectors for storing key values, parent vertices, and checks if vertex is in MST
	vector<int> keyValue(Vertices, INF);
	vector<int> parent(Vertices, -1);
	vector<int> child(Vertices, -1);
	vector<bool> inMST(Vertices, false);

	// Adding the source vertex to the priority queue and sets its value 0
	pq.push(make_pair(0, vertexSource));
	keyValue[vertexSource] = 0;

    cout << "All edges in MST: " << endl; 

    // Loop until the priority queue is empty
    while (!pq.empty())
    {
        // Extract the vertex with the minimum key value from the priority queue
        int u = pq.top().second;
        pq.pop();

        // If the vertex is already in the MST, skip it
        if (inMST[u] == true) {
            continue;
        }

        // Mark the vertex as in the MST
        inMST[u] = true;

        // Iterate over all the adjacent vertices of the current vertex
        list< pair<int, int> >::iterator i;
        for (i = adjList[u].begin(); i != adjList[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            // If the adjacent vertex is not in the MST and its key value is greater than the weight of the edge between u and v
            if (!inMST[v] && inMST[u]) {
                cout << u << " - " << v << " -> W:" << weight << endl;
                pq.push(make_pair(keyValue[v], v));
            }

            if (!inMST[v] && keyValue[v] > weight) {
                // Update the weight of the edge to the new value.
                keyValue[v] = weight;

                // Assign the parent vertex of the current vertex.
                parent[v] = u;

                // Assign the child vertex for referencing
                child[v] = v;
            }


        }
    }

    // To print total weight of the tree
    int totalWeight = 0;
    cout << "Shortest path of the MST: " << endl;


    for (int i = 1; i < parent.size(); ++i) {
        cout << parent[i] << " - " << child[i] << " -> W: " << keyValue[i] <<  endl;
        totalWeight += keyValue[i];
    }
 

    cout << "Total Weight of MST: " << totalWeight;
}


int main() {

    // Tests the program
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 9);
    g.addEdge(1, 4, 9);
    g.addEdge(1, 2, 12);
    g.addEdge(4, 7, 8);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 3);
    g.addEdge(3, 5, 7);
    g.addEdge(4, 7, 8);
    g.addEdge(4, 6, 5);
    g.addEdge(5, 6, 3);
    g.addEdge(6, 7, 15);
    g.addEdge(6, 8, 11);
    g.addEdge(7, 8, 10);

    g.primMST();

    cin.get();
}
