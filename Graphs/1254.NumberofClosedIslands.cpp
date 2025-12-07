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

#define print(grid) \
for(auto const & i : grid){\
            for(auto const & j : i){\
                cout<< j << " ";\
            }\
            cout<<line;\
        }
using namespace std;

class Solution {
public:
bool is_sub = true;
int dr[4] { -1, 0, 1, 0 };
int dc[4] { 0, 1, 0, -1 };

    bool isvalid(vector<vector<int>> &matrix , int r, int c) {
		if (r < 0 || r >= (int) matrix.size())
			return false;
		if (c < 0 || c >= (int) matrix[0].size())
			return false;
		return true;
	}

    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<bool > > visited (grid.size() , vector<bool>(grid[0].size()));
        return countt(grid , visited );
    }

    int countt(vector<vector<int>>& grid1, vector<vector<bool>>&visited){
        int cnt = 0;
        for(int i = 0 ; i < grid1.size() ; i++){

            for(int j = 0 ; j < grid1[0].size() ; j++){
                if(!grid1[i][j]){
                    is_sub = true;
                    dfs(grid1,visited,i,j);
                    cnt += is_sub;
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& grid,vector<vector<bool > > & visited,  int r, int c){
        if(!isvalid(grid , r , c) || visited[r][c]  || grid[r][c]) return;

        visited[r][c] = 1;
        dfs(grid , visited , r-1 , c );
        dfs(grid , visited , r+1 , c );
        dfs(grid , visited , r , c-1 );
        dfs(grid , visited , r , c+1 );
    }

    
};


typedef vector<vector<vector<int> > > GRAPH;

int main()
{
    fast;
    file;
    Solution sol;

   std::vector<std::vector<int>> grid = {
    {1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 1, 1, 0},
    {1, 0, 1, 0, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 0}
};



   
    int n = sol.closedIsland(grid);
    cout<< n;
    return 0;
}

