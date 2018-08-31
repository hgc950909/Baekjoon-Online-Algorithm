#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[11];
int ans[10];
void back(int num, int sum,int st){
    if(num==7 && sum==100){
        for(int i=0; i<7;i++){
            printf("%d\n",ans[i]);
          
        }
          exit(0);
    }
    if(num==7){
        return;
    }
    for(int i=st; i<9; i++){
        if(sum+arr[i]<=100){
            ans[num]=arr[i];
            back(num+1,sum+arr[i],i+1);
            ans[num]=0;
        }
    }
}
int main(){
    for(int i=0; i<9; i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+9);
    back(0,0,0);
    return 0;
}

