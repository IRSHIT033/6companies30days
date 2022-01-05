#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        int res = 0;
        long long mult = 1;
        int start = 0;
        int end = 0;
        while (end < n)
        {
            mult *= a[end];
            while (start < end and mult >= k)
            {
                mult /= a[start];
                start++;
            }

            if (mult < k)
            {
                int len = end - start + 1;
                res += len;
            }

            end++;
        }

        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
