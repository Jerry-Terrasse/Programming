#include<iostream>
#define ld long double
#define MAXN 510
using namespace std;
bool e[MAXN][MAXN];
struct vec
{
	int a,b;
	vec(int a=0,int b=0):a(a),b(b) {}
	vec(vec &A):a(A.a),b(A.b) {}
	inline vec operator*(ld lam)
	{
		vec x(*this);
		x.a*=lam;
		x.b*=lam;
		return x;
	}
	inline bool ok()
	{
		return -50<=a && a<=50 && -50<=b && b<=50 && e[a+50][b+50];
	}
	inline vec r90()
	{
		vec x(*this);
		x.a^=x.b;
		x.b^=x.a;
		x.a^=x.b;
		x.b=-x.b;
		return x;
	}
	inline vec l90()
	{
		vec x(*this);
		x.a^=x.b;
		x.b^=x.a;
		x.a^=x.b;
		x.a=-x.a;
		return x;
	}
	inline vec operator+(vec A)
	{
		vec x(A);
		x.a+=a;
		x.b+=b;
		return x;
	}
	inline bool operator<(vec A)
	{
		return a<A.a || (a==A.a && b<A.b);
	}
	inline vec operator-(vec A)
	{
		vec x(*this);
		x.a-=A.a;
		x.b-=A.b;
		return x;
	}
	inline void operator+=(vec A)
	{
		a+=A.a;
		b+=A.b;
	}
};
int n=0,ans=0;
vec p[MAXN];
//#define pt() cout<<p[i].a<<p[i].b<<p[j].a<<p[j].b<<u.a<<u.b<<v.a<<v.b<<endl;
int main()
{
	int i=0,j=0;
	vec h(0,0),d(0,0),u(0,0),v(0,0);
	freopen("count.in","r",stdin);freopen("count.out","w",stdout);
	ios::sync_with_stdio(0);
	for(cin>>n; i<n; i++)
		{
			cin>>h.a>>h.b;
			p[i]=vec(h);
			e[h.a+50][h.b+50]=1;
		}
	for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
				{
					if(i==j)continue;
					d=p[i]-p[j];
					u=d.r90()+p[j];
					v=p[i]+u-p[j];
					if(u.ok() && v.ok())
						{
							ans++;//pt();
						}
					//cout<<x[i]<<','<<y[i]<<'&'<<x[j]<<','<<y[j]<<"->"<<xx<<','<<yy<<'&'<<uu<<','<<vv<<endl;
				}
		}
	cout<<(ans>>2)<<endl;
	//fclose(stdin);fclose(stdout);
	return 0;
}
