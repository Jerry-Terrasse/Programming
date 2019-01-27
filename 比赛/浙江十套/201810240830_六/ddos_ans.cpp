#include<bits/stdc++.h>

using namespace std;

const int INF = 2333333;//每天笑一笑，十年少23333333333
const int MAXN = 200 + 10;
const int maxWay = 4;//最大的方向个数。。直译一下就好。。
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

struct Point {
    int x, y;
    int lastWay;
};

queue < Point > q;
Point start, end;//起点和终点
char maze[MAXN][MAXN];//maze：迷宫，
int N, step[MAXN][MAXN];

bool check(int x, int y) {
    if ((x < 0) || (x >= N) || (y < 0) || (y >= N) || (maze[x][y] == 'x')) {
        return false;
    }//越界||这个点不能走 return false；
    return true;
}

void Init() {
    cin >> N;
    getchar();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> maze[i][j];
            //cin自动忽略空的字符
            if (maze[i][j] == 'A') {
            //找到起点和终点
                start.x = i; start.y = j;
            }
            if (maze[i][j] == 'B') {
                end.x = i; end.y = j;
            }
            step[i][j] = INF;
    //从起点到点[i][j]的转弯次数设置为INF（无限大）
        }
    }
    step[start.x][start.y] = 0;//起点到起点转0次弯。
}

void Work() {
    q.push(start);
    while (!q.empty()) {
        Point u = q.front();
        q.pop();
        if ((u.x == end.x) && (u.y == end.y)) break;//如果坐标到了终点坐标，根据广搜“先到的必定最优”原则，可立即结束搜索。
        Point V;
        for (int i = 0; i < maxWay; ++i) {//四个方向
            V.x = u.x + dx[i]; V.y = u.y + dy[i];
            while (check(V.x, V.y) == true) {

/*
学长说，一般的广搜是逐渐扩散开来的，但是这样的话，队列里的顺序就没办法保证是由转弯次数少到转弯次数多的，所以用一个while，一次把所有能走的点全部扩展掉。
*/
            if (step[V.x][V.y]>step[u.x][u.y] + 1) {
                    step[V.x][V.y]=step[u.x][u.y] + 1;
                    //更新到达此点的转弯次数。。
                    q.push(V);
                }
                V.x += dx[i]; V.y += dy[i];//顺着此方向继续走，进行下一次加入队列。
            }
        }
    }
}

void Print() {
    (step[end.x][end.y] == INF) ? cout << -1 : cout << step[end.x][end.y] - 1;//学长说，在step数组里，就算是通过起点直接走过去的点，都被算成了“转1次弯”，因为在上面的广搜中，while循环把一种扩展点都扩展了，（可以打出来看一下），为了方便，直接-1；
}

void debug2()
{
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++)
            cout<<step[i][j]<<" ";
        cout<<endl;
    }
}

int main() {
    Init();
    Work();
    Print();
//    debug2();
    return 0;
}
