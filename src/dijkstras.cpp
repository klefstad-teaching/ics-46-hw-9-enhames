#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int num_vertices = G.size();
    // get all vertices
    vector <int> distances(num_vertices, INF);
    // initializing distance to all vertices as unreachable, storing inside a vector w ints
    vector <bool> visited(num_vertices, false);
    // storing visited nodes
    previous.assign(num_vertices, -1);
    // initialize the previous array to store the shortest path tree (-1 means no predecessor)
    distances[source] = 0;
    // distance from the source to itself is always 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    // priority queue (min-heap) to always process the closest (shortest distance) unvisited vertex first
    minHeap.push({0, source});
    // insert the source vertex into the heap with distance 0

    while (!minHeap.empty()){
        // processing vertices in order of shortest distance until pq is empty
        int curr = minHeap.top().second;
        // gets vertex with smallest distance
        minHeap.pop();
        // remove it from the queue

        if (visited[curr]) continue;
        // skip vertex if it's been visited
        visited[curr] = true;
        // mark it as visited if not

        for (const Edge edge: G[curr]){
            // traversing neighbors of the current vertex in the graph
            int v = edge.dst;
            // edge's destination vertex
            int weight = edge.weight;
            // weight for this edge

            if (!visited[v] && distances[curr] + weight < distances[v]){
                // checks that the destination vertex has not been visited and if a shorter path was found
                distances[v] = distances[curr] + weight; // update shortest distance
                previous[v] = curr; // update the previous node
                minHeap.push({distances[v], v}); // push updated distance to our priority queue
            }
        }
    }
    
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){
    // i think this is just for testing
    if (destination == 0) return {0}; // if destination is the source, return immediately

    int current = destination;
    vector <int> path; // stores path from source to destination
    while (current != -1){
        path.push_back(current); // add the current node to the path
        current = previous[current]; // move to previous node
    }

    reverse(path.begin(), path.end()); // reverse to get correct order
    return path;
}

void print_path(const vector<int>& v, int total){
    if (v.empty()){
        cout << endl << "Total cost is " << total << endl;
    }

    for (size_t i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl << "Total cost is " << total << endl;
}