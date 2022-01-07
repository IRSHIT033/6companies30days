
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
       int buy1, profit1, buy2, profit2;
       buy1 = buy2 = INT_MAX;
       profit1 = profit2 = 0;
       for (int i = 0; i < N; i++) {
            buy1 = min(buy1, A[i]);
            profit1 = max(profit1, A[i] - buy1);
            buy2 = min(buy2, A[i] - profit1);
            profit2 = max(profit2, A[i] - buy2);
       }
        return profit2;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  
