//
//  4217.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-8.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define lowbit(x) (x&(-x))
const int MAXN=333333;
int n,k;
int a[MAXN];
#define LL __int64

void Update(int pos){
    while(pos<=n){
        a[pos]--;
        pos+=lowbit(pos);
    }
}
int Query(int pos){
    int sum=0;
    while(pos>0){
        sum+=a[pos];
        pos-=lowbit(pos);
    }
    return sum;
}
int Bisearch(int k){
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(Query(mid)>=k)
            r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    int t,tmp,tt=0;
    LL sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        sum=0;
        for(int i=0;i<=n;i++)
            a[i]=lowbit(i);
        while(k--){
            scanf("%d",&tmp);
            tmp=Bisearch(tmp);
            Update(tmp);
            sum+=tmp;
        }
        cout<<"Case "<<++tt<<": "<<sum<<endl;
        //printf("Case %d: %lld\n",++tt,sum);
    }
    return 0;
}