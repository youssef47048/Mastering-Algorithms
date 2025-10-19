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
const int mx = 1010;
int arr[mx];

class Solution {
public:
// moved off stack (static storage)
    int n ;
    vector<int> p;
    int minimumMountainRemovals(vector<int>& pr) {
           memset(arr,-1,sizeof(arr));
        n = pr.size();
        if (n > mx) { // guard to avoid OOB if input bigger than arr
            throw std::runtime_error("n exceeds DP array capacity");
        }
        p = pr;
        int lsl = 0 , lsr = 0;
        int mxv = 0;
        for(int i = 0 ; i < n ; i++){
            lsl = max(lsl,lisl(i));
            memset(arr,-1,sizeof(arr));
            lsr = max(lsr,lisr(i));
            memset(arr,-1,sizeof(arr));
            if (lsl > 1 && lsr > 1) { // peak must have both sides
                mxv = max(mxv, lsl + lsr - 1);
            }
        }
        return n - mxv;
    }

    int lisl(int idx)
    {
        if (idx < 0)
            return 0;
        int &ret = arr[idx];
        if(ret != -1)
            return ret;
        ret = 0;
            for(int j = idx - 1 ; j >=0 ; j--){
                if(p[j] < p[idx])
                ret = max(ret ,lisl(j));
            }
            ret += 1;
        return ret;
    }

    int lisr(int idx)
    {
        if (idx >= n)
            return 0;
        int &ret = arr[idx];
        if(ret != -1)
            return ret;
        ret = 0;
            for(int j = idx + 1 ; j < n ; j++){
                if(p[j] < p[idx])
                ret = max(ret ,lisr(j));
            }
            ret += 1;
        return ret;
    }

};
// define static storage

   int main()
    {
        fast;
        file;
        Solution sol ; 
        vector<int> a = {2,1,1,5,6,2,3,1};
        cout << sol.minimumMountainRemovals(a) << line;

        return 0;
    }