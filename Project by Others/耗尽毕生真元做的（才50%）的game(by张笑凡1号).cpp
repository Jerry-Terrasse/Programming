#include<iostream>
#include<map>
#include<algorithm>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<cmath>
#include<cctype>
#include<io.h>
#include<stdlib.h>
#include<fstream>
#include<shellapi.h>
#include<cstdio>
#include<winuser.h>
#include<cstring>
#define RED(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
#define YELLOW(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
#define GREEN(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
#define CYAN(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
#define BLUE(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
#define PURPLE(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
#define WHITE(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
#define HUANYUAN(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
#define GRAY(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
map<string,string>date; 
map<string,int>PROPMAX;
char ch;
long long a,b,gamesend;
bool bj,bj2;
int cour;
string st,Verification;
char mapmap[10001][10001],showmap[10001][10001];
DWORD t1,t2;
long long frequency,Maxfrequency;
HWND hwnd=GetForegroundWindow();
struct account{
    string ID;
    string PassWord;
}Account;
string propname[110]={"空","蒲草","纸","怪物的牙","活木","木板","战斗之书","防御之书","能量之书","解剖图","种植之书","木头","小石子","萝卜","土豆","正常的肉","怪物的肉","矿石","皮革","燧石","干草","小树枝","木炭","金锭","铁锭","鱼","木剑","石剑","铁剑","石斧","铁斧","石鸭嘴锄","铁鸭嘴锄","草甲","冰","木甲","药草","药","花","种子","铥","远古护甲","远古大剑","线","竹子","曼德拉草","催眠吹箭","绳子","石砖","机器元件","恶魔花","恶魔之灵","冰魔杖","蓝宝石","回旋镖","重生护符","红宝石","橙宝石","黄宝石","紫宝石","绿宝石","黑宝石","白宝石","黑莲花","纯黑护符","圣洁护符","懒人护符","反伤护符","寒冷护符","火魔杖","掠夺护符","寒冰吹箭","植物护符","燃烧吹箭","小肉块","火龙果","西瓜","茄子","浆果","果酱","肉汤","肉丸","红蘑菇","蓝蘑菇","绿蘑菇","蝴蝶松饼","蝴蝶翅膀","玉米","玉米鱼卷","青蛙腿","香酥鱼排","蛙腿汉堡","什锦圣代","鳄梨沙拉","仙人掌","培根煎蛋","南瓜饼干","蜜汁火腿","饺子","烤肉串","怪物千层面","蜜汁小肉块","鸡腿","火鸡大餐","蔬菜杂烩","石榴","蜂蜜","宝箱钥匙","仿造钥匙","万能钥匙"};
string id;
string password;
int dosum;
string dosomething[1001];
int propsum;
string now;
int prop[2][33];
int HP;
int MAXHP;
int Exocet;
int power;
int MAXpower;
int Day;
int percentage;
int hungry;
int MAXhungry; 
bool Course; 
bool rate(int Successrate,int allrate)
{
    srand(time(0));
    srand(rand()+time(0));
    int a=rand()%allrate+1;
    if(a<=Successrate) return true; else return false;
}
int findpropnumber(long long propnamenumber)
{
    long long lj;
    int i=1;
    for(;i<=32;i++)  if(prop[0][i]==propnamenumber) lj+=prop[1][i];
    return prop[1][i];;
}
bool findprop(long long propnamenumber)
{
    for(int i=1;i<=32;i++)  if(prop[0][i]==propnamenumber) return true;
    return false;
}
void pt(int propID,long long number)
{
    for(int i=1;i<=32;i++)
        if(prop[0][i]==propID)
        {
            if(prop[0][i]>=number) {prop[0][i]-=number;return;}
            if(prop[0][i]<number) {number-=prop[0][i];prop[0][i]=0;}
        }
    return;
}
string potout(int propID,long long number)
void HPdown(long long waittime)
{
    system("color 4F");
    Sleep(500);
    system("color");
}
void potin(int propID,long long number,long long )
{
    for(int i=1;i<=32;i++)
        if(prop[0][i]==propID)
            if(prop[1][i]+number>PROPMAX[propname[propID]]) {propID-=PROPMAX[propname[propID]]-prop[1][i];prop[1][i]=PROPMAX[propname[propID]];} else {prop[1][i]+=number;return;}
    for(int i=1;i<=32;i++)
        if(prop[0][i]==0) {prop[0][i]=propID;prop[1][i]=number;}
    return;
}
void Synthesis()
{

    return;
}
void test()
{
    for(int i=1;i<=32;i++)
        if(prop[1][i]<=0) {prop[0][i]=0;prop[1][i]=0;prop[2][i]=0;}
    return;
}
char ckzt(HWND hwnd)
{
    if(!IsIconic(hwnd)&&!IsZoomed(hwnd)) return '?'; else
        if(IsZoomed(hwnd)) return 'b'; else
            return 's';
}
void wait(int a)
{
    DWORD t1,t2;
    t1=GetTickCount();
    while(GetTickCount()-t1<a);
    return;
}
void say(string st,int speed)
{
    int l=st.length();
    for(int i=0;i<l;i++)cout<<st[i],Sleep(speed);
}
void Sigh()
{
    HUANYUAN();
    system("cls");
    while(!(bj==1&&ch=='\r'))
    {
        CYAN();
        cout<<"帐号:";
        cout<<Account.ID;
        cout<<endl;
        PURPLE();
        cout<<"密码:";
        for(int i=1;i<=Account.PassWord.size();i++)  cout<<'*';
        ch=getch();
        if(bj==0) 
        {
            if(ch=='\b'&&Account.ID!="") {Account.ID[Account.ID.size()-1]='\0';st=Account.ID;Account.ID="";for(int i=0;i<st.size()-1;i++) Account.ID+=st[i];} else
                if(ch=='\r') {bj=1;ch='\000';} else
                    if(ch=='\340') {ch=getch();} else
                        if(ch!='\r'&&ch!='\033') Account.ID+=ch;
        }
        if(bj==1) 
        {
            if(ch=='\b'&&Account.PassWord!="") {Account.PassWord[Account.PassWord.size()-1]='\0';st=Account.PassWord;Account.PassWord="";for(int i=0;i<st.size()-1;i++) Account.PassWord+=st[i];} else 
                if(ch=='\340') {ch=getch();if(ch=='H') bj=0;} else 
                    if(ch=='\340') {ch=getch();} else
                        if(ch!='\r'&&ch!='\033') Account.PassWord+=ch;
            if(bj2==0) {Account.PassWord="";bj2=1;}
        }
        system("cls");
        HUANYUAN();
    }
    string st2=Account.ID+".txt";
    if((_access(st2.c_str(),0))==-1) 
    {
        RED();
        cout<<st2<<endl;
        cout<<"打开帐号失败!原因【无此账号】";
        wait(1000);
        HUANYUAN();
        system("cls");
        ch='\0';
        Account.ID="";
        Account.PassWord="";
        Sigh();
        return; 
    }
    FILE* d=fopen(st2.c_str(),"rt+");
    char ch2;
    while(ch2!='\n')
    {
        fscanf(d,"%c",&ch2);
        if(ch2!='\n') password+=ch2;
    }
    if(password!=Account.PassWord)
    {
        RED();
        cout<<"打开账号失败!原因【密码错误】";
        wait(1000);
        HUANYUAN();
        system("cls");
        ch='\0';
        Account.PassWord="";
        Sigh();
        return; 
    }
    id=Account.ID;
    fscanf(d,"%d",&propsum);
    for(int i=1;i<=32;i++) fscanf(d,"%d%d%d",&prop[0][i],&prop[1][i],&prop[2][i]);
    fscanf(d,"%d%d%d%d%d%d%d%d&d%d",&HP,&MAXHP,&Exocet,&power,&MAXpower,&Day,&hungry,&MAXhungry,&cour,&gamesend);
    if(cour==0) Course=0; else Course=1;
    return;
}
void Establish()
{
    HUANYUAN();
    system("cls");
    while(!(bj==1&&ch=='\r'))
    {
        CYAN();
        cout<<"帐号:";
        cout<<Account.ID;
        cout<<endl;
        PURPLE();
        cout<<"密码:";
        for(int i=1;i<=Account.PassWord.size();i++)  cout<<'*';
        ch=getch();
        if(bj==0) 
        {
            if(ch=='\b'&&Account.ID!="") {st=Account.ID;Account.ID="";for(int i=0;i<st.size()-1;i++) Account.ID+=st[i];} else
                if(ch=='\r') {bj=1;ch='\000';} else
                    if(ch=='\340') {ch=getch();} else
                        if(ch!='\r'&&ch!='\033') Account.ID+=ch;
        }
        if(bj==1) 
        {
            if(ch=='\b'&&Account.PassWord!="") {st=Account.PassWord;Account.PassWord="";for(int i=0;i<st.size()-1;i++) Account.PassWord+=st[i];} else 
                if(ch=='\340') {ch=getch();if(ch=='H') bj=0;} else 
                    if(ch=='\340') {ch=getch();} else
                        if(ch!='\r'&&ch!='\033') Account.PassWord+=ch;
            if(bj2==0) {Account.PassWord="";bj2=1;}
        }
        system("cls");
        HUANYUAN();
    }
    ch='\0';
    while(ch!='\r')
    {
        YELLOW();
        cout<<"重新输入密码:";
        for(int i=1;i<=Verification.size();i++)
            cout<<'*';
        ch=getch();
        if(ch=='\b'&&Verification!="") {st=Verification;Verification="";for(int i=0;i<st.size()-1;i++) Verification+=st[i];} else
                if(ch=='\340') {ch=getch();} else
                    if(ch!='\r'&&ch!='\033') Verification+=ch;
        system("cls");
    }
    HUANYUAN();
    if(Verification!=Account.PassWord)
    {
        Account.PassWord="";
        Verification="";
        bj2=0;
        bj=1;
        ch='\0';
        RED();
        cout<<"两";
        YELLOW();
        cout<<"次";
        GREEN();
        cout<<"密";
        CYAN();
        cout<<"码";
        BLUE();
        cout<<"不";
        PURPLE();
        cout<<"同";
        HUANYUAN();
        cout<<"!";
        wait(1000);
        Establish();
        return;
    }
    string st3=Account.ID+".txt";
    if((_access(st3.c_str(),0))!=-1) 
    {
        RED();
        cout<<"文件创建失败!原因【已有此文件】";
        HUANYUAN();
        wait(1000);
        Account.PassWord="";
        Account.ID="";
        Verification="";
        bj2=0;
        bj=0;
        Establish();
        return;
    } 
    string st2="echo "+Account.PassWord+" >> "+st3;
    system(st2.c_str());
    FILE* a=fopen(st3.c_str(),"rt+");
    fprintf(a,"%s\n",Account.PassWord.c_str());
    fprintf(a,"0\n");
    for(int i=1;i<=32;i++) fprintf(a,"0 0 0\n");
    fprintf(a,"10\n50\n10\n20\n50\n1\n50\n100\n0\n%lld",send);
    GREEN();
    cout<<"地图种子(仅数字17个):";
    long long send;
    cin>>send;
    cout<<"文件创建成功!";
    system("cls");
    fprintf(a,"%lld",send);
    fclose(a);
    HUANYUAN();
    system("cls");
    Account.PassWord="";
    ch=getch();
    ch='\0';
    return;
}
void GO()
{
    power-=5;
    return;
}
void stop(long long alltime)
{
    for(int k=1;k<=10;k++)
    {
        long long j;
        cout<<"|——————————|\n"
        cout<<"|";
        for(int i=1;i<=j;i++) cout<<"■";
        for(int i=j+1;i<=10;i++) cout<<"　";
        cout<<"|\n";
        cout<<"|——————————|";
        wait(alltime/10);
    }
    return;
}
void SLEEP()
{
    system("cls");
    say("今天,救援队仍然没有来,希望，明天能有新气象。\n",100);
    say("今天做了：\n",250);
    for(int i=1;i<=dosum;i++)
    {
        cout<<dosum<<".";
        wait(100);
        say(dosomething[i],100);
        cout<<"\n";
        wait(100);
        dosomething[i]="";
    }
    wait(900);
    system("cls");
    say("■■■■■■　　　　　　　■■■■■■　　　　　　　■■■■■■\n　　　　■　　　　　　　　　　　　■　　　　　　　　　　　　■\n　　　■　　　　　　　　　　　　■　　　　　　　　　　　　■\n　　■　　　　　　　　　　　　■　　　　　　　　　　　　■\n　■　　　　　　　　　　　　■　　　　　　　　　　　　■\n■■■■■■　■　■　■　■■■■■■　■　■　■　■■■■■■　■　■　■\n",5);
    wait(400);
    system("cls");
    power=MAXpower;
    now="";
    dosum=0;
    hungry-=20;
    return;
}
void PROP()
{
    long long hang,lie;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(hang==i&&lie==j) YELLOW();
                HUANYUAN();
        }
    }
}
int main()
{
    PROPMAX["原材料"]=40;
    PROPMAX["魔法原材料"]=20;
    PROPMAX["食材"]=40;
    PROPMAX["菜品"]=20;
    PROPMAX["饰品"]=1;
    PROPMAX["种植"]=40;
    PROPMAX["防具"]=1;
    PROPMAX["武器"]=1;
    PROPMAX["斧"]=1;
    PROPMAX["镐"]=1;
    PROPMAX["消耗武器"]=10;
    PROPMAX["书"]=1;
    PROPMAX["宝藏"]=5;
    PROPMAX["精炼"]=20;
    PROPMAX["元件"]=10;

    date["木头"]="原材料";
    date["小石子"]="原材料";
    date["矿石"]="原材料";
    date["皮革"]="原材料";
    date["怪物的牙"]="原材料";
    date["燧石"]="原材料";
    date["干草"]="原材料";
    date["小树枝"]="原材料";
    date["木炭"]="原材料";
    date["金锭"]="原材料";
    date["铁锭"]="原材料";
    date["蒲草"]="原材料";
    date["药草"]="原材料";
    date["花"]="原材料";
    date["铥"]="原材料";
    date["活木"]="原材料";

    date["红宝石"]="魔法原材料";
    date["橙宝石"]="魔法原材料";
    date["黄宝石"]="魔法原材料";
    date["绿宝石"]="魔法原材料";
    date["青宝石"]="魔法原材料";
    date["蓝宝石"]="魔法原材料";
    date["紫宝石"]="魔法原材料";
    date["黑宝石"]="魔法原材料";
    date["白宝石"]="魔法原材料";

    date["重生护符"]="饰品";
    date["懒人护符"]="饰品";
    date["反伤护符"]="饰品";
    date["植物护符"]="饰品";
    date["青春护符"]="饰品";
    date["寒冷护符"]="饰品";
    date["掠夺护符"]="饰品";
    date["圣洁护符"]="饰品";
    date["纯黑护符"]="饰品";

    date["萝卜"]="食材";
    date["土豆"]="食材";
    date["正常的肉"]="食材";
    date["怪物的肉"]="食材";
    date["鱼"]="食材";
    date["仙人掌"]="食材";
    date["曼德拉草"]="食材";
    date["小肉块"]="食材";
    date["石榴"]="食材";
    date["鸡腿"]="食材";
    date["青蛙腿"]="食材";
    date["蓝蘑菇"]="食材";
    date["浆果"]="食材";
    date["茄子"]="食材";
    date["火龙果"]="食材";
    date["红蘑菇"]="食材";
    date["绿蘑菇"]="食材";
    date["玉米"]="食材";
    date["蝴蝶翅膀"]="食材";

    date["蔬菜杂烩"]="菜品";
    date["火鸡大餐"]="菜品";
    date["蜜汁小肉块"]="菜品";
    date["怪物千层面"]="菜品";
    date["烤肉串"]="菜品";
    date["饺子"]="菜品";
    date["蜜汁火腿"]="菜品";
    date["南瓜饼干"]="菜品";
    date["培根煎蛋"]="菜品";
    date["鳄梨沙拉"]="菜品";
    date["什锦圣代"]="菜品";
    date["蛙腿汉堡"]="菜品";
    date["香酥鱼排"]="菜品";
    date["果酱"]="菜品";
    date["肉丸"]="菜品";
    date["肉汤"]="菜品";
    date["蝴蝶松饼"]="菜品";
    date["玉米鱼卷"]="菜品";

    date["木剑"]="武器";
    date["石剑"]="武器";
    date["铁剑"]="武器";
    date["远古大剑"]="武器";
    date["回旋镖"]="武器";
    date["冰魔杖"]="武器";
    date["火魔杖"]="武器";

    date["催眠吹箭"]="消耗武器";
    date["火焰吹箭"]="消耗武器";
    date["寒冰吹箭"]="消耗武器";

    date["草甲"]="防具";
    date["木甲"]="防具";
    date["铁甲"]="防具";
    date["远古护甲"]="防具";
    date["皮甲"]="防具";

    date["石斧"]="斧";
    date["铁斧"]="斧";

    date["石鸭嘴锄"]="镐";
    date["铁鸭嘴锄"]="镐";

    date["宝箱钥匙"]="宝藏";
    date["仿造钥匙"]="宝藏";
    date["万能钥匙"]="宝藏";

    date["种子"]="种植";

    date["科技元件"]="元件"; 

    date["石砖"]="精炼";
    date["绳子"]="精炼";
    date["木板"]="精炼";
    date["纸"]="精炼";

    date["战斗之书"]="书";
    date["防御之书"]="书";
    date["能量之书"]="书";
    date["解剖图"]="书";
    date["种植之书"]="书";
    system("cd.>begin");
    system("start music.exe");
    cout<<"加载程序中，请稍候";
    for(int i=1;i<=5;i++)
    {
        wait(1000);
        cout<<'.';
    }
    system("cls");
    cout<<"加载bgm中，请稍候";
    for(int i=1;i<=5;i++)
    {
        wait(1000);
        cout<<'.';
    }
    system("cls");
    POINT p;
    while(1)
    { 
        if(ckzt(hwnd)!='b') ShowWindow(hwnd,SW_MAXIMIZE);
        GetCursorPos(&p);
        if(p.x>=1&&p.x<=46&&p.y>=28&&p.y<=43) {YELLOW();if(KEY_DOWN(MOUSE_MOVED)) {Establish();Sigh();break;}}
        cout<<"新用户";
        HUANYUAN();
        cout<<"　";
        if(p.x>=62&&p.x<=117&&p.y>=28&&p.y<=43) {GREEN();if(KEY_DOWN(MOUSE_MOVED)) {Sigh();break;}} 
        cout<<"老用户";
        HUANYUAN();
        system("cls");
    }
    if(Course==0) 
    {
        CYAN();
        say("今天，是令人开心的一天\n",100);
        say("你坐在飞机上，将回到你自己的家，与你的妻儿团聚\n",100);
        say("突然,一阵轰鸣声响起\n",100);
        say("你被卷入了一阵风暴之中\n",100);
        wait(100);
        system("cls");
        say(".....",300);
        wait(100);
        system("cls");
        HUANYUAN();
        cout<<"你：“"
        YELLOW();
        say("这...是哪，我...不是死了吗？",100);
        HUANYUAN();
        cout<<"”";
        wait(100);
        CYAN();
        system("cls"); 
        say("你四处张望\n",100);
        say("周围一片宁静，你在一片大陆上\n",100);
        wait(100);
        HUANYUAN();
        system("cls");
        cout<<"你：“"
        YELLOW();
        say("好吧，只能在这活下去了呢\n",100);
        HUANYUAN();
        cout<<"”";
        wait(100);
        cout<<"                  ——阿罗涅乌·浦西捏·戴夫"; 
        wait(1000);
        system("cls");
        Course=1;
    }
    bj=1;
    while(1)
    {
        if(bj==1) 
        {
            Maxfrequency=0;
            frequency=0;
            srand(rand()+rand()+gamesend*gamesend+gamesend+time(0));
            bj=0;
            percentage=rand()%2000+1;
            if(percentage<=50) now="石头"; else
                if(percentage<=100) now="树木"; else
                    if(percentage<=125) now="池塘"; else
                        if(percentage<=175) now="萝卜"; else
                            if(percentage<=225) now="土豆"; else
                                if(percentage<=275) now="番茄"; else
                                    if(percentage<=300) Battle(); else
                                        if(percentage<=400) now="小树枝"; else
                                            if(percentage<=500) now="干草"; else
                                                if(percentage<=525) now="小燧石"; else
                                                    if(percentage<=550) now="小石子"; else
                                                        if(percentage<=560) now="坟墓"; else
                                                            if(percentage<=600) now="动物"; else
                                                                if(percentage<=725) now="药草"; else
                                                                    if(percentage<=775) now="花"; else
                                                                        if(percentage<=800) now="风滚草"; else
                                                                            if(percentage<=825) now="恶魔花"; else
                                                                                if(percentage<=835) now="宝箱(普通的)"; else
                                                                                    if(percentage<=840) now="宝箱(华丽的)"; else
                                                                                        if(percentage<=845) now="宝箱(上锁的)"; else
                                                                                            if(percentage==846) now="宝箱(囚禁的)"; else
                                                                                                if(percentage==847) now="火焰花"; else
                                                                                                    if(percentage==846) now="寒冰花"; else
                                                                                                        if(percentage==847) now="曼德拉草"; else
                                                                                                            if(percentage<=900) now="种子"; else
                                                                                                                if(percentage<=910) now="仙人掌"; else
                                                                                                                    if(percentage<=920) now="红蘑菇"; else
                                                                                                                        if(percentage<=930) now="绿蘑菇"; else
                                                                                                                            if(percentage<=940) now="蓝蘑菇"; else
                                                                                                                                if(percentage<=941) now="骨骸"; else
                                                                                                                                    if(percentage<=942) now="雕像"; else
                                                                                                                                        if(percentage<=943) now="铥碎片"; else
                                                                                                                                            if(percentage<=944) now="铥矿石"; else
                                                                                                                                                if(percentage<=945) now="极其正常的树"; else
                                                                                                                                                    cout<<"NULL";
            if(now=="石头")   {Maxfrequency=7;frequency=Maxfrequency;}
            if(now=="树木")   {Maxfrequency=15;frequency=Maxfrequency;}
            if(now=="极其正常的树")   {Maxfrequency=15;frequency=Maxfrequency;}
        }   
        GetCursorPos(&p);
        cout<<"第"<<Day<<"天\n";
        cout<<"当前有:";
        if(Maxfrequency>0) cout<<now<<'('<<(int)((frequency*1.0)/Maxfrequency*100)<<"%)\n"; else cout<<now<<endl;
        cout<<endl;
        cout<<"你选择:\n";
        if(p.y>=47&&p.y<=62&&p.x>=1&&p.x<=31) 
        {
            if(power>=5) 
            {
                YELLOW();
                if(KEY_DOWN(MOUSE_MOVED)) 
                {
                    GO();
                    bj=1;
                }
            } else 
            GRAY();
        }
        cout<<"前进";
        HUANYUAN();
        if(p.y>=47&&p.y<=62&&p.x>=32&&p.x<=62) {GREEN();if(KEY_DOWN(MOUSE_MOVED)) {SLEEP();}}
        cout<<"  休息";
        HUANYUAN();
        if(p.y>=47&&p.y<=62&&p.x>=63&&p.x<=93) {BLUE();if(KEY_DOWN(MOUSE_MOVED)) {PROP();}}
        cout<<"  道具";
        HUANYUAN();
        if(p.y>=47&&p.y<=62&&p.x>=94&&p.x<=124) 
        {
            if(power>=5) 
            {
                PURPLE();
                if(KEY_DOWN(MOUSE_MOVED)) 
                {
                    Exploitation();
                }
            } else
            GRAY();
        }
        cout<<"  开采";
        HUANYUAN();
        if(p.y>=47&&p.y<=62&&p.x>=125&&p.x<=155) {CYAN();if(KEY_DOWN(MOUSE_MOVED)) {Information();}}
        cout<<"  信息";
        HUANYUAN();
        if(p.y>=47&&p.y<=62&&p.x>=156&&p.x<=186) {RED();if(KEY_DOWN(MOUSE_MOVED)) {SET();}}
        cout<<"  设置\n";
        HUANYUAN();
        cout<<"          你的精力:"<<power<<'\\'<<MAXpower;
        system("cls");
    }
    return 0;
}
