// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:

    vector<vector<int>> fourSum(vector<int> &arr, int k) 
    {
     
     vector<vector<int>>res;
     
     sort(arr.begin(),arr.end());
     int n=arr.size();
     
     
        for(int i=0;i<n-1;i++)
       {
        for(int j=i+1;j<n;j++)
        {
          int x =k-(arr[i]+arr[j]);
          int lo=j+1,hi=N-1;
           while(lo<hi)
         {
             if(arr[lo]+arr[hi]<x)lo++;
             else if(arr[lo]+arr[hi]>x)hi++;
             else 
             {
                 vector<int>temp={arr[i] , arr[j], arr[lo], arr[hi]};
                 res.push_back(temp);
                 while(lo<hi and arr[lo]==arr[2])lo++;
                 while(lo<hi and arr[lo]==arr[3])hi--;
                 
                 while(j+1<N and arr[j+1]==arr[j])j--;
                 while(i+1<N-1 and arr[i+1]==arr[i])i++;
                 
             }
            }
           }
          
       }
    }
     
     
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
