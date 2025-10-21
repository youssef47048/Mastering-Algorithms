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

const int mx = 310;
int arr[mx][mx];
int d1 , d2;
vector<vector<char>> v;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        v = matrix;
        memset(arr, -1, sizeof(arr));
        d1 = matrix.size(); d2 = matrix[0].size();

        int mn = INT_MIN;
        for(int i = 0 ; i < d1 ; i++){
           for(int j = 0 ; j < d2 ; j++){
                   mn = max(mn , dp(i , j));
           }
        }
        return mn * mn;
    }

    int dp(int r , int c){
        if(r < 0 || c < 0 || r >= d1 || c >= d2) return 0;
        
        if(v[r][c] == '0') return 0;

        auto& ret = arr[r][c];
        if(ret != -1 ) return ret;

        int up = dp(r - 1 , c);
        int left = dp(r , c - 1 );
        int di = dp(r - 1 , c - 1);
        
        return ret = 1 + min(up , min(left , di));
        
    }

    
    
}; 


int main()
{
    fast;
    file;
    Solution sol;
    string s = "cbbd";
    vector<vector<char>> V = {{'0','1'},{'1','0'}};
    cout << sol.maximalSquare(V) << line;

    return 0;
}