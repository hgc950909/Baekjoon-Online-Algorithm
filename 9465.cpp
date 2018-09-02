#include<stdio.h>
int map[3][100005];
int dp[3][100005];
int max(int a,int b){
    if(a<b)return b;
    else return a;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int ans=0;
        int n;
        scanf("%d",&n);
        for(int i=1; i<=2; i++){
            for(int j=1; j<=n; j++){
                scanf("%d",&map[i][j]);
            }
        }
        for(int j=1; j<=n; j++){
            for(int i=1; i<=2; i++){
                if(i==1){
                    dp[i][j]=max(dp[i][j-2],max(dp[i+1][j-2],dp[i+1][j-1]))+map[i][j];
                    ans=max(ans,dp[i][j]);

                }
                else{
                    dp[i][j]=max(dp[i][j-2],max(dp[i-1][j-2],dp[i-1][j-1]))+map[i][j];
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        printf("%d\n",ans);
    }
}

