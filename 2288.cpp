//
//  2288.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-22.
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
int n,m;
int a[20];
int g[20][20];
int dp[1<<14][14];
int cnt[1<<14][14];
int tot1;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        clr(dp,-1);
        clr(cnt,0);
        clr(g,-1);
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        tot1=0;
        for(int i=1;i<=n;i++)
            tot1+=a[i];
        for(int i=0,u,v;i<m;i++){
            scanf("%d %d",&u,&v);
            g[u][v]=g[v][u]=a[u]*a[v];
        }

        for(int i=1;i<=n;i++){
            dp[1<<(i-1)][i]=0;
            cnt[1<<(i-1)][i]=1;
        }
        for(int s=1;s<(1<<n);s++){
            for(int i=1;i<=n;i++){
                if(s&(1<<(i-1))){
                    for(int j=1;j<=n;j++){
                        if(!(s&(1<<j-1)) && g[i][j]!=-1){
                            int tot23=g[i][j];
                            for(int k=1;k<=n;k++){
                                if(k==i) continue;
                                if(g[i][k]!=-1){
                                    tot23+=a[i]*a[j]*a[k];
                                }
                            }
                            int newS=s^(1<<(j-1));

                        }
                    }
                }
            }
        }
        
    }
    return 0;
}
*/