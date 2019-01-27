#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int j,kgs,tc=1,fspd,xxpd,wstblood,plyblood;
int wz=1,sdwza,sdwzb,attack_level=1,blood_level=1,coin_attack_level=5,coin_blood_level=5;
int fs_level=1,xx_level=1,bonus_level=1,coin_fs_level=5,coin_xx_level=5,coin_bonus_level=10;
int fs(void) {
 srand(time(NULL));
 fspd=rand()%5;
 switch(fs_level) {
 case 2: {
  if(fspd==0) {
  system("color 4D");
  printf("反伤！\n\n");
  wstblood--;
  }
  break;
 }
 case 3: {
  if(fspd==0 || fspd==1) {
  system("color 4D");
  printf("反伤！\n\n");
  wstblood--;
  }
  break;
 }
 case 4: {
  if(fspd==0 || fspd==1 || fspd==2) {
  system("color 4D");
  printf("反伤！\n\n");
  wstblood--;
  }
  break;
 }
 case 5: {
  if(fspd==0 || fspd==1 || fspd==2 || fspd==3) {
  system("color 4D");
  printf("反伤！\n\n");
  wstblood--;
  }
  break;
 }
 }
}
int xx(void) {
 srand(time(NULL));
 xxpd=rand()%5;
 switch(xx_level) {
 case 2: {
  if(xxpd==0) {
  if(plyblood<10) {
   system("color 2C");
   printf("吸血！\n\n");
   plyblood++;
  }
  break;
  }
 }
 case 3: {
  if(xxpd==0 || xxpd==1) {
  if(plyblood<10) {
   system("color 2C");
   printf("吸血！\n\n");
   plyblood++;
  }
  }
  break;
 }
 case 4: {
  if(xxpd==0 || xxpd==1 || xxpd==2) {
  if(plyblood<10) {
   system("color 2C");
   printf("吸血！\n\n");
   plyblood++;
  }
  }
  break;
 }
 case 5: {
  if(plyblood<10) {
  system("color 2C");
  printf("吸血！\n\n");
  plyblood++;
  }
  break;
 }
 }
}
int kg(void) {
 for(j=1; j<=kgs; j++) {
 printf(" ");
 }
}
int attack_levelup(void) {
 if(attack_level<5) {
 printf("升级：攻击 当前等级:%d,所需金币：",attack_level);
 if(coin_attack_level<10) {
  printf("0%d",coin_attack_level);
 } else {
  printf("%d",coin_attack_level);
 }
 } else {
 printf(" 升级：攻击 当前等级:MAX ");
 }
}
int blood_levelup(void) {
 if(blood_level<5) {
 printf("升级：血量 当前等级:%d,所需金币：",blood_level);
 if(coin_blood_level<10) {
  printf("0%d",coin_blood_level);
 } else {
  printf("%d",coin_blood_level);
 }
 } else {
 printf(" 升级：血量 当前等级:MAX ");
 }
}
int fs_levelup(void) {
 if(fs_level<5) {
 printf("升级：反伤 当前等级:%d,所需金币：",fs_level);
 if(coin_fs_level<10) {
  printf("0%d",coin_fs_level);
 } else {
  printf("%d",coin_fs_level);
 }
 } else {
 printf(" 升级：反伤 当前等级:MAX ");
 }
}
int xx_levelup(void) {
 if(xx_level<5) {
 printf("升级：吸血 当前等级:%d,所需金币：",xx_level);
 if(coin_xx_level<10) {
  printf("0%d",coin_xx_level);
 } else {
  printf("%d",coin_xx_level);
 }
 } else {
 printf(" 升级：吸血 当前等级:MAX ");
 }
}
int bonus_levelup(void) {
 if(bonus_level<5) {
 printf("升级：奖励 当前等级:%d,所需金币：%d",bonus_level,coin_bonus_level);
 } else {
 printf(" 升级：奖励 当前等级:MAX ");
 }
}
int sdjm(void) {
 switch(sdwza) {
 case 0: {
  if(sdwzb==0) {
  kgs=4;
  kg();
  printf("####################################\n");
  kg();
  printf("#");
  attack_levelup();
  printf("#");
  kgs=2;
  kg();
  blood_levelup();
  printf("\n");
  kgs=4;
  kg();
  printf("####################################\n\n");
  kgs=5;
  kg();
  fs_levelup();
  kgs=3;
  kg();
  xx_levelup();
  printf("\n\n\n");
  kgs=5;
  kg();
  bonus_levelup();
  printf("\n\n");
  } else {
  kgs=41;
  kg();
  printf("####################################");
  kgs=5;
  printf("\n");
  kg();
  attack_levelup();
  kgs=2;
  kg();
  printf("#");
  blood_levelup();
  printf("#\n");
  kgs=41;
  kg();
  printf("####################################\n\n");
  kgs=5;
  kg();
  fs_levelup();
  kgs=3;
  kg();
  xx_levelup();
  printf("\n\n\n");
  kgs=5;
  kg();
  bonus_levelup();
  printf("\n\n");
  }
  break;
 }
 case 1: {
  if(sdwzb==0) {
  kgs=5;
  printf("\n");
  kg();
  attack_levelup();
  kgs=3;
  kg();
  blood_levelup();
  printf("\n\n");
  kgs=4;
  kg();
  printf("####################################\n");
  kg();
  printf("#");
  fs_levelup();
  printf("#");
  kgs=2;
  kg();
  xx_levelup();
  printf("\n");
  kgs=4;
  kg();
  printf("####################################\n\n");
  kgs=5;
  kg();
  bonus_levelup();
  printf("\n\n");
  } else {
  kgs=5;
  printf("\n");
  kg();
  attack_levelup();
  kgs=3;
  kg();
  blood_levelup();
  printf("\n\n");
  kgs=41;
  kg();
  printf("####################################\n");
  kgs=5;
  kg();
  fs_levelup();
  kgs=2;
  kg();
  printf("#");
  xx_levelup();
  printf("#\n");
  kgs=41;
  kg();
  printf("####################################\n\n");
  kgs=5;
  kg();
  bonus_levelup();
  printf("\n\n");
  }
  break;
 }
 case 2: {
  if(sdwzb==0) {
  kgs=5;
  printf("\n");
  kg();
  attack_levelup();
  kgs=3;
  kg();
  blood_levelup();
  printf("\n\n\n");
  kgs=5;
  kg();
  fs_levelup();
  kgs=3;
  kg();
  xx_levelup();
  printf("\n\n");
  kgs=4;
  kg();
  printf("####################################\n");
  kgs=4;
  kg();
  printf("#");
  bonus_levelup();
  printf("#\n");
  kg();
  printf("####################################\n");
  }
  break;
 }
 }
}
int jm(void) {
 switch(wz) {
 case 1: {
  printf(" 欢迎来到暴打王永涵 作者XYQAQ\n\n\n\n");
  printf(" ##############\n");
  printf(" #进入简单模式#\n");
  printf(" ##############\n\n");
  printf(" 进入困难模式\n\n\n");
  printf(" 商店\n\n\n");
  printf(" 游戏规则\n\n\n");
  printf(" 退出\n\n\n");
  break;
 }
 case 2: {
  printf(" 欢迎来到暴打王永涵 作者XYQAQ\n\n\n\n\n");
  printf(" 进入简单模式\n\n");
  printf(" ##############\n");
  printf(" #进入困难模式#\n");
  printf(" ##############\n\n");
  printf(" 商店\n\n\n");
  printf(" 游戏规则\n\n\n");
  printf(" 退出\n\n\n");
  break;
 }
 case 3: {
  printf(" 欢迎来到暴打王永涵 作者XYQAQ\n\n\n\n\n");
  printf(" 进入简单模式\n\n\n");
  printf(" 进入困难模式\n\n");
  printf(" ######\n");
  printf(" #商店#\n");
  printf(" ######\n\n");
  printf(" 游戏规则\n\n\n");
  printf(" 退出\n\n\n");
  break;
 }
 case 4: {
  printf(" 欢迎来到暴打王永涵 作者XYQAQ\n\n\n\n\n");
  printf(" 进入简单模式\n\n\n");
  printf(" 进入困难模式\n\n\n");
  printf(" 商店\n\n");
  printf(" ##########\n");
  printf(" #游戏规则#\n");
  printf(" ##########\n\n");
  printf(" 退出\n\n\n");
  break;
 }
 case 5: {
  printf(" 欢迎来到暴打王永涵 作者XYQAQ\n\n\n\n\n");
  printf(" 进入简单模式\n\n\n");
  printf(" 进入困难模式\n\n\n");
  printf(" 商店\n\n\n");
  printf(" 游戏规则\n\n");
  printf(" ######\n");
  printf(" #退出#\n");
  printf(" ######\n\n");
  break;
 }
 }
}
int main() {
 srand(time(NULL));
 int mode=1,a,b,ans,fh,coin=0,jy=0,i;
 char kz,zbm;
 double ansc,ansr;
 while(!(wz==5 && kz=='r')) {
 system("cls");
 system("color 3E");
 jm();
 printf("金币：%d\n",coin);
 printf("注：w、s上下滚动,r确认，每次输入完需按回车QAQ\n");
 printf(" v3.5彩蛋版\n");
 printf("操作:");
 scanf("%c",&kz);
 switch(kz) {
  case '#': {
  scanf("%c",&zbm);
  if(zbm=='b') {
   scanf("%c",&zbm);
   if(zbm=='d') {
   scanf("%c",&zbm);
   if(zbm=='w') {
    scanf("%c",&zbm);
    if(zbm=='s') {
    scanf("%c",&zbm);
    if(zbm=='t') {
     scanf("%c",&zbm);
     if(zbm=='z') {
     scanf("%c",&zbm);
     if(zbm=='b') {
      scanf("%c",&zbm);
      if(zbm=='m') {
      coin=99999;
      }
     }
     }
    }
    }
   }
   }
  }
  break;
  }
  case 'w': {
  if(wz>1) {
   wz--;
  }
  break;
  }
  case 's': {
  if(wz<5) {
   wz++;
  }
  break;
  }
  case 'r': {
  mode=wz;
  switch(mode) {
   case 1: {
   system("cls");
   wstblood=10;
   plyblood=10+2*(blood_level-1);
   if(blood_level==5) {
    plyblood+=2;
   }
   while(wstblood>0 && plyblood>0) {
    system("color 7B");
    printf(" 简单模式\n");
    printf("王永涵当前血量：|");
    for(i=1; i<=wstblood; i++) {
    printf("##|");
    }
    for(i=1; i<=10-wstblood; i++) {
    printf(" |");
    }
    printf("\n");
    printf("玩家当前血量：|",plyblood);
    for(i=1; i<=plyblood; i++) {
    printf("##|");
    }
    for(i=1; i<=10-plyblood; i++) {
    printf(" |");
    }
    printf("\n\n");
    if(jy!=1) {
    a=rand()%90+10;
    b=rand()%90+10;
    fh=rand()%5;
    }
    switch(fh) {
    case 1: {
     printf("%d+%d=",a,b);
     scanf("%d",&ans);
     if(ans!=a+b) {
     system("color 4F");
     printf("答错了,重新输入\n\n");
     plyblood--;
     fs();
     jy=1;
     } else {
     system("color 2F");
     printf("答对了\n\n");
     wstblood-=attack_level;
     xx();
     jy=0;
     }
     break;
    }
    case 2: {
     printf("%d-%d=",a,b);
     scanf("%d",&ans);
     if(ans!=a-b) {
     system("color 4F");
     printf("答错了,重新输入\n\n");
     plyblood--;
     fs();
     jy=1;
     } else {
     system("color 2F");
     printf("答对了\n\n");
     wstblood-=attack_level;
     xx();
     jy=0;
     }
     break;
    }
    case 3: {
     printf("%d*%d=",a,b);
     scanf("%d",&ans);
     if(ans!=a*b) {
     system("color 4F");
     printf("答错了,重新输入\n\n");
     plyblood--;
     fs();
     jy=1;
     } else {
     system("color 2F");
     printf("答对了\n\n");
     wstblood-=attack_level;
     xx();
     jy=0;
     }
     break;
    }
    case 4: {
     while((double)(a)/(double)(b)!=double(a/b)) {
     a=rand()%90+10;
     b=rand()%90+10;
     }
     printf("%d/%d=",a,b);
     scanf("%d",&ans);
     if(ans!=a/b) {
     system("color 4F");
     printf("答错了,重新输入\n\n");
     plyblood--;
     fs();
     jy=1;
     } else {
     system("color 2F");
     printf("答对了\n\n");
     wstblood-=attack_level;
     xx();
     jy=0;
     }
     break;
    }
    }
    system("pause");
    system("cls");
   }
   if(plyblood>0) {
    system("color 7A");
    printf("恭喜你打败了简单模式的王永涵\n");
    if(coin+plyblood+(bonus_level-1)*5<99999) {
    if(plyblood>10) {
     plyblood=10;
    }
    printf("获得金币：%d\n",plyblood);
    printf("额外奖励：%d金币\n",(bonus_level-1)*5);
    coin+=plyblood+(bonus_level-1)*5;
    } else {
    coin=99999;
    printf("提示：你的金币已达上限\n");
    }
   } else {
    system("color 7C");
    printf("你失败了。。。你被王永涵打死了。。。\n");
   }
   wz=1;
   system("pause");
   break;
   }
   case 2: {
   system("cls");
   wstblood=20;
   plyblood=10+2*(blood_level-1);
   if(blood_level==5) {
    plyblood+=2;
   }
   while(wstblood>0 && plyblood>0) {
    system("color 7B");
    printf(" 困难模式(四舍五入到百分位)\n");
    printf("王永涵当前血量：|");
    for(i=1; i<=wstblood; i++) {
    printf("##|");
    }
    for(i=1; i<=20-wstblood; i++) {
    printf(" |");
    }
    printf("\n");
    printf("玩家当前血量：|",plyblood);
    for(i=1; i<=plyblood; i++) {
    printf("##|");
    }
    for(i=1; i<=10-plyblood; i++) {
    printf(" |");
    }
    printf("\n");
    a=rand()%90+10;
    b=rand()%90+10;
    fh=rand()%5;
    switch(fh) {
    case 1: {
     printf("%d+%d=",a,b);
     scanf("%d",&ans);
     if(ans!=a+b) {
     system("color 4F");
     printf("答错了\n\n");
     if(wstblood<20) {
      wstblood++;
     }
     if(plyblood>0) {
      plyblood--;
      fs();
     }
     system("pause");
     system("cls");
     } else {
     system("color 2F");
     printf("答对了\n\n");
     wstblood-=attack_level;
     xx();
     system("pause");
     system("cls");
     }
     break;
    }
    case 2: {
     printf("%d-%d=",a,b);
     scanf("%d",&ans);
     if(ans!=a-b) {
     system("color 4F");
     printf("答错了\n\n");
     if(wstblood<20) {
      wstblood++;
     }
     if(plyblood>0) {
      plyblood--;
      fs();
     }
     system("pause");
     system("cls");
     } else {
     system("color 2F");
     printf("答对了\n\n");
     wstblood-=attack_level;
     xx();
     system("pause");
     system("cls");
     }
     break;
    }
    case 3: {
     printf("%d*%d=",a,b);
     scanf("%d",&ans);
     if(ans!=a*b) {
     system("color 4F");
     printf("答错了\n\n");
     if(wstblood<20) {
      wstblood++;
     }
     if(plyblood>0) {
      plyblood--;
      fs();
     }
     system("pause");
     system("cls");
     } else {
     system("color 2F");
     printf("答对了\n\n");
     wstblood-=attack_level;
     xx();
     system("pause");
     system("cls");
     }
     break;
    }
    case 4: {
     printf("%d/%d=",a,b);
     scanf("%lf",&ansc);
     ansr=(double)(a)/(double)(b);
     if(ansc!=(int)(100.0*ansr+0.5)/100.0) {
     system("color 4F");
     printf("答错了\n\n");
     if(wstblood<20) {
      wstblood++;
     }
     if(plyblood>0) {
      plyblood--;
      fs();
     }
     system("pause");
     system("cls");
     } else {
     system("color 2F");
     printf("答对了\n\n");
     wstblood-=attack_level;
     xx();
     system("pause");
     system("cls");
     }
     break;
    }
    }
   }
   if(plyblood>0) {
    system("color 7A");
    printf("恭喜你打败了困难模式的王永涵\n");
    if(coin+plyblood*2+(bonus_level-1)*5<99999) {
    if(plyblood>10) {
     plyblood=10;
    }
    printf("获得金币：%d\n",plyblood*2);
    printf("额外奖励：%d金币\n",(bonus_level-1)*5);
    coin+=plyblood*2+(bonus_level-1)*5;
    } else {
    coin=99999;
    printf("提示：你的金币已达上限\n");
    }
   } else {
    system("color 7C");
    printf("你失败了。。。你被王永涵打死了。。。\n");
    if(coin-wstblood>=0) {
    printf("失败惩罚：金币-%d\n",wstblood);
    coin-=wstblood;
    } else {
    printf("提示：你的金币已达下限\n");
    coin=0;
    }
   }
   wz=1;
   system("pause");
   break;
   }
   case 3: {
   sdwza=0;
   sdwzb=0;
   kz='a';
   while(kz!='q') {
    system("cls");
    system("color 5B");
    printf(" 商店(按q退出)\n\n");
    sdjm();
    printf("金币：%d\n",coin);
    printf("注：w、a、s、d上下左右滚动,r确认,q退出,每次输入完需按回车QAQ\n");
    printf("操作:");
    scanf("%c",&kz);
    switch(kz) {
    case '#': {
     scanf("%c",&zbm);
     if(zbm=='M') {
     scanf("%c",&zbm);
     if(zbm=='A') {
      scanf("%c",&zbm);
      if(zbm=='X') {
      scanf("%c",&zbm);
      if(zbm=='_') {
       scanf("%c",&zbm);
       if(zbm=='L') {
       scanf("%c",&zbm);
       if(zbm=='E') {
        scanf("%c",&zbm);
        if(zbm=='V') {
        scanf("%c",&zbm);
        if(zbm=='E') {
         scanf("%c",&zbm);
         if(zbm=='L') {
         scanf("%c",&zbm);
         if(zbm=='.') {
          scanf("%c",&zbm);
          switch(zbm) {
          case 'A': {
           scanf("%c",&zbm);
           if(zbm=='T') {
           scanf("%c",&zbm);
           if(zbm=='K') {
            attack_level=5;
            printf("\n悄悄对你说：作弊成功！\n");
            system("pause");
           }
           } else {
           if(zbm=='L') {
            scanf("%c",&zbm);
            if(zbm=='L') {
            attack_level=5;
            blood_level=5;
            fs_level=5;
            xx_level=5;
            bonus_level=5;
            printf("\n悄悄对你说：作弊成功！\n");
            system("pause");
            }
           } else {
            printf("\n提示：作弊码后缀错误.ERROR\n");
            system("pause");
           }
           }
           break;
          }
          case 'B': {
           scanf("%c",&zbm);
           if(zbm=='L') {
           scanf("%c",&zbm);
           if(zbm=='D') {
            blood_level=5;
            printf("\n悄悄对你说：作弊成功！\n");
            system("pause");
           }
           } else {
           if(zbm=='O') {
            scanf("%c",&zbm);
            if(zbm=='S') {
            }
           } else {
           }
           }
           break;
          }
          case 'X': {
           scanf("%c",&zbm);
           if(zbm=='X') {
           xx_level=5;
           printf("\n悄悄对你说：作弊成功！\n");
           system("pause");
           } else {
           printf("\n提示：作弊码后缀错误.ERROR\n");
           system("pause");
           }
           break;
          }
          case 'F': {
           scanf("%c",&zbm);
           if(zbm=='S') {
           fs_level=5;
           printf("\n悄悄对你说：作弊成功！\n");
           system("pause");
           } else {
           printf("\n提示：作弊码后缀错误.ERROR\n");
           system("pause");
           }
           break;
          }
          default: {
           printf("\n提示：作弊码后缀错误.ERROR\n");

           system("pause");

          }
          }
         }
         }
        }
        }


       }
       }
      }
      }
     }
     }
     break;
    }
    case 'w': {
     if(sdwza>0) {
     sdwza-=1;
     }
     break;
    }
    case 's': {
     if(sdwza<2) {
     sdwza+=1;
     }
     break;
    }
    case 'a': {
     if(sdwzb=1) {
     sdwzb-=1;
     }
     break;
    }
    case 'd': {
     if(sdwzb<1 && sdwza<2) {
     sdwzb+=1;
     }
     break;
    }
    case 'r': {
     switch(sdwza) {
     case 0: {
      if(sdwzb==0) {
      while(tc!=0 && kz!='n' && kz!='y') {
       system("cls");
       system("color 8E");
       printf(" 攻击升级\n\n");
       if(attack_level<5) {
       if(attack_level!=4) {
        printf(" 当前等级：%d级 | 升级后等级：%d级\n",attack_level,attack_level+1);
        printf(" 当前攻击力：%d | 升级后攻击力：%d\n\n",attack_level,attack_level+1);
       } else {
        printf(" 当前等级：4级 | 升级后等级：MAX\n");
        printf(" 当前攻击力:4 | 升级后攻击力：5\n\n");
       }
       if(coin<coin_attack_level) {
        printf("所需金币：%d(你的金币不足，还需%d金币)\n",coin_attack_level,coin_attack_level-coin);
        tc=0;
       } else {
        printf("所需金币：%d(剩余%d)\n",coin_attack_level,coin-coin_attack_level);
        printf("请确认升级(y为确定，n为退出):");
        scanf("%c",&kz);
        printf("\n");
       }
       } else {
       printf(" 当前等级：MAX | 升级后等级：？？？\n");
       printf(" 当前攻击力：5 | 升级后攻击力：？？？\n\n");
       tc=0;
       }
      }
      tc=1;
      if(kz=='y') {
       printf("升级成功！\n");
       coin-=coin_attack_level;
       attack_level+=1;
       coin_attack_level+=5;
      }
      system("pause");
      } else {
      while(tc!=0 && kz!='n' && kz!='y') {
       system("cls");
       system("color 8E");
       printf(" 血量升级\n\n");
       if(blood_level<5) {
       if(blood_level!=4) {
        printf(" 当前等级：%d级 | 升级后等级：%d级\n",blood_level,blood_level+1);
        printf(" 当前血量：%d | 升级后血量：%d\n\n",10+2*(blood_level-1),10+2*blood_level);
       } else {
        printf(" 当前等级：4级 | 升级后等级：MAX\n");
        printf(" 当前血量：16 | 升级后血量：20\n\n");
       }
       if(coin<coin_blood_level) {
        printf("所需金币：%d(你的金币不足，还需%d金币)\n",coin_blood_level,coin_blood_level-coin);
        tc=0;
       } else {
        printf("所需金币：%d(剩余%d)\n",coin_blood_level,coin-coin_blood_level);
        printf("请确认升级(y为确定，n为退出):");
        scanf("%c",&kz);
        printf("\n");
       }
       } else {
       printf(" 当前等级：MAX | 升级后等级：？？？\n");
       printf(" 当前血量：20 | 升级后血量：？？？\n\n");
       tc=0;
       }
      }
      tc=1;
      if(kz=='y') {
       printf("升级成功！\n");
       coin-=coin_blood_level;
       blood_level+=1;
       coin_blood_level+=5;
      }
      system("pause");
      }
      break;
     }
     case 1: {
      if(sdwzb==0) {
      while(tc!=0 && kz!='n' && kz!='y') {
       system("cls");
       system("color 8E");
       printf(" 反伤升级\n\n");
       if(fs_level<5) {
       if(fs_level!=4) {
        if(fs_level==1) {
        printf(" 当前等级：1级 | 升级后等级：2级\n",fs_level,fs_level+1);
        printf(" 当前反伤率：0%% | 升级后反伤率：20%%\n\n",20*(fs_level-1),20*fs_level);
        } else {
        printf(" 当前等级：%d级 | 升级后等级：%d级\n",fs_level,fs_level+1);
        printf(" 当前反伤率：%d%% | 升级后反伤率：%d%%\n\n",20*(fs_level-1),20*fs_level);
        }
       } else {
        printf(" 当前等级：4级 | 升级后等级：MAX\n");
        printf(" 当前反伤率:60%% | 升级后反伤率：80%%\n\n");
       }
       if(coin<coin_fs_level) {
        printf("所需金币：%d(你的金币不足，还需%d金币)\n",coin_fs_level,coin_fs_level-coin);
        tc=0;
       } else {
        printf("所需金币：%d(剩余%d)\n",coin_fs_level,coin-coin_fs_level);
        printf("请确认升级(y为确定，n为退出):");
        scanf("%c",&kz);
        printf("\n");
       }
       } else {
       printf(" 当前等级：MAX | 升级后等级：？？？\n");
       printf(" 当前反伤率：80%% | 升级后反伤率：？？？\n\n");
       tc=0;
       }
      }
      tc=1;
      if(kz=='y') {
       printf("升级成功！\n");
       coin-=coin_fs_level;
       fs_level+=1;
       coin_fs_level+=5;
      }
      system("pause");
      } else {
      while(tc!=0 && kz!='n' && kz!='y') {
       system("cls");
       system("color 8E");
       printf(" 吸血升级\n\n");
       if(xx_level<5) {
       if(xx_level!=4) {
        if(xx_level==1) {
        printf(" 当前等级：1级 | 升级后等级：2级\n",xx_level,xx_level+1);
        printf(" 当前吸血率：0%% | 升级后吸血率：20%%\n\n",20*(xx_level-1),20*xx_level);
        } else {
        printf(" 当前等级：%d级 | 升级后等级：%d级\n",xx_level,xx_level+1);
        printf(" 当前吸血率：%d%% | 升级后吸血率：%d%%\n\n",20*(xx_level-1),20*xx_level);
        }
       } else {
        printf(" 当前等级：4级 | 升级后等级：MAX\n");
        printf(" 当前吸血率:60%% | 升级后吸血率：100%%\n\n");
       }
       if(coin<coin_xx_level) {
        printf("所需金币：%d(你的金币不足，还需%d金币)\n",coin_xx_level,coin_xx_level-coin);
        tc=0;
       } else {
        printf("所需金币：%d(剩余%d)\n",coin_xx_level,coin-coin_xx_level);
        printf("请确认升级(y为确定，n为退出):");
        scanf("%c",&kz);
        printf("\n");
       }
       } else {
       printf(" 当前等级：MAX | 升级后等级：？？？\n");
       printf(" 当前吸血率：100%% | 升级后吸血率：？？？\n\n");
       tc=0;
       }
      }
      tc=1;
      if(kz=='y') {
       printf("升级成功！\n");
       coin-=coin_xx_level;
       xx_level+=1;
       coin_xx_level+=5;
      }
      system("pause");
      }
      break;
     }
     case 2: {
      while(tc!=0 && kz!='n' && kz!='y') {
      system("cls");
      system("color 8E");
      printf(" 奖励升级\n\n");
      if(bonus_level<5) {
       if(bonus_level!=4) {
       printf(" 当前等级：%d级 | 升级后等级：%d级\n",bonus_level,bonus_level+1);
       if(bonus_level>2) {
        printf(" 当前额外奖励：%d金币 | 升级后额外奖励：%d金币\n\n",(bonus_level-1)*5,bonus_level*5);
       } else {
        printf(" 当前额外奖励：%d金币 | 升级后额外奖励：%d金币\n\n",(bonus_level-1)*5,bonus_level*5);
       }
       } else {
       printf(" 当前等级：4级 | 升级后等级：MAX\n");
       printf(" 当前额外奖励:15金币 | 升级后额外奖励：20金币\n\n");
       }
       if(coin<coin_bonus_level) {
       printf("所需金币：%d(你的金币不足，还需%d金币)\n",coin_bonus_level,coin_bonus_level-coin);
       tc=0;
       } else {
       printf("所需金币：%d(剩余%d)\n",coin_bonus_level,coin-coin_bonus_level);
       printf("请确认升级(y为确定，n为退出):");
       scanf("%c",&kz);
       printf("\n");
       }
      } else {
       printf(" 当前等级：MAX | 升级后等级：？？？\n");
       printf(" 当前额外奖励：20金币 | 升级后额外奖励：？？？\n\n");
       tc=0;
      }
      }
      tc=1;
      if(kz=='y') {
      printf("升级成功！\n");
      coin-=coin_bonus_level;
      bonus_level+=1;
      coin_bonus_level+=10;
      }
      system("pause");
      break;
     }
     }
     } 
     } 
     }
	 }
	 }
	 }
	 }
	 }
	 } 
	  
