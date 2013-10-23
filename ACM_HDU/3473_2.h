//
//  3473.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-31.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

// wrong !!!!!
 #include <cstdio>
 #include <cstdlib>
 #include <iostream>
 #include <algorithm>
 #define LL long long
 using namespace std;
 const int N = 100010;
 struct Node
 {
 int l,r;
 int mid()
 {
 return (l+r)>>1;
 }
 } tree[N<<2];
 
 int sorted[N];
 int val[20][N],toLeft[20][N];
 
 LL lsum[20][N],ans,lans,sum[N],lcount;
 
 void build(int l,int r,int rt,int deep)
 {
 tree[rt].l = l;
 tree[rt].r  = r;
 if(l == r) return;
 int m = tree[rt].mid();
 int midval = sorted[m];
 int leftsame = m - l + 1;//表示在左子树上有多少和midval相等的数
 for(int i = l ; i <= r ; i ++)
 {
 if(val[deep][i] < midval)
 --leftsame;
 }
 int lpos = l,rpos = m + 1;
 for(int i = l ; i <= r ;  i++)
 {
 if(i == l){
 toLeft[deep][i] = 0;//toLeft[][i]表示[tree[rt].l,i-1]有多少数在左部
 lsum[deep][i] = 0; //统计有多少个小于的
 }
 else{
 toLeft[deep][i] = toLeft[deep][i-1];//这里相当于对toLeft[][]初始化
 lsum[deep][i]=lsum[deep][i-1]; //相当于初始化
 }
 if(val[deep][i] < midval)
 {
 ++toLeft[deep][i];
 lsum[deep][i]+=val[deep][i];
 val[deep+1][lpos++] = val[deep][i];
 }
 else if(val[deep][i] > midval)
 {
 val[deep+1][rpos++] = val[deep][i];
 }
 else//判断和midval相等的数是放在左部还是右部
 {
 if(leftsame >= 0)
 {
 --leftsame;
 ++toLeft[deep][i];
 lsum[deep][i]+=midval;
 val[deep+1][lpos++] = val[deep][i];
 }
 else
 {
 val[deep+1][rpos++] = val[deep][i];
 }
 }
 }
 build(l,m,rt<<1,deep+1);
 build(m+1,r,rt<<1|1,deep+1);
 }
 
 int query(int l,int r,int k,int rt,int deep)
 {
 if(l == r) return val[deep][l];
 LL tmp;
 //下面就是要确认新的查找区间
 int s;//表示[l,r]里在左边的数的个数
 int ss;//表示[tree[rt].l,l-1]里在左边的数的个数
 
 if(l == tree[rt].l)
 {
 s = toLeft[deep][r];
 ss = 0;
 tmp=lsum[deep][r];
 }
 else
 {
 ss = toLeft[deep][l-1];
 s = toLeft[deep][r] - ss;
 tmp=lsum[deep][r]-lsum[deep][l-1];
 }
 //注意这里的在左边的数都是和sorted[m]相比的，由此可以得到如果s>=k就去左子树找，相反则去右子树
 if(s >= k)
 {
 /*进入左子树，该条线段的左边有ss个数及从是从上面[tree[rt].l,l-1]该进入左子树的数继承而来
 *接着还应该有toLeft[deep][r] - toLeft[deep][l-1]个数即s个数
 *所以可以确定新的查找区间应该是[tree[rt].l+ss,newl+s - 1]
 */
int newl = tree[rt].l + ss;
int newr = newl + s - 1;//这里减1是为了处理边界问题
return query(newl,newr,k,rt<<1,deep+1);
}
else
{
    /*
     *进入右子树，该条线段的左边应该是上条线段[tree[rt].l,l-1]应该进入右子树的数，即bb = l - tree[rt].l - ss个数
     *接着还应该有上条线段[l,r]应该进入右子树的数，即b = r - l + 1 - s个数
     *所以可以确定新的查询区间应该是[mid + 1 + bb,mid + 1 + bb + b - 1]，这里的-1同一是为了处理边界问题
     */
    int m = tree[rt].mid();
    int b = r - l + 1 - s;//表示[l,r]在右边的数的个数
    int bb = (l - 1) - tree[rt].l + 1 - ss;//表示[tree[rt].l,l-1]在右边的数的个数
    int newl = m + 1 + bb;
    int newr = m + b + bb;//m + r - l + 1 - toLeft[deep][r] + ss - l - tree[rt].l - ss = m+r-
    
    lcount+=s;
    lans+=tmp;
    return query(newl,newr,k-s,rt<<1|1,deep+1);
}
}

static inline int Rint()//这段是整型数的输入外挂，可以忽略不用看
{
    struct X
    {
        int dig[256];
        X()
        {
            for(int i = '0'; i <= '9'; ++i) dig[i] = 1;
            dig['-'] = 1;
        }
    };
    static  X fuck;
    int s = 1, v = 0, c;
    for (; !fuck.dig[c = getchar()];);
    if (c == '-') s = 0;
    else if (fuck.dig[c]) v = c ^ 48;
    for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
    return s ? v : -v;
}


int main()
{
    int n,m;
    int t,tt=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum[0]=0;
        for(int i = 1 ; i <= n ;  i++)
        {
            scanf("%d",&val[0][i]);
            sorted[i] = val[0][i];
            sum[i]=sum[i-1]+sorted[i];
        }
        sort(sorted+1,sorted+n+1);
        build(1,n,1,0);
        scanf("%d",&m);
        cout<<"Case #"<<++tt<<":"<<endl;
        while(m--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            lcount=lans=0;
            a++,b++;
            LL midval=query(a,b,2,1,0);
            
            printf("midval=%lld\n",midval);
            printf("lcount=%lld\n",lcount);
            printf("lans=%lld\n",lans);
            ans=midval*lcount-lans;
            lans=sum[b]-sum[a-1]-lans;
            lcount=b-a+1-lcount;
            ans+=lans-midval*lcount;
            cout<<ans<<endl;
        }
        cout<<endl;
    }
    return 0;
}
