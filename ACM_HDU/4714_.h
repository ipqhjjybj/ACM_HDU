//
//  4714.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-8.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#pragma comment(linker,"/STACK:102400000,102400000")  
#include <cstdio>
#include <iostream>
using namespace std;
const int N=1111111;
int n;
struct node{
    int to,next;
}Edge[N<<1];
int head[N],cnt;
bool visit[N];
void addEdge(int u,int v){
    Edge[cnt].to=v;
    Edge[cnt].next=head[u];
    head[u]=cnt++;
}
int ans;
int dfs(int u){
    int sum=0;
    visit[u]=true;
    for(int q=head[u];q!=-1;q=Edge[q].next){
        if(!visit[Edge[q].to])
            sum+=dfs(Edge[q].to);
    }
    if(sum>1){
        if(u==1)
            ans+=(sum-2)*2;
        else ans+=(sum-1)*2;
        return 0;
    }
    return 1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cnt=0;
        memset(head,-1,sizeof(int)*(n+10));
        memset(visit,false,sizeof(false)*(n+10));
        for(int i=1,u,v;i<n;i++){
            scanf("%d %d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        ans=0;
        dfs(1);
        printf("%d\n",ans+1);
    }
    return 0;
}