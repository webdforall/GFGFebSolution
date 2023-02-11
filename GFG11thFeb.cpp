#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin>>A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        // code here
         int ans=0;
        for(int i=0;i<N;i++){
            int temp= P[i];
            if(S[temp]!='?'&&((temp+1<N&&S[temp]==S[temp+1])||(temp-1>=0&&S[temp]==S[temp-1]))) ans= i+1;
            S[temp]='?';
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int N;
        cin>>N;
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}