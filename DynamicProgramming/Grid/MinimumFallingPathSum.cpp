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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        v = matrix;
        memset(arr, -1, sizeof(arr));
        d1 = matrix.size(); d2 = matrix[0].size();

        int mn = INT_MAX;
        for(int i = 0 ; i < d1 ; i++){
            mn = min(mn , dp(0 , i));
        }
        return mn;
    }

    int dp(int idx1 , int idx2){

        if( idx2 == d2 || idx2 < 0 ) return INT16_MAX;
        
        if(idx1 == d1 - 1) return v[idx1][idx2];
        auto& ret = arr[idx1][idx2];
        if(ret != -1 ) return ret;

        ret = INT16_MAX;
        return ret = v[idx1][idx2] + min(ret , min(min( dp(idx1 + 1 , idx2) ,  dp(idx1 + 1 , idx2+1)), dp(idx1 + 1 , idx2-1)));

    }
    
}; 


int main()
{
    fast;
    file;
    Solution sol;
    string s = "cbbd";
    vector<vector<int>> V = {{2,3,3},{6,1,4},{7,8,9}};
    cout << sol.minFallingPathSum(V) << line;

    return 0;
}