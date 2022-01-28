// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        int i=0;
        char ch;
        string res="";
        while(s[i]!='\0')
        {
          if(i==0 && isupper(s[i]))
            {
            ch = tolower(s[i]); 
            res+=ch;
            }
          else if(i!=0 && isupper(s[i]))
           {
             ch = tolower(s[i]);
             res=res+' '+ch;
            }else{
                res+=s[i];
            }
           
           i++; 
        }
        
        return res;
        
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends
