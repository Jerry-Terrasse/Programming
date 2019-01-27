#include<iostream>
#include<cstring>
#include<bitset>
#include<map>
using namespace std;
map<bitset<10>,int>mp;
bitset<10>a,b;
inline bool operator<(const bitset<10>&,const bitset<10>&)const;
int main()
{
  register int i=0;
  mp.insert(make_pair(a,1));
  a[1]=1;
  mp.insert(make_pair(a,2));
  if(mp.count(a))
  {
    cout<<'a'<<endl;
  }
  a[0]=0;
  if(mp.count(a))
  {
    cout<<'b'<<endl;
  }
  a[2]=1;
  if(mp.count(a))
  {
    cout<<'c'<<endl;
  }
  return 0;
}
inline bool operator<(const bitset<10> &a,const bitset<10> &b)const
{
  return strcmp(a.to_string(),b.to_string());
}