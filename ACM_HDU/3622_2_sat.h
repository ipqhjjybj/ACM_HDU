//
//  3622.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-3.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define pow(x) ((x)*(x))
using namespace std;

const int N=3333;
const int M=111111;
int n;
bool flag;
double di[N][N];
const double eps=1e-6;
struct node{
    int to,next;
}Edge[M];
struct POINT{
    int x,y;
}p[N];
int cnt,tot,sig,dfn[N],low[N],id[N],head[N],sta[N],sa;
void addEdge(int u,int v){
    Edge[cnt].to=v;
    Edge[cnt].next=head[u];
    head[u]=cnt++;
}
double dist(int i,int j){
    return sqrt(pow(p[i].x-p[j].x)*1.0+pow(p[i].y-p[j].y));
}
void dfs(int u){
    int tmp=dfn[u]=low[u]=sig++;
    sta[sa++]=u;
    for(int q=head[u];q!=-1;q=Edge[q].next){
        int v=Edge[q].to;
        if(dfn[v]==-1) dfs(v);
        tmp=min(tmp,low[v]);
    }
    if(tmp<low[u]){
        low[u]=tmp;
        return ;
    }
    int t;
    do{
        id[ t=sta[--sa]] = tot;
        low[t]=n<<1;
    }while(t!=u);
    tot++;
}
void tarjan(){
    memset(dfn,-1,sizeof(dfn));
    sa=sig=tot=0;
    for (int i=0; i<(n<<1);i++ ) {
        if(dfn[i]==-1)
            dfs(i);
    }
    for(int i=0;i<n;i++){
        if(id[i]==id[n+i]){
            flag=false;
            return;
        }
    }
}
void check(double mid){
    int ii,jj;
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=0;i<(n<<1);i++){
        for(int j=i+1;j<(n<<1);j++){
            if(i==j||abs(i-j)==n)continue;
            if(mid*2>di[i][j]){
                if(i>=n)ii=i-n;
                else ii=i+n;
                if(j>=n)jj=j-n;
                else jj=j+n;
                addEdge(j,ii);
                addEdge(i,jj);
            }
            
        }
    }
  //  printf("tarjan mid=%.2lf\n",mid);
    tarjan();
}
void solve(){
    double left=0x3f3f3f3f,right=0;
    for(int i=0;i<(n<<1);i++){
        for(int j=i+1;j<(n<<1);j++){
            di[j][i]=di[i][j]=dist(i,j);
            right=max(right,di[i][j]);
            left=min(left,di[i][j]);
        }
    }
    left/=2.0;
    right/=2.0;
    double mid;
    while(left+eps<right){
        mid=(left+right)/2.0;
        flag=true;
        check(mid);
        if(flag){
            left=mid+eps;
        }else{
            right=mid-eps;
        }
    }
    printf("%.2lf\n",left);
}
int main(){
    
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d %d %d %d",&p[i].x,&p[i].y,&p[i+n].x,&p[i+n].y);
        }
        solve();
    }
    return 0;
}