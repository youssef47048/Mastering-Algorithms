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

const int mx = 5010;
int arr[mx][310];  // dp[amount][coin_index]
vector<int> v;
int n , target;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        target = amount;
        v= coins;
        sort(v.begin() , v.end());
        memset(arr , -1 , sizeof(arr));
        return dp(amount, 0);  // Start with coin index 0
    }

    int dp(int rem, int idx){
        if(rem == 0) return 1;
        if(idx >= n) return 0;  // No more coins available

        int &ret = arr[rem][idx];
        if(ret != -1 ) return ret;

        int cnt = 0 ;

        // Try using current coin (can use it multiple times)
        if(rem - v[idx] >= 0){
            cnt += dp(rem - v[idx], idx);  // Stay at same index
        }
        
        // Skip current coin and move to next
        cnt += dp(rem, idx + 1);

        return ret = cnt;
    }
};


int main()
{
    fast;
    file;
    Solution sol;
    string st = "12";
    vector<int> V = {1,2,3};
    cout << sol.change(4,V) << line;

    return 0;
}