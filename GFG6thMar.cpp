#include <bits/stdc++.h>
using namespace std;
class Solution {

  public:
    int noConseBits(int n) {
        // code here
        int cnt=0;
        for(int i=31;i>=0;i--){
            int mask=(1<<i);
            if(n&mask){
                cnt++;
                if(cnt==3){
                    n=n&(~mask);
                    cnt=0;
                }
            }
            else{
                cnt=0;
            }
        }
        return n;
    }
};
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}
