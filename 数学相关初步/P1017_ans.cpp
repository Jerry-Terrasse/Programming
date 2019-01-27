#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

char toChar[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

int mod(int n, int k){
    if(n%k < 0)
        return n-(n/k+1)*k;
    else
        return n%k;
}

int main(){
    int n, k;
    string ans;

    while(cin>>n>>k){
        ans = "";
        cout<<n<<"=";
        while(n){
            ans = ans + toChar[mod(n, k)];
            if(n%k < 0)
                n = n/k+1;
            else
                n /= k;
        }

        reverse(ans.begin(), ans.end());
        cout<<ans<<"(base"<<k<<")"<<endl;
    }
    return 0;
}
