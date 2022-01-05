class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int start=0;
        int end=0;
        int sum=0;
        int MINlen=INT_MAX;
        int n=nums.size();
       while(end<n){
            sum+=nums[end];
           if(sum<target)
            {
            end++;
            }
             if(sum>=target){
                while(sum>=target)
                {
                int len=end-start+1;
                MINlen=min(len,MINlen);    
                sum-=nums[start];
                start++;    
                }
                end++;
            }
            
           
        }
        if ( MINlen== INT_MAX || MINlen < 0)
             return 0;
          return MINlen;
    }
};
