//
//  1890.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-27.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
struct SplayTree{
    const static int maxn=111111;
    int n,tot,root;
    map<int,int> Map;
    int child[maxn][2];
    int pre[maxn],size[maxn],flex[maxn];
    int id[maxn];
    struct node{
        int id,val;
        bool operator < (const node & tmp) const{
            return val<tmp.val||(val==tmp.val&&id<tmp.id);
        }
    }in[maxn];
    void Pushup(int &x){
        size[x]=size[child[x][0]]+size[child[x][1]]+1;
    }
    void Pushdown(int &x){
        if(flex[x]){
            flex[x]=0;
            flex[child[x][0]]^=1;
            flex[child[x][1]]^=1;
            swap(child[x][0],child[x][1]);
        }
    }
    void Del_root(){
        int t=root;
        if(child[root][1]){
            root=child[root][1];
            Select(1,0);
            child[root][0]=child[t][0];
            if(child[t][0]) pre[child[t][0]]=root;
        }else
            root=child[root][0];
        pre[root]=0;
        Pushup(root);
    }
    // c==0  左旋 ,  c==1 右旋
    void Rotate(int x,int c){
        int k=pre[x];
        Pushdown(k);
        Pushdown(x);
        child[k][!c]=child[x][c];
        
        if(child[x][c]) pre[child[x][c]]=k;
        pre[x]=pre[k];
        if(pre[k]) child[pre[k]][child[pre[k]][1]==k]=x;
        pre[k]=x;
        child[x][c]=k;
        Pushup(k);
    }
    void Splay(int x,int f){
        puts("fuck Splay");
        Pushdown(x);
        while(pre[x]!=f){
            printf("f=%d pre[%d]=%d\n",f,x,pre[x]);
            int y=pre[x],z=pre[pre[x]];
            Pushdown(z),Pushdown(y),Pushdown(x);
            if(pre[pre[x]]==f){
                Rotate(x,child[pre[x]][0]==x);
            }else{
                if ( child[z][0] == y ) {
                    if ( child[y][0] == x )
                        Rotate(y, 1), Rotate(x, 1);
                    else
                        Rotate(x, 0), Rotate(x, 1);
                }
                else {
                    if ( child[y][0] == x )
                        Rotate(x, 1), Rotate(x, 0);
                    else
                        Rotate(y, 0), Rotate(x, 0);
                }
            }
        }
        Pushup(x);
        if(f==0) root=x;
    }
    void Select(int k,int f){
        puts("fuck select");
        int x=root;
        while(1){
            Pushdown(x);
            if(k==size[child[x][0]]+1)
                break;
            if(k<=size[child[x][0]])
                x=child[x][0];
            else{
                k-=size[child[x][0]]+1;
                x=child[x][1];
            }
        }
        Splay(x,f);
    }
    void Newnode(int &x,int f){
        puts("fuck newnode");
        x=++tot;
        child[x][0]=child[x][1]=0;
        pre[x]=f;
        flex[x]=0;
        size[x]=1;
    }
    void Build(int &x,int l,int r,int f){
        if(l>r)return;
        int mid=(l+r)>>1;
        puts("Fuck(Build)");
        Newnode(x,f);
        Map[id[mid]]=x;
        Build(child[x][0],l,mid-1,x);
        Build(child[x][1],mid+1,r,x);
        Pushup(x);
    }
    void init(int _n){
        n=_n; Map.clear(); root=tot=0;
        pre[0]=child[0][0]=child[0][1]=0;
        size[0]=flex[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&in[i].val);
            in[i].id=i;
        }
        sort(in+1,in+1+n);
        for(int i=1;i<=n;i++)
            id[in[i].id]=i;
        Map[id[1]]=1;
        Map[id[n]]=2;
        Newnode(root,0);
        Newnode(child[root][1],root);
        Build(child[child[root][1]][0],2,n-1,child[root][1]);
        Pushup(child[root][1]);
        Pushup(root);
    }
    void solve(int _n){
        for(int i=1;i<=n;i++){
            printf("i=%d\n",i);
            printf("Map[%d]=%d\n",i,Map[i]);
            Splay(Map[i],0);
            printf("root=%d\n",root);
            printf("%d%c",i+size[child[root][0]],i==n?'\n':' ');
            flex[child[root][0]]^=1;
            Del_root();
        }
    }
}spt;
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        spt.init(n);
        spt.solve(n);
    }
    return 0;
}
*/