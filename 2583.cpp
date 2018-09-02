#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int map[105][105];
int ck[105][105];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int sum[11000];
struct dot{
    int x;
    int y;
};
int ans;
int main(){
    int m,n,k,x,y,xx,yy;
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1; i<=k; i++){
        scanf("%d%d%d%d",&x,&y,&xx,&yy);
        for(int i=x; i<xx; i++){
            for(int j=y;j<yy; j++){
                map[j][i]=1;
                ck[j][i]=1;
            }
        }
    }
  
    
    queue<pair<int,int>>q;
    dot now;
   
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[j][i]==0 && ck[j][i]==0){
                ck[j][i]=1;
                q.push(make_pair(i,j));
                ans++;
                
                while(!q.empty()){
                    sum[ans]++;
                    now.x= q.front().first;
                    now.y=q.front().second;
                    q.pop();
                    for(int qq=0; qq<4; qq++){
                        if(now.x+dx[qq]>=0 && now.x+dx[qq]<n && now.y+dy[qq]>=0 && now.y+dy[qq]<m && ck[now.y+dy[qq]][now.x+dx[qq]]==0){
                            ck[now.y+dy[qq]][now.x+dx[qq]]=1;
                            q.push(make_pair(now.x+dx[qq],now.y+dy[qq]));
                        }
                    }
                }
                
            }
        }
    }
    printf("%d\n",ans);
    sort(sum+1,sum+ans+1);
    for(int i=1; i<=ans; i++){
        printf("%d ",sum[i]);
    }
}

