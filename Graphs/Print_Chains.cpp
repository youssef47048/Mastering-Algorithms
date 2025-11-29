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


void print_direction(GRAPH & graph , int from){

    cout << from << " ";

    if(graph[from].size() > 0){
        print_direction(graph,graph[from][0]);
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

    int q ; cin>>q;
    while(q--){
        int number; cin >> number;
        print_direction(graph , number);
        cout<<line;
    }








    
	

	return 0;
}

