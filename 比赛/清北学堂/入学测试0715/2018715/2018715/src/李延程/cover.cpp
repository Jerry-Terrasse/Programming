#include<iostream> 
#include<string>
//#include<stdio.h>
using namespace std;
 
int main()
{
   //freopen("cover.in", "r", stdin);
  // freopen("cover.out","w",stdout); 
     int n=0,k=0,i=0;
     int left[n],right[n];
     int minleft=0;
     int t=0,cc[n],b=1,longthmax=0,maxright=0,o=0;
     int longmax1,longlong;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
	cin>>left[i]>>right[i];}
    minleft=left[1];
    t=1;
    for(i=2;i<=n;i++)
    {
    
     if(minleft>=left[i])
     {
     	minleft=left[i];
     	t=i;
	 }
	}//查找最左侧点 
cout<<right[t]<<" ";//测试数据 
	for(i=2;i<=n;i++)
	{
		if(left[i]<=right[t])
		cc[b]=i;
		b++;
		}//找到左侧点小于t点的数据 
		b=b-1;
	//	cout<<b<<" ";
		maxright=right[t];
		//cout<<maxright<<" ";
	for(o=1;o<=b;o++)
	{
		if(maxright<right[cc[o]]);
		{
		maxright=right[cc[o]];}
	}//最右侧点
		cout<<maxright<<" ";
	 
	longthmax=maxright-minleft;
cout<<longthmax<<endl;
	

//fclose(stdin);
    //fclose(stdout);
	system("pause");
	return 0;
	 
}

