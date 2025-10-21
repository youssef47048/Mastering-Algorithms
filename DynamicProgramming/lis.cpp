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

class Solution
{
    

public:
    int n;
    static const int MAX = 1e4 + 10;
    vector<int> e;
    int lengthOfLIS(vector<int> &nums)
    {
        n = nums.size();
        e = nums;
        int ans = 0;
        memset(vis ,-1, sizeof(vis));
        for(int i = 0 ; i < n ; i++ ){
            ans = max(ans , lis(i));
        }

        return ans;
    }

    int vis[MAX] ;
    int lis(int idx)
    {
        if (idx == n)
            return 0;
        int &ret = vis[idx];
        if(ret != -1)
            return ret;
        ret = 0;
        int pick = 0 , leave ;
            for(int j = idx + 1 ; j < n ; j++){
                if(e[j] > e[idx])
                ret = max(ret ,lis(j));
            }
            ret += 1;
        return ret;
    }
};

    int main()
    {
        fast;
        file;
        Solution sol ; 
       vector<int> arr = {1,2};
        cout << sol.lengthOfLIS(arr) << line;

        return 0;
    }
