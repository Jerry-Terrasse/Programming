//by moqiyu_Luogu
#include<iostream>
#include<conio.h>
#include<cstdio>
#include <stdio.h>
#include <stdlib.h>
#include<iomanip>
#include<fstream>
#include<string>    
#include <time.h> 
#include <windows.h>
#include<ctime>
using namespace std;
int n,ma=-2147483647,kgs,gs[100+5],kgs2,hbbh,hbdh;
string st,s[100+5],s2[100+5];
char hbd[10+5],hbb[10+5];
int main()
{
s[1]="东风";
s[2]="何处";
s[3]="人间";
s[4]="风流";
s[5]="归去";
s[6]="春风";
s[7]="西风";
s[8]="归来";
s[9]="江南";
s[10]="相思";
s[11]="梅花";
s[12]="千里";
s[13]="回首";
s[14]="明月";
s[15]="多少";
s[16]="如今";
s[17]="阑干";
s[18]="年年";
s[19]="万里";
s[20]="一笑";
s[21]="黄昏";
s[22]="当年";
s[23]="天涯";
s[24]="相逢";
s[25]="芳草";
s[26]="樽前";
s[27]="一枝";
s[28]="风雨";
s[29]="流水";
s[30]="依旧";
s[31]="风吹";
s[32]="风月";
s[33]="多情";
s[34]="故人";
s[35]="当时";
s[36]="无人";
s[37]="斜阳";
s[38]="不知";
s[39]="不见";
s[40]="深处";
s[41]="时节";
s[42]="平生";
s[43]="凄凉";
s[44]="春色";
s[45]="匆匆";
s[46]="功名";
s[47]="一点";
s[48]="无限";
s[49]="今日";
s[50]="天上";
s[51]="杨柳";
s[52]="西湖";
s[53]="桃花";
s[54]="扁舟";
s[55]="消息";
s[56]="憔悴";
s[57]="何事";
s[58]="芙蓉";
s[59]="神仙";
s[60]="一片";
s[61]="桃李";
s[62]="人生";
s[63]="十分";
s[64]="心事";
s[65]="黄花";
s[66]="一声";
s[67]="佳人";
s[68]="长安";
s[69]="东君";
s[70]="断肠";
s[71]="而今";
s[72]="鸳鸯";
s[73]="为谁";
s[74]="十年";
s[75]="去年";
s[76]="少年";
s[77]="海棠";
s[78]="寂寞";
s[79]="无情";
s[80]="不是";
s[81]="时候";
s[82]="肠断";
s[83]="富贵";
s[84]="蓬莱";
s[85]="昨夜";
s[86]="行人";
s[87]="今夜";
s[88]="谁知";
s[89]="不似";
s[90]="江上";
s[91]="悠悠";
s[92]="几度";
s[93]="青山";
s[94]="何时";
s[95]="天气";
s[96]="唯有";
s[97]="一曲";
s[98]="月明";
s[99]="往事";
s2[1]="渔父引";
s2[2]="闲中好";
s2[3]="纥那曲";
s2[4]="梧桐影";
s2[5]="醉妆词";
s2[6]="南歌子";
s2[7]="朝天子";
s2[8]="忆少年";
s2[9]="荷叶杯";
s2[10]="舞马词";
s2[11]="晴偏好";
s2[12]="凭栏人";
s2[13]="花非花";
s2[14]="摘得新";
s2[15]="梧叶儿";
s2[16]="渔歌子";
s2[17]="归字谣";
s2[18]="浪淘沙";
s2[19]="杨柳枝";
s2[20]="八拍蛮";
s2[21]="十样花";
s2[22]="天净沙";
s2[23]="甘州曲";
s2[24]="醉吟商";
s2[25]="喜春来";
s2[26]="踏歌词";
s2[27]="秋风清";
s2[28]="抛球乐";
s2[29]="忆王孙";
s2[30]="古调笑";
s2[31]="遐方怨";
s2[32]="如梦令";
s2[33]="诉衷情";
s2[34]="西溪子";
s2[35]="天仙子";
s2[36]="风流子";
s2[37]="饮马歌";
s2[38]="相见欢";
s2[39]="定西番";
s2[40]="江城子";
s2[41]="望江怨";
s2[42]="长相思";
s2[43]="思帝乡";
s2[44]="河满子";
s2[45]="风光好";
s2[46]="望梅花";
s2[47]="醉太平";
s2[48]="上行杯";
s2[49]="感恩多";
s2[50]="长命女";
s2[51]="春光好";
s2[52]="酒泉子";
s2[53]="怨回纥";
s2[54]="生查子";
s2[55]="蝴蝶儿";
s2[56]="醉公子";
s2[57]="昭君怨";
s2[58]="玉蝴蝶";
s2[59]="归国谣";
s2[60]="女冠子";
s2[61]="恋情深";
s2[62]="赞浦子";
s2[63]="浣溪沙";
s2[64]="醉垂鞭";
s2[65]="中兴乐";
s2[66]="醉花间";
s2[67]="点绛唇";
s2[68]="雪花飞";
s2[69]="沙塞子";
s2[70]="水仙子";
s2[71]="菩萨蛮";
s2[72]="采桑子";
s2[73]="后庭花";
s2[74]="清商怨";
s2[75]="卜算子";
s2[76]="一落索";
s2[77]="谒金门";
s2[78]="柳含烟";
s2[79]="好事近";
s2[80]="天门谣";
s2[81]="忆闷令";
s2[82]="散余霞";
s2[83]="好女儿";
s2[84]="万里春";
s2[85]="太平年";
s2[86]="清平乐";
s2[87]="忆秦娥";
s2[88]="更漏子";
s2[89]="相思引";
s2[90]="落梅风";
s2[91]="江亭怨";
s2[92]="阮郎归";
s2[93]="贺圣朝";
s2[94]="甘草子";
s2[95]="珠帘卷";
s2[96]="画堂春";
s2[97]="三字令";
s2[98]="山花子";
s2[99]="忆余杭";
s2[100]="献天寿";
hbd[1]='~';
hbd[2]='-';
hbd[3]='^';
hbd[4]='*';
hbd[5]='+';
hbd[6]='.';
hbd[7]='@';
hbd[8]='`';
hbd[9]='$';
hbd[10]='=';
hbb[1]='|';
hbb[2]='+';
hbb[3]='.';
hbb[4]='`';
hbb[5]='$';
    cout<<"欢迎使用写诗器，请告诉我你的名字"<<endl;
    cin>>st;
    cout<<"写诗中,请稍后";
    srand(time(0));
    cout<<".";
    Sleep(1*1000);
    cout<<".";
    Sleep(1*1000);
    cout<<".";
    Sleep(1*1000);
    cout<<endl<<"写诗完毕，请到 诗.txt 查看"<<endl;
    Sleep(0.5*1000);
    n=(rand()-1)%50+1;
    hbdh=(rand()-1)%10+1;
    hbbh=(rand()-1)%5+1;
    if (n<5) n=5;
    freopen("诗.txt","w",stdout);
    for (int i=1;i<=n;i++)
    {
    gs[i]=(rand()-1)%10+1;
    if (gs[i]<4) gs[i]=4;
    if (gs[i]>ma) ma=gs[i];
    }
    ma*=2;
    ma+=2;
    for (int i=1;i<=ma*2;i++)
    cout<<hbd[hbdh];
    cout<<endl;
    kgs=(ma-3)/2;
    cout<<hbb[hbbh];
    for (int i=1;i<=kgs-1;i++)
    cout<<" ";
    cout<<s2[(rand()-1)%100+1];
    for (int i=1;i<=kgs;i++)
    cout<<" ";
    cout<<endl;
    kgs2=(ma-st.size())/2;
    cout<<hbb[hbbh];
    for (int i=1;i<=kgs2-1;i++)
    cout<<" ";
    cout<<st;
    for (int i=1;i<=kgs2;i++)
    cout<<" ";
    cout<<endl;
    for (int i=1;i<=n;i++)
    {
    cout<<hbb[hbbh];
    for (int j=1;j<=gs[i];j++)
    cout<<s[(rand()-1)%99+1];
    if (n%2==1&&i==n)
    cout<<"。";
    else
    if (i%2==1)
    cout<<"，";
    else
    cout<<"。";
    cout<<endl;
    }
    for (int i=1;i<=ma*2;i++)
    cout<<hbd[hbdh];
    cout<<endl;
    return 0;
}
