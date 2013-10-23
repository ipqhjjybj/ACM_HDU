//
//  3254.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-20.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define clr(x,k) memset(x,k,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int MOD=1e9;
int dp[15][800];
int state[800],top;
int g[15][15];
int cnt[20];
bool fit(int u,int v){
    if(cnt[u]&v) return false;
    return true;
}
void init(int n){
    top=0;
    int total=1<<n;
    for(int i=0;i<total;i++)
        if(!(i&(i<<1)))
            state[top++]=i;
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            cnt[i]=0;
            for(int j=1;j<=m;j++){
                scanf("%d",&g[i][j]);
                if(!g[i][j]) cnt[i]+=1<<(j-1);
            }   
        }
        init(m);
        clr(dp,0);
        for(int i=0;i<top;i++)
            if(fit(1,state[i]))
                dp[1][i]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<top;j++){
                if(!fit(i,state[j])) continue;
                for(int k=0;k<top;k++){
                    if(!fit(i-1,state[k])||(state[j]&state[k])) continue;
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
                }
            }
        }
        int ans=0;
        for(int j=0;j<top;j++){
            ans=(ans+dp[n][j])%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/