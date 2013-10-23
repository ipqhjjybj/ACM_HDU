/*
#include <stdio.h>
#include <string.h>
const int N=1000005;
char s[2][N];
int len[2];
int next[2][N];
int max(int a,int b){return a>b?a:b;}
void getNext(int v){
    int i=0,j=-1;
    next[v][0]=-1;
    while(i<len[v]){
        if(j==-1||s[v][i]==s[v][j]) {
            i++;j++;
            next[v][i]=j;
        }
        else j=next[v][j];
    }
}
int kmp1(int u,int v){
    int i=0,j=0;
    while(i<len[u]&&j<len[v]){
        if(j==-1||s[u][i]==s[v][j]){
            i++;j++;
        }else j=next[v][j];
    }
    if(j>=len[v]) return 1;
    return 0;
}

int kmp2(int u,int v){
    int i=0,j=0;
    while(i<len[u]){
        if(i==-1||s[u][i]==s[v][j]){
            i++;j++;
            if(j>=len[v]) return i;
        }else i=next[u][i];
    }
    return 0;
}
int main(){
    int i,j,t;
    scanf("%d",&t);
    while(t--){
        scanf("%s %s",s[0],s[1]);
        
        len[0]=strlen(s[0]);
        len[1]=strlen(s[1]);
        getNext(0);
        getNext(1);
        
        if(len[0]>=len[1]&&kmp1(0,1)) {
            printf("%d\n",len[0]);
        }
        else if(len[0]<len[1]&&kmp1(1,0)) {
            printf("%d\n",len[1]);
        }
        else{
            printf("%d\n",len[0]+len[1]-max(kmp2(0,1),kmp2(1,0)));
        }
    }
    return 0;
}
 */
/*
 
 Wrong ans!
 
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1000010;
char a[2][N];
int fail[N];
int kmp(int &i,int &j,char *str,char *pat){
    
    j=-1,i=1;
    fail[0]=-1;
    while(pat[i]){
        if(j==-1||pat[i]==pat[j]){
            i++,j++;
            fail[i]=j;
        }else j=fail[j];
    }
    
    i=j=0;
    while(str[i]&&pat[j]){
        if(pat[j]==str[i])++i,++j;
        else if(j==0)++i;
        else j=fail[j-1]+1;
    }
    if(pat[j])return -1;
    else return i-j;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int i,j,l1=0,l2=0;
        scanf("%s %s",a[0],a[1]);
        int len1=strlen(a[0]),len2=strlen(a[1]),val;
        val = kmp(i,j,a[1],a[0]);
        //printf("i=%d j=%d\n",i,j);
        if(val!=-1) l1=len1;
        else{
            //if(i==len2&&j>0&&a[1][len2-1]==a[0][j-1])
                l1=j;
        }
        val=kmp(i,j,a[0],a[1]);
        //printf("i=%d j=%d\n",i,j);
        if(val!=-1)l2=len2;
        else{
            //if(i==len1&&j-1>=0&&a[0][len1-1]==a[1][j-1])
                l2=j;
        }
        printf("%d\n",len1+len2-max(l1,l2));
    }
    return 0;
}

*/