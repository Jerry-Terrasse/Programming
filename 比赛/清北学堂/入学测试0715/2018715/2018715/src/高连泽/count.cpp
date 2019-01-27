#include <iostream>
#include <cstdio>

char f[10], s[10], e[10];
char Pan[10], Pan1[10], Pan2[10];
int ans, Ans;
bool pan(char p)
{
	for(int i = 0; i < ans; i++)
	{
		if(p == Pan[i])
		return true;
	}
	return false;
}

bool pan2(char p,char q)
{
	for(int i = 0; i < Ans; i++)
	{
		if(p == Pan1[i] || p == Pan2[i])
			if(q == Pan1[i] || q == Pan2[i])
			return true;	
	}
	return false;
}

int main()
{
	//freopen("count.in","r",stdin);
	//freopen("count.out","w",stdout);
	scanf("%s", f + 1);
	scanf("%s", s + 1);
	scanf("%s", e + 1);
	if(f[1] == f[2] && f[2] == f[3])
	{
		ans++;
		Pan[ans] = f[1];
		if(pan(f[1]))ans--;
	}
	if(s[1] == s[2] && s[2] == s[3])
	{
		ans++;
		Pan[ans] = s[1];
		if(pan(s[1]))ans--;
	}
	if(e[1] == e[2] && e[2] == e[3])
	{
		ans++;
		Pan[ans] = e[1];
		if(pan(e[1]))ans--;
	}
	if(f[1] == s[2] && s[2] == e[3])
	{
		ans++;
		Pan[ans] = s[2];
		if(pan(s[2]))ans--;
	}
	if(e[1] == s[2] && s[2] == f[3])
	{
		ans++;
		Pan[ans] = s[2];
		if(pan(s[2]))ans--;
	}
	if(f[1] == s[1] && s[1] == e[1])
	{
		ans++;
		Pan[ans] = s[1];
		if(pan(s[1]))ans--;
	}
	if(f[2] == s[2] && s[2] == e[2])
	{
		ans++;
		Pan[ans] = s[2];
		if(pan(s[2]))ans--;
	}
	if(f[3] == s[3] && s[3] == e[3])
	{
		ans++;
		Pan[ans] = s[3];
		if(pan(s[3]))ans--;
	}	
	
	
	
	
	
	if(f[1] != f[2] || f[2] != f[3])
	{
		if(f[1] == f[2] || f[2] == f[3])
		{
			Ans++;
			Pan1[Ans] = f[1];
			Pan2[Ans] = f[3];
			if(pan2(f[1],f[3]))Ans--;
		}
		
		if(f[1] == f[3])
		{
			Ans++;
			Pan1[Ans] = f[1];
			Pan2[Ans] = f[2];
			if(pan2(f[1],f[2]))Ans--;
		}	
	}
	if(s[1] != s[2] || s[2] != s[3])
	{
		if(s[1] == s[2] || s[2] == s[3])
		{
			Ans++;
			Pan1[Ans] = s[1];
			Pan2[Ans] = s[3];
			if(pan2(s[1],s[3]))Ans--;
		}
		
		if(s[1] == s[3])
		{
			Ans++;
			Pan1[Ans] = s[1];
			Pan2[Ans] = s[2];
			if(pan2(s[1],s[2]))Ans--;
		}
	}
	if(e[1] != e[2] || e[2] != e[3])
	{
		if(e[1] == e[2] || e[2] == e[3])
		{
			Ans++;
			Pan1[Ans] = e[1];
			Pan2[Ans] = e[3];
			if(pan2(e[1],e[3]))Ans--;
		}
		
		if(e[1] == e[3])
		{
			Ans++;
			Pan1[Ans] = e[1];
			Pan2[Ans] = e[2];
			if(pan2(e[1],e[2]))Ans--;
		}
	}
	if(f[1] != s[2] || s[2] != e[3])
	{
		if(f[1] == s[2] || s[2] == e[3])
		{
			Ans++;
			Pan1[Ans] = f[1];
			Pan2[Ans] = e[3];
			if(pan2(f[1],e[3]))Ans--;
		}
		
		if(f[1] == e[3])
		{
			Ans++;
			Pan1[Ans] = f[1];
			Pan2[Ans] = s[2];
			if(pan2(f[1],s[2]))Ans--;
		}
	}
	if(e[1] != s[2] || s[2] != f[3])
	{
		if(e[1] == s[2] || s[2] == f[3])
		{
			Ans++;
			Pan1[Ans] = e[1];
			Pan2[Ans] = f[3];
			if(pan2(e[1],f[3]))Ans--;
		}
		
		if(e[1] == f[3])
		{
			Ans++;
			Pan1[Ans] = s[2];
			Pan2[Ans] = f[3];
			if(pan2(s[2],f[3]))Ans--;
		}
	}
	if(f[1] != s[1] || s[1] != e[1])
	{
		if(f[1] == s[1] || s[1] == e[1])
		{
			Ans++;
			Pan1[Ans] = f[1];
			Pan2[Ans] = e[1]; 
			if(pan2(f[1],e[1]))Ans--;
		}
		
		if(f[1] == e[1])
		{
			Ans++;
			Pan1[Ans] = f[1];
			Pan2[Ans] = s[1]; 
			if(pan2(f[1],s[1]))Ans--;
		}
	}
	if(f[2] != s[2] || s[2] != e[2])
	{
		if(f[2] == s[2] || s[2] == e[2])
		{
			Ans++;
			Pan1[Ans] = f[2];
			Pan2[Ans] = e[2]; 
			if(pan2(f[2],e[2]))Ans--;
		}
		
		if(f[2] == e[2])
		{
			Ans++;
			Pan1[Ans] = f[2];
			Pan2[Ans] = s[2]; 
			if(pan2(f[2],s[2]))Ans--;
		}
	}
	if(f[3] != s[3] || s[3] != e[3])
	{
		if(f[3] == s[3] || s[3] == e[3])
		{
			Ans++;
			Pan1[Ans] = f[3];
			Pan2[Ans] = e[3];
			if(pan2(f[3],e[3]))Ans--;
		}
		
		if(f[3] == s[3])
		{
			Ans++;
			Pan1[Ans] = f[3];
			Pan2[Ans] = s[3];
			if(pan2(f[3],s[3]))Ans--;
		}
	}

	if(ans == 8 && Ans == 1)Ans = 0;
	std::cout << ans << std::endl << Ans << std::endl;
	return 0;
}
