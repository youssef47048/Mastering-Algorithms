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
int arr[mx];
vector<int> v;
int n;
string s;
class Solution {
public:
    int numDecodings(string S) {
        n = S.size();
        s = S;
            memset(arr , -1 , sizeof(arr));

        return dp(0);
    }

    int dp(int idx){

        if(idx >= n) return 1;

        int &ret = arr[idx];
        if(ret != -1 ) return ret;

        int cnt = 0;
        if(s[idx] - '0' >= 1){
             cnt += dp(idx + 1);
        }else return 0;

        if(idx + 1 >= n) return ret = cnt;
        int num = (s[idx]- '0' )*10 + (s[idx+1] - '0');
        if(num>= 1 && num<= 26){
            cnt += dp(idx + 2);
        }

        return ret = cnt;
    }
};


int main()
{
    fast;
    file;
    Solution sol;
    string st = "12";
    vector<int> V = {3,1,5,8};
    cout << sol.numDecodings(st) << line;

    return 0;
}