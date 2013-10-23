//
//  3311.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-21.
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
int dp[1<<12][12];
int dis[12][12];
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                scanf("%d",&dis[i][j]);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                for(int k=0;k<=n;k++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        clr(dp,0x3f);
        for(int s=0;s<(1<<n);s++){
            for(int i=1;i<=n;i++){
                if(s&(1<<(i-1))){
                    if(s==(1<<(i-1))){
                        dp[s][i]=dis[0][i];
                    }else{
                        for(int j=1;j<=n;j++){
                            if(i==j) continue;
                            if(s&(1<<(j-1))){
                                dp[s][i]=min(dp[s][i],dp[s^(1<<(i-1))][j]+dis[j][i]);
                            }
                        }
                    }
                }
            }
        }
        int ans=inf;
        for(int i=1;i<=n;i++){
            ans=min(ans,dp[(1<<n)-1][i]+dis[i][0]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/