
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

int n;
const int mx = 1000;
int arr[mx];
vector<int> v;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        n = cost.size();
        memset(arr , -1 , sizeof(arr));
        v = cost;
        return min(dp(0), dp(1));
    }
    int dp(int idx)
    {
        if (idx >= n)
            return 0;

        int &ret = arr[idx];
        if (ret != -1)
            return ret;

        int ch1 = v[idx] + dp(idx + 1);
        int ch2 = v[idx] + dp(idx + 2);

        return ret = min(ch1, ch2);
    }
};

int main()
{
    fast;
    file;
    Solution sol;
    vector<int>V = {10, 15, 20};
    cout << sol.minCostClimbingStairs(V) << line;

    return 0;
}