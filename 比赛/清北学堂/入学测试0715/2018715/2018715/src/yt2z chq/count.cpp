#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
char a[5][5];
int ans,cnt;
char t[12];
char x[12][3];
int main()
{
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)  cin>>a[i][j];
    
    
  for(int i=1;i<=3;i++) 
	if(a[i][1]==a[i][2]&&a[i][1]==a[i][3]&&a[i][2]==a[i][3]) 
	{
	  bool f=true;
	  for(int j=0;j<ans;j++) if(a[i][1]==t[j]) {f=false;break;}
	  if(f==true)   {t[ans]=a[i][1];ans++;}
    }
    else  if(a[i][1]==a[i][2]||a[i][1]==a[i][3]||a[i][2]==a[i][3])  
	{
	  bool f=true;
	  for(int j=1;j<=cnt;j++) 
	  {
	    if((a[i][1]==x[j][1]&&a[i][2]==x[j][2])||(a[i][1]==x[j][2]&&a[i][2]==x[j][1])) 
	      {f=false;break;}
	    if((a[i][1]==x[j][2]&&a[i][3]==x[j][1])||(a[i][1]==x[j][1]&&a[i][3]==x[j][2])) 
	      {f=false;break;}  
	    if((a[i][2]==x[j][1]&&a[i][3]==x[j][2])||(a[i][2]==x[j][2]&&a[i][3]==x[j][1])) 
	      {f=false;break;}  
	  }
	  if(f==true) 
	  {cnt++;
	   x[cnt][1]=a[i][1];
	   x[cnt][2]=a[i][2];
	   if(x[cnt][1]==x[cnt][2]) x[cnt][2]=a[i][3];
	  }  
	}
    
  
  
  for(int i=1;i<=3;i++)  
  {
    if(a[1][i]==a[2][i]&&a[1][i]==a[3][i]&&a[2][i]==a[3][i]) 
    {
	  bool f=true;
	  for(int j=0;j<ans;j++) if(a[1][i]==t[j]) {f=false;break;}
	  if(f==true)   {t[ans]=a[1][i];ans++;}
    }
    else if(a[1][i]==a[2][i]||a[1][i]==a[3][i]||a[2][i]==a[3][i]) 
    {
	  bool f=true;
	  for(int j=1;j<=cnt;j++) 
	  {
	    if(a[1][i]==x[j][1]&&a[2][i]==x[j][2])
	      {f=false;break;}
		if(a[1][i]==x[j][2]&&a[2][i]==x[j][1])
		  {f=false;break;}
	    if(a[1][i]==x[j][1]&&a[3][i]==x[j][2])
	      {f=false;break;}
		if(a[1][i]==x[j][2]&&a[3][i]==x[j][1])
		  {f=false;break;}
	    if(a[2][i]==x[j][1]&&a[3][i]==x[j][2])
	      {f=false;break;}
		if(a[2][i]==x[j][2]&&a[3][i]==x[j][1])
		  {f=false;break;}
	  }   
	  if(f==true) 
	  {cnt++;
	   x[cnt][1]=a[1][i];
	   x[cnt][2]=a[2][i];
	   if(x[cnt][1]==x[cnt][2]) x[cnt][2]=a[3][i];
	  
		}  
	}
}
    
    
  if(a[1][1]==a[2][2]&&a[1][1]==a[3][3]&&a[2][2]==a[3][3])	
  {
	  bool f=true;
	  for(int j=0;j<ans;j++) if(a[1][1]==t[j]) {f=false;break;}
	  if(f==true)   {t[ans]=a[1][1];ans++;}
    }
  else if(a[1][1]==a[2][2]||a[2][2]==a[3][3]||a[1][1]==a[3][3]) 
  {
	  bool f=true;
	  for(int j=1;j<=cnt;j++) 
	  {
	    if((a[1][1]==x[j][1]&&a[2][2]==x[j][2])||(a[1][1]==x[j][2]&&a[2][2]==x[j][1]) )
	      {f=false;break;}
	    if((a[1][1]==x[j][1]&&a[3][3]==x[j][2])||(a[1][1]==x[j][2]&&a[3][3]==x[j][1]) )
	      {f=false;break;}
	    if((a[2][2]==x[j][1]&&a[3][3]==x[j][2])||(a[2][2]==x[j][2]&&a[3][3]==x[j][1]) )
	      {f=false;break;}
	  }   
	  if(f==true) 
	  {x[cnt][1]=a[1][1];
	   x[cnt][2]=a[2][2];
	   if(x[cnt][1]==x[cnt][2]) x[cnt][2]=a[3][3];
	    cnt++;
		}  
	}
  
  
  
  if(a[1][3]==a[2][2]&&a[1][3]==a[3][1]&&a[2][2]==a[3][1])
  {
	  bool f=true;
	  for(int j=0;j<ans;j++) if(a[1][3]==t[j]) {f=false;break;}
	  if(f==true)   {t[ans]=a[1][3];ans++;}
    }
  else if(a[1][3]==a[2][2]||a[2][2]==a[3][1]||a[1][3]==a[3][1]) 
  {
	  bool f=true;
	  for(int j=1;j<=cnt;j++) 
	  {
	    if((a[1][3]==x[j][1]&&a[2][2]==x[j][2])||(a[1][3]==x[j][2]&&a[2][2]==x[j][1]) )
	      {f=false;break;}
	    if((a[1][3]==x[j][1]&&a[3][1]==x[j][2])||(a[1][3]==x[j][2]&&a[3][1]==x[j][1]) )
	      {f=false;break;}
	    if((a[2][2]==x[j][1]&&a[3][1]==x[j][2])||(a[2][2]==x[j][2]&&a[3][1]==x[j][1]) )
	      {f=false;break;}
	  }   
	  if(f==true) 
	  {x[cnt][1]=a[1][3];
	   x[cnt][2]=a[2][2];
	   if(x[cnt][1]==x[cnt][2]) x[cnt][2]=a[3][1];
	    cnt++;
		}  
	}
	           
  cout<<ans<<endl;
  cout<<cnt<<endl;
  return 0;
}
