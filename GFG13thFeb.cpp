#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        if(B==A){
            return 1;
        }
        if(C==0 && B!=A){
            return 0;
        }
        
        int flag = ((B-A)%C==0)?1:0;
        if(flag==0){
            return 0;
        }
        /*
        if(C>0){
            (B>A)?1:0;
        }
        else{
            (A>B)?1:0;
        }*/
        
        if(C>0){
            if(B>A){
                return 1;
            }
            else{
                return 0;
            }
        }else{
            if(A>B){
                return 1;
            }else{
                return 0;
            }
        }
        
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}