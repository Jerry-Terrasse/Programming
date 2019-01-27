#include<iostream> 
#include<algorithm> 
using namespace std; 
struct line { 
    int start, end;
}a[101];
int ans=0;
bool operator<(const line& a,const line& b) 
{   return a.end < b.end; } 
int main() { 
    freopen("cover.in","r",stdin);
    freopen("cover.out","w",stdout);
    int n,k;    
    cin >> n>>k;    
    for (int i = 1; i <= n; i++) 
    {   
        cin >> a[i].start >> a[i].end; 
        if (a[i].start>a[i].end)
        swap(a[i].start, a[i].end); 
    }   
    sort(a + 1, a + n + 1); 
    int s=0,e=0;
    for(int i = 0; i < n; ++i)
    {
        s = a[i].start;
        e = a[i].end;
        while(e >= a[i+1].start)
        {
            ++i;
            e = a[i].end > e? a[i].end : e;
        }
        ans += (e - s);
    }
    cout << ans << endl; 
    fclose(stdin);
    fclose(stdout);
    return 0;
} 
