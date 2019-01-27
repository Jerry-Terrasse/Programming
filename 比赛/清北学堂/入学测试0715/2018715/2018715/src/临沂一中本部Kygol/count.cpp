#include <iostream>
#include <cstdio>
#include <algorithm>


int main()
{
    freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
    int a[10];
    bool b[30][30];
    int cnt = 0;
    int p = 0, g = 0;
    for(int i = 1; i <= 9; i ++){
        char c;
        scanf("%c", &c);
        if(c == '\n')
		{
        	i--;
			continue;	
		}
        a[i] = (int)c - 64;
    }
    for(int i = 1; i <= 9; i++){
        if(i == 1 || i == 4 || i == 7){
            if(a[i] == a[i + 1] && a[i] == a[i + 2] && !b[a[i]][a[i]]){
                b[a[i]][a[i]] = true;
                p++;
            }
            if(a[i] == a[i + 1] && !b[a[i]][a[i + 2]] && !b[a[i + 2]][a[i]] && a[i] != a[i + 2]){
                b[a[i]][a[i + 2]] = b[a[i + 2]][a[i]] = true;
                g++;
            }
            if(a[i] == a[i + 2] && !b[a[i]][a[i + 1]] && !b[a[i + 1]][a[i]] && a[i] != a[i + 1]){
                b[a[i]][a[i + 1]] = b[a[i + 1]][a[i]] = true;
                g++;
            }
            if(a[i + 1] == a[i + 2] && !b[a[i + 1]][a[i]] && !b[a[i]][a[i + 1]] && a[i + 1] != a[i]){
                b[a[i]][a[i + 1]] = b[a[i + 1]][a[i]] = true;
                g++;
            }
        }
        if(i == 1 || i == 2 || i == 3){
            if(a[i] == a[i + 3] && a[i] == a[i + 6] && !b[a[i]][a[i]]){
                b[a[i]][a[i]] = true;
                p++;
            }
            if(a[i] == a[i + 3] && !b[a[i]][a[i + 6]] && !b[a[i + 6]][a[i]] && a[i] != a[i + 6]){
                b[a[i]][a[i + 6]] = b[a[i + 6]][a[i]] = true;
                g++;
            }
            if(a[i] == a[i + 6] && !b[a[i]][a[i + 3]] && !b[a[i + 3]][a[i]] && a[i] != a[i + 3]){
                b[a[i]][a[i + 3]] = b[a[i + 3]][a[i]] = true;
                g++;
            }
            if(a[i + 6] == a[i + 3] && !b[a[i]][a[i + 3]] && !b[a[i + 3]][a[i]] && a[i] != a[i + 3]){
                b[a[i]][a[i + 3]] = b[a[i + 3]][a[i]] = true;
                g++;
            }
        }
        if(a[1] == a[5] && a[1] == a[9] && !b[a[i]][a[i]]){
            b[a[i]][a[i]] = true;
            p++;
        }
        if(a[3] == a[5] && a[3] == a[7] && !b[a[i]][a[i]]){
            b[a[i]][a[i]] = true;
            p++;
        }
        if(a[1] == a[5] && !b[a[1]][a[9]] && !b[a[9]][a[1]] && a[1] != a[9]){
            b[a[1]][a[9]] = b[a[9]][a[1]] = true;
            g++;
        }
        if(a[1] == a[9] && !b[a[1]][a[5]] && !b[a[5]][a[1]] && a[1] != a[5]){
            b[a[1]][a[5]] = b[a[5]][a[1]] = true;
            g++;
        }
        if(a[9] == a[5] && !b[a[1]][a[5]] && !b[a[5]][a[1]] && a[1] != a[5]){
            b[a[1]][a[5]] = b[a[5]][a[1]] = true;
            g++;
        }
        if(a[3] == a[5] && !b[a[3]][a[7]] && !b[a[7]][a[3]] && a[3] != a[7]){
            b[a[3]][a[7]] = b[a[7]][a[3]] = true;
            g++;
        }
        if(a[3] == a[7] && !b[a[3]][a[5]] && !b[a[5]][a[3]] && a[3] != a[5]){
            b[a[3]][a[5]] = b[a[5]][a[3]] = true;
            g++;
        }
        if(a[5] == a[7] && !b[a[3]][a[5]] && !b[a[5]][a[3]] && a[3] != a[5]){
            b[a[3]][a[5]] = b[a[5]][a[3]] = true;
            g++;
        }
    }
    printf("%d\n%d", p, g);
    return 0;
}
