#include <cstdio>
#include <vector>
using namespace std;
char map[5][5];
bool canWin[27][27];
int single;
int multy;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%s",map[1]+1);
	scanf("%s",map[2]+1);
	scanf("%s",map[3]+1);
	
	for(int i=1;i<=3;i++)
	{
		vector<char> existed;
		for(int j=1;j<=3;j++)
		{
			bool repeated=false;
			for(int k=0;k<existed.size();k++)
			{
				if(existed[k]==map[i][j])
				{
					repeated=true;
					break;
				}
			}
			if(!repeated)existed.push_back(map[i][j]);
		}
		if(existed.size()==1)
		{
			if(!canWin[existed[0]-'A'][existed[0]-'A'])
			{
				canWin[existed[0]-'A'][existed[0]-'A']=true;
				single+=1;
			}
		}
		else if(existed.size()==2)
		{
			if(!canWin[existed[0]-'A'][existed[1]-'A'])
			{
				canWin[existed[0]-'A'][existed[1]-'A']=true;
				canWin[existed[1]-'A'][existed[0]-'A']=true;
				multy+=1;
			}
		}
	}
	
	for(int j=1;j<=3;j++)
	{
		vector<char> existed;
		for(int i=1;i<=3;i++)
		{
			bool repeated=false;
			for(int k=0;k<existed.size();k++)
			{
				if(existed[k]==map[i][j])
				{
					repeated=true;
					break;
				}
			}
			if(!repeated)existed.push_back(map[i][j]);
		}
		if(existed.size()==1)
		{
			if(!canWin[existed[0]-'A'][existed[0]-'A'])
			{
				canWin[existed[0]-'A'][existed[0]-'A']=true;
				single+=1;
			}
		}
		else if(existed.size()==2)
		{
			if(!canWin[existed[0]-'A'][existed[1]-'A'])
			{
				canWin[existed[0]-'A'][existed[1]-'A']=true;
				canWin[existed[1]-'A'][existed[0]-'A']=true;
				multy+=1;
			}
		}
	}
	

	vector<char> existed;
	for(int i=1,j=1;j<=3;i++,j++)
	{
		bool repeated=false;
		for(int k=0;k<existed.size();k++)
		{
			if(existed[k]==map[i][j])
			{
				repeated=true;
				break;
			}
		}
		if(!repeated)existed.push_back(map[i][j]);
	}
	if(existed.size()==1)
	{
		if(!canWin[existed[0]-'A'][existed[0]-'A'])
		{
			canWin[existed[0]-'A'][existed[0]-'A']=true;
			single+=1;
		}
	}
	else if(existed.size()==2)
	{
		if(!canWin[existed[0]-'A'][existed[1]-'A'])
		{
			canWin[existed[0]-'A'][existed[1]-'A']=true;
			canWin[existed[1]-'A'][existed[0]-'A']=true;
			multy+=1;
		}
	}
	
	existed.clear();
	for(int i=1,j=3;i<=3;i++,j--)
	{
		bool repeated=false;
		for(int k=0;k<existed.size();k++)
		{
			if(existed[k]==map[i][j])
			{
				repeated=true;
				break;
			}
		}
		if(!repeated)existed.push_back(map[i][j]);
	}
	if(existed.size()==1)
	{
		if(!canWin[existed[0]-'A'][existed[0]-'A'])
		{
			canWin[existed[0]-'A'][existed[0]-'A']=true;
			single+=1;
		}
	}
	else if(existed.size()==2)
	{
		if(!canWin[existed[0]-'A'][existed[1]-'A'])
		{
			canWin[existed[0]-'A'][existed[1]-'A']=true;
			canWin[existed[1]-'A'][existed[0]-'A']=true;
			multy+=1;
		}
	}
	printf("%d\n%d",single,multy);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
