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

int n, m;
string s;
struct init_t {
	init_t() {
		fin.open("alice.in");
		fin >> n >> m >> s;
	}
} init_t;

int main() {
	if (get_bit() == '0') {
		for (int x = 0; x < n; ++x) send_bit(s[x]);
	} else {
		for (int x = 0; x < n; ++x) send_bit(s[x + n]);
	}
}
