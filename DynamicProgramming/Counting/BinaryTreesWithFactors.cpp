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
const int mx = 1010;
vector<int> v;  
int n, mod = 1e9 + 7;
unordered_map<int, ll> arr[mx];
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& nums) {
        // No initialization needed for unordered_map
        v = nums;
        n = v.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            cnt = (cnt % mod + dp(0,v[i])%mod)%mod;
        }
        return cnt;
    }
    
    int dp(int idx , int target){
        if(target == 0) return 1;
        if(target < 0) return 0;

        // Check if key exists
        if(arr[idx].count(target)) {
            return arr[idx][target];
        }

        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            cnt += dp( i + 1 , target - v[i]);
        }
        cnt%=mod;
        return arr[idx][target] = cnt;
    }
};

int main()
{
    fast;
    file;
    Solution sol;
    string st = "12";
    vector<int> V = {2,4,5,10};
    cout << sol.numFactoredBinaryTrees(V) << line;

    return 0;
}