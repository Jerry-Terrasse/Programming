#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int t=0;
    for(;;++t)
    {
        cout<<t<<':'<<endl;
        system("P3384_da.exe >P3384.in");
        system("P3384_ans.exe <P3384.in >P3384.ans");
        system("P3384.exe <P3384.in >P3384.out");
        if(system("fc P3384.ans P3384.out"))
        {
            system("pause");
            system("pause");
        }
        else
        {
            cout<<"AC"<<endl;
        }
    }
    return 0;
}
