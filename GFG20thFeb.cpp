#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
    int countPaths(int N){
        // code here 
        if(N<2)
            return 0;
       long int m=1000000007;
       long int t=0;
       int i=2;
         while(i<=N){
                t=(t*3)%m;
                 if(i%2!=0)
                    t-=3;
                   else t=(t+3)%m;
                  i++;
            }
        return t;
    }
};
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}