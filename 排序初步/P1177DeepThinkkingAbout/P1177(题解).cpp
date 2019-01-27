#include<iostream>
#include<cstdio>
using namespace std;
long n=0,a[100000];
void quick_sort(int x,int y)
            {
                int i=x,j=y,t;//t用于稍后的交换
                int k=a[x];
                if(i>=j)
                    return;
                while (i<j)
                {
                    while((i<j)&&a[j]>=k)
                        j--;
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                    while((i<j)&&(a[i]<k))
                        i++;
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
                quick_sort(x,i-1);
                quick_sort(i+1,y);
                return;
            }
int main()
{
  long i=0;
  scanf("%i",&n);
  for(i=0;i<n;i++)
  {
  	scanf("%i",&a[i]);
  }
  quick_sort(0,n-1);
  for(i=0;i<n;i++)
  {
  	printf("%i ",a[i]);
  }
  printf("\n");
  //fclose(stdin);
  return 0;
}
