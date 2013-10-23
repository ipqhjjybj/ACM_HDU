/*
//
//  1729.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-17.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include "cstdio"
#include "iostream"
#include "cstring"
#include "cmath"
int sg(int s,int c){
    int d=(int)sqrt(s);
    while(d+d*d>=s) d--;
    if(c>d)return s-c;
    else  return sg(d,c);
}
int main(){
    int n;
    int s,c;
    int tt=0;
    while(scanf("%d",&n)!=EOF && n){
        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d %d",&s,&c);
            if(s==c)continue;
            ans^=sg(s,c);
        }
        printf("Case %d:\n",++tt);
        if(ans==0)puts("No");
        else puts("Yes");
    }
    return 0;
}
*/