#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
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