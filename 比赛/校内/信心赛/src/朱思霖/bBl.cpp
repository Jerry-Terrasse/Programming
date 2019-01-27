#include <fstream>
#include <algorithm>
#define maxn 500005
using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");

int N, M, ans, Seniorsx[maxn], Young_Peopley[maxn], Seniorsy[maxn], Young_Peoplex[maxn];

int main()
{
	ios::sync_with_stdio(false);
	fin >> N >> M;
	for (int i = 1;i <= N;i++)
	{
		fin >> Young_Peoplex[i] >> Young_Peopley[i];
	}
	for (int i = 1;i <= M;i++)
	{
		fin >> Seniorsx[i] >> Seniorsy[i];
	}
	for (int i = 1;i <= N;i++)
	{
		ans = 0;
		for (int j = 1;j <= M;j++)
		{
			ans = max(ans, abs(Seniorsx[j] - Young_Peoplex[i]) + abs(Seniorsy[j] - Young_Peopley[i]));
		}
		fout << ans << endl;
	}
	return 0;
}
