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

struct Edge{
    int to;
    int cost;
};

class Mapping{
    private:
    map<string,int>mp_str_int;
    map<int,string>mp_int_str;
    public:
    int get_id(string s){
        if(mp_str_int.count(s) != 0) return mp_str_int[s];
        int sz = mp_str_int.size();
        mp_str_int[s] = sz;
        mp_int_str[sz] = s;
        return sz;
    }

    string get_id(int id){
     return mp_int_str[id];
    }

};

typedef vector<vector<Edge> > GRAPH;

void add_directed_edge(GRAPH & graph , int from , int to , int cost){
    graph[from].push_back({to,cost});
}
void print_adjaceny_matrix(GRAPH & graph , Mapping& mp){
    int sz = graph.size();
    for(int i = 0 ; i < sz ; i++){
        cout<<"Node "<<mp.get_id(i)<<" has neighbors: ";
        for(int j = 0  ; j < graph[i].size();j++){
            cout<<"to "<< mp.get_id(graph[i][j].to) << " cost "<< graph[i][j].cost<<" | "; 
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
    Mapping mp;
    for(int i = 0 ; i < edges ; i++){
        string from , to;
        int cost;
        cin>>from>>to>>cost;

        add_directed_edge(graph , mp.get_id(from) , mp.get_id(to) , cost);
    }
    print_adjaceny_matrix(graph , mp);

    

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