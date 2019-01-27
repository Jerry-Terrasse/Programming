#include<iostream>
#include<direct.h>
#include"Snake_Class.h"

#define _max(ID) --snake.ID_option < ID_1?ID : snake.ID_option
#define _min(ID) ++snake.ID_option > ID?ID_1 : snake.ID_option

//钩子过程
LRESULT CALLBACK _HookProc(int,WPARAM,LPARAM);

void Wall();       //画墙函数
void Frame();      //画框函数
void initialize_();//初始化蛇结构数据

Snake_data snake;
Snake_class csnake(&snake);
static HANDLE handle;  //控制台句柄
//控制台信息结构
static CONSOLE_SCREEN_BUFFER_INFO info ;

int main(){
    using namespace std;
        //获取输出缓冲区句柄
    handle = GetStdHandle(STD_OUTPUT_HANDLE); 
    //获取相关信息（主要是缓冲区大小）
    GetConsoleScreenBufferInfo( handle, &info );
    initialize_();
    _mkdir( "d://SnakeRecord" ); //创建目录

    CONSOLE_CURSOR_INFO cursor;           //光标结构 
    cursor.dwSize = 10;
    cursor.bVisible = 0;                  //0为隐藏光标
    SetConsoleCursorInfo(handle, &cursor);//设置隐藏光标函数 

    //csnake.ShowMenu();
    HHOOK hook;
    MSG msg;
    //相应的钩子有相应的过程函数MSDN中可看，安装键盘钩子 
    hook = SetWindowsHookEx(WH_KEYBOARD_LL,_HookProc,GetModuleHandle(NULL),0);
    while(1){
        //判断蛇是否还活着
        Wall();
        if( !snake.state && snake.ID_interface == ID_2 ){
               //csnake.Die();
               snake.ID_interface = ID_4;
               Frame();
        }
        if( snake.ID_interface == ID_2 ){
             csnake.StartGame();
             Sleep( snake.rank );
        }
        if( PeekMessage(&msg,NULL,0,0,PM_REMOVE) ){//循环接收消息
               TranslateMessage(&msg);
               DispatchMessage(&msg);
        }
    }

    UnhookWindowsHookEx( hook );    //卸载钩子 
    return 0;
}

