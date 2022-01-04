class Solution {
public:
    int solve(int i,string &s,vector<int>&dp){
        if(i>=s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        int s1=s[i]-'0',s2=0;
        if(i<s.size()-1){
            s2=s1*10+s[i+1]-'0'; 
        }
        if(s1>0) ans+=solve(i+1,s,dp);
        if(s1>0 and s2>0 and s2<=26) ans+=solve(i+2,s,dp);
        return dp[i]=ans;
        
    }
    int numDecodings(string s) {
        vector<int>dp(101,-1);
        return solve(0,s,dp);
        
    }
};
