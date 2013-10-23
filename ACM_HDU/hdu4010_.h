//
//  hdu4010.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-11.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 333333
using namespace std;
int n,head[MAXN],cnt;
int pre[MAXN],ch[MAXN][2],add[MAXN],rev[MAXN],Max[MAXN],key[MAXN];
bool rt[MAXN];
int max(int a,int b){
    if(a>b)return a;
    else return b;
}
struct node{
    int to,next;
}Edge[MAXN<<1];
void addEdge(int u,int v){
    Edge[cnt].to=v;
    Edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u){
    for(int q=head[u];q!=-1;q=Edge[q].next){
        int v=Edge[q].to;
        if(pre[v]!=0)continue;
        pre[v]=u;
        dfs(v);
    }
}
void Update_add(int u,int w){
    if(!u)return;
    key[u]+=w;
    add[u]+=w;
    Max[u]+=w;
}
void Update_rev(int u){
    if(!u)return;
    swap(ch[u][1],ch[u][0]);
    rev[u]^=1;
}
void PushUp(int u){
    Max[u]=max(max(Max[ch[u][0]],Max[ch[u][1]]),key[u]);
}
void PushDown(int u){
    if(add[u]){
        Update_add(ch[u][0], add[u]);
        Update_add(ch[u][1],add[u]);
        add[u]=0;
    }
    if(rev[u]){
        Update_rev(ch[u][0]);
        Update_rev(ch[u][1]);
        rev[u]=0;
    }
}
void Rotate(int x){
    int y=pre[x];int kind=(ch[y][1]==x);
    ch[y][kind]=ch[x][!kind];
    pre[ch[y][kind]]=y;
    pre[x]=pre[y];
    pre[y]=x;
    ch[x][!kind]=y;
    if(rt[y])
        rt[y]=false,rt[x]=true;
    else ch[pre[x]][ch[pre[x]][1]==y]=x;
    PushUp(y);
}
void P(int u){
    if(!rt[u]) P(pre[u]);
    PushDown(u);
}
void Splay(int u){
    P(u);
    while(!rt[u]){
        int f=pre[u],ff=pre[f];
        if(rt[f])
            Rotate(u);
        else{
            if((ch[ff][1]==f)==(ch[f][1]==u))
                Rotate(f),Rotate(u);
            else Rotate(u),Rotate(u);
        }
    }
    PushUp(u);
}
int Access(int u){
    int f;
    for(f=0;u;u=pre[f=u]){
        Splay(u);
        rt[ch[u][1]]=true,rt[ch[u][1]=f]=false;
        PushUp(u);
    }
    return f;
}
bool judge(int u,int v){
    while(pre[u])u=pre[u];
    while(pre[v])v=pre[v];
    return u==v;
}
void mroot(int u){
    Access(u);
    Splay(u);
    Update_rev(u);
}
void lca(int &u,int &v){
    Access(v);
    for(v=0;u;u=pre[v=u]){
        Splay(u);
        if(pre[u]==0)return;
        rt[ch[u][1]]=true,rt[ch[u][1]=v]=false;
        PushUp(u);
    }
}
void Link(int u,int v){
    if(judge(u,v)){
        puts("-1");
        return;
    }
    mroot(u);
    pre[u]=v;
}
void Add(int u,int v,int w){
    if(!judge(u,v)){
        puts("-1");
        return;
    }
    lca(u,v);
    Update_add(ch[u][1], w);
    Update_add(v,w);
    key[u]+=w;
    PushUp(u);
}
void Cut(int u,int v){
    if(u==v||!judge(u,v)){
        puts("-1");
        return;
    }
    mroot(u);
    Splay(v);
    pre[ch[v][0]]=pre[v];
    pre[v]=0;
    rt[ch[v][0]]=true;
    ch[v][0]=0;
    PushUp(v);
}
void Query(int u,int v){
    if(!judge(u, v)){
        puts("-1");
        return;
    }
    lca(u,v);
    printf("%d\n",max(max(Max[ch[u][1]],Max[v]),key[u]));
}
int main(){
    int q,cmd,a,b,c;
    while(scanf("%d",&n)!=EOF){
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=1,u,v;i<n;i++){
            scanf("%d %d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        for(int i=1;i<=n;i++)
            scanf("%d",key+i);
        key[0]=0;
        for(int i=0;i<=n;i++){
            ch[i][0]=ch[i][1]=pre[i]=rev[i]=add[i]=0;
            Max[i]=key[i];
            rt[i]=true;
        }
        Max[0]=-122222;
        pre[1]=-1;
        dfs(1);
        pre[1]=0;
        scanf("%d",&q);
        while(q--){
            scanf("%d",&cmd);
            if(cmd==1){
                scanf("%d %d",&a,&b);
                Link(a,b);
            }else if(cmd==2){
                scanf("%d %d",&a,&b);
                Cut(a,b);
            }else if(cmd==3){
                scanf("%d %d %d",&a,&b,&c);
                Add(b,c,a);
            }else{
                scanf("%d %d",&a,&b);
                Query(a,b);
            }
            //printf("q=%d a=%d b=%d\n",q,a,b);
        }
        printf("\n");
    }
    return 0;
}