
ll fexp(ll b, ll exp){
	ll ans = 1;
	while(exp){
		if(exp&1) ans = (ans*b)%MOD;
		b = (b*b)%MOD;
		exp >>= 1;
	}
	return ans;
}
