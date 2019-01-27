#include<bits/stdc++.h>
using namespace std;
int fa[30001],front[30001],num[30001],x,y,i,j,n,T,ans;    //fa[i]表示飞船i的祖先
//front[i]表示飞船i与其所在列队头的距离
                                        //num[i]表示第i列的飞船数量 
char ins;
int find(int n){                                        //查找祖先的函数 
    if(fa[n]==n)return fa[n];
    int fn=find(fa[n]);                                    //先递归找到祖先 
    front[n]+=front[fa[n]];    //在回溯的时候更新front（因为更新时要用到正确的front[祖先]，
                                    //所以只能在回溯的时候更新） 
    return fa[n]=fn;
}
int main(){
    cin>>T;
    for(i=1;i<=30000;++i){                                //定初值 
        fa[i]=i;
        front[i]=0;
        num[i]=1;
    }
    while(T--){
        cin>>ins>>x>>y;
        int fx=find(x);                                    //fx为x所在列的队头 
        int fy=find(y);                                    //fy同上 
        if(ins=='M'){
            front[fx]+=num[fy];        //更新front[x所在列队头(现在在y所在队列后面)]
//即加上y所在队列的长度 
            fa[fx]=fy;                                    //将fy设为fx的祖先 
            num[fy]+=num[fx];                            //更新以fy为队头队列的长度 
            num[fx]=0;                        //以fx为队头的队列已不存在，更新 
        }
        if(ins=='C'){
            if(fx!=fy)cout<<"-1"<<endl;            //若x和y的祖先不相同，则不在同一列 
else cout<<abs(front[x]-front[y])-1<<endl;    //否则利用x和y离队头的距离算
//出它们的距离 
        }
    }
    return 0;
}