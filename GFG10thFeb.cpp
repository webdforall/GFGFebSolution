#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxInstance(string s){
          map<char,int>m;
        map<char,int> m1;

        string t="balloon";

        for(int i=0;i<t.size();i++){
            m1[t[i]]++;
        }

        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }

        int mini=INT_MAX;
        for(int i=0;i<t.size();i++){
            mini=min(mini,m[t[i]]/m1[t[i]]);
        }

        return mini;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}