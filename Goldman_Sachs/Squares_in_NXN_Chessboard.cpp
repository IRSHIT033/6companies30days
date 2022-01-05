
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        return N*(N+1)*(2*N+1)/6;
    }
};


int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
}
