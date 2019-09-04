
typedef unsigned long long ull;
typedef long double ld;

//miller_rabin

ull fmul(ull a, ull b, ull m) {
	ull q = (ld) a * (ld) b / (ld) m;
	ull r = a * b - q * m;
	return (r + m) % m;
}

ull fexp(ull x, ull e, ull m) {
	ull ans = 1;
	x = x % m;
	for(; e; e >>= 1) {
		if(e & 1) ans = fmul(ans, x, m);
		x = fmul(x, x, m);
	}
	return ans;
}

bool miller(ull p, ull a) {
	ull s = p - 1;
	while(s % 2 == 0) s >>= 1;
	while(a >= p) a >>= 1;
	ull mod = fexp(a, s, p);
	while(s != p - 1 && mod != 1 && mod != p - 1) {
		mod = fmul(mod, mod, p);
		s <<= 1;
	}
	if(mod != p - 1 && s % 2 == 0)return false;
	else return true;
}

vector<int> vp = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool prime(ull p) {
	if(p <= 3) return 1;
	if(p % 2 == 0) return 0;
	for(int u: vp) if(!miller(p, u)) return 0;
	return 1;
}

//pollard_rho

ull func(ull x, ull c, ull n) {
	return (fmul(x, x, n) + c) % n;
}

ull gcd(ull a, ull b) {
	if(!b) return a;
	return gcd(b, a % b);
}

ull rho(ull n) {
	if(n % 2 == 0) return 2;
	if(prime(n)) return n;
	while(1) {
		ull c;
		do {
			c = rand() % n;
		} while(c == 0 || (c + 2) % n == 0);
		ull x = 2, y = 2, d = 1;
		ull pot = 1, lam = 1;
		do {
			if(pot == lam) {
				x = y;
				pot <<= 1;
				lam = 0;
			}
			y = func(y, c, n);
			lam++;
			d = gcd(x >= y ? x - y : y - x, n);
		} while(d == 1);
		if(d != n) return d;
	}
}

vector<ull> factors(ull n) {
	vector<ull> ans, rest, times;
	if(n == 1) return ans;
	rest.push_back(n);
	times.push_back(1);
	while(!rest.empty()) {
		ull x = rho(rest.back());
		if(x == rest.back()) {
			int freq = 0;
			for(int i = 0; i < rest.size(); i++) {
				int cur_freq = 0;
				while(rest[i] % x == 0) {
					rest[i] /= x;
					cur_freq++;
				}
				freq += cur_freq * times[i];
				if(rest[i] == 1) {
					swap(rest[i], rest.back());
					swap(times[i], times.back());
					rest.pop_back();
					times.pop_back();
					i--;
				}
			}
			while(freq--) ans.push_back(x);
			continue;
		}
		ull e = 0;
		while(rest.back() % x == 0) {
			rest.back() /= x;
			e++;
		}
		e *= times.back();
		if(rest.back() == 1) {
			rest.pop_back();
			times.pop_back();
		}
		rest.push_back(x);
		times.push_back(e);
	}
	return ans;
}
