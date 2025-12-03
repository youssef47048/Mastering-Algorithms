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

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        return countt(grid1 , grid2);        
    }

    int countt(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int cnt = 0;
        for(int i = 0 ; i < grid2.size() ; i++){

            for(int j = 0 ; j < grid2[0].size() ; j++){
                if(grid2[i][j]){
                    is_sub = true;
                     dfs(grid1,grid2,i,j);
                     cnt += is_sub;
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2 , int r , int c){
        if(!isvalid(grid2 , r , c) || !grid2[r][c]) return;

        if( grid1[r][c] != grid2[r][c]){
            is_sub = false;
            return;
        }

        grid2[r][c] = 0;

        for(int d = 0 ; d < 4 ; d++){
            dfs(grid1, grid2 , r + dr[d] , c + dc[d]);
        }

    }  
    
};


typedef vector<vector<vector<int> > > GRAPH;

int main()
{
    fast;
    file;
    Solution sol;

    std::vector<std::vector<int>> grid1 = {
    {1, 1, 1, 0, 0},
    {0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1}
};

std::vector<std::vector<int>> grid2 = {
    {1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1},
    {0, 1, 0, 0, 0},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 1, 0}
};

   
    int n = sol.countSubIslands(grid1,grid2);
    cout<< n;
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