class Solution {
private:
int ans;
vector< vector< int >>DP;
public:
long long split( int start, int end ){

    if( start >= end )
        return 0;
    
    if( DP[start][end] != -1 )
        return DP[start][end];
    
    long long temp = INT_MAX;
    
    for( int i = start ; i <= end; i++ ){
        
        long long temp1 = max( split( start , i-1 ) ,split( i+1, end ) ) + i;
        
        temp = min( temp , temp1 ); 
    }
    
    DP[start][end] = temp;
    
    return temp;
}

int getMoneyAmount(int n) {
    
    DP = vector< vector< int >>( n+1 , vector< int >( n+1 , -1 ) );
    
    ans = split( 1, n );
    
    return ans;
}
};
