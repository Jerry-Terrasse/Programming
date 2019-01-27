#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <fstream>
using namespace std;
const int maxn = 19;
int now;
int map[maxn][maxn];
int out[maxn][maxn];
int can[maxn][maxn];
int mx[8] = {-1,0,1,-1,1,-1,0,1};
int my[8] = {-1,-1,-1,0,0,1,1,1};
void PTONY(){//Tony!!! 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
}
void Pwhite(){//-1
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
} 
void Pred(){//1
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
}
void Pblue(){//0
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
}
void read(){
fstream File("save.txt",ios::in | ios::out);
int temp;
for(int i = 0;i <= 9;i++){
    for(int j = 0;j <= 9;j++){
        File>>temp;
        map[i][j] = temp;
        }
    }
for(int i = 0;i <= 9;i++){
    for(int j = 0;j <= 9;j++){
        File>>temp;
        out[i][j] = temp;
        }
    }
for(int i = 0;i <= 9;i++){
    for(int j = 0;j <= 9;j++){
        File>>temp;
        can[i][j] = temp;
        }
    }
File>>temp;
now = temp;
}
bool goon,end;
void start(){
PTONY();printf("Tony's mini Game\n");
Sleep(1000);
Pred(); 
printf("HOW TO PLAY\n");
Pwhite();
printf("输入坐标控制落子\n先纵轴 后横轴 以空格隔开\nEnter = 确定\n");
printf("坐标 0, 0结束游戏\n坐标19,19存档\n请在游玩时关闭输入法\n");
Sleep(1000);
PTONY();
printf("Tony Double Sky ");
Sleep(1000);
printf("Present\n");
Sleep(1000);
Pblue();
printf("thx:@Charles @niiick\n");
Pwhite();
printf("Press any key to continue");
char c = getch();
system("cls");
printf("请选择：\n1.读取存档\n2.新游戏\n");
char a = getch();
while(!(a == '1' || a == '2'))a = getch();
if(a == '1'){
    read();
    goon = 1;
    PTONY();
    printf("读档成功\n");
    Sleep(2000);
    }
}
void print(){
system("cls");
PTONY();printf(" Tony's mini Game\n");
Pwhite();
printf(" ");
for(int i = 1;i <= 8;i++)printf("%d ",i);
printf("\n");
for(int i = 1;i <= 8;i++){
    Pwhite();printf("%d",i);
    for(int j = 1;j <= 8;j++){
        if(out[i][j] == -1){
            Pwhite();printf("■");
            }
        else if(out[i][j] == 1){
            Pred();printf("■");
            }
        else{
            Pblue();printf("■");
            } 
        }
    printf("\n");
    }
if(now){Pred();printf("红方下\n");}
else{Pblue();printf("蓝方下\n");}
Pwhite();printf("请输入坐标\n");
}
void init(){
memset(map,-1,sizeof(map));
memset(out,-1,sizeof(out));
map[4][4] = out[4][4] = 1;
map[4][5] = out[4][5] = 0;
map[5][4] = out[5][4] = 0;
map[5][5] = out[5][5] = 1;
now = 1;
}
bool change(int x,int y,int mx,int my,int c){
if(map[x][y] == c)return 1;
if(map[x][y] == -1)return 0;
bool flag = change(x + mx,y + my,mx,my,c);
out[x][y] ^= flag;
return flag;
}
bool judge(int x,int y,int mx,int my,int c,bool flag){
if(map[x][y] == c)return (1 && flag);
if(map[x][y] == -1)return 0;
if(map[x][y] == c ^ 1)flag = 1;
return judge(x + mx,y + my,mx,my,c,flag);
}
bool check(int c){
memset(can,0,sizeof(can));
bool flag = 0;
for(int i = 1;i <= 8;i++){
    for(int j = 1;j <= 8;j++){
        if(map[i][j] == -1){
            for(int k = 0;k < 8;k++){
                int gox = mx[k];
                int goy = my[k];
                can[i][j] |= judge(i + gox,j + goy,gox,goy,c,0);
                if(can[i][j]){
                    flag = 1;
                    break;
                    }
                }
            }
        }
    }
return flag;
}
void save(){
ofstream SaveFile("save.txt");
for(int i = 0;i <= 9;i++){
    for(int j = 0;j <= 9;j++){
        SaveFile<<map[i][j]<<" ";
        }
    SaveFile<<endl;
    }
for(int i = 0;i <= 9;i++){
    for(int j = 0;j <= 9;j++){
        SaveFile<<out[i][j]<<" ";
        }
    SaveFile<<endl;
    }
for(int i = 0;i <= 9;i++){
    for(int j = 0;j <= 9;j++){
        SaveFile<<can[i][j]<<" ";
        }
    SaveFile<<endl;
    }
SaveFile<<now<<endl;
SaveFile.close();
}
int main(){
    start();
    if(!goon)init();
    print();
    int cnt = 4;
    int x,y;
    bool again = 0;
    while(1){
        if(check(now)){
            scanf("%d%d",&x,&y);
            if(x == 19 && y == 19){
                save();
                PTONY();
                printf("已保存\n");
                Sleep(2000);
                print();
                continue;
                }
            else if(x == 0 && y == 0){
                break;
                }
            while(!can[x][y]){

                printf("位置不合法请重新输入：\n");
                scanf("%d%d",&x,&y);
                if(x == 19 && y == 19){
                    save();
                    PTONY();
                    printf("已保存\n");
                    Sleep(2000);
                    print();
                    continue;
                    }
                else if(x == 0 && y == 0){
                    end = 1;
                    break;
                    }
                }
            if(end)break;
            map[x][y] = now;cnt++;again = 0;
            for(int i = 0;i <= maxn;i++){
                for(int j = 0;j <= maxn;j++){
                    out[i][j] = map[i][j];
                    }
                }
            for(int k = 0;k < 8;k++){
                int gox = mx[k];
                int goy = my[k];
                change(x + gox,y + goy,gox,goy,now);
                }
            }
        else{
            if(now == 1)Pred(),printf("无棋可下\n");
            else Pblue(),printf("无棋可下\n");
            Sleep(2000);
            if(again)break;
            else again = 1;
            }
        now ^= 1;
        print();
        for(int i = 0;i <= maxn;i++){
            for(int j = 0;j <= maxn;j++){
                map[i][j] = out[i][j];
                }
            }
        }
    int R = 0,B = 0;
    for(int i = 1;i <= 8;i++){
        for(int j = 1;j <= 8;j++){
            if(map[i][j] == 1)R++;
            else if(map[i][j] == 0)B++;
            }
        }
    Pred();printf("红方得分：%d\n",R);
    Pblue();printf("蓝方得分：%d\n",B);
    Sleep(1000);
    if(R == B){
        Pwhite();printf("--平局--\n");
        }
    else if(R > B){
        Pred();printf("--红方胜--\n");
        }
    else{
        Pblue();printf("--蓝方胜--\n"); 
        }
    Sleep(2000);
    PTONY();printf("Thanks to play my game\n");
    Sleep(2000);
    printf("Press any key to end\n");
    char c = getch();
    return 0;
    }
