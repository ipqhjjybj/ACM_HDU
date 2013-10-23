//
//  4686.cpp
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
#include <iostream>
#define clr(x,k) memset(x,k,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
#define ll long long

const int MAXN=5;
const int MOD=1000000007;
struct node{
    ll a[MAXN][MAXN];
    void clear(){
        clr(a,0);
    }
}ans,t;
node multi(node c,node d){
    node tmp;
    for(int i=0;i<MAXN;i++){
        for(int j=0;j<MAXN;j++){
            tmp.a[i][j]=0;
            for(int k=0;k<MAXN;k++){
                tmp.a[i][j]+= c.a[i][k]*d.a[k][j] % MOD;
            }
            tmp.a[i][j]%=MOD;
        }
    }
    return tmp;
}
node pow(node X,node Y,ll d){
    while(d){
        if(d&1) X=multi(X,Y);
        d>>=1;
        Y=multi(Y,Y);
    }
    return X;
}

int main(){
    ll n,a0,ax,ay,b0,bx,by;
    while(cin>>n>>a0>>ax>>ay>>b0>>bx>>by){

        if(n<=0){
            cout<<"0"<<endl;
            continue;
        }
        ans.clear();
        t.clear();
        
        ans.a[0][0]=1,ans.a[0][1]=a0%MOD,ans.a[0][2]=b0%MOD,
        ans.a[0][4]=ans.a[0][3]=a0*b0%MOD;
        t.a[0][0]=1,t.a[0][1]=ay%MOD,t.a[0][2]=by%MOD;
        t.a[0][3]=t.a[0][4]=ay*by%MOD,t.a[1][1]=ax%MOD;
        t.a[1][3]=t.a[1][4]=ax*by%MOD,t.a[2][2]=bx%MOD,
        t.a[2][3]=t.a[2][4]=ay*bx%MOD,t.a[3][3]=t.a[3][4]=ax*bx%MOD,t.a[4][4]=1;
        
        ans=pow(ans,t,n-1);

        cout<<ans.a[0][4]%MOD<<endl;
    }
    return 0;
}
*/