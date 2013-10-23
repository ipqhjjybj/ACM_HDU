//
//  2143.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-8.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <set>
#include <cmath>
using namespace std;

const int N=1111111;
int prm[N],k;
bool is[N];

int getprm(int n){
    int i,j,k=0;
    int s,e=(int)(sqrt(0.0+n)+1);
    memset(is,true,sizeof(is));
    prm[k++]=2,is[0]=is[1]=0;
    for(i=4;i<n;i+=2)is[i]=0;
    for(i=3;i<e;i+=2)if(is[i]){
        prm[k++]=i;
        for(s=i+i,j=i*i;j<n;j+=s)
            is[j]=0;
    }
    for(;i<n;i+=2)if(is[i])prm[k++]=i;
    return k;
}
 
/*
 下面的算法效率不够高。 
 int getprm(int n){
 int k=0;
 prm[k++]=2;
 for(int i=2;i<n;i++)is[i]=true;
 for(int i=4;i<n;i+=2)is[i]=false;
 for(int i=3;i<n;i+=2)
 if(is[i]){
 prm[k++]=i;
 for(int j=i+i;j<n;j+=i){
 is[j]=false;
 }
 }
 return k;
 }
*/
set<int> S;
int main(){
    k=getprm(N);
    S.clear();
    for(int i=0;i<k;i++)
        S.insert(prm[i]);
    int t,n,i,b;
    bool flag;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        flag=false;
        for(i=0;i<prm[i];i++){
            b=prm[i]+n;
            if(S.find(prm[i]+n)!=S.end()){
                flag=true;
                break;
            }
        }
        if(flag){
            printf("%d %d\n",prm[i]+n,prm[i]);
        }else printf("FAIL\n");
    }
    return 0;
}