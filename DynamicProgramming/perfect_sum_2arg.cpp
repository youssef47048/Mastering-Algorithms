
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
int arr[mx][10000];
vector<int> sq;
int vis[mx];

int target , sz;
class Solution {
public:
    int numSquares(int n) {
        squared();
        sz = sq.size();
        memset(arr , -1 , sizeof(arr));
        auto lw = lower_bound(sq.begin() , sq.end() , n);
        if(*lw != n ) --lw;
        int idx = lw - sq.begin();

        int mn = INT_MAX;
        for(int i = idx ; i >= 0 ; i--){
            mn = min(mn , minmize(i,n));
        }
        return mn;

    }

    int minmize(int idx , int rem){
        if(idx == sz) return 0;

        int &ret = arr[idx][rem];
        if(ret != -1) return ret;
        rem -= sq[idx];

        if(rem <= 0) return 1;

        auto lw = lower_bound(sq.begin() , sq.end() , rem);
        if(*lw != rem ) --lw;
        int nxt = lw - sq.begin();

        return ret = 1+minmize(nxt,rem);


    }

    void squared(){
        for(int i = 1 ; i <= 100 ; i++){
            sq.push_back(i*i);
        }
    }
};


int main()
{
    fast;
    file;
    Solution sol;
    vector<int>nums = {10, 15, 20};
    cout << sol.numSquares(13) << line;

    return 0;
}