//
//  1005.cpp
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
const int P = int(1e9+7.5);

ll inv[MAXN];
ll fac[MAXN], fac1[MAXN];
ll phi[MAXN];

ll C(int n, int m){
    if(m > n)
        return 0;
    return (ll)fac[n]*fac1[m]%P*fac1[n-m]%P;
}

ll C(int n, int m1, int m2){
    if(m1+m2 > n)
        return 0;
    return (ll)fac[n]*fac1[m1]%P*fac1[m2]%P*fac1[n-m1-m2]%P;
}

ll f(int n, int m, int k){
    ll ret = 0;
    ll s = 1;
    int i = 0;
    while(n >= i*(k+1) && m >= i*k){
        ret += ll(s)*C(n-i*k, m-i*k, i)%P*n%P*inv[n-i*k]%P;
        i++;
        s = (ll)s*(-1)%P;
    }
    return ret%P;
}

int main()
{
#ifdef __FIO
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T, i0;
    int i, j, k;
    inv[1] = 1;
    for(i = 2; i < MAXN; i++){
        inv[i] = P-(ll)(P/i)*inv[P%i]%P;
    }
    fac[0] = fac1[0] = 1;
    for(i = 1; i < MAXN; i++){
        fac[i] = (ll)fac[i-1]*i%P;
        fac1[i] = (ll)fac1[i-1]*inv[i]%P;
    }
    for(i = 1; i < MAXN; i++)
        phi[i] = i;
    for(i = 1; i < MAXN; i++)
        for(j = i*2; j < MAXN; j += i)
            phi[j] -= phi[i];
    scanf("%d", &T);
    for(i0 = 1; i0 <= T; i0++){
        ll ans = 0;
        int n, m;
        scanf("%d%d%d", &n, &m, &k);
        if(m == 0){
            ans = 1;
            goto print;
        }
        if(n == m){
            if(k > n)
                ans = 1;
            else
                ans = 0;
            goto print;
        }
        for(i = 1; i <= n; i++)
            if(n%i == 0 && m%i == 0)
                ans = (ans+f(n/i, m/i, k)*phi[i])%P;
        ans %= P;
        ans = ans*inv[n]%P;
        ans = (ans+P)%P;
    print:
        printf("Case #%d: %I64d\n", i0, ans);
    }
    return 0;
}