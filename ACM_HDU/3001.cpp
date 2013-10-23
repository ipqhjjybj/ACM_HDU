//
//  3001.cpp
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
const int N=111;
int tri[12] ={0,1,3,9,27,81,243,729,2187,6561,19683,59049};
int dp[60000][13];
int dir[60000][13];
int g[111][111];
int main(){
    int n,m;
    for(int i=0;i<60000;i++){
        int t=i;
        for(int j=1;t;j++){
            dir[i][j]=t%3;
            t/=3;
        }
    }
    while(scanf("%d %d",&n,&m)!=EOF){
        clr(g,0x3f);
        for(int i=0,a,b,c;i<m;i++){
            scanf("%d %d %d",&a,&b,&c);
            if(c<g[a][b]) g[a][b]=g[b][a]=c;
        }
        clr(dp,0x3f);
        for(int i=1;i<=n;i++)
            dp[tri[i]][i]=0;
        int ans=inf;
        for(int s=0;s<tri[n+1];s++){
            int visit_all=1;
            for(int i=1;i<=n;i++){
                if(dir[s][i]==0) visit_all=0;
                if(dp[s][i]==inf) continue;
                for(int j=1;j<=n;j++){
                    if(i==j) continue;
                    if(g[i][j]==inf||dir[s][j]>=2) continue;
                    int news=s+tri[j];
                    dp[news][j] = min(dp[news][j],dp[s][i]+g[i][j]);
                }
            }
            if(visit_all){
                for(int i=1;i<=n;i++)
                    ans=min(ans,dp[s][i]);
            }
        }
        if(ans==inf){
            puts("-1");
            continue;
        }else{
            printf("%d\n",ans);
        }
    }
    return 0;
}
*/