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
    int findLongestChain(vector<vector<int>>& pairs) {
        
    }
};

    int main()
    {
        fast;
        file;
        Solution sol ; 
       vector<vector<int>> arr = {{1,2} , {7,8} , {4,5}};
        cout << sol.findLongestChain(arr) << line;

        return 0;
    }
