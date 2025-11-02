#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define file                          \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define in(arr, n)              \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

#define ou(arr, n)              \
    for (int i = 0; i < n; i++) \
    cout << arr[i]

#define ll long long
#define line "\n"
using namespace std;

// As the graph is sparce, we better use adjaceny list (or set)
typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to) {
	graph[from].push_back(to);
}

void print_adjaceny_matrix(GRAPH &graph) {
	int nodes = graph.size();
	for (int from = 0; from < nodes; ++from) {
		cout << "Node " << from << " has neighbors: ";
		for (int to = 0; to < (int) graph[from].size(); ++to)
			cout << graph[from][to] << " ";
		cout << "\n";
	}
}


bool isvalid(int nr , int nc , int rows , int cols){
    return (nr >= 0 && nr < rows) && (nc >= 0 && nc < cols);
}


int main() {

    fast;
    file;


	int rows, cols;

	cin >> rows >> cols;
    GRAPH graph(rows*cols);
    for(int i = 0 ; i < rows ; i++){

        for(int j = 0 ; j < cols ; j++){

            int from = i*cols + j;

            int nr = i + 1 , nc = j , to = nr * cols + nc;
            if(isvalid(nr , nc , rows , cols)) add_directed_edge(graph , from , to);

            nr = i - 1 , nc = j , to = nr * cols + nc;
            if(isvalid(nr , nc , rows , cols)) add_directed_edge(graph , from , to);

            nr = i , nc = j+1 , to = nr * cols + nc;
            if(isvalid(nr , nc , rows , cols)) add_directed_edge(graph , from , to);

            nr = i , nc = j-1 , to = nr * cols + nc;
            if(isvalid(nr , nc , rows , cols)) add_directed_edge(graph , from , to);

        }
    }

    print_adjaceny_matrix(graph);

	

	return 0;
}

/*
3 4
Node 0 has neighbors: 4 1
Node 1 has neighbors: 5 2 0
Node 2 has neighbors: 6 3 1
Node 3 has neighbors: 7 2
Node 4 has neighbors: 8 0 5
Node 5 has neighbors: 9 1 6 4
Node 6 has neighbors: 10 2 7 5
Node 7 has neighbors: 11 3 6
Node 8 has neighbors: 4 9
Node 9 has neighbors: 5 10 8
Node 10 has neighbors: 6 11 9
Node 11 has neighbors: 7 10


Node 0 has neighbors: 4 1 
Node 1 has neighbors: 5 2 0 
Node 2 has neighbors: 6 3 1 
Node 3 has neighbors: 7 2 
Node 4 has neighbors: 8 0 5 
Node 5 has neighbors: 9 1 6 4 
Node 6 has neighbors: 10 2 7 5 
Node 7 has neighbors: 11 3 6 
Node 8 has neighbors: 4 9 
Node 9 has neighbors: 5 10 8 
Node 10 has neighbors: 6 11 9 
Node 11 has neighbors: 7 10 


 */

