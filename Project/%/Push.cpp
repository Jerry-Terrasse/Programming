#include<iostream>
#include<map>
#include<cstring>
std::map<std::string,bool>mp;
inline void init();
int main()
{
  init();
  if(mp["蒲实学了三门高难竞赛"],mp["常规课还不落下"],mp["番还看得多"],mp["成天睡觉还考满分"],mp["游戏还打得好"])
  {
  	std::cout<<"蒲实真是太强了"<<std::endl;
  }
  else
  {
  	std::cout<<"蒲实还能变得更强"<<std::endl;
  }
  return 0;
}














inline void init()
{
  mp["蒲实学了三门高难竞赛"]=0;
  mp["番还看得多"]=1;
  mp["常规课还不落下"]=0;
  mp["成天睡觉还考满分"]=0;
  mp["游戏还打得好"]=1;
  return;
}
