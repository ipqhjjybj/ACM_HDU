//
//  KMP.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-30.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
const int maxn=1111;
int KMP(char s[],char tmp[]){
    int fail[maxn];
    memset(fail,-1,sizeof(fail));
    int i,j;
    for(i=1;tmp[i];i++){
        for(j=fail[i-1];j>=0&&tmp[j+1]!=tmp[i];j=fail[j])
            ;
        if(tmp[j+1]==tmp[i])fail[i]=j+1;
    }
    i=j=0;
    while(s[i]&&tmp[j]){
        if(s[i]==tmp[j])i++,j++;
        else if(j==0)++i;
        else j=fail[j-1]+1;
    }
    return tmp[j]?-1:i-j;
}
int fail[maxn];
int kmp(char *str,char *pat){
    int i,j,k;
    memset(fail,-1,sizeof(fail));
    for(i=1;pat[i];i++){
        for(k=fail[i-1];k>=0&&pat[i]!=pat[k+1];k=fail[k])
            ;
        if(pat[k+1]==pat[i]) fail[i]=k+1;
    }
    for(i=0;pat[i];i++){
        printf("%d %c %d \n",i,pat[i],fail[i]);
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

int main(){
    char s[maxn],tmp[maxn];
    scanf("%s %s",s,tmp);
    printf("%d\n",KMP(s,tmp));
}
*/