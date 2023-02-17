#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        long long preSum = 0;
        queue<long long> q;
        for (auto num : GeekNum) {
            q.push(num);
            preSum += num;
        }
        if (N <= K) return GeekNum[N - 1];
        long long curr = preSum;
        for (int i = K; i < N; ++i){
            curr = preSum;
            q.push(curr);
            preSum += curr;
            preSum -= q.front();
            q.pop();
        }
        return curr;
    }
};
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}
