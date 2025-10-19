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
    int n1, n2;
    string s1, s2;
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;
        n1 = text1.length();
        n2 = text2.length();

        return lcs(0,0);

    }

    int lcs(int idx1 , int idx2){

        if(idx1 == n1 || idx2 == n2)return 0;

        if(s1[idx1] == s2[idx2]){
            return 1 + lcs(idx1+1 , idx2 + 1);
        }else{
            return max(lcs(idx1,idx2+1) , lcs(idx1+1,idx2));
        }


    }
};

    int main()
    {
        fast;
        file;
        Solution sol ; 
       vector<vector<int>> arr = {{1,2} , {7,8} , {4,5}};
        cout << sol.longestCommonSubsequence("abcde" , "ace" ) << line;

        return 0;
    }