//定义钩子过程（未完成）
LRESULT CALLBACK _HookProc(int message, WPARAM wParam, LPARAM lParam){
    //判断是否弹起按键消息
    if( wParam == WM_KEYUP){
        bool state = true;
            switch(((LPKBDLLHOOKSTRUCT) lParam)->vkCode){//lParam:指向一个结构 
                //按下上键
                case VK_UP:              
                    switch( snake.ID_interface ){
                        case ID_1:
                            snake.Flag = true;
                            csnake.ShowMenu();
                            snake.Flag = false;
                            snake.ID_option = _max( ID_5 );
                            csnake.ShowMenu();
                            break;
                        case ID_2:
                            if( snake.key != VK_DOWN && snake.key != VK_UP ){
                                snake.key = VK_UP;
                            }
                            break;
                        case ID_5:
                            snake.Flag = true;
                            csnake.ShowRank();
                            snake.ID_option = _max( ID_3 );
                            snake.Flag = false;
                            csnake.ShowRank();
                            break;
                        case ID_6:
                            snake.Flag = true;
                            csnake.ShowRecord();
                            snake.ID_option = _max( ID_6 );
                            snake.Flag = false;
                            csnake.ShowRecord();
                            break;
                    }
                    break;
                    //按下下键
                case VK_DOWN:
                    switch( snake.ID_interface ){
                        case ID_1:
                            snake.Flag = true;
                            csnake.ShowMenu();
                            snake.Flag = false;
                            snake.ID_option = _min( ID_5 );
                            csnake.ShowMenu();
                            break;
                        case ID_2:
                            if( snake.key != VK_UP && snake.key != VK_DOWN ){
                                snake.key = VK_DOWN;
                            }
                            break;
                        case ID_5:
                            snake.Flag = true;
                            csnake.ShowRank();
                            snake.ID_option = _min( ID_3 );
                            snake.Flag = false;
                            csnake.ShowRank();
                            break;
                        case ID_6:
                            snake.Flag = true;
                            csnake.ShowRecord();
                            snake.ID_option = _min( ID_6 );
                            snake.Flag = false;
                            csnake.ShowRecord();
                            break;
                    }
                    break;
                    //按下左键
                case VK_LEFT:
                    switch( snake.ID_interface ){
                        case ID_2:
                            if( snake.key != VK_RIGHT && snake.key != VK_LEFT ){
                                snake.key = VK_LEFT;
                            }
                            break;
                        case ID_3:
                            snake.Flag = true;
                            csnake.ShowPause();
                            snake.ID_option = _max( ID_3 );
                            snake.Flag = false;
                            csnake.ShowPause();
                            break;
                        case ID_4:
                            snake.Flag = true;
                            csnake.Die();
                            snake.ID_option = _max( ID_2 );
                            snake.Flag = false;
                            csnake.Die();
                            break;
                    }
                    break;
                    //按下右键
                 case VK_RIGHT:
                     switch( snake.ID_interface ){
                        case ID_2:
                            if( snake.key != VK_LEFT && snake.key != VK_RIGHT ){
                                snake.key = VK_RIGHT;
                            }
                            break;
                        case ID_3:
                            snake.Flag = true;
                            csnake.ShowPause();
                            snake.ID_option = _min( ID_3 );
                            snake.Flag = false;
                            csnake.ShowPause();
                            break;
                        case ID_4:
                            snake.Flag = true;
                            csnake.Die();
                            snake.ID_option = _min( ID_2 );
                            snake.Flag = false;
                            csnake.Die();
                            break;
                     }
                     break;
                     //按下空格和回车键
                 case VK_SPACE:
                 case VK_RETURN:
                     system( "cls" );
                     switch( snake.ID_interface ){
                        case ID_1://主菜单界面
                            switch( snake.ID_option ){
                                 case ID_1:
                                     snake.ID_interface = ID_2;//开始游戏界面ID
                                     csnake.StartGame();
                                     break;
                                 case ID_2:
                                     snake.ID_interface = ID_5;//等级界面
                                     snake.ID_option = ID_1;
                                     Frame();
                                     //csnake.ShowRank();
                                     break;
                                 case ID_3:
                                     snake.ID_interface = ID_6;//读取记录界面
                                     snake.ID_option = ID_1;
                                     csnake.ShowRecord();
                                     break;
                                 case ID_4:
                                     snake.ID_interface = ID_7;//英雄榜界面
                                     csnake.ShowArmory();
                                     break;
                                 case ID_5:
                                     state = false;
                                     break;
                            }
                            break;

                        case ID_2://游戏界面
                            snake.ID_interface = ID_3;
                            snake.ID_option = ID_1;
                            Frame();
                            //csnake.ShowPause();
                            break;

                        case ID_3://暂停界面
                            switch( snake.ID_option ){
                                 case ID_1:
                                     snake.ID_interface = ID_2;
                                     csnake.StartGame();
                                     break;
                                 case ID_2:
                                     csnake.SaveRecord();
                                     break;
                                 case ID_3:
                                     state = false;
                                     break;
                            }
                            break;

                        case ID_4://死亡界面
                            switch( snake.ID_option ){
                                 case ID_1:
                                     snake.ID_interface = ID_1;
                                     snake.ID_option = ID_1;
                                     initialize_();
                                     csnake.ShowMenu();
                                     break;
                                 case ID_2:
                                     state = false;
                                     break;
                            }
                            break;

                        case ID_5://等级界面
                            switch( snake.ID_option ){
                                 case ID_1:
                                     snake.rank = first;
                                     break;
                                 case ID_2:
                                     snake.rank = middle;
                                     break;
                                 case ID_3:
                                     snake.rank = high;
                                     break;
                            }
                            snake.ID_interface = ID_1;
                            snake.ID_option = ID_1;
                            csnake.ShowMenu();
                            break;

                        case ID_6://读取界面
                            size_t id;
                            switch( snake.ID_option ){
                                 case ID_1:
                                     id = 0; break;
                                 case ID_2:
                                     id = 1; break;
                                 case ID_3:
                                     id = 2; break;
                                 case ID_4:
                                     id = 3; break;
                                 case ID_5:
                                     id = 4; break;
                            }
                            //进行读取文件
                            if( snake.ID_option != ID_6&&snake.ID_option != ID_7 ){
                                     initialize_();
                                     if( csnake.Read( id ) ){
                                         snake.ID_interface = ID_2;
                                         csnake.StartGame();
                                     }
                                     else snake.ID_interface = ID_6;
                            }
                            else {
                                     snake.ID_interface = ID_1;
                                     snake.ID_option = ID_1;
                                     csnake.ShowMenu();
                            }
                            break;

                        case ID_7://英雄榜界面
                            snake.ID_interface = ID_1;
                            snake.ID_option = ID_1;
                            csnake.ShowMenu();
                            break;
                     }
                     if( !state ){
                         COORD cd = { info.srWindow.Right/4, info.srWindow.Bottom/5*4 };
                         SetConsoleCursorPosition( handle,cd );
                         exit(0);
                     }
                     snake.ID_option = ID_1;
                    break;
            }
    }
          //消息传给下个钩子
          return CallNextHookEx ( NULL, message, wParam, lParam );
}

