#include <cstdio>
#include <iostream>
#include <algorithm>

char map[4][4];
bool peo[300];
bool que[300][300];

int main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    for (int i = 1; i <= 3; i++)
      for (int j = 1; j <= 3; j++) {
          std::cin >> map[i][j];
      }
    for (int i = 1; i <= 3; i++) {  // 行
        if (map[i][1] == map[i][2]) {
            if (map[i][1] == map[i][3]) {
                int num = map[i][1] - 'A';
                peo[num] = true;
            }
            else {
                int num1 = map[i][1] - 'A', num2 = map[i][3] - 'A';
                if (num1 > num2) std::swap(num1, num2);
                que[num1][num2] = true;
            }
        }
        else if (map[i][1] == map[i][3]) {
            int num1 = map[i][1] - 'A', num2 = map[i][3] - 'A';
            if (num1 > num2) std::swap(num1, num2);
            que[num1][num2] = true;
        }
        else if (map[i][2] == map[i][3]) {
            int num1 = map[i][2] - 'A', num2 = map[i][3] - 'A';
            if (num1 > num2) std::swap(num1, num2);
            que[num1][num2] = true;
        }
    }
    for (int i = 1; i <= 3; i++) {  //列
        if (map[1][i] == map[2][i]) {
            if (map[1][i] == map[3][i]) {
                int num = map[1][i] - 'A';
                peo[num] = true;
            }
            else {
                int num1 = map[1][i] - 'A', num2 = map[3][i] - 'A';
                if (num1 > num2) std::swap(num1, num2);
                que[num1][num2] = true;
            }
        }
        else if (map[1][i] == map[3][i]) {
            int num1 = map[1][i] - 'A', num2 = map[3][i] - 'A';
            if (num1 > num2) std::swap(num1, num2);
            que[num1][num2] = true;
        }
        else if (map[2][i] == map[3][i]) {
            int num1 = map[2][i] - 'A', num2 = map[3][i] - 'A';
            if (num1 > num2) std::swap(num1, num2);
            que[num1][num2] = true;
        }
    }
    // zheng dui jiao xian
    if (map[1][1] == map[2][2]) {
        if (map[1][1] == map[3][3]) {
            int num = map[1][1] - 'A';
            peo[num] = true;
        }
        else {
            int num1 = map[1][1] - 'A', num2 = map[3][3] - 'A';
            if (num1 > num2) std::swap(num1, num2);
            que[num1][num2] = true;
        }
    }
    else if (map[1][1] == map[3][3]) {
        int num1 = map[1][1] - 'A', num2 = map[3][3] - 'A';
        if (num1 > num2) std::swap(num1, num2);
        que[num1][num2] = true;
    }
    else if (map[2][2] == map[3][3]) {
        int num1 = map[2][2] - 'A', num2 = map[3][3] - 'A';
        if (num1 > num2) std::swap(num1, num2);
        que[num1][num2] = true;
        }
    //fan dui jiao xian
    if (map[1][3] == map[2][2]) {
        if (map[1][3] == map[3][1]) {
            int num = map[1][3] - 'A';
            peo[num] = true;
        }
        else {
            int num1 = map[1][3] - 'A', num2 = map[3][1] - 'A';
            if (num1 > num2) std::swap(num1, num2);
            que[num1][num2] = true;
        }
    }
    else if (map[1][3] == map[3][1]) {
        int num1 = map[1][3] - 'A', num2 = map[3][1] - 'A';
        if (num1 > num2) std::swap(num1, num2);
        que[num1][num2] = true;
    }
    else if (map[2][2] == map[3][1]) {
        int num1 = map[2][2] - 'A', num2 = map[3][1] - 'A';
        if (num1 > num2) std::swap(num1, num2);
        que[num1][num2] = true;
    }
    int ansp = 0, ansq = 0;
    for (int i = 0; i <= 299; i++) {
        ansp += peo[i];
    }
    for (int i = 1; i <= 299; i++)
      for (int j = 1; j <= 299; j++) {
          ansq += que[i][j];
      }
    printf("%d \n", ansp);
    printf("%d ", ansq);
    return 0;
}
