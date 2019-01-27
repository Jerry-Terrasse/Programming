#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin;
char get_bit() {
	return getchar();
}
void send_bit(char ch) {
	putchar(ch);
	fflush(stdout);
}
ofstream fout;
void answer(string s) {
	fout << s << endl, exit(0);
}

const int N = 1000;

int n, m, pos[N + 1];
struct init_t {
	init_t() {
		int x;
		fin.open("bob.in");
		fout.open("bob.out");
		fin >> n >> m;
		for (x = 1; x <= n; ++x) fin >> pos[x];
	}
} init_t;

int main() {
	if (pos[n] == n) {
		send_bit('0');
	} else {
		send_bit('1');
	}
	string ans = "";
	for (int x = 0; x < n; ++x) {
		ans += get_bit();
	}
	answer(ans);
}
