#include<stdio.h>
char arr[22][22];
int max;
  int r,c;
int ck1[22][22];
int ck2[28];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void back(int x,int y, int ans){
    if(max< ans){
        max=ans;
    }
    for(int i=0; i<4; i++){
        if(x+dx[i]<c && x+dx[i]>=0 && y+dy[i]>=0 && y+dy[i]<r && ck2[arr[y+dy[i]][x+dx[i]]-'A'] == 0){
            ck2[arr[y+dy[i]][x+dx[i]]-'A']=1;
            back(x+dx[i],y+dy[i],ans+1);
            ck2[arr[y+dy[i]][x+dx[i]]-'A']=0;
        }
    }
}
int main(){
  
    scanf("%d%d",&r,&c);
    for(int i=0; i<r; i++){
        scanf("%s",arr[i]);
    }
    ck2[arr[0][0]-'A']=1;
    back(0,0,1);
    printf("%d",max);
}

