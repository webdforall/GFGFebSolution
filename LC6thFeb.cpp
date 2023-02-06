#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
         vector<int> ans;
        
        for(int i =0 ;i < n;i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        return ans;
    }
};

int main() {

        vector <int> arr = {1,7,8,3,4,6};
        int n=3;
        Solution ob;
        vector<int> result = ob.shuffle(arr,n);
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
   return 0;
}