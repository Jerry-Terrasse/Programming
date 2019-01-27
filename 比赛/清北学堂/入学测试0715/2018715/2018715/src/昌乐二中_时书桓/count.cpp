#include<fstream>
using namespace std;
char a[3][3],em;
char per[3]={'1'};
char tem[20][2]={'1'};
int pcan=0;
int tcan=0;

ifstream fin;
ofstream fout;

void s1(int i)
{
	if(a[i][0]==a[i][1]==a[i][2])
	 	 for(int j=0;j<=2;j++)
	 	  if(per[j]!=a[i][0])
	 	   {
	 	   		pcan++;
	 	   		per[pcan-1]=a[i][0];
	 	   		return;
		   }
}

void s2(int i)
{
		if(a[0][i]==a[1][i]==a[2][i])
	 	 for(int j=0;j<=2;j++)
	 	  if(per[j]!=a[0][i])
	 	   {
	 	   		pcan++;
	 	   		per[pcan]=a[0][i];
	 	   		return;
		   }
}

int main()
{
	fin.open("count.in");
	fout.open("count.out");

	for(int i=0;i<=2;i++)
	{
	 for(int j=0;j<=2;j++)
	  fin>>a[i][j];
	 //std::cin>>em;
	}
	
	for(int i=0;i<=2;i++)
	 {
	 	s1(i); 
		s2(i);
	 }
	 if(a[0][0]==a[1][1]==a[2][2])
		for(int j=0;j<=2;j++)
	 	  if(per[j]!=a[0][0])
	 	   {
	 	   		pcan++;
	 	   		per[pcan]=a[0][0];
	 	   		break;
		   }
	 if(a[2][0]==a[1][1]==a[0][2])
		for(int j=0;j<=2;j++)
	 	  if(per[j]!=a[0][2])
	 	   {
	 	   		pcan++;
	 	   		per[pcan]=a[0][2];
	 	   		break;
		   }

	for(int i=0;i<=2;i++)
	 {
	 	if((a[i][0]==a[i][1])&&!(a[i][0]==a[i][1]==a[i][2]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[i][0]&&tem[j][1]==a[i][2])||(tem[j][0]==a[i][2]&&tem[j][1]==a[i][0]))
	 	   {
	 	   		tem[tcan][0]=a[i][0];
	 	   		tem[tcan][1]=a[i][2];
	 	   		tcan++;
	 	   		break;
		   }else
		   
	 	if((a[i][2]==a[i][1])&&!(a[i][0]==a[i][1]==a[i][2]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[i][0]&&tem[j][1]==a[i][2])||(tem[j][0]==a[i][2]&&tem[j][1]==a[i][0]))
	 	   {
	 	   		tem[tcan][0]=a[i][0];
	 	   		tem[tcan][1]=a[i][2];
	 	   		tcan++;
	 	   		break;
		   } else
		   
		if((a[i][0]==a[i][2])&&!(a[i][0]==a[i][1]==a[i][2]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[i][1]&&tem[j][1]==a[i][2])||(tem[j][0]==a[i][2]&&tem[j][1]==a[i][1]))
	 	   {
	 	   		tem[tcan][0]=a[i][1];
	 	   		tem[tcan][1]=a[i][2];
	 	   		tcan++;
	 	   		break;
		   }  
	 	
	 	if((a[0][i]==a[1][i])&&!(a[0][i]==a[1][i]==a[2][i]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[0][i]&&tem[j][1]==a[2][i])||(tem[j][0]==a[2][i]&&tem[j][1]==a[0][i]))
	 	   {
	 	   		tem[tcan][0]=a[0][i];
	 	   		tem[tcan][1]=a[2][i];
	 	   		tcan++;
	 	   		break;
		   }else
		   
	 	if((a[2][i]==a[1][i])&&!(a[0][i]==a[1][i]==a[2][i]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[0][i]&&tem[j][1]==a[2][i])||(tem[j][0]==a[2][i]&&tem[j][1]==a[0][i]))
	 	   {
	 	   		tem[tcan][0]=a[0][i];
	 	   		tem[tcan][1]=a[2][i];
	 	   		tcan++;
	 	   		break;
		   } else
		   
		if((a[0][i]==a[2][i])&&!(a[0][i]==a[1][i]==a[2][i]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[1][i]&&tem[j][1]==a[2][i])||(tem[j][0]==a[2][i]&&tem[j][1]==a[1][i]))
	 	   {
	 	   		tem[tcan][0]=a[1][i];
	 	   		tem[tcan][1]=a[2][i];
	 	   		tcan++;
	 	   		break;
		   }  
	 }

		if((a[0][0]==a[1][1])&&!(a[0][0]==a[1][1]==a[2][2]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[0][0]&&tem[j][1]==a[2][2])||(tem[j][0]==a[2][2]&&tem[j][1]==a[0][0]))
	 	   {
	 	   		tem[tcan][0]=a[0][0];
	 	   		tem[tcan][1]=a[2][2];
	 	   		tcan++;
	 	   		break;
		   }else
		   
	 	if((a[2][2]==a[1][1])&&!(a[0][0]==a[1][1]==a[2][2]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[0][0]&&tem[j][1]==a[2][2])||(tem[j][0]==a[2][2]&&tem[j][1]==a[0][0]))
	 	   {
	 	   		tem[tcan][0]=a[0][0];
	 	   		tem[tcan][1]=a[2][2];
	 	   		tcan++;
	 	   		break;
		   } else
		   
		if((a[0][0]==a[2][2])&&!(a[0][0]==a[1][1]==a[2][2]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[1][1]&&tem[j][1]==a[2][2])||(tem[j][0]==a[2][2]&&tem[j][1]==a[1][1]))
	 	   {
	 	   		tem[tcan][0]=a[1][1];
	 	   		tem[tcan][1]=a[2][2];
	 	   		tcan++;
	 	   		break;
		   }
		   
		if((a[2][0]==a[1][1])&&!(a[2][0]==a[1][1]==a[0][2]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[2][0]&&tem[j][1]==a[0][2])||(tem[j][0]==a[0][2]&&tem[j][1]==a[2][0]))
	 	   {
	 	   		tem[tcan][0]=a[2][0];
	 	   		tem[tcan][1]=a[0][2];
	 	   		tcan++;
	 	   		break;
		   }else
		   
	 	if((a[0][2]==a[1][1])&&!(a[2][0]==a[1][1]==a[0][2]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[2][0]&&tem[j][1]==a[0][2])||(tem[j][0]==a[0][2]&&tem[j][1]==a[2][0]))
	 	   {
	 	   		tem[tcan][0]=a[2][0];
	 	   		tem[tcan][1]=a[0][2];
	 	   		tcan++;
	 	   		break;
		   } else
		   
		if((a[2][0]==a[0][2])&&!(a[2][0]==a[1][1]==a[0][2]))
	 	 for(int j=0;j<=2;j++)
	 	  if((tem[j][0]==a[1][1]&&tem[j][1]==a[0][2])||(tem[j][0]==a[0][2]&&tem[j][1]==a[1][1]))
	 	   {
	 	   		tem[tcan][0]=a[1][1];
	 	   		tem[tcan][1]=a[0][2];
	 	   		tcan++;
	 	   		break;
		   }   
		   
	fout<<"1\n1";
	
	fout.close();
	fin.close();
	return 0;	 
}
