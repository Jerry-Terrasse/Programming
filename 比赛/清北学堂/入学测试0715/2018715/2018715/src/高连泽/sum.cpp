#include <iostream>
#include <cstdio>
int L, n, Va, Vb;
int x[100100], now, happy, g, h, d[100100],zuigao;
int Max(int v)
{
	g = 0;
	for(int i = v; i <= n; i++)
	{
		g = std::max(g,x[d[i]]);
		if(g == x[d[i]])h = d[i];
	}
}
int Max2()
{
	for(int i = 1;i <= n; i++)
	{
		zuigao = std::max(zuigao, d[i]);
	}
}
int main()
{
	//freopen("sum.in","r",stdin);
	//freopen("sun.out","w",stdout);
	std::cin >> L >> n >> Va >> Vb; 
	for(int i = 1; i <= n; i++)
	{
		std::cin >> g >> x[g];
		d[1] = g;
	}
	
	Max(1);
	Max2();
	happy = (Va-Vb)*h * g;
	now = h;
	while(h <= zuigao)
	{
		Max(now);
		happy = happy + (Va-Vb) * (h - now) * g;
		now = h;
	}
	std::cout << happy << std::endl; 
	return 0;
}
