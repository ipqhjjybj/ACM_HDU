//
//  4421.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-3.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n;
const int N=1111;
const int M=633333;
int b[N][N];
int bitm;
bool flag;
int tmp;
int head[N<<1];
struct node{
    int to,next;
}Edge[M];
int cnt,tot,sig,sa;
int dfn[N<<1],low[N<<1],id[N<<1],sta[N<<1];
void dfs(int u){
    int tmp=low[u]=dfn[u]=sig++;
    sta[sa++]=u;
    for(int q=head[u];q!=-1;q=Edge[q].next){
        int v=Edge[q].to;
        if(dfn[v]==-1) dfs(v);
        tmp=min(tmp,low[v]);
    }
    if(tmp<low[u]){
        low[u]=tmp;
        return;
    }int t;
    do{
        id[t=sta[--sa]]=tot;
        low[t]=n<<1;
    }while(t!=u);
    tot++;
}
bool check(){
    memset(dfn,-1,sizeof(dfn));
    tot=sig=sa=0;
    for(int i=0;i<(n<<1);i++){
        if(dfn[i]==-1){
            dfs(i);
        }
    }
    for(int i=0;i<n;i++){
        if(id[i<<1]==id[i<<1|1]){
            flag=false;
            return false;
        }
    }
    return true;
}
void addEdge(int u,int v){
    Edge[cnt].to=v;
    Edge[cnt].next=head[u];
    head[u]=cnt++;
}
void solve(){
    for(bitm=0;bitm<32;bitm++){
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tmp=b[i][j]&(1<<bitm);
                //printf("b[%d][%d]=%d bitm=%d tmp=%d\n",i,j,b[i][j],bitm,tmp);
                if(i==j){
                    if(tmp){
                        flag=false;
                        return;
                    }
                }
                else if(i%2==1&&j%2==1){ // ｜
                    if(tmp){ //i是0时，j必须是1，同理，j==0时,i==1
                        addEdge(i<<1,j<<1|1);
                        addEdge(j<<1,i<<1|1);
                        
                    }else{// i跟j只能是0
                        addEdge(i<<1|1,i<<1);
                        addEdge(j<<1|1,j<<1);
                        
                    }
                }else if(i%2==0&&j%2==0){ // &
                    if(tmp){//  i跟j只能是1
                        addEdge(i<<1,i<<1|1);
                        addEdge(j<<1,j<<1|1);
                    }else{// i是1时,j==0    j==1时,i==0
                        addEdge(i<<1|1,j<<1);
                        addEdge(j<<1|1,i<<1);
                    }
                }else{      // ^ 
                    if(tmp){ //i跟j一个为1，一个为0
                        addEdge(i<<1,j<<1|1);
                        addEdge(i<<1|1,j<<1);
                        addEdge(j<<1,i<<1|1);
                        addEdge(j<<1|1,i<<1);
                    }else{ //i跟j同时为1或者0
                        addEdge(i<<1,j<<1);
                        addEdge(j<<1,i<<1);
                        addEdge(i<<1|1,j<<1|1);
                        addEdge(j<<1|1,i<<1|1);
                    }
                }
            }
        }
        if(!check()){
            flag=false;
            return;
        }
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        flag=true;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                scanf("%d",&b[i][j]);
                if(i==j&&b[i][j])
                    flag=false;
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(b[i][j]!=b[j][i])
                    flag=false;
        if(!flag){
            printf("NO");
            continue;
        }
        solve();
        if(flag)printf("YES");
        else printf("NO");
    }
    return 0;
}