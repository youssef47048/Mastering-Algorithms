#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

using namespace std;

typedef unordered_map<int, vector<int>> GRAPH;

class Solution {
public:
    void add_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> restoreArray(vector<vector<int>>& p) {
        GRAPH graph;
        for(auto const & i : p) {
            add_edge(graph, i[0], i[1]);
        }
        
        // Find starting node (node with only 1 neighbor)
        int start = 0;
        for(auto const & [node, neighbors] : graph) {
            if(neighbors.size() == 1) {
                start = node;
                break;
            }
        }
        
        vector<int> ans;
        unordered_set<int> visited;
        dfs(graph, ans, start, visited);
        
        return ans;
    }

    void dfs(GRAPH & graph, vector<int> &ans, int from, unordered_set<int> &visited) {
        visited.insert(from);
        ans.push_back(from);
        
        for(int neighbor : graph[from]) {
            if(!visited.count(neighbor)) {
                dfs(graph, ans, neighbor, visited);
            }
        }
    }
};

int main()
{
    fast;
    Solution sol;

    vector<vector<int>> pairs = {
        {4, -2},
        {1, 4},
        {-3, 1}
    };

   
    auto v = sol.restoreArray(pairs);
    return 0;
}
