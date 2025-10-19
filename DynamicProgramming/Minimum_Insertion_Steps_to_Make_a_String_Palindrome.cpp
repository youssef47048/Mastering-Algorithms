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



const int mx = 510;
int arr[mx][mx];
int n , sh , k;
vector<int> v;
string st;
class Solution {
public:
    int minInsertions(string s) {
        memset(arr, -1, sizeof(arr));
        n = s.size();
        st = s;
        return dp(0,n-1);
    }
    int dp(int start , int end){
        if(start >= end) return 0;

        int &ret = arr[start][end];
        if(ret != -1 ) return ret;

        if(st[end] == st[start]) return dp(start+1 , end - 1);
        else return 1 + dp(start + 1 , end);

    }

};








int main()
{
    fast;
    file;
    Solution sol;
    string s = "zzazz";
    vector<int> V = {1,15,7,9,2,5,10};
    cout << sol.minInsertions(s) << line;

    return 0;
}