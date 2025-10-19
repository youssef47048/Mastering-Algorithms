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

const int mx = 52 , mod = 1e9 + 7;
int arr[mx][mx][mx];
int rows , cols , mxmoves;
vector<vector<int>> v;
class Solution {
public:
 int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(arr, -1, sizeof(arr));
        rows = m ; cols = n , mxmoves = maxMove;
        return dp(startRow , startColumn , 0);   
    }

    int dp(int idx1 , int idx2 , int moves)
    {
        //success
        if((idx1 == rows || idx1 == -1 || idx2 == -1 || idx2 == cols) && moves <= mxmoves) return 1;
        

        if(moves > mxmoves || idx1 > rows || idx2 > cols) return 0;

        auto & ret = arr[idx1][idx2][moves];
        if(ret != -1 ) return ret;

        ret = 0;

        int ch4 = dp(idx1 - 1 , idx2 , moves + 1) % mod;
        int ch3 = dp(idx1  , idx2 + 1 , moves + 1) % mod;
        int ch1 = dp(idx1 + 1 , idx2 , moves + 1) % mod;
        int ch2 = dp(idx1 , idx2 - 1 , moves + 1) % mod;

       
        return ret += ((ch1 + ch2) % mod + (ch3 + ch4) % mod) % mod;
    }
}; 


int main()
{
    fast;
    file;
    Solution sol;
    string s = "cbbd";
    vector<vector<int>> V = {{2,1,3},{6,5,4},{7,8,9}};
    cout << sol.findPaths(1,3,3,0,1) << line;

    return 0;
}