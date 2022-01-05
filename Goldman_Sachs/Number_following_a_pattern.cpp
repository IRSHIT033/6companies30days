
#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    string printMinNumberForPattern(string S){
              stack<int> st;
        int num = 1;
        string res = "";
        for (int i = 0; i < S.size(); i++)
        {
            char ch = S.at(i);
            if (ch == 'D')
            {
                st.push(num);
                num++;
            }
            else
            {
                st.push(num);
                num++;
                while (st.size() > 0)
                {
                    string newStr = to_string(st.top());
                    res += newStr;
                    st.pop();
                }
            }
        }
        st.push(num);
        while (st.size() > 0)
        {
            string newStr = to_string(st.top());
            res += newStr;
            st.pop();
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
