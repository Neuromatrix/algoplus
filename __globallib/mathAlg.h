long long algoplus::bin_cof_DP(long long n, long long k,
long long mod, std::vector <std::vector <long long>> &dp){
    if(dp[n][k]!=-1) return dp[n][k];
    if (k==n || k==0) {
        dp[n][k] = 1;
        return 1;
    }
    dp[n][k] = (algoplus::bin_cof_DP(n-1,k-1,mod,dp)%mod+algoplus::bin_cof_DP(n-1,k,mod,dp)%mod)%mod;
    return dp[n][k];
}
long long algoplus::bin_cof(long long n, long long k,long long mod){
    if(k==n || k == 0) return 1;
    return (algoplus::bin_cof(n-1,k-1,mod)%mod+algoplus::bin_cof(n-1,k,mod)%mod)%mod;

}
long long algoplus::catalan_numb(long long n, long long mod){
    return algoplus::bin_cof(2*n,n,mod)/((n+1)%mod);
}
inline std::tuple <int, int, int> algoplus::equation::gcd(int aa, int bb){
    if(bb==0) return {1,0,aa};
    else{
        int x, y, g;
        std::tie(x,y,g) = algoplus::equation::gcd(bb,aa%bb);
        return {y,x-(aa/bb)*y,g};
    }
}
void algoplus::equation::init(int _a_,int _b_, int _c_){
    this->a = _a_;
    this->b = _b_;
    this->c = _c_;
}
bool algoplus::equation::solvable(){
    return !fall;
}
std::pair <int, int> algoplus::equation::solve(){
    int x, y,g, mult;
    std::tie(x,y,g) = algoplus::equation::gcd(a,b);
    if (c%g == 0){
        mult  = c/g;
        fall = true;
        return std::make_pair(x*mult, y*mult);
    } else {
        fall = false;
        return std::make_pair(0,0);
    }
}
std::pair <int, int> algoplus::equation::solve(int k){
    int x, y, g,mult;
    std::tie(x,y,g) = algoplus::equation::gcd(a,b);
    if (c%g == 0){
        mult  = c/g;
        fall = true;
        return std::make_pair(x*mult+(b*k)/g, y*mult-(a*k)/g);
    } else {
        fall = false;
        return std::make_pair(0,0);
    }
}
algoplus::equation::equation(){}
algoplus::equation::equation(int __a, int __b, int __c){
    algoplus::equation::init(__a,__b,__c);
}
inline long long algoplus::bpow(long long a, long long pow,long long mod){
	if (a == 1 || pow == 0) {
		return 1;
	} else if (pow == 1) {
		return a%=mod;
	} else {
		long long  part = algoplus::bpow(a, pow >> 1,mod)%mod;
		if (pow & 1) {
			return (((part * part)%mod) * a)%mod;
		} else {
			return (part * part)%mod;
		}
	}
}
template <typename T> inline T algoplus::gcd(T a, T b){
    if (b == 0) return a;
    return algoplus::gcd(b,a%b);
}
template <typename T> T algoplus::lcm(T a, T b){
    return a*b/algoplus::gcd(a,b);
}
bool algoplus::isprime(int N){
    if (N < 2) return false;
    for(int i = 2; i*i <=N; i++){
        if (N%i==0) return false;
    }
    return true;
}

bool algoplus::fast_prime(long long x){
    if(x == 2)
		return true;
	srand(time(NULL));
	for(int i=0;i<100;i++){
		long long a = (rand() % (x - 2)) + 2;
		if (e_gcd(a, x) != 1)
			return false;
		if( pows(a, x-1, x) != 1)
			return false;
	}
	return true;
}
// O(sqrt(n)), быстрее, но подсчет степени медленнее
std::vector <long long> algoplus::factorisation(long long N){
    std::vector <long long> f;
    for(long long i = 2; i * i <= N; i++){
        while(N%i == 0){
            f.push_back(N);
            N/=i;
        }
    }
    if (N > 1) f.push_back(N);
    return f;
}
//O(sqrt(nlogn))
// чуть медленнее, но если нужна быстро узанть  /alpha_i(степень делителя), то это лучше
std::map <long long,long long> algoplus::factorisation_with_map(long long N){
    std::map <long long,long long> f;
    for(long long i = 2; i * i <= N; i++){
        while(N%i == 0){
            f[i]++;
            N/=i;
        }
    }
    if (N > 1) f[N]++;
    return f;
}
std::vector <bool> algoplus::eratostene(int N){
    std::vector <bool> sieve;
    sieve.assign(N<<1,0);
    for (int i = 2; i <= N; i++){
        if (sieve[i]) continue;
        for (int j = i<<1; j <= N; j+=i){
            sieve[j] = true;
        }
    }
    return sieve;
}
