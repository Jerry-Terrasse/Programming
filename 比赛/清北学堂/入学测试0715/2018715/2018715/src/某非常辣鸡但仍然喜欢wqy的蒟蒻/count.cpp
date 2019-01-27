#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

string c[4];
int ans1,ans2;
bool is_win[200];
bool is_team_win[200][200];

int main(void){
	freopen ("count.in","r",stdin);
	freopen ("count.out","w",stdout);
	for (int i=1;i<=3;i++)
	 cin>>c[i];
	for (int i=1;i<=3;i++){
		if (c[i][1]==c[i][0]){
			if (c[i][2]==c[i][0]){
				int now_sign=(int)c[i][0];
				if (!is_win[now_sign]){
					is_win[now_sign]=1;
					ans1++;
			}
		 }
		 else if (c[i][2]!=c[i][0]){
		 	int a=(int)c[i][0],b=(int)c[i][2];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 }
		}
		else if (c[i][2]==c[i][0]){
			if (c[i][1]==c[i][0]){
				int now_sign=(int)c[i][0];
				if (!is_win[now_sign]){
					is_win[now_sign]=1;
					ans1++;
			}
		 }
		 else if (c[i][1]!=c[i][0]){
		 	int a=(int)c[i][0],b=(int)c[i][1];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 }
		}
		else if (c[i][2]==c[i][1]){
			if (c[i][1]==c[i][0]){
				int now_sign=(int)c[i][0];
				if (!is_win[now_sign]){
					is_win[now_sign]=1;
					ans1++;
			}
		 }
		 else if (c[i][1]!=c[i][0]){
		 	int a=(int)c[i][0],b=(int)c[i][1];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 }
		}
	} 
	//cout<<ans1<<endl<<ans2<<endl;
	for (int i=0;i<3;i++){
		if (c[1][i]==c[2][i]){
			if (c[1][i]==c[3][i]){
				int now_sign=(int)c[1][i];
				if (!is_win[now_sign]){
					is_win[now_sign]=1;
					ans1++;
			}
		 }
			if (c[3][i]!=c[1][i]){
		 	int a=(int)c[1][i],b=(int)c[3][i];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 }
		}
		else if (c[3][i]==c[1][i]){
			if (c[2][i]==c[1][i]){
				int now_sign=(int)c[1][i];
				if (!is_win[now_sign]){
					is_win[now_sign]=1;
					ans1++;
			}
		 }
		 if (c[2][i]!=c[1][i]){
		 	int a=(int)c[1][i],b=(int)c[2][i];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 }
		}
		else if (c[3][i]==c[2][i]){
			if (c[2][i]==c[1][i]){
				int now_sign=(int)c[1][i];
				if (!is_win[now_sign]){
					is_win[now_sign]=1;
					ans1++;
			}
		 }
		 else if (c[2][i]!=c[1][i]){
		 	int a=(int)c[2][i],b=(int)c[1][i];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 }
		}
	} 
	//cout<<ans1<<endl<<ans2<<endl;
	if (c[1][0]==c[2][1]){
		if (c[1][0]==c[3][2]){
			int now_sign=(int)c[1][0];
			if (!is_win[now_sign]){
				is_win[now_sign]=1;
				ans1++;
			}
		}
		else if (c[1][0]!=c[3][2]){
		 	int a=(int)c[1][0],b=(int)c[3][2];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 } 
	}
	if (c[1][0]==c[3][2]){
		if (c[1][0]==c[2][1]){
			int now_sign=(int)c[1][0];
			if (!is_win[now_sign]){
				is_win[now_sign]=1;
				ans1++;
			}
		}
		else if (c[1][0]!=c[2][1]){
		 	int a=(int)c[1][0],b=(int)c[2][1];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 }  
	}
	if (c[2][1]==c[3][2]){
		if (c[1][0]==c[2][1]){
			int now_sign=(int)c[1][0];
			if (!is_win[now_sign]){
				is_win[now_sign]=1;
				ans1++;
			}
		}
		else if (c[1][0]!=c[2][1]){
		 	int a=(int)c[1][0],b=(int)c[2][1];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 }  
	}
	if (c[1][2]==c[2][1]){
		if (c[3][0]==c[2][1]){
			int now_sign=(int)c[3][0];
			if (!is_win[now_sign]){
				is_win[now_sign]=1;
				ans1++;
			}
		}
		else if (c[3][0]!=c[2][1]){
		 	int a=(int)c[3][0],b=(int)c[2][1];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 }  
	}
	
	if (c[1][2]==c[3][0]){
		if (c[3][0]==c[2][1]){
			int now_sign=(int)c[3][0];
			if (!is_win[now_sign]){
				is_win[now_sign]=1;
				ans1++;
			}
		}
		else if (c[3][0]!=c[2][1]){
		 	int a=(int)c[3][0],b=(int)c[2][1];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 }  
	}
	if (c[2][1]==c[3][0]){
		if (c[1][2]==c[2][1]){
			int now_sign=(int)c[1][2];
			if (!is_win[now_sign]){
				is_win[now_sign]=1;
				ans1++;
			}
		}
		else if (c[1][2]!=c[2][1]){
		 	int a=(int)c[1][2],b=(int)c[2][1];
			if (!is_team_win[a][b]){
			ans2++;
			is_team_win[a][b]=1;
			is_team_win[b][a]=1;
		  }
		 }  
	}
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}
