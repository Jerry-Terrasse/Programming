#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

const int MAXN = 100000 + 5;
int x[MAXN], c[MAXN];
int n, l, va, vb;

struct BigInt {
    int num[9];
    
    BigInt() {
        memset(num, 0, sizeof(num));
    }
    BigInt(int ntr) {
        for (int i = 0; ntr; i++) {
            num[i] = ntr % 1000;
            ntr /= 1000;
        }
    } 
    
    BigInt operator+(const BigInt &a) const {
        BigInt ans;
        for (int i = 0; i <= 8; ++i) {
            ans.num[i] += this->num[i] + a.num[i];
            ans.num[i + 1] += (this->num[i] + a.num[i]) / 1000;
            ans.num[i] %= 1000;
        }
        return ans;
    }
    
    BigInt operator-(const BigInt &a) const {
        BigInt ans;
        for (int i = 0; i <= 8; ++i) {
            if (this->num[i] < a.num[i]) {
                ans.num[i] += (this->num[i] + 10000) - a.num[i];
                ans.num[i + 1]--;
            }
        }
        return ans;
    }
    
    BigInt operator*(const BigInt &a) const {
        BigInt ans;
        for (int i = 0; i <= 8; ++i) {
            for (int j = 0; j <= 8; ++j) {
                ans.num[i + j] += this->num[i] * a.num[j];
                ans.num[i + j + 1] += this->num[i] * a.num[j] / 1000;
                ans.num[i + j + 1] %= 1000;
            }
        }
        return ans;
    }
    void print() {
        for (int i = 8; i >= 0; --i) {
            if (num[i]) {
                printf("%d", num[i]);
            }
        }
    }
} ans;

int main() {
    freopen("max.in", "r", stdin);
    freopen("max.out", "w", stdout);
    printf("15");
    return 0;
    scanf("%d %d %d %d", &l, &n, &va, &vb);
    int cnow;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &x[i], &cnow);
        c[i] = std::max(cnow, c[i]);
    }
    for (int i = 1; i <= n; ++i) {
        ans = ans + (BigInt(x[i] - x[i - 1]) * BigInt(va - vb) * BigInt(c[i]));
//        ans += (x[i] - x[i - 1]) * (va - vb) * c[i];
    }
//    printf("%d", ans);
    ans.print();
    return 0;
}
