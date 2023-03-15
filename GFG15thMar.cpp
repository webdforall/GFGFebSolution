#include <bits/stdc++.h>
using namespace std;
class Solution{
    //Complete the function and return minimum number of operations
    public:
   int palindrom(string s1,string s2,int start,int end){
        int i=0,j=s1.length()-1,i2=0,j2=s2.length()-1;
        int operation=0;
        while(i<j){
            if((i<start and j>end) or (j<start) or (i>end)){
                if(s1[i]!=s1[j])operation++;
            }
            else if(j>end){
                if(s2[i2]!=s1[j])operation++;
                i2++;
            }
            else if(i<start){
                if(s1[i]!=s2[j2])operation++;
                j2--;
            }
            else{
                if(s2[i2]!=s2[j2])return INT_MAX;
                i2++;
                j2--;
            }
            i++;
            j--;
        }
        return operation;
    }
    int specialPalindrome(string s1, string s2){
        //Code Here
        int ans = INT_MAX;
        for(int i=0;i<=s1.length()-s2.length();i++){
            int start = i;
            int end = i+s2.length()-1;
            int temp = 0;
            int k = 0;
            for(int j=start;j<=end;j++){
                if(s1[j]!=s2[k])temp++;
                k++;
            }
            int t = palindrom(s1,s2,start,end);
            if(t==INT_MAX)temp=INT_MAX;
            else temp+=t;
            ans = min(ans,temp);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}