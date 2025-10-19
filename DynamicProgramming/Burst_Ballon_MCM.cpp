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
vector<int> v;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // Add 1's at the beginning and end (virtual balloons)
        v.clear();
        v.push_back(1);
        for(int x : nums) v.push_back(x);
        v.push_back(1);
        
        memset(arr, -1, sizeof(arr));
        // Start from index 1 to n (excluding the virtual balloons at 0 and n+1)
        return dp(1, nums.size());
    }

    int dp(int st , int en){
        if(st >en) return 0;

          int &ret = arr[st][en];
        if(ret != -1 ) return ret;

        ret = INT_MIN;

        for(int i = st; i <= en ; i++){
            int revenue = v[i] * v[st-1] * v[en+1];
            int left = dp(st , i - 1);
            int right = dp(i + 1 , en);
            int total = left + right + revenue ;
            ret = max(ret , total );
        }
        return ret;
    }
    
};


int main()
{
    fast;
    file;
    Solution sol;
    string s = "cbbd";
    vector<int> V = {3,1,5,8};
    cout << sol.maxCoins(V) << line;

    return 0;
}