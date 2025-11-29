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
struct  Edge{
    int to;
    int cost;

    bool operator == (const Edge &other)const{
        return to == other.to ;
    }
};
namespace std{
    template<>
    struct hash<Edge>{
        size_t operator()(const Edge & edge)const{
            return hash<int>()(edge.to) ^ hash<int>()(edge.cost)>>1;
        }
    };
}

typedef vector<unordered_set<Edge> > GRAPH;

void add_directed_edge(GRAPH & graph , int from , int to , int cost){
    graph[from].insert({to,cost});
}

void print_adjaceny_matrix(GRAPH & graph){

    int sz = graph.size();
    for(int i = 0 ; i < sz ; i++){
        cout<<"Node "<<i<<" has neighbors: ";
        for(auto const &k : graph[i]){
            cout<<"to "<< k.to << " cost "<< k.cost<<" | "; 
        }cout<<line;
    }
}

int main()
{
    fast;
    file;
    int nodes , edges;
    cin >>nodes >> edges;
    GRAPH graph(nodes);
    for(int i = 0 ; i < edges ; i++){
        int from , to , cost;
        cin>>from>>to>>cost;
        add_directed_edge(graph , from , to , cost);
    }
    print_adjaceny_matrix(graph);

    

    return 0;
}

/*

6 7
2 1 10
2 5 20
2 0 77
2 3 33
0 5 45
1 4 60
5 4 10

*/