#include"Snake_Class.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>

//获取缓冲区句柄
static const HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
static CONSOLE_SCREEN_BUFFER_INFO info ;
//保存蛇的记录数据文件
static const char *Snake_Record[] = { "d://SnakeRecord//Snake1.txt",
                                      "d://SnakeRecord//Snake2.txt",
                                      "d://SnakeRecord//Snake3.txt",
                                      "d://SnakeRecord//Snake4.txt",
                                      "d://SnakeRecord//Snake5.txt" };

static const char *S_Armory[] = { "d://SnakeRecord//Armory1.txt",
                                  "d://SnakeRecord//Armory2.txt",
                                  "d://SnakeRecord//Armory3.txt" };
//显示主菜单（完成已测试）
void Snake_class::ShowMenu(){
    //获取缓冲区相关信息
    GetConsoleScreenBufferInfo( handle, &info );
    char *str[] = {"开 始 游 戏",
                   "难 度 等 级",
                   "读 取 存 档",
                   "英 雄 榜",
                   "退 出 游 戏"};
    //输出菜单选项
    short y = 3;
    COORD cd = { info.srWindow.Right/2 - 5, y };
    for( size_t n=0;n<sizeof(str)/sizeof(*str);++n ){
        SetConsoleCursorPosition( handle, cd );
        std::cout<<*(str+n);
        cd.Y += 2;
    }
//判断指针指向哪个菜单选项
    cd.X -= 2;
    cd.Y  = y;
    switch( pSnake->ID_option ){
        case ID_1:
            break;
        case ID_2:
            cd.Y = y+2; break;
        case ID_3:
            cd.Y = y+4; break;
        case ID_4:
            cd.Y = y+6; break;
        case ID_5:
            cd.Y = y+8; break;
    }
    ShowPointer( cd,pSnake->Flag?std::string("  "):std::string("><") );
}

//开始游戏（完成待测试）
void Snake_class::StartGame(){
    COORD cd;
    //判断是否已有食物
    if( !pSnake->food_coord.X ){
        srand((unsigned int)time(NULL));
        while(1){
            //限制食物出现的坐标不与围墙相同
              ++( cd.X = rand()%78 ); 
              ++( cd.Y = rand()%18 );
            //判断食物坐标是否与蛇身吻合
            std::vector<COORD>::iterator ite;
            for( ite=pSnake->Snake_coord.begin(); ite!=pSnake->Snake_coord.end(); ++ite ){
                    if( ite->X == cd.X && ite->Y == cd.Y )
                        break;
            }
            if( ite == pSnake->Snake_coord.end() ){
                pSnake->food_coord.X = cd.X ;
                pSnake->food_coord.Y = cd.Y ;
                break;
            }
        }
    }
    SetConsoleCursorPosition( handle, pSnake->food_coord );
    std::cout<<"*";
    //判定按键方向
    cd.X  = pSnake->Snake_coord.begin()->X;
    cd.Y = pSnake->Snake_coord.begin()->Y ;
    switch( pSnake->key ){
        case VK_UP:
            --cd.Y; break;
        case VK_DOWN:
            ++cd.Y; break;
        case VK_LEFT:
            --cd.X; break;
        case VK_RIGHT:
            ++cd.X; break;
    }
    ShowSnake( cd );
    JudgeDie();
}

//显示暂停界面(完成已测试)
void Snake_class::ShowPause(){
    COORD cd = { info.srWindow.Right/2-10, info.srWindow.Bottom/5 };
    SetConsoleCursorPosition( handle, cd );
    std::cout<<"游 戏 暂 停 中 ......";
    char *str[] = { "继 续 游 戏",
                    "保 存 游 戏",
                    "退 出 游 戏" };
//输出菜单选项
    short X = info.srWindow.Right/3;
    cd.X = X/2-5 ;
    cd.Y = info.srWindow.Bottom/3*2-4;
    for( size_t i=0;i<sizeof(str)/sizeof(*str);++i ){
        SetConsoleCursorPosition( handle, cd );
        std::cout<<*(str+i);
        cd.X += X;
    }

//判断指针应指向的菜单选项
    switch( pSnake->ID_option ){
        case ID_1:
            cd.X = X/2-7; break;
        case ID_2:
            cd.X = X/2+X-7; break;
        case ID_3:
            cd.X = X/2+2*X-7; break;
    }
    ShowPointer( cd,pSnake->Flag?std::string("  "):std::string("><") );
}

