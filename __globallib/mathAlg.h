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
