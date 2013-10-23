//
//  4700.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-24.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=111;
#define MAX_INT 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define foreach(it,v) for(vi::iterator it=v.begin();it!=v.end();it++)
int flow[N][N];
int graph[N][N];
bool check(vi v0){
    if(v0.size()<=1) return true;
    int bridge=MAX_INT;
    foreach(u,v0)
        foreach(v,v0){
            bridge=min(bridge,flow[*u][*v]);
        }
    vi v1,v2;
    int u0=v0.front();
    foreach(v,v0){
        if(flow[*v][u0]>bridge)
            v2.pb(*v);
        else v1.pb(*v);
    }
    if(v1.empty()||v2.empty())
        return false;
    graph[v1.front()][v2.front()]=graph[v2.front()][v1.front()]=bridge;
    foreach(u,v1)
        foreach(v,v2)
            if(flow[*u][*v]>bridge)
                return false;
    return check(v1)&check(v2);
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&flow[i][j]);
                if(i==j)
                    flow[i][j]=MAX_INT;
            }
        }
        vi v;
        for(int i=1;i<=n;i++)
            v.pb(i);
        memset(graph,0,sizeof(graph));
        for(int i=1;i<=n;i++)
            graph[i][i]=-1;
        if(check(v)){
            printf("YES\n");
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    printf("%d%c",graph[i][j],j==n?'\n':' ');
                }
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
*/