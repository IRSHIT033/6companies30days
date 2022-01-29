class Solution {
public:
    private:
    bool isValid(vector<int>& piles, int h, int mx) {
        int hours = 0;
        for(int i = 0; i < piles.size(); i++) { 
            hours += ceil(1.0 * piles[i] / mx);
        }
        
        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = 0;
        for(int i = 0; i < piles.size(); i++)
            mx = max(mx, piles[i]);
        
        if(piles.size() == h)
            return mx;
        
        int start = 1;
        int end = mx;
        int ans = -1;
      
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(isValid(piles, h, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
};
