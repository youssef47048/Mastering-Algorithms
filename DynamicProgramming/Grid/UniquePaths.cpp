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

const int mx = 110;
int arr[mx][mx];
int d1 , d2;
vector<vector<int>> v;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        v = obstacleGrid;
        memset(arr, -1, sizeof(arr));
        d1 = obstacleGrid.size(); d2 = obstacleGrid[0].size();
        return dp(0,0);
    }

    int dp(int idx1 , int idx2){
        if(idx1 >= d1 || idx2 >= d2) return 0;

        if(idx1 == d1-1 && idx2 == d2 - 1) return 1;

        if(v[idx1][idx2] == 1) return 0;

        auto& ret = arr[idx1][idx2];
        if(ret != -1 ) return ret;

        int cnt = 0;
        cnt += dp(idx1 + 1 , idx2 );
        cnt += dp(idx1 , idx2+1 );
        return ret = cnt;
       
    }

    
    
};


int main()
{
    fast;
    file;
    Solution sol;
    string s = "cbbd";
vector<vector<int>> V = {{0,0,0},{0,1,0,},{0,0,0}};
    cout << sol.uniquePathsWithObstacles(V) << line;

    return 0;
}