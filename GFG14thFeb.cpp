#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        int dp[N][3];

      int j=1;

      dp[0][0]=colors[0][0];

      dp[0][1]=colors[0][1];

      dp[0][2]=colors[0][2];

      for(int i=1;i<N;i++){

          dp[i][0]=colors[j][0]+min(dp[j-1][1],dp[j-1][2]);

          dp[i][1]=colors[j][1]+min(dp[j-1][0],dp[j-1][2]);

          dp[i][2]=colors[j][2]+min(dp[j-1][1],dp[j-1][0]);

          j++;

      }

      int ans=INT_MAX;

      for(int i=0;i<3;i++){

          if(dp[N-1][i]<ans){

              ans=dp[N-1][i];

          }

      }

      return ans;
    }
};
int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}