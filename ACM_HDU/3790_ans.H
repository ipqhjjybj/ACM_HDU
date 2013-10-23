//
//  3790.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-6.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;

const int N=1111;
int g[1111][1111];
int f[1111][1111];
int dis[N];
int dif[N];
bool visit[N];
#define inf 0x3f3f3f3f
int n,m,s,t;
void disjact(int s){
    memset(visit,false,sizeof(visit));
    for(int i=1;i<=n;i++){
        dis[i]=g[s][i];
        dif[i]=f[s][i];
    }
    dis[s]=0;
    visit[s]=true;
    int tmp,v;
    for(int i=1;i<=n;i++){
        tmp=inf;
        for(int j=1;j<=n;j++)
            if(!visit[j]&&dis[j]<tmp)
                tmp=dis[j],v=j;
        visit[v]=true;
        for(int j=1;j<=n;j++){
            if(!visit[j]&&g[v][j]<inf&&(dis[j]>g[v][j]+dis[v]
                           ||(dis[j]==g[v][j]+dis[v]&&dif[v]+f[v][j]<dif[j]))){
                dis[j]=g[v][j]+dis[v];
                dif[j]=f[v][j]+dif[v];
            }
        }
    }
    printf("%d %d\n",dis[t],dif[t]);
}
int main(){
    int u,v,w,p;
    while(scanf("%d %d",&n,&m),n||m){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]=f[i][j]=inf;
        while(m--){
            scanf("%d %d %d %d",&u,&v,&w,&p);
            if(g[u][v]>w||(g[u][v]==w&&f[u][v]>p)){
                g[u][v]=g[v][u]=w;
                f[u][v]=f[v][u]=p;
            }
        }
        scanf("%d %d",&s,&t);
        disjact(s);
    }
}