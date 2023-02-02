#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    vector < int > vis(N);
        long long ans = -1, cur, s = 0;
        bool cycle;
        for (long long i = 0; i < N; i++) {
        cur = i, s = 0, cycle = 0;
        while (cur != -1) {
            if (vis[cur] != 0) {
            cycle = vis[cur] == i + 1 ? 1 : 0;
            break;
            }
            vis[cur] = i + 1;
            cur = Edge[cur];
        }
        if (cycle) {
            long long s = cur, savecur = cur;
            cur = Edge[cur];
            while (cur != savecur) {
            s += cur;
            cur = Edge[cur];
            }
            ans = max(ans, s);
        }
        }
        return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}