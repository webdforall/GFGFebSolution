#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
	/* This code is also better and easy to understand and second one is also easy
	
	int minIteration(int N, int M, int x, int y){    
	     int ans=0;
	     for(int i=0;i<=N;i++){
		 for(int j=0;j<=M;j++){
		     ans=max(ans,abs(i-x)+abs(j-y));
		 }
	     }
	     return ans;
	    }
	*/
    int minIteration(int N, int M, int x, int y){    
        // code here
       int top = x-1, down = N-x;
	    int left = y-1, right = M-y;
	    return max(top+left, max(top+right, max(down+left, down+right)));
    }
};
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
