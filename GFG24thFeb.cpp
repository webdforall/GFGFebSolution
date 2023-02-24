#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
   vector<int> dijkstra(int S,int n,vector<vector<int>> adj[]){
        vector<int> dis(n+1,INT_MAX);
        dis[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        while(pq.size()){
            auto temp = pq.top();
            pq.pop();
            int node = temp.second;
            int distance = temp.first;
            for(int i=0;i<adj[node].size();i++){
                int sathkinode = adj[node][i][0];
                int duri = adj[node][i][1];
                if(distance+duri<dis[sathkinode]){
                    dis[sathkinode]=distance+duri;
                    pq.push({distance+duri,sathkinode});
                }
            }
        }
        return dis;
    }
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj[n+1];
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<int> from_a = dijkstra(a,n,adj);
        vector<int> from_b = dijkstra(b,n,adj);
        int ans = from_a[b];
        if(ans==INT_MAX)return -1;
        for(auto x:edges){
            if(from_a[x[0]]!=INT_MAX and from_b[x[1]]!=INT_MAX){
                ans = min(ans,from_a[x[0]]+x[3]+from_b[x[1]]);
            }
            if(from_a[x[1]]!=INT_MAX and from_b[x[0]]!=INT_MAX){
                ans = min(ans,from_a[x[1]]+x[3]+from_b[x[0]]);
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}