
 
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
     int miss=0,rep=0;
     for(int i =0;i<n;i++){
         if(arr[abs(arr[i])-1]<0){
             rep=abs(arr[i]);
         }else{
            arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
         }
     }
     for(int i=0;i<n;i++){
         if(arr[i]>0)
         {
             miss=i+1;
             break;
         }
     }
     int * p=(int*)malloc(2*sizeof(int));
     p[0]=rep;
     p[1]=miss;
     return p;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  
