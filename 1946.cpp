#include<stdio.h>
#include<algorithm>
using namespace std;
struct person{
    int paper;
    int interview;
}per[100005];

int sortpap(person a,person b){
    if(a.paper < b.paper)return 1;
    else return 0;
}

int sortint(person a,person b){
    if(a.interview < b.interview)return 1;
    else return 0;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int ans=n;
        for(int i=0; i<n; i++){
            scanf("%d %d",&per[i].paper,&per[i].interview);
        }
        sort(per,per+n,sortpap);
        for(int i=n-1; i>0; i--){
            for(int j=i-1; j>=0; j--){
                if(per[i].interview >per[j].interview){
                    
                    ans--;
                    break;
                }
            }
        }

        printf("%d\n",ans);
        
    }
    return 0;
}


