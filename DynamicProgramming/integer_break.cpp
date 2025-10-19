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

const int mx = 60;
int nn;
int arr[mx];

class Solution
{
public:
    int integerBreak(int num)
    {
        if (num == 2)
            return 1;
        if (num == 3)
            return 2;
        return dp(num);
    }

    int dp(int n)
    {
        
        if (n == 2)
            return 2;
        if (n == 3)
            return 3;
            
        int &ret = arr[n];

        if (ret != -1)
            return ret;

        int ch1 = 2 * dp(n - 2);
        int ch2 = 3 * dp(n - 3);

        return max(ch1, ch2);
    }
};

int main()
{
    fast;
    file;
    Solution sol;
    memset(arr, -1, sizeof(arr));

    cout << sol.integerBreak(10) << line;

    return 0;
}