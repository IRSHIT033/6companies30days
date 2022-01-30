// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/

int getvalue(const string& str,int i,int m)
{
    if(i+m>str.length())
    return -1;
    
    int val=0;
    
    for(int j=0;j<m;j++){
        int c=str[i+j]-'0';
        if(c<0 or c>9)return -1;
        val=val*10+c;
    }
    
    return val;
}


int missingNumber(const string& str)
{
    // Code here
    for(int m=1;m<=6;m++){
        int n=getvalue(str,0,m);
        if(n==-1)break;
        
        int missing_num=-1;
        bool flag=false;
        
        for(int i=m;i!=str.length();i+=1+log10l(n))
        {
            if((missing_num==-1) and getvalue(str,i,1+log10l(n+2))==n+2)
            {
                missing_num=n+1;
                n+=2;
            }
            else if(getvalue(str,i,1+log10l(n+1))==n+1)n++;
            
            else{
                flag=true;
                break;
            }
        }
        if(!flag)return missing_num;
    }
    return -1;
}
