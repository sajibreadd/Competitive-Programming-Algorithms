vector <int> primes;
bool isComp[MAX];

void Sieve(int N) {
	for (int i = 2; i <= N; ++i) {
		if (!isComp[i]) primes.push_back(i);
		for (int j = 0; j < primes.size () and i * primes[j] <= N; ++j) {
			isComp[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}
