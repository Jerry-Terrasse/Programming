#include<windows.h>
#include<cstdlib>
#include<ctime>
//int main(accept){return}
using namespace std;
int main() 
{
    //your main cpp;
    int x=GetSystemMetrics(SM_CXSCREEN);
    int y=GetSystemMetrics(SM_CYSCREEN);
    srand(time(0));
    while(1)SetCursorPos(500,500);//rand()%x,rand()%y);
    return 0;
}
