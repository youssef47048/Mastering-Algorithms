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

    static const int mx = 1010;
    int arr[mx][2];
    int n ;
    vector<int> p;
    int maxProfit(vector<int>& pr) {
        memset(arr,-1,sizeof(arr));
        n = pr.size();
        p = pr;
      return dp(0,true);        
         
    }

    int dp(int cur , bool flag ){
       if(cur >= n ) return 0;

       int &ret = arr[cur][flag];
       if(arr[cur][flag] != -1) return ret;
        int res1= 0 , res2 = 0;
       if(flag){
        int buy = dp(cur+1 , false) - p[cur];
        int skip = dp(cur+1 , true);
        res1 = max(buy , skip);
       }else{
        int sell = dp(cur+2 , true) + p[cur];
        int skip = dp(cur+1 , false);
        res2 = max(sell , skip);
       }
       return ret = max(res1 , res2);
    }
};

    int main()
    {
        fast;
        file;
        Solution sol ; 
       vector<int> a = {1,2,4};
        cout << sol.maxProfit(a) << line;

        return 0;
    }