//保存记录（完成未测试）
void Snake_class::SaveRecord(){
    std::ofstream outopen;
    outopen.open( *( Snake_Record + Create_file() ) );
    if( !outopen ){
        std::cerr<<"\n打开文件失败！\n";
        exit(0);
    }
    //保存记录到文件中,前面加"0"是为了后面检测是否文件为空使用
    outopen<<"0 "<<pSnake->Snake_size<<" ";
    for(std::vector<COORD>::iterator ite=pSnake->Snake_coord.begin();
        ite!=pSnake->Snake_coord.end();++ite )
            outopen<<ite->X<<" "<<ite->Y<<" ";
    outopen<<pSnake->rank<<" "<<pSnake->mark<<" "<<pSnake->key;
    outopen.close();
//输出保存成功
    COORD cd = { info.srWindow.Right/2-4, info.srWindow.Bottom/3*2-1 };
    SetConsoleCursorPosition( handle, cd );
    std::cout<<"保存成功!\a";
}

//显示等级(已测试)
void Snake_class::ShowRank(){
    COORD cd = { info.srWindow.Right/2-6, info.srWindow.Bottom/3+2 };
    char *str[] = { "初       级",
                    "中       级",
                    "高       级" };
    for( size_t i=0;i<sizeof(str)/sizeof(*str);++i ){
        SetConsoleCursorPosition( handle, cd );
        std::cout<<*(str+i);
        cd.Y += 2;
    }
    //判断指针所停留的选项
    cd.X -= 2;
    cd.Y  = info.srWindow.Bottom/3+2;
    switch( pSnake->ID_option ){
        case ID_1:
            break;
        case ID_2:
            cd.Y += 2; break;
        case ID_3:
            cd.Y += 4; break;
    }
    ShowPointer( cd,pSnake->Flag?std::string("  "):std::string("><") );
}

//显示存档记录(已测试)
void Snake_class::ShowRecord(){
    COORD cd = { info.srWindow.Right/2-12, 8 };
    //输出记录
    std::ifstream inopen;
    SetConsoleCursorPosition( handle, cd );
    for( size_t i=0;i<sizeof(Snake_Record)/sizeof(*Snake_Record);++i ){
        inopen.open( *(Snake_Record+i) );
        if( !inopen || (inopen.get() == EOF && i==0) ){
            Show_not();
            pSnake->ID_option = ID_7;//第7个选项标记,在按回车时检测下
            return;
        }
        if( inopen.get() != EOF ){
            UINT _rank, _mark;
            inopen>>_mark;
            ++(_mark *= 2);
            while( _mark-- )
                inopen>>_rank;
            inopen>>_mark;
            switch( _rank ){
                case first:
                    std::cout<<"初级"; break;
                case middle:
                    std::cout<<"中级"; break;
                case high:
                    std::cout<<"高级"; break;
            }
            std::cout<<"\t\t\t  "<<_mark;            
        }else
            std::cout<<" ---\t\t\t  ---"; 

        cd.Y += 2;
        SetConsoleCursorPosition( handle, cd );
        inopen.close();
        inopen.clear();//重置流状态
    }
    std::cout<<"\t   返 回 菜 单";
    cd.X = info.srWindow.Right/2-4; 
    cd.Y = 4;
    SetConsoleCursorPosition( handle, cd );
    std::cout<<"存 档 记 录";
    cd.X -=10;
    cd.Y +=2;
    SetConsoleCursorPosition( handle, cd );
    std::cout<<"游戏等级\t\t当前分数";
    //输出指针
    cd.X = info.srWindow.Right/2-14;
    cd.Y = 8;
    switch( pSnake->ID_option ){
        case ID_1:
            break;
        case ID_2:
            cd.Y +=2; break;
        case ID_3:
            cd.Y +=4; break;
        case ID_4:
            cd.Y +=6; break;
        case ID_5:
            cd.Y +=8; break;
        case ID_6:
            cd.Y +=10;break;
    }
    ShowPointer( cd,pSnake->Flag?std::string("  "):std::string("><") );
}

//读取记录
bool Snake_class::Read( size_t i ){
    std::ifstream inopen( *(Snake_Record+i) );
    if( inopen.get() == EOF ){
        std::cout<<"\a";
        inopen.close();
        return false;
    }
    inopen>>pSnake->Snake_size;
    COORD cd;
    pSnake->Snake_coord.clear();
    for( int n=1;n<=pSnake->Snake_size;++n ){
        inopen>>cd.X>>cd.Y ;
        pSnake->Snake_coord.push_back( cd );
    }
    inopen>>pSnake->rank>>pSnake->mark>>pSnake->key;
    inopen.close();
    inopen.clear();
    return true;
}

