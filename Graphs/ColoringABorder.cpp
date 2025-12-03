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
int dr[4] { -1, 0, 1, 0 };
	int dc[4] { 0, 1, 0, -1 };

bool isvalid(vector<vector<int>> &matrix , int r, int c) {
		if (r < 0 || r >= (int) matrix.size())
			return false;
		if (c < 0 || c >= (int) matrix[0].size())
			return false;
		return true;
	}

int    initial_col;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int colo, int color) {
         initial_col = grid[row][colo];
        vector<vector<bool > > visited (grid.size() , vector<bool>(grid[0].size()));

        dfs(grid , visited , row , colo );
        coloring(grid , visited , color);

        return grid;
        
    }

    bool comp(vector<vector<int>>& grid , int r , int c){
        if(r == 0 || r+1 == grid.size()) return false;
        if(c == 0 || c+1 == (int) grid[0].size()) return false;
        return true;

    }
    void dfs(vector<vector<int>>& grid,vector<vector<bool > > & visited,  int r, int c){
        if(!isvalid(grid , r , c) || visited[r][c]  || grid[r][c] != initial_col) return;

        visited[r][c] = 1;
        dfs(grid , visited , r-1 , c );
        dfs(grid , visited , r+1 , c );
        dfs(grid , visited , r , c-1 );
        dfs(grid , visited , r , c+1 );
    }

    void coloring(vector<vector<int>>& grid,vector<vector<bool > > & visited , int new_color){

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(!visited[i][j])continue;

                for(int d = 0 ; d < 4 ; d++){
                    int nr = i + dr[d] , nc = j+dc[d];
                    if(!isvalid(grid , nr , nc) || !visited[nr][nc]) grid[i][j] = new_color; 
                }
            }
        }
    }
};


typedef vector<vector<vector<int> > > GRAPH;

int main()
{
    fast;
    file;
    Solution sol;

    vector<vector<int>> color = {{1,1,1},{1,1,1},{1,1,1}};
    
    color = sol.colorBorder(color , 1,1,2);

    for(auto &i : color){
        for(auto &j:i) cout<< j<<" ";
        cout<<line;
    }
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