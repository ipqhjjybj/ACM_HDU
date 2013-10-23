#include<iostream>
#include<algorithm>
int MIN(int a,int b) { if( a<b )  return a;  else return b; }
int MAX(int a,int b) { if( a>b )  return a;  else return b; }
#define CLR(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME))
using namespace std;
typedef __int64 LL;
const int N=100000+10;
const int DEEP=20;
LL  sum[N];
int data[N];
int seg[DEEP][N];
LL  lsum[DEEP][N];
int lessMid[DEEP][N];
void Build(int l,int r,int d) {
    if( l==r )  return;
    int i,mid=(l+r)>>1;
    int lsame=mid-l+1;   //这个变量表示左边最多可放几个与DATA[MID]相同的数
    for(i=l;i<=r;++i) {  //得出实际能放几个相同的数
        if( seg[d][i]<data[mid] ) {
            --lsame;
        }
    }
    int tl=l,tr=mid+1,same=0;
    for(i=l;i<=r;++i) {
        if( i==l ) {
            lsum[d][i]=0;
            lessMid[d][i]=0;  //表示在[L，R]内有几个数小于等于DATA[MID]
        }
        else {
            lsum[d][i]=lsum[d][i-1];
            lessMid[d][i]=lessMid[d][i-1];
        }
        if( seg[d][i]<data[mid] ) {
            ++lessMid[d][i];
            lsum[d][i]+=seg[d][i];
            seg[d+1][tl++]=seg[d][i];
        }
        else if( seg[d][i]>data[mid] ) {
            seg[d+1][tr++]=seg[d][i];
        }
        else {
            if( same<lsame ) {
                ++same,++lessMid[d][i];
                lsum[d][i]+=seg[d][i];
                seg[d+1][tl++]=seg[d][i];
            }
            else {
                seg[d+1][tr++]=seg[d][i];
            }
        }
    }
    Build(l,mid,d+1);
    Build(mid+1,r,d+1);
}
LL  numl,suml;
int Query(int l,int r,int tl,int tr,int d,int cnt) {
    if( l==r )  return seg[d][l];
    int s;   //表示在[L，R]内有几个小于等于DATA[MID]的个数
    int ss;  //表示在[tr[root].l,l-1]内有几个小于等于DATA[MID]的个数
    LL tmp;   //少于中位数的数的和
    int mid=(tl+tr)>>1;
    if( l==tl ) {
        tmp=lsum[d][r];
        s=lessMid[d][r];
        ss=0;
    }
    else {
        tmp=lsum[d][r]-lsum[d][l-1];
        s=lessMid[d][r]-lessMid[d][l-1];
        ss=lessMid[d][l-1];
    }
    if( s>=cnt ) {
        return Query(tl+ss,tl+ss+s-1,tl,mid,d+1,cnt);
    }
    else {
        numl+=s;
        suml+=tmp;
        int bb=l-tl-ss;
        int b=r-l+1-s;
        return Query(mid+bb+1,mid+bb+b,mid+1,tr,d+1,cnt-s);
    }
}

LL GetAns(int n,int l,int r) {
    numl=suml=0;
    LL midval=Query(l,r,1,n,1,(r-l)/2+1);
    LL ans=midval*numl-suml;
    suml=sum[r]-sum[l-1]-suml;
    numl=r-l+1-numl;
    ans+=suml-midval*numl;
    return ans;
}


int main() {
    int n,m,l,r,i,j,ca;
    scanf("%d",&ca);
    for(i=1;i<=ca;++i) {
        scanf("%d",&n);
        sum[0]=0;
        for(j=1;j<=n;++j) {
            scanf("%d",data+j);
            seg[1][j]=data[j];
            sum[j]=sum[j-1]+data[j];
        }
        sort(data+1,data+n+1);
        Build(1,n,1);    
        scanf("%d",&m);
        printf("Case #%d:\n",i);
        while( m-- ) {
            scanf("%d%d",&l,&r);
            printf("%I64d\n",GetAns(n,l+1,r+1));
        }
        printf("\n");
    }
    return 0;
}
