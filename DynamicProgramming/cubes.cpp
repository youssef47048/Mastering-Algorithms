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

//////////////////////////////////////////..........................\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
class Solution {
public:
    static const int mx = 500;
    int arr[mx];
    vector<int> v;
    int rob(vector<int>& nums) {
        memset(arr,-1,sizeof(arr));
        v = nums;
        return dp(0);
    }

    int dp(int idx){
        if(idx >= v.size()) return 0;

        int &ret = arr[idx];

        if(ret != -1)return ret;

        int ch1 = v[idx] + dp(idx+2);
        int ch2 = dp(idx+1);
        return ret = max(ch1 , ch2);
    }
};
    int main()
    {
        fast;
        file;
        Solution sol ; 
       vector<int> a = { 1,2,3,1 };
        cout << sol.rob(a) << line;

        return 0;
    }
