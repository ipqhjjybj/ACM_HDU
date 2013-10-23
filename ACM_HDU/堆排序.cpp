//
//  堆排序.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-26.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int N = 11111;
int a[N];

template <class T>
void swap(T &a ,T &b){
    T c=a;
    a=b;
    b=c;
}
template <class T>
void arrayAdjact(T *array,int s,int t) {
    int tmp=array[s];
    for(int j=s<<1;j<=t;j<<=1){
        if(j<t&&array[j]<array[j+1]) j++;
        if(array[j]<tmp) break;
        array[s]=array[j];
        s=j;
    }
    array[s]=tmp;
};
//从小到大
template<class T>
void heapSort(T *array,T s,T e){
    
    array--;s++,e++;
    for(int j=e>>1;j>0;j--)
        arrayAdjact(array,j,e);

    for(int j=e;j>1;j--){
        swap(array[1],array[j]);
        arrayAdjact(array, 1, j-1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    heapSort(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d%c",a[i],i==n-1?'\n':' ');
    return 0;
}
*/