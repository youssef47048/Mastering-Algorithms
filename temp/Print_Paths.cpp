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


void print_direction(GRAPH & graph){

    for(int i = 0 ; i < graph.size() ; i++){

        for(int j = 0 ; j < graph[i].size(); j++){
            int n2 = graph[i][j];
            for(int l =  0 ; l < graph[n2].size() ; l++){
                int n3 = graph[n2][l];
                cout << i <<" "<<  n2 << " "<< n3 <<line;
            }
        }
    }
}

int main() {

    fast;
    file;


	int rows, cols;

    cin >> rows >> cols;
    GRAPH graph(rows*cols);
    
    for(int j = 0 ; j < cols ; j++){
        int from , to;
        cin >> from >> to;
        add_directed_edge(graph , from , to);

    }
        print_direction(graph);
        cout<<line;

	return 0;
}

