#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct card{int kind;int cost;int guo;string dis;};
struct people{int atk;int hp;int tai;int chf;int dis;};
struct magic{int atk;int drew;int lfei;int aoe;};
int zucard[2][31],handcard[2][11],kucard[2][61];
int health[2],l=1,t[2],femax[2],fnow,hands[2],chaof[2],tai[2],guo[2];bool p=true,p1;
card allcard[250];people suicong[350],chang[2][8]; magic fashu[350];
void lost(int a,int x)
{
    for(int i=x;i<hands[a];i++)handcard[a][i]=handcard[a][i+1];
    hands[a]--;
}
void dcard(int x,int n)
{
    for(int i=1;i<=n;i++)
    {
        t[x]--;if(hands[x]<10&&t[x]>0)
        {
            hands[x]++;handcard[x][hands[x]]=kucard[x][t[x]];
        }
        if(t[x]<1)health[x]+=t[x]-1;
    }
}
void xi(int a,int x)
{
    int k=rand()%t[a]+1;
    for(int i=t[a];i>k;i--)kucard[a][i]=kucard[a][i-1];
    kucard[a][k]=x;t[a]++;
}
void ges(int x)
{
    cout<<x<<" ";if(x<10)cout<<" ";
}
void ges2(int x)
{
    int kg=6;
    if(x%2){kg-=2;cout<<"风";}x/=2;
    if(x%2){kg-=2;cout<<"冲";}x/=2;
    if(x%2){kg-=2;cout<<"嘲";}x/=2; 
    for(int i=1;i<=kg;i++)cout<<" ";
}
void dscreen(int x)
{
    if(p1){cout<<allcard[x].dis;return;} 
    ges(allcard[x].kind);ges(allcard[x].cost);ges(allcard[x].guo);
    if (allcard[x].kind==1){ges(suicong[x].atk);ges(suicong[x].hp);ges(suicong[x].chf);}
                      else {ges(fashu[x].atk);ges(fashu[x].drew);ges(fashu[x].aoe);}
}
void cscreen(int a,people x)
{
    cout<<x.atk;int pp=1;if(x.atk>9)pp=0;
    if(a<1&&x.tai||a)cout<<"-";if(a<1&&x.tai<1)cout<<"z";
    ges(x.hp);if(pp)cout<<" ";
}
void screen(int a,int b)
{
    for(int i=1;i<=30;i++)cout<<endl;cout<<"                  "<<health[b]<<endl;
    for(int i=1;i<=7;i++)cscreen(1,chang[b][i]);cout<<"     "<<t[b]-1<<endl;
    for(int i=1;i<=7;i++)ges2(chang[b][i].chf);cout<<endl;
    for(int i=1;i<=7;i++)ges2(chang[a][i].chf);cout<<endl;
    for(int i=1;i<=7;i++)cscreen(0,chang[a][i]);cout<<"     "<<t[a]-1<<endl;
    cout<<"                  "<<health[a]<<"     "<<fnow<<endl;
    if(tai[a]){cout<<"0:";dscreen(0);cout<<endl;}
    for(int i=1;i<=hands[a];i++)
    {
        int x=handcard[a][i];
        cout<<i<<":";dscreen(x);cout<<endl;
    }
    if(!p)cout<<endl<<"违规操作"<<endl; 
}
void jin(int a,int y,int w)
{
    chang[a][y].atk=suicong[w].atk;chang[a][y].hp=suicong[w].hp;
    chang[a][y].chf=suicong[w].chf;chang[a][y].dis=chang[a][y].dis;
    if(chang[a][y].chf/4%2)chaof[a]++;chang[a][y].tai=0;
    if(chang[a][y].chf/2%2&&chang[a][y].chf%2<1)chang[a][y].tai=1;
    if(chang[a][y].chf/2%2&&chang[a][y].chf%2)chang[a][y].tai=2;
}
void chu(int a,int x)
{
    chang[a][x].hp=0;chang[a][x].atk=0;chang[a][x].tai=1;
    if(chang[a][x].chf/4%2)chaof[a]--;chang[a][x].chf=0;
}
void blood(int a,int x,int y)
{
    chang[a][x].hp-=y;if(chang[a][x].hp<=0)chu(a,x);
}
void use(int a,int x,int y)
{
    if(x>hands[a])return;int w=handcard[a][x];
    if(x<1&&y<8&&(y<1||y&&chang[1-a][y].hp)&&fnow>1&&tai[a])
    {
        if(y==0){health[1-a]-=1;fnow-=2;tai[a]=0;p=true;}
        if(y>0&&chang[1-a][y].hp>0){blood(1-a,y,1);fnow-=2;tai[a]=0;p=true;}
        return;
    }
    if(allcard[w].kind==1&&y>0&&y<8&&chang[a][y].hp==0&&fnow>=allcard[w].cost)
    {
        jin(a,y,w);lost(a,x);fnow-=allcard[w].cost;
        guo[a]+=allcard[w].guo;p=true;
    }
    if(allcard[w].kind==2&&fnow>=allcard[w].cost&&y<8&&(y==0||y>0&&chang[1-a][y].hp>0))
    {
        if(w==40)fnow++;if(y==0&&w!=30)
        {
            health[1-a]-=fashu[w].atk;fnow-=allcard[w].cost;
            dcard(a,fashu[w].drew);lost(a,x);guo[a]+=allcard[w].guo;
        }
        if(y>0&&chang[1-a][y].hp>0)
        {
            blood(1-a,y,fashu[w].atk);dcard(a,fashu[w].drew);
            lost(a,x);fnow-=allcard[w].cost;guo[a]+=allcard[w].guo;
        }
        health[1-a]-=fashu[w].aoe;p=true;
        for(int i=1;i<8;i++)blood(1-a,i,fashu[w].aoe);
    }
}
void kill(int a,int x,int y)
{
    if(chang[a][x].atk>0&&chang[a][x].tai>0&&x>0&&x<8&&y>=0&&y<8)
    {
        if(y==0&&chaof[1-a]<1)
        {
            health[1-a]-=chang[a][x].atk;chang[a][x].tai--;p=true;
        }
        if(y>0&&chang[1-a][y].hp>0&&(chaof[1-a]<1||chang[1-a][y].chf/4%2))
        {
            int sh=chang[a][x].atk;chang[a][x].tai--;p=true;
            blood(a,x,chang[1-a][y].atk);blood(1-a,y,sh);
        }
    }
}
int main()
{ 

    health[1]=health[0]=30;t[1]=t[0]=31;int x,y=0,z=0;p1=1; 
    //allcard[0].kind=2;allcard[0].cost=0;fashu[0].lfei=1;
    {
    allcard[0].kind=2;allcard[0].cost=2;fashu[0].atk=1;allcard[0].dis="英雄技能2费打1"; 
    allcard[1].kind=1;allcard[1].cost=1;suicong[1].atk=1;suicong[1].hp=2;allcard[1].dis="1-1-2白板"; 
    allcard[2].kind=1;allcard[2].cost=1;suicong[2].atk=2;suicong[2].hp=1;allcard[2].dis="1-2-1白板"; 
    allcard[3].kind=1;allcard[3].cost=0;suicong[3].atk=1;suicong[3].hp=1;allcard[3].dis="0-1-1白板";
    allcard[4].kind=2;allcard[4].cost=1;fashu[4].atk=2;allcard[4].dis="1费打2";
    allcard[5].kind=1;allcard[5].cost=2;suicong[5].atk=1;suicong[5].hp=5;allcard[5].dis="2-1-5白板";
    allcard[6].kind=1;allcard[6].cost=2;suicong[6].atk=2;suicong[6].hp=3;allcard[6].dis="2-2-3白板";
    allcard[7].kind=1;allcard[7].cost=2;suicong[7].atk=3;suicong[7].hp=2;allcard[7].dis="2-3-2白板";
    allcard[8].kind=2;allcard[8].cost=2;fashu[8].atk=1;fashu[8].drew=1;allcard[8].dis="2费打1抽1";
    allcard[9].kind=1;allcard[9].cost=3;suicong[9].atk=2;suicong[9].hp=5;allcard[9].dis="3-2-5白板";
    allcard[10].kind=1;allcard[10].cost=3;suicong[10].atk=4;suicong[10].hp=3;allcard[10].dis="3-4-3白板";
    allcard[11].kind=2;allcard[11].cost=3;fashu[11].atk=4;allcard[11].dis="3费打4";
    allcard[12].kind=2;allcard[12].cost=3;fashu[12].drew=2;allcard[12].dis="3费抽2";
    allcard[13].kind=1;allcard[13].cost=4;suicong[13].atk=4;suicong[13].hp=5;allcard[13].dis="4-4-5白板";
    allcard[14].kind=1;allcard[14].cost=4;suicong[14].atk=6;suicong[14].hp=3;allcard[14].dis="4-6-3白板";
    allcard[15].kind=2;allcard[15].cost=4;fashu[15].atk=3;fashu[15].drew=1;allcard[15].dis="4费打3抽1";
    allcard[16].kind=2;allcard[16].cost=4;fashu[16].atk=6;allcard[16].dis="4费打6";
    allcard[17].kind=1;allcard[17].cost=5;suicong[17].atk=5;suicong[17].hp=6;allcard[17].dis="5-5-6白板";
    allcard[18].kind=2;allcard[18].cost=6;fashu[18].atk=4;fashu[18].drew=2;allcard[18].dis="6费打4抽2";
    allcard[19].kind=1;allcard[19].cost=7;suicong[19].atk=9;suicong[19].hp=5;allcard[19].dis="7-9-5白板";
    allcard[20].kind=1;allcard[20].cost=8;suicong[20].atk=6;suicong[20].hp=10;allcard[20].dis="8-6-10白板";
    allcard[21].kind=1;allcard[21].cost=2;suicong[21].atk=1;suicong[21].hp=4;suicong[21].chf=4;allcard[21].dis="2-1-4嘲讽";
    allcard[22].kind=1;allcard[22].cost=4;suicong[22].atk=5;suicong[22].hp=4;suicong[22].chf=4;allcard[22].dis="4-5-4嘲讽";
    allcard[23].kind=1;allcard[23].cost=6;suicong[23].atk=5;suicong[23].hp=7;suicong[23].chf=4;allcard[23].dis="6-5-7嘲讽";
    allcard[24].kind=1;allcard[24].cost=9;suicong[24].atk=4;suicong[24].hp=12;suicong[24].chf=4;allcard[24].dis="9-4-12嘲讽";
    allcard[25].kind=2;allcard[25].cost=2;fashu[25].aoe=1;allcard[25].dis="2费对所有敌方角色打1";
    allcard[26].kind=2;allcard[26].cost=5;fashu[26].atk=1;fashu[26].aoe=2;allcard[26].dis="5费对一个敌方角色打3，其余敌方角色打2";
    allcard[27].kind=1;allcard[27].cost=0;allcard[27].guo=1;suicong[27].atk=2;suicong[27].hp=2;suicong[27].chf=4;allcard[27].dis="0-2-2嘲讽，过载1";
    allcard[28].kind=1;allcard[28].cost=4;allcard[28].guo=2;suicong[28].atk=7;suicong[28].hp=7;allcard[28].dis="4-7-7，过载2";
    allcard[29].kind=1;allcard[29].cost=2;allcard[29].guo=1;suicong[29].atk=3;suicong[29].hp=4;allcard[29].dis="2-3-4，过载1";
    allcard[30].kind=2;allcard[30].cost=2;allcard[30].guo=3;fashu[30].atk=8;allcard[30].dis="2费对一个敌方随从打8，过载3";
    allcard[31].kind=2;allcard[31].cost=1;allcard[31].guo=1;fashu[31].atk=3;allcard[31].dis="1费打3，过载1";
    allcard[32].kind=1;allcard[32].cost=3;suicong[32].atk=2;suicong[32].hp=4;suicong[32].chf=1;allcard[32].dis="3-2-4风怒";
    allcard[33].kind=1;allcard[33].cost=7;suicong[33].atk=4;suicong[33].hp=8;suicong[33].chf=1;allcard[33].dis="7-4-8风怒";
    allcard[34].kind=1;allcard[34].cost=4;suicong[34].atk=4;suicong[34].hp=3;suicong[34].chf=2;allcard[34].dis="4-4-3冲锋";
    allcard[35].kind=1;allcard[35].cost=2;suicong[35].atk=2;suicong[35].hp=1;suicong[35].chf=2;allcard[35].dis="2-2-1冲锋";
    allcard[36].kind=1;allcard[36].cost=5;suicong[36].atk=3;suicong[36].hp=2;suicong[36].chf=3;allcard[36].dis="5-3-2风怒冲锋";
    allcard[37].kind=1;allcard[37].cost=2;allcard[37].guo=1;suicong[37].atk=2;suicong[37].hp=3;suicong[37].chf=6;allcard[37].dis="2-2-3冲锋嘲讽，过载1";
    allcard[38].kind=2;allcard[38].cost=4;fashu[38].aoe=2;allcard[38].dis="4费对所有敌方角色打2";
    allcard[39].kind=2;allcard[39].cost=7;fashu[39].aoe=4;allcard[39].dis="7费对所有敌方角色打4";
    allcard[40].kind=2;allcard[40].dis="在本回合+1费";}
    srand((unsigned)time(NULL));
    for(int i=1;i<=30;i++)kucard[0][i]=rand()%39+1;
    for(int i=1;i<=30;i++)kucard[1][i]=rand()%39+1;
    dcard(0,3);for(int i=1;i<=7;i++)chang[0][i].tai=1;
    dcard(1,4);for(int i=1;i<=7;i++)chang[1][i].tai=1;
    for(int i=30;i>0;i--){dscreen(kucard[0][i]);cout<<"    ";dscreen(kucard[1][i]);cout<<endl;}
    screen(0,1);p=false;cout<<endl<<"选择你想换下的牌，0为结束"<<endl;
    cin>>x;while(x)if(x<=hands[0])
    {
        xi(0,handcard[0][x]);lost(0,x);y++;p=true;screen(0,1);
        cout<<endl<<"选择你想换下的牌，0为结束"<<endl;cin>>x;p=false;
    }
    else{screen(0,1);cout<<endl<<"选择你想换下的牌，0为结束"<<endl;cin>>x;}
    p=true;dcard(0,y);screen(1,0);cout<<endl<<"选择你想换下的牌，0为结束"<<endl;
    cin>>x;p=false;while(x)if(x<=hands[1])
    {
        xi(1,handcard[1][x]);lost(1,x);z++;p=true;screen(1,0);
        cout<<endl<<"选择你想换下的牌，0为结束"<<endl;cin>>x;p=false;
    }
    else{screen(1,0);cout<<endl<<"选择你想换下的牌，0为结束"<<endl;cin>>x;}
    dcard(1,z);hands[1]++;handcard[1][5]=40;
    while (health[0]>0&&health[1]>0)
    {
        int a,b=l%2;l++;a=l%2;tai[a]=1;dcard(a,1);
        if(femax[a]<10)femax[a]++;fnow=femax[a]-guo[a];
        for(int i=1;i<=7;i++)if(chang[a][i].chf%2)chang[a][i].tai=2;else chang[a][i].tai=1;
        guo[a]=0;p=true;screen(a,b);
        cout<<endl<<"输入一个数，1为用牌，2为攻击，0为结束本轮"<<endl;cin>>x;
        while(x&&health[0]>0&&health[1]>0)
        {
            p=false;if(x==1)
            {
                cout<<"选择一张牌"<<endl;cin>>y;
                if(allcard[handcard[a][y]].kind>1&&fashu[handcard[a][y]].atk<1)z=0;
                else {if(allcard[handcard[a][y]].kind>1)cout<<"选择释放目标（0为英雄）"<<endl;
                else cout<<"选择放置位置"<<endl;cin>>z;}
                use(a,y,z);
            }
            if(x==2)
            {
                cout<<"选择进行攻击的随从"<<endl;cin>>y;
                cout<<"选择攻击目标（0为英雄）"<<endl;cin>>z; 
                kill(a,y,z);
            }
            screen(a,b);
            cout<<endl<<"输入一个数，1为用牌，2为攻击，0为结束本轮"<<endl;cin>>x;
        }
    }
    cout<<"You win!"<<endl;return 0;
}
