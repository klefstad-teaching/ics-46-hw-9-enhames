#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){

    int num_vertices = G.size();
    vector <int> distances(num_vertices, INF);
    // storing shortest distance 
    vector <bool> visited(num_vertices, false);
    // storing visited nodes

    distances[source] = 0;
    previous[source] = UNDEFINED;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({source, 0});

    while (!minHeap.empty()){
        int curr = minHeap.top().second;
        minHeap.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

        for (Edge& edge: G[curr]){
            int v = edge.dst;
            int weight = edge.weight;

            if (!visited[v] && distances[curr] + weight < distances[v]){
                distances[v] = distances[curr] + weight;
                previous[v] = curr;
                minHeap.push({distances[v], v});
            }
        }
    }
    
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){
    vector <int> path;

    if (previous[destination] == 0){
        return {0};
    }
}

void print_path(const vector<int>& v, int total){
    if (v.empty()){
        cout << "Total cost is " << total << endl;
    }

    for (size_t i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl << "Total cost is " << total << endl;
}