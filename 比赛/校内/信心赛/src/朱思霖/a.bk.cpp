#include <fstream>
#include <cstring>
#define MAXN 3005
#define LL long long
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

int fa[MAXN], rank[MAXN], T, M, N, a, b, Num[MAXN];
LL ans;

int getfa(int x)
{
	return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}

inline bool querySet(int x, int y)
{
	return getfa(x) == getfa(y);
}

void mergeSet(int x, int y)
{
	int fx = getfa(x), fy = getfa(y);
	if (rank[fx] > rank[fy])
	{
		++rank[fx];
		fa[fy] = fa[fx];
	} else {
		++rank[fy];
		fa[fx] = fa[fy];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	fin >> T;
	while (T--)
	{
		fin >> N >> M;
		ans = 0; 
		memset(rank, 0, sizeof(rank));
		memset(Num, 0, sizeof(Num));
		for (int i = 1;i <= N;i++)
		{
			fa[i] = i;
		}
		for (int i = 1;i <= N;i++)
		{
			fin >> a >> b;
			mergeSet(a, b);
		}
		for (int i = 1;i <= N;i++)
		{
			Num[fa[i]]++;
		}
		for (int i = 1;i <= N;i++)
		{
			ans += Num[i] * Num[i];
		}
		fout << ans << endl;
	}
	return 0;
}