//显示英雄榜(未测试)
void Snake_class::ShowArmory(){
    short nt=0;
    COORD cd = { info.srWindow.Right/3, info.srWindow.Bottom/3 };
    std::ifstream inopen;
    for( size_t i=0;i<sizeof(S_Armory)/sizeof(*S_Armory);++i ){
        UINT _rank=0, _mark=0;
        inopen.open( *(S_Armory+i) );
        if( !inopen ){
            ++nt;
            continue;
        }
        inopen>>_rank>>_mark;
        switch( _rank ){
            case first:
                SetConsoleCursorPosition( handle, cd );
                std::cout<<"小牛 ：初级\t\t  "<<_mark;
                break;
            case middle:
                cd.Y +=2;
                SetConsoleCursorPosition( handle, cd );
                std::cout<<"中牛 ：中级\t\t  "<<_mark;
                break;
            case high:
                cd.Y +=2;
                SetConsoleCursorPosition( handle, cd );
                std::cout<<"大牛 ：高级\t\t  "<<_mark;
                break;
        }
        inopen.close();
        inopen.clear();
    }
    if( nt == 3 ){
        Show_not();
        return;
    }
    cd.X = info.srWindow.Right/2-3;
    cd.Y = 4;
    SetConsoleCursorPosition( handle, cd );
    std::cout<<"英 雄 榜";
    cd.X -=10;
    cd.Y +=2;
    SetConsoleCursorPosition( handle,cd );
    std::cout<<"\t等 级\t\t分 数"; 
    cd.Y = info.srWindow.Bottom-7;
    SetConsoleCursorPosition( handle, cd );
    std::cout<<"按回车返回主菜单........";
}

//死亡界面(未测试)
void Snake_class::Die(){
    COORD cd = { info.srWindow.Right/2-10, info.srWindow.Bottom/5 };
    SetConsoleCursorPosition( handle, cd );
    std::cout<<"    您 已 x_x 了 ！";
    char *str[] = { "返 回 菜 单",
                    "退 出 游 戏" };
//输出菜单选项
    short X = info.srWindow.Right/2;
    cd.X = X/2-5 ;
    cd.Y = info.srWindow.Bottom/3*2-4;
    for( size_t i=0;i<sizeof(str)/sizeof(*str);++i ){
        SetConsoleCursorPosition( handle, cd );
        std::cout<<*(str+i);
        cd.X += X;
    }

//判断指针应指向的菜单选项
    switch( pSnake->ID_option ){
        case ID_1:
            cd.X = X/2-7; break;
        case ID_2:
            cd.X = X/2+X-7; break;
    }
    ShowPointer( cd,pSnake->Flag?std::string("  "):std::string("><") );
    if( Jesus() ){
        cd.X = X/2;
        cd.Y = info.srWindow.Bottom/3;
        SetConsoleCursorPosition( handle, cd );
        std::cout<<"哟...这分？ ╮(╯▽╰)╭ 也能上榜。。。！";
        cd.Y +=2;
        SetConsoleCursorPosition( handle, cd );
        std::cout<<"上榜等级：";
        switch( pSnake->rank ){
            case first:
                std::cout<<"初级"; break;
            case middle:
                std::cout<<"中级"; break;
            case high:
                std::cout<<"高级"; break;
        }
        std::cout<<"\t上榜分数："<<pSnake->mark;
    }
}

//存储记录文件(完成未测试)
size_t Snake_class::Create_file(){
    std::ifstream inopen;
    size_t fn=0, fc=0, iend = sizeof(Snake_Record)/sizeof(*Snake_Record);
    //判断文件是否存在或文件已被存满
    for( size_t i=0;i<iend;++i ){
        inopen.open( *(Snake_Record+i) );
        if( !inopen ) ++fn;
        else if( inopen.get() == EOF ){  
            inopen.close(); 
            return i; 
        }
        else { ++fc; inopen.close(); }
    }
    if( fn == iend || fc == iend ){
            std::ofstream outopen;
                   //创建文本
            for( size_t i=0;i<iend;++i ){
                outopen.open( *(Snake_Record+i) );
                outopen.close(); 
            }
    } 
    //返回打开成功的文件索引
    return 0 ;
}

