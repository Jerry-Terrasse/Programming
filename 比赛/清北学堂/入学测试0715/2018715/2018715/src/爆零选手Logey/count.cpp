#include <cstdio>
#include <iostream>
#include <cstring>

char map[10][10];

bool vis[300];
bool org[300][300];

int main(int argc, char *argv[]) {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);

    for (int i = 1; i <= 3; i++) {
        scanf("%s", map[i] + 1);
    }

    for (int i = 1; i <= 3; i++) {//行
        if (map[i][1] == map[i][2]) {
            if (map[i][3] == map[i][2]) {
                int num = map[i][1] - 'A';
                vis[num] = true;
            }
            else {
                int num1 = map[i][1] - 'A', num2 = map[i][3] - 'A';
                if (num1 > num2) std::swap(num1, num2);
                org[num1][num2] = true;
            }
        }
        else if (map[i][1] == map[i][3]) {
            int num1 = map[i][1] - 'A', num2 = map[i][2] - 'A';
            if (num1 > num2) std::swap(num1, num2);
            org[num1][num2] = true;
        }
        else if (map[i][2] == map[i][3]) {
            int num1 = map[i][1] - 'A', num2 = map[i][2] - 'A';
            if (num1 > num2) std::swap(num1, num2);
            org[num1][num2] = true;
        }
    }

    for (int i = 1; i <= 3; i++) {//列
        if (map[1][i] == map[2][i]) {
            if (map[3][i] == map[2][i]) {
                int num = map[1][i] - 'A';
                vis[num] = true;
            }
            else {
                int num1 = map[1][i] - 'A', num2 = map[3][i] - 'A';
                if (num1 > num2) std::swap(num1, num2);
                org[num1][num2] = true;
            }
        }
        else if (map[1][i] == map[3][i]) {
            int num1 = map[1][i] - 'A', num2 = map[2][i] - 'A';
            if (num1 > num2) std::swap(num1, num2);
            org[num1][num2] = true;
        }
        else if (map[2][i] == map[3][i]) {
            int num1 = map[1][i] - 'A', num2 = map[2][i] - 'A';
            if (num1 > num2) std::swap(num1, num2);
            org[num1][num2] = true;
        }
    }

    if (map[1][1] == map[2][2]) {
        if (map[1][1] == map[3][3]) {
            int num = map[1][1] - 'A';
            vis[num] = true;
        }
        else {
            int num1 = map[1][1], num2 = map[3][3];
            if (num1 > num2) std::swap(num1, num2);
            org[num1][num2] = true;
        }
    }
    else if (map[2][2] == map[3][3]) {
        int num1 = map[1][1], num2 = map[3][3];
        if (num1 > num2) std::swap(num1, num2);
        org[num1][num2] = true;
    }
    else if (map[1][1] == map[3][3]) {
        int num1 = map[1][1], num2 = map[2][2];
        if (num1 > num2) std::swap(num1, num2);
        org[num1][num2] = true;
    }

    if (map[1][3] == map[2][2]) {
        if (map[2][2] == map[3][1]) {
            int num = map[2][2] - 'A';
            vis[num] = true;
        }
        else {
            int num1 = map[1][3], num2 = map[3][1];
            if (num1 > num2) std::swap(num1, num2);
            org[num1][num2] = true;
        }
    }
    else if (map[1][3] == map[3][1]) {
        int num1 = map[1][3], num2 = map[2][2];
        if (num1 > num2) std::swap(num1, num2);
        org[num1][num2] = true;
    }
    else if (map[2][2] == map[3][1]) {
        int num1 = map[1][3], num2 = map[2][2];
        if (num1 > num2) std::swap(num1, num2);
        org[num1][num2] = true;
    }
    int ansP = 0, ansO = 0;
    for (int i = 0; i<= 299; ++i) {
        ansP += vis[i];
    }
    for (int i = 0; i <= 299; i++) {
        for (int j = 0; j <= 299; j++) {
            ansO += org[i][j];
        }
    }
    printf ("%d\n%d\n", ansP, ansO);
    return 0;
}
