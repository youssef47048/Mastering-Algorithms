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

typedef unordered_map<int, vector<int>> GRAPH;
void print(GRAPH &graph) {
    for(auto const & [node, neighbors] : graph){
        cout << node << " -> ";
        for(auto const & neighbor : neighbors){
            cout << neighbor << " ";
        }
        cout << line;
    }
}
class Solution {
public:

bool is_sub = false;
int dr[4] { -1, 0, 1, 0 };
int dc[4] { 0, 1, 0, -1 };

    bool isvalid(vector<vector<int>> &matrix , int r, int c) {
		if (r < 0 || r >= (int) matrix.size())
			return false;
		if (c < 0 || c >= (int) matrix[0].size())
			return false;
		return true;
	}  

    void add_edge(GRAPH &graph , int from , int to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

     vector<int> restoreArray(vector<vector<int>>& p) {
        GRAPH graph;
        for(auto const & i : p){
            add_edge(graph, i[0] , i[1]);
        }
        print(graph);
        return {};
    }
    
};




int main()
{
    fast;
    file;
    Solution sol;

    vector<vector<int>> pairs = {
        {4, -2},
        {1, 4},
        {-3, 1}
    };

   
    auto v = sol.restoreArray(pairs);
    //print(v);
    return 0;
}