//判断死亡(未测试)
void Snake_class::JudgeDie(){
    std::vector<COORD>::iterator hbeg = pSnake->Snake_coord.begin(),
        beg = hbeg+1;
    while( beg != pSnake->Snake_coord.end() ){
        if( beg->X == hbeg->X && beg->Y == hbeg->Y ){
            pSnake->state = FALSE;
            return;
        }
        ++beg;
    }
    COORD cd;
    if(hbeg->X <= 0 || hbeg->Y <= 0 ||
        hbeg->X >=info.srWindow.Right || hbeg->Y >= info.srWindow.Bottom-5 ){
            if( pSnake->Snake_size < 40 ){
                pSnake->state = FALSE;
                return;
            }
            //如果达到了40级可以穿墙
            switch( pSnake->key ){
                case VK_UP:
                    cd.X = pSnake->Snake_coord.begin()->X ;
                    cd.Y = info.srWindow.Bottom-6;
                    break;
                case VK_DOWN:
                    cd.X = pSnake->Snake_coord.begin()->X ;
                    cd.Y = 1;
                    break;
                case VK_LEFT:
                    cd.X = info.srWindow.Right-1;
                    cd.Y = pSnake->Snake_coord.begin()->Y ;
                    break;
                case VK_RIGHT:
                    cd.X = 1;
                    cd.Y = pSnake->Snake_coord.begin()->Y ;
                    break;
            }
            ShowSnake( cd );
    }
}

//上榜判断（未测试）
bool Snake_class::Jesus(){
    std::ifstream inopen;
    size_t i;
    //判断相应等级打开相应文件
    switch( pSnake->rank ){
        case first:
            i=0; break;
        case middle:
            i=1; break;
        case high:
            i=2; break;
    }
    inopen.open( *(S_Armory+i) );
    if( inopen ){
        UINT _mark;
        inopen>>_mark>>_mark;
        if( _mark >= pSnake->mark ){
            inopen.close();
            return FALSE;
        }
    }
    std::ofstream outopen( *(S_Armory+i) );//创建文件并输入
    if( !outopen ){
        std::cerr<<"打开英雄榜文件出错"<<std::endl;
        exit(0);
    }
    outopen<<pSnake->rank<<" "<<pSnake->mark;
    outopen.close();
    return TRUE;
}
//显示蛇(未测试)
void Snake_class::ShowSnake( COORD& cd){
    if( cd.X == pSnake->food_coord.X && cd.Y == pSnake->food_coord.Y ){
            //在最后添加一个坐标
        pSnake->Snake_coord.push_back( *(pSnake->Snake_coord.rbegin()) );
        pSnake->food_coord.X = pSnake->food_coord.Y = 0;//标志食物已被吃掉
        ++pSnake->mark;
        ++pSnake->Snake_size;
    }
    COORD cod;
    cod.X = (pSnake->Snake_coord.rbegin())->X ;
    cod.Y = (pSnake->Snake_coord.rbegin())->Y ;
    std::vector<COORD>::reverse_iterator rbeg = pSnake->Snake_coord.rbegin();
    while( rbeg != pSnake->Snake_coord.rend()-1 ){
        rbeg->X = (rbeg+1)->X ;
        rbeg->Y = (rbeg+1)->Y ;
        ++rbeg;
    }
    //显示蛇
    pSnake->Snake_coord.begin()->X = cd.X ;
    pSnake->Snake_coord.begin()->Y = cd.Y ;
    for( std::vector<COORD>::iterator beg = pSnake->Snake_coord.begin();
        beg != pSnake->Snake_coord.end();++beg ){
            SetConsoleCursorPosition( handle, *beg );
            std::cout<<"*";
    }
    SetConsoleCursorPosition( handle,cod );
    std::cout<<" ";
}

//显示指针（完成）
inline void Snake_class::ShowPointer( COORD cd,std::string str ){
    SetConsoleCursorPosition( handle, cd );
    std::cout<<str[0];
    pSnake->ID_interface != ID_6?cd.X += 14:cd.X = info.srWindow.Right/3*2+3;
    SetConsoleCursorPosition( handle, cd );
    std::cout<<str[1];
}

//显示无数据(完成)
inline void Snake_class::Show_not(){
    COORD cd = { info.srWindow.Right/2-4 ,info.srWindow.Bottom/2 };
    SetConsoleCursorPosition( handle, cd );
    std::cout<<"无 数 据 ！";
    cd.X -= 6;
    cd.Y += 2;
    SetConsoleCursorPosition( handle, cd );
    std::cout<<"请按回车返回主菜单......";
}
