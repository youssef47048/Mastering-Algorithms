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


struct Edge
{
    string to;
    int cost;
    bool operator < (const Edge & e) const {
		if (to != e.to)
			return to < e.to;
		return cost < e.cost;
	}
};

typedef map<string, multiset<Edge> > GRAPH;

void Add_Edge(GRAPH& graph , string from , string to , int cost){
    graph[from].insert({to,cost});
}

void print_graph(GRAPH& graph){
    for(auto& i : graph){
        cout<< "Flight from "<< i.first<<":" <<line;
        for(auto& j : i.second){
            cout<< "\t\t to "<< j.to << "cost "<< j.cost << line;
        }
    }
}



int main()
{
    fast;
    file;
    int nodes , edges;
    cin >>nodes >> edges;
    GRAPH graph;
    for(int i = 0 ; i < edges ; i++){
        string from , to;
        int cost;
        cin>>from>>to>>cost;
       Add_Edge(graph , from , to , cost);
    }
    print_graph(graph);
   

    

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