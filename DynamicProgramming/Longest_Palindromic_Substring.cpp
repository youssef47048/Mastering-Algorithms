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

const int mx = 5;
int arr[mx][mx];
string s;
class Solution
{
public:
    string longestPalindrome(string st)
    {
        s = st;
        memset(arr, -1, sizeof(arr));
        int len = 0 , length = 0 , sz = s.size() , l = -1  , r  = -1 ;

        for(int i = 0 ; i < sz ; i++){
            for(int j = i ; j < sz ; j++){
                length = j - i + 1  ;
                if(palin(i , j) && len < length ){
                    len = length;
                    l = i;
                }
            }
        }
        return s.substr(l,len);

    }

    int palin(int l, int r)
    {
        if(l>=r) return 1;

        int &ret = arr[l][r];
        if(ret != -1 ) return ret;

        if(s[l] == s[r]) return ret = palin(l+1,r-1);
        return ret = 0; 
    }
};

int main()
{
    fast;
    file;
    Solution sol;
    string s = "cbbd";
    vector<int> V = {10, 15, 20};
    cout << sol.longestPalindrome(s) << line;

    return 0;
}