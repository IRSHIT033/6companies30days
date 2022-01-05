
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
         int n=nums.size();
    if(n%2==1) return false;
    unordered_map<int,int>mp;
    int j=0; 
    for(int i=0;i<nums.size();i++){
        int v= (k + (nums[i]%k))%k; 
        if(mp[(k-v)%k] > 0) {mp[(k-v)%k]--; j--;} 
        else {
            mp[v]++; j++;
        }
    }
    return j==0;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  
