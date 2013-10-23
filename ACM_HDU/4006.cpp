//
//  4006.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-25.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include <cstdio>
#include <cstdlib>

#define ls p[t].l
#define rs p[t].r
#define rrs p[p[t].r].r
#define lls p[p[t].l].l
#define rls p[p[t].r].l
#define lrs p[p[t].l].r
const int N=1111111;
struct BST{
    int l,r,size,key;
    void clear(){
        l=r=0;
        size=1;
    }
}p[N];
int tot;
void l_rotate(int &t){
    int k=rs;
    rs=p[k].l;
    p[k].l=t;
    p[k].size=p[t].size;
    p[t].size=p[ls].size+p[rs].size+1;
    t=k;
}
void r_rotate(int &t){
    int k=ls;
    ls=p[k].r;
    p[k].r=t;
    p[k].size=p[t].size;
    p[t].size = p[ls].size + p[rs].size + 1;
    t=k;
}
void maintain(int &t,bool flag){
    if(flag){
        if(p[lls].size>p[rs].size){
            r_rotate(t);
        }else if(p[lrs].size>p[rs].size){
            l_rotate(ls);
            r_rotate(t);
        }else return;
    }else{
        if(p[rrs].size>p[ls].size){
            l_rotate(t);
        }else if(p[rls].size>p[ls].size){
            r_rotate(rs);
            l_rotate(t);
        }else return;
    }
    maintain(ls,true);
    maintain(rs,false);
    maintain(t,false);
    maintain(t,true);
}
void insert(int &t,int val){
    if(!t){
        t=++tot;
        p[t].clear();
        p[t].key=val;
    }
    else{
        p[t].size++;
        if(p[t].key>val){
            insert(ls,val);
        }else{
            insert(rs,val);
        }
        maintain(t,p[t].key>val);
    }
}
int get_MAX_k(int t,int k){
    int x=p[rs].size+1;
    if(x==k) return p[t].key;
    else if(x>k){
        return get_MAX_k(rs,k);
    }else{
        return get_MAX_k(ls,k-x);
    }
}
int main(){
    int n,k,num;
    char opt[10];
    int root;
    while(scanf("%d %d",&n,&k)!=EOF){
        root=tot=0;
        while(n--){
            scanf("%s",opt);
            if(opt[0]=='I'){
                scanf("%d",&num);
                insert(root,num);
            }else{
                printf("%d\n",get_MAX_k(root, k));
            }
        }
    }
    return 0;
}
*/