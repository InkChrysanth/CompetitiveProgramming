ll qmi(ll a, ll k)
{
	ll res=1;
	while(k)
	{
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}

ll f[N], inv[N];
void init()
{
	f[0]=inv[0]=1;
	for(int i=1; i<N; i++) f[i]=(f[i-1]*i)%mod;
	inv[N-1]=qmi(f[N-1], mod-2);
	for(int i=N-1; i>=1; i--) inv[i-1]=(inv[i]*i)%mod; 
}

ll C(int a, int b)
{
	if(a<b) return 0;
	return f[a]*inv[b]%mod*inv[a-b]%mod;
}