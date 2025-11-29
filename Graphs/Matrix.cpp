#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define file                          \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define in(arr, n)              \
    for (int i = 0; i < n; i++) \
    cin >> arr{i}

#define ou(arr, n)              \
    for (int i = 0; i < n; i++) \
    cout << arr{i}

#define ll long long
#define line "\n"
using namespace std;



typedef vector<vector<vector<int> > > GRAPH;

void add_directed_edge(GRAPH & graph , int from , int to , int cost){
    graph[from][to].push_back(cost);
}
void print_adjaceny_matrix(GRAPH & graph){

    int sz = graph.size();
    for(int i = 0 ; i < sz ; i++){
        for(int j = 0  ; j < graph[i].size();j++){
            for(auto & k : graph[i][j]){
                cout<<"From "<<i<<" to "<< j << " the cost is "<< k << " | ";
            }
        }cout<<line;
    }
}

int main()
{
    fast;
    file;
    int nodes , edges;
    cin >>nodes >> edges;
    GRAPH graph(nodes , vector<vector<int>>(nodes));
    for(int i = 0 ; i < edges ; i++){
        int from , to , cost;
        cin>>from>>to>>cost;
        add_directed_edge(graph , from , to , cost);
    }
    print_adjaceny_matrix(graph);

    

    return 0;
}

/*

6 8
2 1 10
2 5 20
2 0 77
2 3 33
0 5 45
1 4 60
5 4 10
5 4 110

*/