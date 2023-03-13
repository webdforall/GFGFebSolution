#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        long long sum=0;
        int mn=INT_MAX,total=0;
        for(int i=0;i<N;i++){
            int temp = B[i]/2;
            sum+=temp*2*A[i];
            total+=temp*2;
            if(temp)
            mn=min(mn,A[i]);
        }
        if(total%4){
            sum-=mn*2;
        }
        return sum;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
}