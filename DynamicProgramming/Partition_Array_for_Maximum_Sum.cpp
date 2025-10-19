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



const int mx = 1010;
int arr[mx];
int n , sh , k;
vector<int> v;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& a, int num) {
        memset(arr, -1, sizeof(arr));
        n = a.size();
        k = num;
        v = a ;
        return dp(0) ;
    }
    int dp(int idx){
        if(idx == n) return 0;

        int &ret = arr[idx];
        if(ret != -1 ) return ret;

        int win = INT_MIN;
        ret = INT_MIN ;
        for(int i = idx , cnt = 0; cnt < k && i < n; cnt++,i++){
            win = max(win, v[i]);
            int total = win * (cnt + 1) + dp(idx + cnt + 1);
            ret = max(total , ret);
        }
        return ret;
    }
};


int main()
{
    fast;
    file;
    Solution sol;
    vector<int> V = {1,15,7,9,2,5,10};
    cout << sol.maxSumAfterPartitioning(V , 3) << line;

    return 0;
}