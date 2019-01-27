#include "game.h"
#define MAXN 1550
int f[MAXN],m=0,cnt=0;
void initialize(int n)
{
  m=n;
  cnt=m*(m-1)>>1;
  return;
}
int hasEdge(int u,int v)
{
  if(f[u]<m-2&&f[v]<m-2&&cnt>m-1)
  {
    ++f[u];++f[v];--cnt;
    return 0;
  }
  return 1;
}

#include <cstdio>
#include <cassert>
int read_int() {
    int x;
    assert(scanf("%d", &x) == 1);
    return x;
}

int main() {
    int n, u, v;
    n = read_int();
    initialize(n);
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        u = read_int();
        v = read_int();
        printf("%d\n", hasEdge(u, v));
    }
    return 0;
}
