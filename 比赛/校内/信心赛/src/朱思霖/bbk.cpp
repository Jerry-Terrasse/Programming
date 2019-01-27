#include <fstream>
#include <algorithm>
#define maxn 500005
using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");

int N, M, ans, Seniors[maxn], Young_People[maxn];

int main()
{
	ios::sync_with_stdio(false);
	fin >> N >> M;
	for (int i = 1;i <= N;i++)
	{
		int tmp1, tmp2;
		fin >> tmp1 >> tmp2;
		Young_People[i] = tmp1 + tmp2;
	}
	for (int i = 1;i <= M;i++)
	{
		int tmp1, tmp2;
		fin >> tmp1 >> tmp2;
		Seniors[i] = tmp1 + tmp2;
	}
	for (int i = 0;i < N;i++)
	{
		ans = 0;
		for (int j = 0;j < M;j++)
		{
			ans = max(ans, abs(Seniors[j] - Young_People[i]));
		}
		fout << ans << endl;
	}
	return 0;
}
