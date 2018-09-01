#include<stdio.h>
int arr[10];
int ck[10];
 int n;
void back(int a){
    if(a==n){
        for(int i=0; i<n; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1; i<=n; i++){
        if(ck[i]==0){
            arr[a]=i;
            ck[i]=1;
            back(a+1);
            ck[i]=0;
            arr[a]=0;
        }
    }
}
int main(){
   
    scanf("%d",&n);
    back(0);
    
}

