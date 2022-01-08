class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3)return 0;
       bool mountain_peak=false;
       bool mountain_valley=false;
        int n=arr.size();
      int res=0;
        int  i=0;
       while(i<n-1){
           if(arr[i]<arr[i+1]){
                int start=i;
               while(i<n-1 and arr[i]<arr[i+1]){
                   mountain_peak=true;
                   i++;
               }
               while(i<n-1 and arr[i]>arr[i+1]){
                   mountain_valley=true;
                   i++;
               }
                if(mountain_peak==true and mountain_valley==true){
                    res=max(res,i-start+1);
                } 
               mountain_peak=false;
               mountain_valley=false;
               
           }else{
               i++;
           }
           
       }
        return res;
    }
};
