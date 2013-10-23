//
//  1010.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-14.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 100004;
const int MAXM = 33;

int s[MAXN][MAXM];
int n, m;

int get(int i){
    int l, r;
    int j, t;
    l = i;
    r = n+1;
    while(r-l > 1){
        int mid = (r-l)/2+l;
        t = 0;
        for(j = MAXM-1; j >= 0; j--){
            t = (t<<1)+(s[mid][j] != s[i][j]);
        }
        if(t < m)
            l = mid;
        else
            r = mid;
    }
    return l-i;
}

int main()
{
#ifdef __FIO
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T, i0;
    scanf("%d", &T);
    for(i0 = 1; i0 <= T; i0++){
        int i, j, k;
        int t;
        scanf("%d%d", &n, &m);
        for(i = 0; i < MAXM; i++)
            s[0][i] = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &t);
            for(j = 0; j < MAXM; j++){
                s[i][j] = s[i-1][j]+(t&1);
                t >>= 1;
            }
        }
        ll ans = 0;
        j = -1;
        for(i = 0; i < n; i++){
            ans += get(i);
            //cout<<ans<<endl;
        }
        printf("Case #%d: %I64d\n", i0, ans);
    }
    return 0;
}