//画墙函数和调用相应界面(已测试完成)
void Wall(){
    short i;
    COORD coord = { 0,0 };  //坐标结构
//绘墙
    SetConsoleCursorPosition( handle, coord );
    for( i=0;i<=info.srWindow.Right;++i )
            std::cout<<"#";

    coord.X = info.srWindow.Right;
    coord.Y = 1;
    for( i=1;i<info.srWindow.Bottom;++i ){
        SetConsoleCursorPosition( handle, coord );
        std::cout<<"#";
        ++coord.Y ;
    }

    coord.X = 0;
    coord.Y = info.srWindow.Bottom;
    for( i=1;i<=info.srWindow.Right;++i ){
        SetConsoleCursorPosition( handle, coord );
        std::cout<<"#";
        ++coord.X ;
    }

    coord.X = 0;
    coord.Y = 1;
    for( i=1;i<info.srWindow.Bottom;++i ){
        SetConsoleCursorPosition( handle, coord );
        std::cout<<"#";
        ++coord.Y ;
    }
//判断所在界面显示相关界面的菜单选项及其它
    int j = info.srWindow.Right/4;
    switch( snake.ID_interface ){
        case ID_1:
            csnake.ShowMenu(); 
            coord.X = j;
            coord.Y = info.srWindow.Bottom-6;
            SetConsoleCursorPosition( handle, coord );
            std::cout<<"o(-\"-)o  贪  #^_^#  吃  →_→  蛇  \\(^o^)/";
            break;//显示菜单选项

        case ID_2:
        case ID_3:
        case ID_4:
            //绘输出信息框
            coord.X = 1;
            coord.Y = info.srWindow.Bottom - 5;
            SetConsoleCursorPosition( handle, coord );
            for( i=1;i<info.srWindow.Right; std::cout<<"#", ++i );
            for( coord.X=j;coord.X<=info.srWindow.Right-j;coord.X+=j ){
                coord.Y = info.srWindow.Bottom - 5;
                for( i=coord.Y;i<info.srWindow.Bottom;++i ){
                        SetConsoleCursorPosition( handle, coord );
                        std::cout<<"#";
                        ++coord.Y ;
                }
            }
            //输出每个框的信息
            coord.X = 2;
            coord.Y-= 4;
            SetConsoleCursorPosition( handle, coord );
            std::cout<<"游戏难度：";
            coord.Y +=2;
            SetConsoleCursorPosition( handle, coord );
            std::cout<<"\t   ";
            switch( snake.rank ){
                  case first:
                      std::cout<<"初 级"; break;
                  case middle:
                      std::cout<<"中 级"; break;
                  case high:
                      std::cout<<"高 级"; break;
            }
      //当前分数
            coord.X += j;
            coord.Y -= 2;
            SetConsoleCursorPosition( handle, coord );
            std::cout<<"  当 前 分 数";
            coord.X +=j/2-3;
            coord.Y +=2;
            SetConsoleCursorPosition( handle, coord );
            std::cout<<snake.mark ;
      //操作说明
            coord.X = j*2+1;
            coord.Y = info.srWindow.Bottom -4;
            SetConsoleCursorPosition( handle, coord );
            std::cout<<" 操作说明: ";
            coord.Y +=2;
            SetConsoleCursorPosition( handle, coord );
            std::cout<<"  ↑ ↓ ←  →";
            ++coord.Y; 
            SetConsoleCursorPosition( handle, coord );
            std::cout<<" 空格： 暂停游戏";
      //制作人
            coord.X += j;
            SetConsoleCursorPosition( handle, coord );
            std::cout<<"\t制作人： _ 翼";
            break;

        case ID_5:
            csnake.ShowRank(); break;//显示游戏等级

        case ID_6:
            csnake.ShowRecord(); break;//显示存档记录

        case ID_7:
            csnake.ShowArmory(); break;//显示英雄榜
    }

}

//画框函数(完成)
void Frame(){
    COORD coord = { 0, info.srWindow.Bottom/3 };
    SetConsoleCursorPosition( handle, coord );
    for( short i=0;i<=info.srWindow.Right; std::cout<<"-", ++i );
        
    coord.Y = info.srWindow.Bottom/3*2;
    SetConsoleCursorPosition( handle, coord );
    for( short i=0;i<=info.srWindow.Right; std::cout<<"-", ++i );
        
    switch( snake.ID_interface ){
        case ID_3:
            csnake.ShowPause(); break;//显示暂停菜单
        case ID_4:
            csnake.Die(); break;//显示死亡界面菜单
        case ID_5:
            csnake.ShowRank(); break;//显示等级选项
    }
}

//初始化蛇数据（完成）
void initialize_(){
    snake.state = true; //蛇状态
    snake.Snake_size = 5; //蛇初始化长度
    //初始化蛇位置
    COORD cd;
    cd.Y = 3;
    snake.Snake_coord.clear();
    for( size_t i=10;i>5;--i ){
        cd.X = i;
        snake.Snake_coord.push_back( cd );
    }
    snake.food_coord.X = 0;
    snake.food_coord.Y = 0;
    snake.rank = first;   //默认等级
    snake.mark = 0; //分数
    snake.key = VK_RIGHT; 
    snake.ID_interface = ID_1;//界面标记
    snake.ID_option = ID_1;   //选项标记
    snake.Flag = false;
}
