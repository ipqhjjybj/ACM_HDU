//
//  1841.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-30.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

 #include <cstdio>
 #include <iostream>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 const int maxn=1111111;
 char s1[maxn],s2[maxn];
 int fail[maxn];
 int kmp(int &i,int &j,const char *s1,const char *s2){
 memset(fail,-1,sizeof(fail));
 int k;
 for(i=1;s2[i];i++){
 for(k=fail[i-1];k>=0&&s2[k+1]!=s2[i];k=fail[k])
 ;
 if(s2[k+1]==s2[i])fail[i]=k+1;
 }
 i=j=0;
 while(s1[i]&&s2[j]){
 if(s1[i]==s2[j])i++,j++;
 else if(!j) i++;
 else j=fail[j]+1;
 }
 if(s2[j])return -1;
 else return i-j;
 }
 int main(){
 int t;
 scanf("%d",&t);
 while(t--){
 int ans;
 scanf("%s %s",s1,s2);
 int i,j,l1,l2;
 l1=strlen(s1),l2=strlen(s2);
 int val=kmp(i,j,s1,s2);
 //printf("l1=%d l2=%d i=%d j=%d val=%d\n",l1,l2,i,j,val);
 if(val != -1){
 printf("%d\n",max(l1,l2));
 continue;
 }else ans=i+l2-j;
 
 val=kmp(i,j,s2,s1);
 //printf("l1=%d l2=%d i=%d j=%d val=%d\n",l1,l2,i,j,val);
 if(val != -1){
 printf("%d\n",max(l1,l2));
 continue;
 }else ans=min(ans,i+l1-j);
 printf("%d\n",ans);
 }
 return 0;
 }
 