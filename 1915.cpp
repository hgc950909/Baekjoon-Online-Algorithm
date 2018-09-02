#include<stdio.h>
int map[1005][1005];
int dp[1005][1005];
int min(int a,int b){
    if(a<b)return a;
    else return b;
}

int main(){
    int n,m;
    int ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d",&map[i][j]);
         
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j]==1){
            dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                if(ans<dp[i][j]){
                    ans=dp[i][j];
                }
            }
        }
    }
    printf("%d",ans*ans);
}

