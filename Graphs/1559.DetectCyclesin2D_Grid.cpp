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
bool is_ = false;
int dr[4] { -1, 0, 1, 0 };
int dc[4] { 0, 1, 0, -1 };

    bool isvalid(vector<vector<char>> &matrix , int r, int c) {
		if (r < 0 || r >= (int) matrix.size())
			return false;
		if (c < 0 || c >= (int) matrix[0].size())
			return false;
		return true;
	}

    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size() , col = grid[0].size();
        vector<vector<bool> > visited ( rows, vector<bool>(col));
        
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(!visited[i][j]){
                    is_ = false;
                dfs(grid , visited , i , j , i , j , grid[i][j] );
                if(is_ ) return true;
                }
                
            }
        }
        return false;
    }

    void dfs(vector<vector<char>>& grid , vector<vector<bool> > & visited , int r , int c , int pr , int pc , char old_col){
        
        if(!isvalid(grid , r , c) || grid[r][c] != old_col ){
            return ;
        }

        if(visited[r][c]) {
            is_ = true;
            return ;

        }

        visited[r][c] = true;

        for(int d = 0 ; d < 4 ; d++){

            int nr = r + dr[d] , nc = c + dc[d];
            if(nr == pr && nc == pc ) continue;
            dfs(grid , visited , nr , nc , r,c , old_col);
        }

    }  
    
};


typedef vector<vector<vector<int> > > GRAPH;

int main()
{
    fast;
    file;
    Solution sol;

    std::vector<std::vector<char>> grid = {
    {'a', 'b', 'b'},
    {'b', 'z', 'b'},
    {'b', 'b', 'a'}
};

   
    bool n = sol.containsCycle(grid);
    cout<< n;
    return 0;
}
