//
//  4605.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-24.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define lowbit(x) (x&(-x))
#define vi vector<que>
#define foreach(it,v) for(vi::iterator it=v.begin();it!=v.end();it++)
const int N=211111;
int w[N];
struct node{
    int p,l,r;
}p[N];
struct que{
    int id,v;
    que(){};
    que(int _id,int _v){
        id=_id,v=_v;
    }
};
vi ib[N];
int wm[N<<1],cnt;
map<int,int> ma;
int sum[N][2]; // 0 存储的是往左的 存在的数， 1 存储的是往右的 存在的数
int ans[N][2];
int tot;
void add(int pos,int lr,int val){
    for( ; pos <= tot; pos+=lowbit(pos))
        sum[pos][lr]+=val;
}
int query(int pos,int lr){
    int ret=0;
    for(;pos>0;pos-=lowbit(pos))
        ret+=sum[pos][lr];
    return ret;
}
void dfs(int u){
    foreach(it,ib[u]){
        int v=ma[it->v];
        if(query(v-1,0)-query(v,0)||query(v-1,1)-query(v,1)){
                ans[it->id][0]=ans[it->id][1]=-1;
            
        }else{
                ans[it->id][0]=query(v-1,1);
                ans[it->id][1]=3*(query(v-1,0)+query(v-1,1))+query(tot,0)+query(tot,1)-query(v,0)-query(v,1);
            }
    }
    if(p[u].l!=-1){
    int v=ma[w[u]];
        add(v,0,1);
        dfs(p[u].l);
        add(v,0,-1);

    }
    if(p[u].r!=-1){
    int v=ma[w[u]];
        add(v,1,1);
        dfs(p[u].r);
    add(v,1,-1);
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    memset(p,-1,sizeof(p));
    memset(sum,0,sizeof(sum));
    ma.clear();
    for(int i=0;i<=n;i++)
        ib[i].clear();
    cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        wm[cnt++]=w[i];
    }
    int m;
    scanf("%d",&m);
    for(int i=0,u,v,par;i<m;i++){
        scanf("%d %d %d",&par,&u,&v);
        p[u].p=p[v].p=par;
        p[par].l=u,p[par].r=v;
    }
    int Q;
    scanf("%d",&Q);
    
    for(int i=1,v,x;i<=Q;i++){
        scanf("%d %d",&v,&x);
        ib[v].push_back(que(i,x));
        wm[cnt++]=x;
    }

    sort(wm,wm+cnt);

    tot=0;
    for(int i=0;i<cnt;i++)
        if(!ma[wm[i]])
            ma[wm[i]]=++tot;
    
    //int v=ma[w[1]];
    //add(v,0,1);
    //add(v,1,1);
    dfs(1);
    for(int i=1;i<=Q;i++){
        if(ans[i][0]==-1)
            puts("0");
        else{
            printf("%d %d\n",ans[i][0],ans[i][1]);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
*/