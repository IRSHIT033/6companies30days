
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;



class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
       vector<vector<string>>res;
       unordered_map<string,vector<string>>mp;
     
       for(int i=0;i<string_list.size();i++){
           string st=string_list[i];
         sort(st.begin(),st.end());
      
          mp[st].push_back(string_list[i]); 
       }
         unordered_map<string, vector<string>>::iterator it;
       for (it = mp.begin(); it != mp.end(); it++)
       {
          res.push_back(it->second); 
       }
       return res;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
