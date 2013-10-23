//
//  1185.cpp
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
int dp[111][111][111];
int cnt[111];
int state[111],top,num[111];
char s[110][40];
int n,m;

void init(int n){
    top=0;
    int total=1<<n;
    for(int i=0;i<total;i++)
        if(!(i&i<<1||i&i<<2))
            state[top++]=i;
}
bool fit(int i,int st){
    if(cnt[i]&st)return false;
    else return true;
}
int jcount(int x){
    int cnt=0;
    while(x){
        cnt++;
        x&=(x-1);
    }
    return cnt;
}
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        if(!n&&!m) break;   
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++){
            cnt[i]=0;
            for(int j=1;j<=m;j++)
                if(s[i][j]=='H') cnt[i]+=1<<(j-1);
        }
        init(m);
        clr(dp,-1);
        for(int i=0;i<top;i++){
            num[i]=jcount(state[i]);
            if(fit(1,state[i]))
                dp[1][0][i]=num[i];
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<top;j++){
                if(!fit(i,state[j])) continue;
                for(int k=0;k<top;k++){
                    if(!fit(i-1, state[k])) continue;
                    if(state[j]&state[k]) continue;
                    for(int z=0;z<top;z++){
                        if(i>2&&!fit(i-2,state[z])) continue;
                        if(state[z]&state[j]) continue;
                        if(dp[i-1][z][k]==-1) continue;
                        dp[i][k][j]=max(dp[i][k][j],dp[i-1][z][k]+num[j]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<top;j++)
                for(int k=0;k<top;k++)
                    ans=max(ans,dp[i][j][k]);
        printf("%d\n",ans);
    }
    return 0;
}
*/