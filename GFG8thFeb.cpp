#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      long freeCells = n * n;
        std::vector<bool> filledRows(n);
        std::vector<bool> filledCols(n);
        int rowCount = 0;
        int colCount = 0;
        std::vector<long long> ans(k);
        
        for (int i = 0; i < k; i++)
        {
            int row = arr[i][0];
            int col = arr[i][1];
            
            //if it is a new row to be filled
            if (!filledRows[row - 1])
            {
                freeCells -= (n - colCount);
                filledRows[row - 1] = true;
                rowCount++;
            }
            
            //if it is a new col to be filled
            if (!filledCols[col - 1])
            {
                freeCells -= (n - rowCount);
                filledCols[col - 1] = true;
                colCount++;
            }
            
            //remaining freeCells after filling row and col
            ans[i] = freeCells;
        }
        return ans;
  }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}
