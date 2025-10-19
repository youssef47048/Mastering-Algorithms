
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

string str1 , str2;
const int mx = 600;
int arr[mx][mx];


class Solution {
public:
    int minDistance(string word1, string word2) {

        memset(arr , -1 , sizeof(arr));
        str1 = word1 ; str2 = word2;
        return edit(0,0);
    }

    int edit(int idx1 , int idx2){
        if(idx1 == str1.size()) return str2.size() - idx2;

        if(idx2 == str2.size()) return str1.size() - idx1 ;

        int &ret = arr[idx1][idx2];
        if(ret != -1 ) return ret;

        if(str1[idx1] == str2[idx2]) return ret = edit(idx1 + 1 , idx2 + 1);

        int change = 1 + edit(idx1 + 1 , idx2 + 1) ;

        int del = 1 + edit(idx1 + 1 , idx2) ;

        int ins = 1 + edit(idx1 , idx2 + 1 );

        return ret = min (min(change , del ) , ins);
    }
};

    int main()
    {
        fast;
        file;
        Solution sol ; 
        cout << sol.minDistance("horse" , "ros" ) << line;

        return 0;
    }