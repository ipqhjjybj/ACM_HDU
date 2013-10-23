//
//  stlSet.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-31.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <queue>
using namespace std;
char s[10];
struct node{
    int a;
    int  operator () (node &tmp){
        return a<tmp.a;
    };
    node(){};
    node(int _a){
        a=_a;
    };
};
priority_queue< node , vector<node>,less<node> > DDD;

int main(){
    set<int> Q;
    int a;
    
    DDD.push(node(3));
    while(scanf("%s",s)!=EOF){
        if(s[0]=='I'){
            scanf("%d",&a);
            Q.insert(a);
        }else{
            scanf("%d",&a);
            set<int>::iterator it=Q.find(a);
            printf("it=%d\n",*it);
        }
    }
    return 0;
}
*/