#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool possible(int n,vector<int> a,int k,int w,int mid){
        for(int i=0;i<n;i++){
            if(a[i]<mid){
                int temp = mid-a[i];
                if(temp>k)return false;
                k-=temp;
                a[i]=mid;
                for(int j=i+1;j<n and j<i+w;j++){
                    a[j]+=temp;
                }
            }
        }
        return true;
    }
    long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
    {
        // code here
        int mn=INT_MAX,mx;
        for(int i=0;i<n;i++)mn=min(mn,a[i]);
        mx=mn+k;
        long long int ans;
        while(mn<=mx){
            int mid = (mn+mx)/2;
            if(possible(n,a,k,w,mid)){
                ans=mid;
                mn=mid+1;
            }
            else mx=mid-1;
        }
        return ans;
        }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}