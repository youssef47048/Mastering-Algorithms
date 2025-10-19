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
int arr[mx];  
vector<int> v;
int n , target;
class Solution {
public:
    int combinationSum4(vector<int>& coins , int amount) {
        n = coins.size();
        v= coins;
        memset(arr , -1 , sizeof(arr));
        return dp(amount);
        
    }

    int dp(int rem){
         if(rem < 0 ) return 0;
        if(rem == 0) return 1;
       

        int &ret = arr[rem];
	    if (ret != -1) return ret;

        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            cnt += dp(rem - v[i]);
        }
        return ret = cnt ;

    }
};


int main()
{
    fast;
    file;
    Solution sol;
    string st = "12";
    vector<int> V = {1,2,3};
    cout << sol.combinationSum4(V,4) << line;

    return 0;
}