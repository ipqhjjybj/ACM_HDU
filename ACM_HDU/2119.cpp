//
//  2119.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-2.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N=111;
int g[N][N];
int visit[N],pre[N];
int n,m;
bool find(int u){
    for(int i=1;i<=m;i++){
        if(g[u][i]&&!visit[i]){
            visit[i]=1;
            if(pre[i]==-1||find(pre[i])){
                pre[i]=u;
                return true;
            }
        }
    }
    return false;
}
int Maxmatch(){
    int ans=0;
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=n;i++){
        memset(visit,0,sizeof(visit));
        ans+=find(i);
    }
    return ans;
}
int main(){
    while(scanf("%d",&n)&&n){
        
        scanf("%d",&m);
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&g[i][j]);
        printf("%d\n",Maxmatch());
    }
    return 0;
}
*/