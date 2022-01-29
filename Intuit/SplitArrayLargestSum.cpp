class Solution {
public:
    
    int min_subarray(vector<int>& nums,int maxSum){
        int currSum=0,split=0;
        for(int el:nums){
            if(currSum+el<=maxSum)
                currSum+=el;
            else{
                currSum=el;
                split++;
            }
            
        }
        return split+1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int sum=0;
        int maxi=INT_MIN;
        for(int el:nums){
            sum+=el;
            maxi=max(maxi,el);
        }
        
        int left=maxi,right=sum, minSplit_sum=0;
        
        while(left<=right){
            int maxSum=left+(right-left)/2;
            
            if(min_subarray(nums,maxSum)<=m){
                right=maxSum-1;
                minSplit_sum=maxSum;
            }else{
            left=maxSum+1;
            }
        }
        return minSplit_sum;
    }
};
