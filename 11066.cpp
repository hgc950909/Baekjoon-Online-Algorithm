#include<stdio.h>
int arr[505];
int dp[505][505];
int sum[505];
int min(int a,int b){
    if(a<b)return a;
    else return b;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int qw;
       
        scanf("%d",&qw);
        for(int i=1; i<=qw; i++){
            scanf("%d",&arr[i]);
        }
        for(int i=1; i<=qw; i++){
            for(int j=1; j<=i; j++){
                sum[i]=0;
            }
            
        }
        for(int i=1; i<=qw; i++){
            for(int j=1; j<=i; j++){
                sum[i]=sum[i]+arr[j];
            }
            
        }
        for(int i=1; i<=qw; i++){
            for(int j=1; j<=qw; j++){
                dp[i][j]=0;
            }
        }
        for(int j=2; j<=qw; j++){
            for(int i=j-1; i>=1; i--){
                for(int k=i; k<=j-1; k++){
                    if(dp[i][j]==0){
                        dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                    }
                    else{
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
                    }
                }
            }
        }
        printf("%d\n",dp[1][qw]);
    }
}

