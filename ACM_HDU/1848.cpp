//
//  1848.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-17.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include<stdio.h>
#include<string.h>


int f[100] = {1,2,3,5};
int e[1001] = {0,1,2,3};
int b[16];
int main()
{
    int n, i, j, m, p;
    for( i = 3 ; f[i-1] <= 1000 ; i++)
    {
        f[i] = f[i -1] + f[i - 2];
    }
    
    for( i = 4 ; i  < 1001 ; i++)
    {
        e[i] = i;
        memset(b,0,sizeof(b));
        for( j = 0 ; f[j] <= i ; j++)
            b[e[i-f[j]]] = 1;
        for( j = 0 ; j < 15 ; j++)
        {
            if(b[j] == 0)
            {
                e[i] = j;
                break;
            }
        }
    }
    for(int i=0;i<600;i++){
        if(e[i]==7)
        printf("%d %d\n",i,e[i]);
    }
    while(scanf("%d%d%d", &n, &m, &p), (n!= 0 || m!= 0 || p!= 0 ))
    {
        if( (e[n] ^ e[m] ^ e[p]) == 0)
            printf("Nacci\n");
        else
            printf("Fibo\n");
    }
    return 0;
}
 */
