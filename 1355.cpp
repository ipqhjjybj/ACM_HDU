//
//  1355.cpp
//  ACM_NEU
//
//  Created by 沈卓亨 on 13-8-19.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=4111;
const int M=2111111;
int dfn[N],low[N],id[N],head[N],stack[N];
struct node{
    int v,next;
}Edge[M];
int cnt,tcc,sig,sa;
void addEdge(int u,int v){
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
    char s[10];
    while(scanf("%d %d",&n,&m)!=EOF){
        memset(head,-1, sizeof(head));
        cnt=sig=tcc=sa=0;
        for(int j=0,a,b,c;j<m;j++){
            scanf("%d %d %d %s",&a,&b,&c,s);
            switch(s[0]){
                    case 'A':
                        if(c==1){
                            addEdge(a<<1,a<<1|1);
                            addEdge(b<<1,b<<1|1);
                        }else{
                            addEdge(a<<1|1,b<<1);
                            addEdge(b<<1|1,a<<1);
                        }
                    break;
                    case 'O':
                        if(c==1){
                            addEdge(a<<1,b<<1|1);
                            addEdge(b<<1,a<<1|1);
                        }else{
                            addEdge(a<<1|1,a<<1);
                            addEdge(b<<1|1,b<<1);
                        }
                    break;
                    case 'X':
                        if(c==1){
                            addEdge(a<<1,b<<1|1);
                            addEdge(a<<1|1,b<<1);
                            addEdge(b<<1,a<<1|1);
                            addEdge(b<<1|1,a<<1);
                        }else{
                            addEdge(a<<1,b<<1);
                            addEdge(a<<1|1,b<<1|1);
                            addEdge(b<<1,a<<1);
                            addEdge(b<<1|1,a<<1|1);
                        }
                    break;
            }
        }
        memset(dfn,-1,sizeof(dfn));
        int z=n<<1;
        for(int i=0;i<z;i++)
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