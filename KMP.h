//
//  KMP.h
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-30.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#ifndef __ACM_HDU__KMP__
#define __ACM_HDU__KMP__

#include <iostream>

const int maxn=1111;
int fail[maxn];
int kmp(char *str,char *pat){
    int i,j,k;
    memset(fail,-1,sizeof(fail));
    for(i=1;pat[i];i++){
        for(k=fail[i-1];k>=0&&pat[i]!=pat[k+1];k=fail[k])
            ;
        if(pat[k+1]==pat[i]) fail[i]=k+1;
    }
    i=j=0;
    while(str[i]&&pat[j]){
        if(pat[j]==str[i])i++,j++;
        else if(j==0) ++i;
        else j=fail[j-1]+1;
    }
    if(pat[j]) return -1;
    else return i-j;
}
#endif /* defined(__ACM_HDU__KMP__) */
