#include <iostream>
#include <cstdio>
#include <cstring>

int map[6][6];
int ans1, ans2;

int main(){
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            map[i][j] = getchar();
        }
        getchar();
    }

	
	for(int i = 1; i <= 3; i ++){
		for(int j = 1; j <= 3; j ++){
			if(i == 1 && j == 1){
				if(map[i][j] == map[i + 1][j] && map[i + 2][j] != map[i][j]){ans2 ++;}
				if(map[i][j] == map[i][j + 1] && map[i][j + 2] != map[i][j]){ans2 ++;}
				if(map[i][j] == map[i + 1][j] && map[i + 2][j] == map[i][j]){ans1 ++;}
				if(map[i][j] == map[i][j + 1] && map[i][j + 2] == map[i][j]){ans1 ++;}
				if(map[i][j] == map[i + 1][j + 1] && map[i + 2][j + 2] != map[i][j]){ans2 ++;}
				if(map[i][j] == map[i + 1][j + 1] && map[i + 2][j + 2] == map[i][j]){ans1 ++;}
				if(map[i][j] == map[i][j + 2] && map[i][j + 1] != map[i][j]) ans2 ++;
				if(map[i][j] == map[i + 2][j] && map[i + 1][j] != map[i][j]) ans2 ++;
				if(map[i][j] == map[i + 2][j + 2] && map[i + 1][j + 1] != map[i][j]) ans2 ++;
			} 
			if(i == 1 && j == 2){
				if(map[i][j] == map[i + 1][j] && map[i + 2][j] != map[i][j]){ans2 ++;}
				if(map[i][j] == map[i][j + 1] && map[i][j + 1] != map[i][j - 1]){ans2 ++;}
				if(map[i][j] == map[i + 1][j] && map[i + 2][j] == map[i][j]){ans1 ++;}
				if(map[i][j] == map[i + 2][j] && map[i + 1][j] != map[i][j]) ans2 ++;
			}
			if(i == 2 && j == 1){
				if(map[i][j] == map[i + 1][j] && map[i + 1][j] != map[i - 1][j]){ans2 ++;}
				if(map[i][j] == map[i][j + 1] && map[i][j + 2] != map[i][j]){ans2 ++;}
				if(map[i][j] == map[i][j + 1] && map[i][j + 2] == map[i][j]){ans1 ++;}
				if(map[i][j] == map[i][j + 2] && map[i][j + 1] != map[i][j]) ans2 ++;
			}
			if(i == 2 && j == 2){
				if(map[i][j] == map[i + 1][j] && map[i + 1][j] != map[i - 1 ][j]){ans2 ++;}
				if(map[i][j] == map[i][j + 1] && map[i][j + 1] != map[i][j - 1]){ans2 ++;}

			}
			if(i == 3 && j == 1){
				if(map[i][j] == map[i][j + 1] && map[i][j] != map[i][j + 2]){ans2 ++;}
				if(map[i][j] == map[i][j + 2] && map[i][j + 2] != map[i][j]){ans2 ++;}
				if(map[i][j] == map[i][j + 1] && map[i][j] == map[i][j + 2]) ans1 ++;
				if(map[i][j + 1] == map[i][j + 2] && map[[i][j] != map[i][j + 1]]) ans2 ++;
				if(map[i][j + 1] == map[i][j + 2] && map[[i][j] == map[i][j + 1]]) ans1 ++;
			}
			if(i == 1 && j == 3){
				if(map[i][j] == map[i + 1][j] && map[i + 2][j] != map[i][j]){ans2 ++;}
				if(map[i][j] == map[i + 2][j] && map[i][j] != map[i + 1][j]){ans2 ++;}
				if(map[i][j] == map[i + 1][j] &&map[i][j] == map[i + 2][j]) ans1 ++;l
				if(map[i + 1][j] == map[i + 2][j] && map[[i][j] != map[i + 1][j]]) ans2 ++;
				if(map[i + 1][j] == map[i + 2][j] && map[[i][j] == map[i + 1][j]]) ans2 ++;
			}
		}
	}
	
	freopen("count.in","r" ,stdin);
	freopen("count.out","r",stdout);
	
	printf("%d\n", ans1);
	printf("%d\n", ans2);
	
	return 0;
}
