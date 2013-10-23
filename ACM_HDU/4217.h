//
//  4217.h
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-8.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#ifndef __ACM_HDU___217__
#define __ACM_HDU___217__

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
#define lowbit(x) (x&(-x))
const int MAXN=333333;
int n,k;
int a[MAXN];
#define LL long long

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
    while(l<=r){
        mid=(l+r)>>1;
        int tmp=Query(mid)+mid;
        if(tmp==k){
            return mid;
        }else if(tmp<k){
            l=mid+1;
        }else r=mid-1;
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
        memset(a,0,sizeof(a));
        while(k--){
            scanf("%d",&tmp);
            tmp=Bisearch(tmp);
            Update(tmp);
            sum+=tmp;
        }
        printf("Case %d: ",++tt);
        printf("%lld\n",sum);
    }
    return 0;
}
#endif /* defined(__ACM_HDU___217__) */
