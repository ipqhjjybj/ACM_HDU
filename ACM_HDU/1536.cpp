//
//  1536.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-8-17.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//
/*
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<cstring>
#include<set>
#include<string>
#include<algorithm>
#include<sstream>
#include<ctype.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stack>
#include<queue>
#include<ctime>
//#include<conio.h>
using namespace std;

const int INF_MAX=0x7FFFFFFF;
const int INF_MIN=-(1<<31);

const double eps=1e-10;
const double pi=acos(-1.0);

#define pb push_back   //a.pb( )
#define chmin(a,b) ((a)<(b)?(a):(b))
#define chmax(a,b) ((a)>(b)?(a):(b))


template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}


typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
int dir_4[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int dir_8[8][2]={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
//下，左下，左，左上，上，右上，右，右下。

//******* WATER ****************************************************************


const int MAXN = 10500;
bool judge[150];
int sg[MAXN];
int M[150];
const int Init = 1e7;
int Num;

void input_m()
{
    for(int i = 0; i < Num; i++)
    {
        cin>>M[i];
    }
    return ;
}

void debug()
{
    cout<<"sg function"<<endl;
    for(int i = 0; i < 100; i++)
    {
        cout<<i<<" "<<sg[i]<<endl;
    }
    return ;
}

void getsg()
{
    for(int i = 0; i < MAXN; i++)
    {
        memset(judge, false, sizeof(judge));
        //int tsg = Init;
        for(int j = 0; j < Num; j++)
        {
            int ps = i - M[j];
            if(ps >= 0) judge[sg[ps]] = true;
        }
        //if(tsg == Init) tsg = 0;
        for(int j = 0; j < Num + 1; j++)
        {
            if(judge[j] == false)
            {
                sg[i] = j;
                break;
            }
        }
    }
    //debug();
    return ;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(cin>>Num, Num)
    {
        input_m();
        getsg();
        int num;
        cin>>num;
        while(num--)
        {
            int nn, tp;
            cin>>nn;
            int ret = 0;
            for(int i = 0; i < nn; i++)
            {
                cin>>tp;
                ret ^= sg[tp];
            }
            if(ret == 0) cout<<"L";
            else cout<<"W";
        }
        cout<<endl;
    }
    return 0;
    //printf("%.6f\n",(double)clock()/CLOCKS_PER_SEC);
}
*/