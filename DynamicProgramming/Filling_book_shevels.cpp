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
int n , sh;
vector<vector<int>>v;
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& b, int shelfWidth) {
        memset(arr, -1, sizeof(arr));
        n = b.size();
        sh = shelfWidth;
        v = b;
        return dp(0);

    }

    int dp(int idx){
        if(idx == n ) return 0;

        int th = 0 , tw = 0 ;

        int&ret = arr[idx];
        if(ret != -1 ) return ret;

        ret = INT_MAX;

        for(int i = idx ; i < n ; i++){
            tw += v[i][0];

            if(tw > sh) break;

            th = max(v[i][1] , th);

            int total = th + dp(i+1);
            ret = min(ret , total); 

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
    vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    cout << sol.minHeightShelves(books , 4) << line;

    return 0;
}