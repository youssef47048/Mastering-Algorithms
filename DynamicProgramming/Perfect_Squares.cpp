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

class Solution {
public:

const static int mx = 1000 + 1;
int arr[mx];
vector<int> sq;
int vis[mx];

int perfect(int n){
    if(n <= 0 ) return 0;

    int &ret = arr[n];

    if(ret != -1 ) return ret;

    ret = INT_MAX;

    for(int i = 1 ;; i++){
        if( i*i > n ) break;

        ret = min(ret , 1+perfect(n-i*i));
    }

    return ret;
}
int target , sz , rem;
    int numSquares(int n) {
        sz = sq.size();
        memset(arr , -1 , sizeof(arr));

        return perfect(n);
    }
};


int main()
{
    fast;
    file;
    Solution sol;
    vector<int>nums = {10, 15, 20};
    cout << sol.numSquares(5) << line;

    return 0;
}