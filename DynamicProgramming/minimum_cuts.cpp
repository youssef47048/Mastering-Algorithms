
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


const int MAX = 100 + 2 + 1;	// 2 for two extra values we add
int arr[MAX][MAX];

vector<int> cuts;

class Solution {
public:
	int minCost(int n, vector<int> &cuts_) {
		cuts = cuts_;
		cuts.push_back(0);
		cuts.push_back(n);
		sort(cuts.begin(), cuts.end());

		memset(arr, -1, sizeof(arr));

		return cut(0, (int) cuts.size() - 1);
	}

    int cut(int start , int end){
        if(start + 1 == end ) return 0;

        int &ret = arr[start][end];
        if(ret != -1 ) return ret;

        ret = INT_MAX;

        for(int i = start + 1 ; i < end ; i++){
            int left = cut(start , i);
            int right = cut(i,end);
            int cut_cost = cuts[end] - cuts[start];
            ret = min(ret , left + right + cut_cost);
        }
        return ret;
    }

};

int main()
{
    fast;
    file;
    Solution sol;
    memset(arr, -1, sizeof(arr));
    vector<int> cuts{1,3,5,4};
    cout << sol.minCost(7,cuts) << line;

    return 0;
}