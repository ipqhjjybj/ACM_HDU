//
//  4267.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-7.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include<cstdio>
#include <iostream>
#include <cstring>
#define lowbit(x) ((x)&(-x))

int a[50050][11][11];
int s[50050];
int n,q;
void Update(int mod,int k,int pos,int add){
    while(pos>0){
        a[pos][k][mod]+=add;
        pos-=lowbit(pos);
    }
}
int Query(int pos,int num){
    int i,sum=0;
    while(pos<=n){
        for(i=1;i<=10;i++)
            sum+=a[pos][i][num%i];
        pos+=lowbit(pos);
    }
    return sum;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            scanf("%d",s+i);
        scanf("%d",&q);
        int cas,a,b,k,c;
        while(q--){
            scanf("%d",&cas);
            switch(cas){
                case 2:
                    scanf("%d",&a);
                    printf("%d\n",Query(a,a)+s[a]);
                break;
                case 1:
                    scanf("%d %d %d %d",&a,&b,&k,&c);
                    Update(a%k,k,b,c);
                    Update(a%k,k,a-1,-c);
                break;
            }
        }
    }
    return 0;
}