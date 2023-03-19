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
            scanf("%d ",&A[i]);
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
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        unordered_map<int,int> mm,mm2;
        for(int i=0;i<N;i++)mm[A[i]]++;
        vector<int> ans;
        for(int i=0;i<N;i++){
            int left = mm2.size();
            mm[A[i]]--;
            if(mm[A[i]]==0)mm.erase(A[i]);
            int right = mm.size();
            ans.push_back(left-right);
            mm2[A[i]]++;
        }
        return ans;
    }
};
int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}