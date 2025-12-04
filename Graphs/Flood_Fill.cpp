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
class Solution {
    public:
    int old  , nw , rs , cs;
    
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            old = image[sr][sc];nw = color; rs = image.size() ; cs = image[0].size();

            dfs(image , sr , sc );
            return image;
        }

        void dfs(vector<vector<int>>& image, int nr, int nc){
            if(nr >= rs || nr < 0 || nc < 0|| nc >= cs) return;
            if(image[nr][nc] == old && image[nr][nc] != nw  ){
                image[nr][nc] =  nw;

                dfs(image , nr + 1 , nc);
                
                dfs(image , nr - 1 , nc);
                
                dfs(image , nr , nc + 1);

                dfs(image , nr, nc - 1);

            }
        }   
    };



int main() {

    fast;
    file;
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    sol.floodFill(image , 1 , 1 , 2);
    for(auto i:image){
        for(auto j:i){
            cout<< j<<" "; 
        }
        cout<<line;
    }
	return 0;
}

