//
//  2104.h
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-2.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=1111111;
int sorted[N];
int val[20][N];
int toLeft[20][N];
void Build(int l,int r,int d){
    if(l==r) return ;
    int m=(l+r)>>1;
    int lsame=m-l+1;
    int midval=sorted[m];
    for(int i=l;i<=r;i++){
        if(sorted[i]<midval)
            lsame--;
    }
    int lpos=l,rpos=m+1,same=0;
    for(int i=l;i<=r;i++){
        if(i==l){
            toLeft[d][i]=0;
        }else{
            toLeft[d][i]=toLeft[d][i-1];
        }
        if(val[d][i]<midval){
            val[d+1][lpos++]=val[d][i];
            toLeft[d][i]++;
            printf("toLeft[%d][%d]=%d\n",d,i,toLeft[d][i]);
        }else if(val[d][i]>midval){
            val[d+1][rpos++]=val[d][i];
        }else{
            if(same<lsame){
                same++;
                val[d+1][lpos++]=val[d][i];
                toLeft[d][i]++;
            }else{
                val[d+1][rpos++]=val[d][i];
            }
        }
    }
    Build(l,m,d+1);
    Build(m+1,r,d+1);
}
int Query(int l,int r,int tl,int tr,int k,int d){
    if(l==r)return val[d][l];
    int m=(tl+tr)>>1;
    int s,ss;
    if(l==tl){
        ss=0;
        s=toLeft[d][r];
    }else{
        ss=toLeft[d][l-1];
        s=toLeft[d][r]-ss;
    }
    if(k<=s){//左子树
        int newl=tl+ss;
        int newr=newl+s-1;
        return Query(newl,newr,tl,m,k,d+1);
    }else{
        int dd=l-tl-ss;
        int d=r-l+1-s;
        int newl=m+1+dd;
        int newr=m+d+dd;
        //printf("newl=%d newr=%d m+1=%d tr=%d k=%d d=%d\n",
        //      newl,newr,m+1,tr,k,d);
        return Query(newl,newr,m+1,tr,k-s,d+1);
    }
}
void Debug(int n){
    printf("debug:\n");
    for(int i=0;i<=3;i++){
        printf("i=%d:  ",i);
        for(int j=1;j<=n;j++){
            printf("%d ",val[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(int i=0;i<=3;i++){
        printf("i=%d:  ",i);
        for(int j=1;j<=n;j++){
            printf("%d ",toLeft[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&sorted[i]);
            val[0][i]=sorted[i];
        }
        sort(sorted+1,sorted+1+n);
        
        Build(1,n,0);
        Debug(n);
        int a,b,c;
        while(m--){
            scanf("%d %d %d",&a,&b,&c);
            int num=Query(a,b,1,n,c,0);
            printf("%d\n",num);
        }
    }
    return 0;
}