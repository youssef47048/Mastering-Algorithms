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

    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>>grid2(grid.size() , vector<int>(grid[0].size()));

        return other(grid,grid2);
    }

    int other(vector<vector<int>>& grid1, vector<vector<int>>& grid2){

        int cc = 1  ,cnt = 0; // Start cc at 1 to avoid 0 (unvisited) conflict
        for(int i = 0 ; i < grid1.size();i++){
            for(int j = 0 ; j < grid1[0].size() ; j++){
                // Check !grid2[i][j] to ensure we don't process visited nodes
                if(!grid1[i][j] && !grid2[i][j]){
                    is_sub = true; // Assume it is closed initially
                    dfs(grid1, grid2, i , j , cc++);
                    cnt += is_sub; // Add 1 if it remained true
                }
            }
        }
        return cnt;
    }


    bool is_grid_boundry(vector<vector<int>>& grid , int r , int c){
        if (r == 0 || r  == (int) grid.size()-1)
			return true;
		if (c == 0 || c == (int) grid[0].size()-1)
			return true;
		return false;
    }
    

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2 , int r , int c , int cc){
        if(!isvalid(grid1 , r , c) || grid2[r][c] || grid1[r][c] ) return;

        if(is_grid_boundry(grid1,r,c)){
            is_sub = false;
        }
        

        grid2[r][c] = cc;

        for(int d = 0 ; d < 4 ; d++){
            dfs(grid1, grid2 , r + dr[d] , c + dc[d],cc);
        }

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
