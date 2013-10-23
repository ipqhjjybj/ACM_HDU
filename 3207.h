//
//  3207.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-3.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=2111;
const int M=322222;
int n,m;
struct node{
    int to,next;
}Edge[M];
int head[N],cnt,tot,sig,sa;
int low[N],dfn[N],sta[N],id[N];
int e[M][2];
void addEdge(int u,int v){
    Edge[cnt].to=v;
    Edge[cnt].next=head[u];
    head[u]=cnt++;
}
void tarjan(int u){
    int tmp=low[u]=dfn[u]=sig++;
    sta[sa++]=u;
    for(int q=head[u];q!=-1;q=Edge[q].next){
        int v=Edge[q].to;
        if(dfn[v]==-1){
            tarjan(v);
        }tmp=min(tmp,low[v]);
    }
    if(tmp<low[u]){
        low[u]=tmp;
        return;
    }
    int t;
    do{
        low[t=sta[--sa]]=n;
        id[t]=tot;
    }while(t!=u);
    
    tot++;
}
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=0;i<m;i++){
            scanf("%d %d",&e[i][0],&e[i][1]);
            if(e[i][0]>e[i][1])
                swap(e[i][0],e[i][1]);
        }
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                if((e[i][0]>e[j][0]&&e[i][0]<e[j][1]&&e[i][1]>e[j][1])
                   ||(e[j][0]>e[i][0]&&e[j][0]<e[i][1]&&e[j][1]>e[i][1])){
                    addEdge(i<<1|1,j<<1);
                    addEdge(j<<1|1,i<<1);
                    addEdge(i<<1,j<<1|1);
                    addEdge(j<<1,i<<1|1);
                }
            }
        }
        
        memset(dfn,-1,sizeof(dfn));
        tot=sa=sig=0;
        for(int i=0;i<(m<<1);i++){
            if(dfn[i]==-1)
                tarjan(i);
        }
        bool flag=true;
        for(int i=0;i<m;i++){
            if(id[i<<1]==id[i<<1|1]){
                flag=false;
                break;
            }
        }
        if(flag)puts("panda is telling the truth...");
        else puts("the evil panda is lying again");
    }
    return 0;
}