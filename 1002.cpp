//
//  1002.cpp
//  ACM_HDU
//
//  Created by 沈卓亨 on 13-9-14.
//  Copyright (c) 2013年 沈卓亨. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long int64;
#define K 2500000
#define N 110000

int ll, len, T, lim, s, t, k, a, b, c, n, m, limit, root[N], ss[K], sum[K], son[K][2], till[N], go[N * 2], f[N * 2], next[N * 2], h[N], n1[N], fa[N][20];
int64 ans;

void read(int &x) {
    char k;
    for (k = getchar(); k <= 32; k = getchar());
    for (x = 0; '0' <= k; k = getchar())    x = x * 10 - '0' + k;
}

void add(int x, int y, int z) {
    next[++ll] = till[x];
    till[x] = ll;
    go[ll] = y;
    f[ll] = z;
}

void insert(int &k, int k1, int x, int q, int h) {
    k = ++len;
    ss[k] = ss[k1] + 1;
    sum[k] = sum[k1] + x;
    if (q < h) {
        if (x <= (q + h) / 2)    insert(son[k][0], son[k1][0], x, q, (q + h) / 2), son[k][1] = son[k1][1];
        else    insert(son[k][1], son[k1][1], x, (q + h) / 2 + 1, h), son[k][0] = son[k1][0];
    }
}

int64 get(int k1, int k2, int k3, int64 s1, int64 s2, int q, int h, int64 xx) {
    if (q == h)    return q;
    int64 mid = (q + h) / 2 + 1;
    if (mid * (s1 + ss[son[k1][0]] + ss[son[k2][0]] - 2 * ss[son[k3][0]]) - (s2 + sum[son[k1][0]] + sum[son[k2][0]] - 2 * sum[son[k3][0]]) <= xx)    return get(son[k1][1], son[k2][1], son[k3][1], s1 + ss[son[k1][0]] + ss[son[k2][0]] - 2 * ss[son[k3][0]], s2 + sum[son[k1][0]] + sum[son[k2][0]] - 2 * sum[son[k3][0]], mid, h, xx);
    else    return get(son[k1][0], son[k2][0], son[k3][0], s1, s2, q, mid - 1, xx);
}

void bfs() {
    int q, hh, i, j;
    for (n1[q = hh = 1] = 1, h[1] = 1, insert(root[1], 0, 0, 0, 9999); q <= hh; q++)
        for (i = till[n1[q]]; i; i = next[i])
            if (!h[go[i]]) {
                h[go[i]] = h[n1[q]] + 1;
                fa[go[i]][0] = n1[q];
                
                insert(root[go[i]], root[n1[q]], f[i], 0, 9999);
                n1[++hh] = go[i];
            }
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= limit; j++)
            fa[n1[i]][j] = fa[fa[n1[i]][j - 1]][j - 1];
}

int lca(int x, int y) {
    if (h[x] < h[y])    swap(x, y);
    for (int i = limit; i >= 0; i--)    if (h[fa[x][i]] >= h[y])    x = fa[x][i];
    if (x == y) return x;
    for (int i = limit; i >= 0; i--)
        if (fa[x][i] != fa[y][i])   x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

int main() {
    read(T);
    for (int lim = 1; lim <= T; lim++) {
        printf("Case #%d:\n", lim);
        read(n); read(m);
        memset(till, 0, sizeof(till));
        memset(h, 0, sizeof(h));
        limit = int(log(n) / log(2));
        ll = len = 0;
        for (int i = 1; i < n; i++) {
            read(a); read(b); read(c);
            add(a, b, c);
            add(b, a, c);
        }
        bfs();
        while (m--) {
            read(s); read(t); read(k); read(a); read(b);
            int p = lca(s, t);
            if (a <= b)    printf("%I64d\n", get(root[s], root[t], root[p], 0, 0, 0, 9999, 0) + k / a);
            else {
                ans = get(root[s], root[t], root[p], 0, 0, 0, 9999, k / b);
                if (k >= a)    ans = max(ans, get(root[s], root[t], root[p], 0, 0, 0, 9999, 0) + 1 + (k - a) / b);
                int64 s1 = 0LL + ss[root[s]] + ss[root[t]] - 2 * ss[root[p]], s2 = sum[root[s]] + sum[root[t]] - 2 * sum[root[p]];
                if (9999LL * s1 - s2 < k / b) {
                    ans = max(ans, (k / b + s2) / s1);
                }
                printf("%I64d\n", ans);
            }
        }
    }
}