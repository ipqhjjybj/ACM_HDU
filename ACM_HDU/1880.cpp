//
//  1880.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-30.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
const int N=100007;
const int MOD=100007;
const size_t seed=131;
template <class T>
size_t BKDRhash(const T *str){
    size_t ch=*str++;
    if(!ch) return 0;
    while(*str){
        ch = ch*seed + *str++;
    }
    return (ch&0x7fffffff)%MOD;
}
struct node{
    struct node * ne;
    char s[111];
}head[N<<2],*h[N],*cur;

int getID(char *s){
    int code = (int)BKDRhash(s);
    
    strcpy(cur->s,s);
    cur->ne=h[code];
    h[code]=cur++;
    
    return (int)(cur-1-head);
}

int find(char *s){
    int code = (int)BKDRhash(s);
    struct node *t = h[code];
    while(t){
        if(!strcmp(s,t->s))
            return (int)(t-head);
        else t=t->ne;
    }
    return -1;
}
char s[1000];
int main(){
    memset(h,0,sizeof(h));
    cur=head;
    while(scanf("%s",s)&&s[0]!='@'){
        getID(s);
        getchar();
        gets(s);
        getID(s);
    }
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        gets(s);
        int d=find(s);
      //  printf("s=%s d=%d\n",s,d);
        if(d==-1){
            puts("what?");
            continue;
        }else{
            struct node * tmp=&head[d^1];
            if(*tmp->s=='['){
                char *t=tmp->s;
                while(*++t != ']'){
                    putchar(*t);
                }
                puts("");
            }else{
                puts(tmp->s);
            }
        }
    }
    return 0;
}
*/