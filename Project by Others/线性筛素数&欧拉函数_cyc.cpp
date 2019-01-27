int prime[maxn];
int tot;

inline void euler() {
	fill(prime, prime + maxn, 1);
	for (int i = 2; i < maxn; ++ i) {
		if (prime[i]) prime[++tot] = i;
		for (int j = 1; j <= tot && i * prime[j] < maxn; ++ j) {
			prime[i * prime[j]] = 0;
			if (i % prime[j] == 0) break;
		}
	}
}

inline void phi() {
	fill(prime, prime + maxn, 1);
	for (int i = 2; i < maxn; ++ i) {
		if (prime[i]) prime[++tot] = i, phi[i] = i - 1;
		for (int j = 1; j <= tot && i * prime[j] < maxn; ++ j) {
			prime[i * prime[j]] = 0;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = prime[j] * phi[i];
			} else {
				phi[i * prime[j]] = (prime[j] - 1) * phi[i];
				break;
			}
		}
	}
}
