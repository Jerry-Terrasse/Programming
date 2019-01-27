#include <fstream>
#include <cstring>
using namespace std;

const int maxn=3005;

ifstream fin("a.in");
ofstream fout("a.out");

struct Road{
	int next, to;
};

Road Connection[maxn];
int ans, cnt, head[maxn], T, Map[maxn][maxn], n, m;

void AddRoad(int x, int y)
{
	Connection[++cnt].to = y;
	Connection[cnt].next = head[x];
	head[x] = cnt;
	//Map[x][y]=Map[y][x]=1;
}

int main()
{
	ios::sync_with_stdio(false);
	fin >> T;
	while (T--)
	{
		memset(head, 0, sizeof(head));
		cnt = 0;
		memset(Map, 0, sizeof(Map));
		fin >> n >> m;
		for (int i = 1;i <= m;i++)
		{
			int tmp1, tmp2;
			fin >> tmp1 >> tmp2;
			AddRoad(tmp2, tmp1);
		}
		ans = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (i == j){
					Map[i][j] = 1;
				} else {
					for (int k = head[i];k && !Map[i][j];k = Connection[k].next)
					{
						int to = Connection[k].to;
						Map[i][j] |= Map[to][j];
					}
					for (int k = head[j];k && !Map[i][j];k = Connection[k].next)
					{
						int to = Connection[k].to;
						Map[i][j] |= Map[i][to];
					}
				}
				ans += Map[i][j];
			}
		}
		fout << ans << endl;
	}
	return 0;
}
