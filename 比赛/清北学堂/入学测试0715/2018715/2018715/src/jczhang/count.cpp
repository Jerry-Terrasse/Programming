#include <iostream>
#include <cstdio>
#include <cstring>

char B[3][3];
bool check(char ch1, char ch2, char a, char b, char c) {
  if (a != ch1 && a != ch2) return 0;
  if (b != ch1 && b != ch2) return 0;
  if (c != ch1 && c != ch2) return 0;
  if (ch2 == '#')return 1;
  if (a != ch1 && b != ch1 && c != ch1) return 0;
  if (a != ch2 && b != ch2 && c != ch2) return 0;
  return true;
}
int win(char ch1, char ch2){
  if (check(ch1, ch2, B[0][0], B[1][1], B[2][2])) return 1;
  if (check(ch1, ch2, B[0][2], B[1][1], B[2][0])) return 1;
  for (int i = 0; i < 3; ++ i){
    if (check(ch1, ch2, B[0][i], B[1][i], B[2][i])) return 1;
    if (check(ch1, ch2, B[i][0], B[i][1], B[i][2])) return 1;
  }
  return 0;
}
int main(){
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  for (int i = 0; i < 3; ++i)
      scanf("%s",B[i]);
  int ans1=0,ans2=0;
  for (int i = 'A'; i <= 'Z'; ++ i)
    ans1+=win(i,'#');
  for (int i = 'A'; i <= 'Z'; ++ i)
    for (int j = i+1; j <= 'Z'; ++ j)
      ans2+=win(i,j);
  printf("%d\n%d\n",ans1,ans2);
  return 0;
}

