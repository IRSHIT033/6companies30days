class Solution {
public:
      int DayCounter(vector<int>& w, int cap)
    {
        int ans=1,holder=0;
        for(auto i:w)
        {
            holder+=i;
            if(holder>cap)
            {
                ans++;
                holder=i;
            }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
       
        int largest_capacity = accumulate(weights.begin(),weights.end(),0);
        int smallest_capacity = max(largest_capacity/days, *max_element(weights.begin(), weights.end()));
       
        int low=smallest_capacity,high=largest_capacity,mid;
        while(low<high)
        {
            mid = low + (high-low)/2;
            if(DayCounter(weights,mid)<=days)
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};
