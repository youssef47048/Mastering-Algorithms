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
const int mx = 1010;
vector<int> v;  
int n, mod = 1e9 + 7;
unordered_set<int> s;
unordered_map<int, ll> arr;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& nums) {
        s.clear();
        arr.clear();
        for (auto x : nums) {
            s.insert(x);
        }

        int sum = 0;
        for(auto i : s){
            sum += cnt(i);
            sum%= mod;
        }
        return sum;
    }
    int cnt(int node){
        if(arr.count(node)) return arr[node];
        if(s.count(node) == 0) return 0;
        ll cn = 1;
        for(auto i : s){
            if(node % i == 0 && s.count(node/i)){  // Check if node/i exists in set
                ll left = cnt(i);
                ll right = cnt(node/i);
                cn = (cn + (left * right) % mod) % mod;
            }
        }
        return arr[node] = cn;
    }
};

int main()
{
    fast;
    file;
    Solution sol;
    string st = "12";
    vector<int> V = {2,4,5,10};
    cout << sol.numFactoredBinaryTrees(V) << line;

    return 0;
}