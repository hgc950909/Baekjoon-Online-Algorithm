#include<stdio.h>
int dp[32][32];
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1; i<=30; i++){
        dp[1][i]=i;
    }
    for(int i=2; i<=30; i++){
        for(int j=1; j<=30; j++){
            if(i>j){
                dp[i][j]=0;
            }
            else if(i==j){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            }
        }
    }
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        
        printf("%d\n",dp[n][m]);
    
    }
    return 0;
}

