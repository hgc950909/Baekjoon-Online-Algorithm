#include<stdio.h>
long long int dp[105];
int main(){
    int t;
    scanf("%d",&t);
    dp[1]=dp[2]=dp[3]=1;
    dp[4]=dp[5]=2;
    
    for(int i=6; i<=101; i++){
        dp[i]=dp[i-1]+dp[i-5];
    }
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
}

