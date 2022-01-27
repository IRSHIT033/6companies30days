// { Driver Code Starts
//Initial Template for C



#include<stdio.h>

 // } Driver Code Ends
//User function Template for C


void rotate(int n,int a[][n])
{
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
         
             if(i>j){
                 int t=a[i][j];
                 a[i][j]=a[j][i];
                 a[j][i]=t;
             }
         }
     }
     
     for(int i=0;i<n;i++){
         for(int j=0;j<n/2;j++){
         
             
                 int t=a[j][i];
                 a[j][i]=a[n-j-1][i];
                 a[n-j-1][i]=t;
             
         }
     }
     
     
     
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d",&t); 
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        }
        rotate(n,a);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}

  // } Driver Code Ends
