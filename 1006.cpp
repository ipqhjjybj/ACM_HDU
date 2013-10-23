//
//  1006.cpp
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

char a[MAXN], b[MAXN];
char a1[MAXN], b1[MAXN];
int cnt[MAXN][2], cnt1[MAXN];
int n;
ll ans;

void restore(int pos){
    int i;
    for(i = 0; i < n; i++){
        if(i == pos){
            if(a[i] != '?'){
                a1[i] = a[i];
                b1[i] = a[i]^1;
            }
            else{
                a1[i] = b[i]^1;
                b1[i] = b[i];
            }
        }
        else if(i == pos+1)
            a1[i] = b1[i] = '1';
        else if(i > pos+1)
            a1[i] = b1[i] = '0';
        else{
            if(a[i] != '?'){
                a1[i] = a[i];
                b1[i] = a[i];
            }
            else{
                a1[i] = b[i];
                b1[i] = b[i];
            }
        }
    }
}

void solve(int pos){
    ans += cnt1[pos];
    if(cnt1[pos] && ans == 1)
        restore(pos-1);
}

bool test(char x, char y){
    return x == '?' || y == '?' || x == y;
}

bool test1(char x, char y){
    return x == '?' || y == '?' || x != y;
}

int main()
{
#ifdef __FIO
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T, i0;
    scanf("%d", &T);
    for(i0 = 1; i0 <=  T; i0++){
        printf("Case #%d:\n", i0);
        int i, j, k, l;
        ans = 0;
        scanf("%s%s", a, b);
        n = strlen(a);
        memset(cnt, 0, sizeof cnt);
        memset(cnt1, 0, sizeof cnt1);
        cnt[0][0] = 1;
        for(i = 0; i < n; i++){
            if(test(a[i], '0') && test(b[i], '0')){
                cnt[i+1][0] += cnt[i][0];
                cnt[i+1][1] += cnt[i][1];
            }
            if(test(a[i], '1') && test(b[i], '1')){
                cnt[i+1][0] += cnt[i][1];
                cnt[i+1][1] += cnt[i][0];
                cnt[i+1][0] %= P;
                cnt[i+1][1] %= P;
            }
            if(test(a[i], '0') && test(b[i], '1')){
                cnt1[i+1] += cnt[i][0];
            }
            if(test(a[i], '1') && test(b[i], '0')){
                cnt1[i+1] += cnt[i][1];
                cnt1[i+1] %= P;
            }
        }
        solve(n);
        for(i = n-1; i > 0; i--){
            if(test(a[i], '1') && test(b[i], '1')){
                if(i == 0){
                    ans++;
                    if(ans == 1)
                        restore(-1);
                }
                else{
                    solve(i);
                }
            }
            if(!(test(a[i], '0') && test(b[i], '0')))
                break;
        }
        if(ans == 0){
            printf("Impossible\n");
        }
        else if(ans == 1){
            a1[n] = b1[n] = '\0';
            puts(a1);
            puts(b1);
        }
        else{
            printf("Ambiguous %I64d\n", ans%P);
        }
    }
    return 0;
}
