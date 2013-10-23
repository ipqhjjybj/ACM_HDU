//
//  3062.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-19.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include <cstdio>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=2111;
const int M=1111*1111;
int dfn[N],low[N],id[N],head[N],stack[N];
struct node{
    int v,next;
}Edge[M];
int cnt,tcc,sig,sa;
void addEdge(int u,int v){
    //printf("u=%d v=%d\n",u,v);
    Edge[cnt].v=v;
    Edge[cnt].next=head[u];
    head[u]=cnt++;
}
int n,m;
void tarjan(int u){
    int t,minc=low[u]=dfn[u]=sig++;
    stack[sa++]=u;
    for(int p=head[u];p!=-1;p=Edge[p].next){
        int v=Edge[p].v;
        if(-1==dfn[v]) tarjan(v);
        minc=min(minc,low[v]);
    }
    if(minc<low[u]){
        low[u]=minc;return;
    }
    do{
        id[t=stack[--sa]] = tcc; low[t]=(n<<1);
    }while(t!=u);
    ++tcc;
}
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        memset(head,-1, sizeof(head));
        cnt=sig=tcc=sa=0;
        for(int i=0,a1,a2,c1,c2;i<m;i++){
            scanf("%d %d %d %d",&a1,&a2,&c1,&c2);
            addEdge((a1<<1)+c1,(a2<<1)+1-c2);
            addEdge((a2<<1)+c2,(a1<<1)+1-c1);
        }
        memset(dfn,-1,sizeof(dfn));
        for(int i=0;i<(n<<1);i++)
            if(dfn[i]==-1)
                tarjan(i);
        bool flag=false;
        for(int i=0;i<n;i++){
            if(id[i<<1]==id[i<<1|1]){
                flag=true;
                break;
            }
        }
        if(flag) puts("NO");
        else puts("YES");
    }
    return 0;
}
*/