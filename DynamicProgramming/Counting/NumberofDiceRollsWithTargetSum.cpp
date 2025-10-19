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
int arr[mx][mx];
vector<int> v;  
int  mod = 1e9 + 7;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(arr , -1 , sizeof(arr));
        for(int i = 1 ; i <= k ; i++) v.push_back(i);
        v.shrink_to_fit();
        return dp(target , n);
    }
    int dp(int rem , int cnt){
        if(rem == 0 && cnt == 0) return 1;
        if(rem < 0  || cnt < 0) return 0;
        int &ret = (arr[rem][cnt]);
        if(ret != -1 ) return ret;

        ret = 0;
        for(auto&i : v){
            ret =(ret%mod + dp(rem - i , cnt-1)%mod)%mod;
        }

        return ret;
    }
   
};


int main()
{
    fast;
    file;
    Solution sol;
    string st = "12";
    vector<int> V = {1,2,3};
    cout << sol.numRollsToTarget(2,6,7) << line;

    return 0;
}