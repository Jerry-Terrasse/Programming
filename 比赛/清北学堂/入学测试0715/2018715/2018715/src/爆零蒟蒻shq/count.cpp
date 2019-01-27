#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

#include <vector>

const int MAXN = 3;

int pupil, team;
bool flag = true;
bool v[200], d[200];
std::string p[MAXN];

inline bool emm (const char &a, const char &b, const char &c) {
    return (a == b ? (b == c ? true : false) : false);
}

int main(int argc, char const *argv[]) {
    freopen ("count.in", "r", stdin);
    freopen ("count.out", "w", stdout);
    for (int i = 0; i <= 2; i++) {
        std::cin >> p[i];
    }
    if (emm(p[0][0], p[0][1], p[0][2])) {
        if (!v[p[0][0]]) pupil ++;
        v[ p[0][0] ] = true;
    }
    if (emm(p[1][0], p[1][1], p[1][2])) {
        if (!v[p[1][0]]) pupil ++;
        v[ p[1][0] ] = true;
    }
    if (emm(p[2][0], p[2][1], p[2][2])) {
        if (!v[p[2][0]]) pupil ++;
        v[ p[2][0] ] = true;
    }
    if (emm(p[0][0], p[1][0], p[2][0])) {
        if (!v[p[0][0]]) pupil ++;
        v[ p[0][0] ] = true;
    }
    if (emm(p[0][1], p[1][1], p[2][1])) {
        if (!v[p[0][1]]) pupil ++;
        v[ p[0][1] ] = true;
    }
    if (emm(p[0][2], p[1][2], p[2][2])) {
        if (!v[p[0][2]]) pupil ++;
        v[ p[0][2] ] = true;
    }
    if (emm(p[0][0], p[1][1], p[2][2])) {
        if (!v[p[0][0]]) pupil ++;
        v[ p[0][0] ] = true;
    }
    if (emm(p[0][2], p[1][1], p[2][0])) {
        if (!v[p[0][2]]) pupil ++;
        v[ p[0][2] ] = true;
    }

    for (int i1 = 0; i1 <= 2; i1++)
        for (int i2 = 0; i2 <= 2; i2++)
            for (int i3 = 0; i3 <= 2; i3++)
                for (int i4 = 0; i4 <= 2; i4++) {
                    //std::cout << p[i1][i2] << p[i3][i4] << std::endl;
                    if (!(i1 == i3 && i2 == i4) && p[i1][i2] == p[i3][i4]) {
                        //printf("%d %d %d %d\n", i1, i2, i3, i4);
                        if (!d[ p[i1][i2] ] && !v[ p[i1][i2] ]) team++;
                        d[ p[i1][i2] ] = true;
                    }
                }
    printf("%d\n%d", pupil, team);
    return 0;
}
