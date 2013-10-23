//
//  3790.h
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-6.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#ifndef __ACM_HDU___790__
#define __ACM_HDU___790__

/*
 #include <iostream>
 #include <map>
 #include <cstdio>
 #include <cstdlib>
 #include <algorithm>
 #include <vector>
 #include <queue>
 #include <cstring>
 template <class T>
 inline void scan_d(T &ret) {
 char c; ret=0;
 while((c=getchar())<'0'||c>'9');
 while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
 }
 using namespace std;
 const int maxn=1111;
 int visit[maxn][maxn];
 int g[maxn][maxn];
 int d[maxn],f[maxn];
 int cost[maxn][maxn];
 vector<int> Map[maxn];
 const int inf=1<<29;
 int s,t,n,m;
 bool vis[maxn];
 void dfs(int u){
 queue<int> Q;
 memset(visit,false,sizeof(visit));
 for(int i=1;i<=n;i++)
 d[i]=f[i]=inf;
 Q.push(u);
 d[u]=f[u]=0;
 vis[u]=true;
 while(!Q.empty()){
 int u=Q.front();
 Q.pop();
 for(int j=0;j<Map[u].size();j++){
 int v=Map[u][j];
 if(d[u]+g[u][v]<d[v]||(d[u]+g[u][v]==d[v]&&f[u]+cost[u][v]>f[v])){
 d[v]=d[u]+g[u][v];
 f[v]=f[u]+cost[u][v];
 if(!vis[v]){
 Q.push(v);
 vis[v]=true;
 }
 }
 }
 vis[u]=false;
 }
 printf("%d %d\n",d[t],f[t]);
 }
 int main(){
 //  freopen("3790.in","r",stdin);
 while(scanf("%d %d",&n,&m)!=EOF&&n+m){
 memset(visit,0,sizeof(visit));
 memset(cost,-1,sizeof(cost));
 memset(g,-1,sizeof(g));
 for(int i=0,a,b,c,d;i<m;i++){
 scan_d(a),scan_d(b),scan_d(c),scan_d(d);
 if(!visit[a][b]){
 visit[a][b]=1;
 Map[a].push_back(b);
 g[a][b]=c;
 cost[a][b]=d;
 }else{
 if(g[a][b]<c||g[a][b]==c&&cost[a][b]>d){
 g[a][b]=c;
 cost[a][b]=d;
 }
 }
 }
 scanf("%d %d",&s,&t);
 dfs(s);
 
 }
 return 0;
 }
 */
#endif /* defined(__ACM_HDU___790__) */
