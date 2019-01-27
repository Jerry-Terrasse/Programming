#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

#include <vector>
#include <stack>
#include <queue>


int n, k;
std::vector <int> shq;

inline int SlowRead () {
    char ch = 0;
    int data = 0, f = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while  (ch >= '0' && ch <= '9') {
        data = data * 10 + ch - '0';
        ch = getchar();
    }
    return data * f;
}

int main(int argc, char const *argv[]) {
    freopen ("cover.in", "r", stdin);
    freopen ("cover.out", "w", stdout);
    n = SlowRead();
    k = SlowRead();
    for (int i = 1; i <= n; i++) {
        SlowRead(); shq.push_back(SlowRead());
    }
    std::sort (shq.begin(), shq.end());
    printf("%d\n", shq[n - k]);
    return 0;
}
