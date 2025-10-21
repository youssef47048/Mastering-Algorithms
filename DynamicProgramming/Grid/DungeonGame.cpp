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

const int mx = 110;
int arr[mx][mx];
int d1 , d2;
vector<vector<int>> v;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& matrix) {
        v = matrix;
        memset(arr, -1, sizeof(arr));
        d1 = matrix.size(); d2 = matrix[0].size();

        return dp(0,0);
    }

    int dp(int r , int c){
        if(r >= d1 || c >= d2) return 1e8;
        if(r == d1 - 1 && c == d2 - 1){
            if(v[r][c] < 0){
                return 1 - v[r][c];
            }
            return 1;
        }

    
        auto& ret = arr[r][c];
        if(ret != -1 ) return ret;

        int mn = min(dp(r + 1 , c) , dp(r , c+1));

        if(v[r][c] >= mn){
            return mn = 1;
        }else{
            mn = mn - v[r][c];
        }        
        return ret = mn;
    }

    
    
}; 


int main()
{
    fast;
    file;
    Solution sol;
    string s = "cbbd";
vector<vector<int>> V = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    cout << sol.calculateMinimumHP(V) << line;

    return 0;
}