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
