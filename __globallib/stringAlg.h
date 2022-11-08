std::string algoplus::lcs(std::string a, std::string b){
    int n = a.size();
    int m = b.size();
    std::vector<std::vector<int>> data(n+1,std::vector<int>(m+1));
    for(int i = 0; i < n+1; i++){
        for(int j= 0; j < m+1; j++){
            if(i==0 || j==0){
                data[i][j] = 0;
            } else if (a[i-1]!=b[j-1]){
                data[i][j] = 0;
            } else if(a[i-1]==b[j-1]){
                data[i][j] = data[i-1][j-1]+1;
            }
        }
    }
    int mx = INT_MIN;
    int ii, jj;
    for(int i = 0; i < n+1; i++){
        for(int j= 0; j < m+1; j++){
            if(data[i][j]>mx){
                mx = data[i][j];
                ii = i;
                jj = j;
            }
        }

    }
    return a.substr(ii-mx,mx);
}

int algoplus::len_longest_palindrome(std::string s){
    int n = s.length();
    std::vector<int> d1 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 1 : std::min (d1[l+r-i], r-i+1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
    }
    std::vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : std::min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
    return std::max(2*(*std::max_element(d1.begin(),d1.end()))-1,2*(*std::max_element(d2.begin(),d2.end())));
}
std::vector <std::pair <int, int>> algoplus::pair_palindrome_index(std::string s){
    int n = s.length();
    std::vector<int> d1 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 1 : std::min (d1[l+r-i], r-i+1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
    }
    std::vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : std::min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
    std::vector <std::pair <int, int>> ans = {};
    for (size_t i = 0; i < n; i++){
        for(size_t l = 1; l < d1[i]; l++){
            ans.push_back({i-l,i+l});
        }
    }
    for (size_t i = 0; i < n; i++){
        for(size_t l = 0; l < d2[i]; l++){
            ans.push_back({i-l,i+l-1});
        }
    }
    return ans;
}
long long algoplus::count_pair_palindrome_index(std::string s){
    int n = s.length();
    std::vector<int> d1 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 1 : std::min (d1[l+r-i], r-i+1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
    }
    std::vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : std::min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
    long long anss = 0;
    for (size_t i = 0; i < n; i++){
        for(size_t l = 1; l < d1[i]; l++){
            anss++;
        }
    }
    for (size_t i = 0; i < n; i++){
        for(size_t l = 0; l < d2[i]; l++){
            anss++;
        }
    }
    return anss;
}
std::string algoplus::longest_palindrome(std::string s){
    int n = s.length();
    std::vector<int> d1 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 1 : std::min (d1[l+r-i], r-i+1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
    }
    std::vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : std::min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
    std::string ann;
    int lens = std::max(2*(*max_element(d1.begin(),d1.end()))-1,2*(*max_element(d2.begin(),d2.end())));
    if(lens == 2*(*max_element(d1.begin(),d1.end()))-1){
        int ind = max_element(d1.begin(),d1.end()) - d1.begin();
        for (size_t i = ind-d1[ind]+1; i < ind-d1[ind]+lens+1; i++){
            ann.push_back(s[i]);
        }

    } else {
        int ind = max_element(d2.begin(),d2.end()) - d2.begin();
        for (size_t i = ind-d2[ind]; i < ind-d2[ind]+lens; i++){
            ann.push_back(s[i]);
        }
    }
    return ann;
}
algoplus::Z_array::Z_array(std::string s){
    init(s);
}
algoplus::Z_array::Z_array(){
    init(" ");
}
size_t algoplus::Z_array::size(){
    return size_it;
}
void algoplus::Z_array::init(std::string s){
    inp = s;
    size_it = s.length();
    int n = (int) s.length();
    z_array.resize(n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z_array[i] = std::min (r-i+1, z_array[i-l]);
        while (i+z_array[i] < n && s[z_array[i]] == s[i+z_array[i]])
            ++z_array[i];
        if (i+z_array[i]-1 > r)
            l = i,  r = i+z_array[i]-1;
    }
    return;
}
int algoplus::Z_array::operator[](size_t ind){
    return z_array[ind];
}
void algoplus::Z_array::print(std::string sep ){
    for(size_t i = 0; i < size_it; i++) {
        std::cout << z_array[i] << sep;
    }
    std::cout <<std::endl;
}
std::vector <int> algoplus::find_substring(std::string data, std::string pat){
    std::string zz = pat + "`" + data;
    algoplus::Z_array arr(zz);
    int m = pat.size();
    std::vector <int> ans = {};
    for (size_t i = 0; i < arr.size(); i++){
        if(arr[i]==m) ans.push_back(i-m-1);
    }
    return ans;

}
std::vector<size_t> algoplus::Rabin_Karp(std::string s,std::string sub){
    algoplus::hashstring hs;
    algoplus::hashstring hsub;
    hs.init(s);
    hsub.init(sub);
    size_t len = sub.size();
    std::vector <size_t> ans;
    for (size_t i = 0;i+len-1 < s.size(); i++){
        if (hsub.allhash()*hs.poww(i)==hs.prefix_hash(i,len)) ans.push_back(i);//сравниванием хэши
    }
    return ans;
}
void algoplus::hashstring::init(const std::string &pull){//инициализируем префикс-хэши от строки
    data = pull;
    len = pull.size();
    p_pow.resize(len);
    h.resize(len);
    p_pow[0] = 1;
    for (size_t i = 1; i < len; i++){
        p_pow[i] = (p_pow[i-1]*p)%mod;// запоимнаем в массив степеней
    }
    for (size_t i = 0; i < len; i++){
        h[i] = ((data[i]- 'a' + 1) * p_pow[i])%mod;  //высчитываем хэш
        if (i) h[i] += h[i-1];
    }
}
bool algoplus::hashstring::compare(size_t i1,size_t j1, size_t i2, size_t j2){//сравнение двух подстрок
    size_t lent = j1-i1;// вычисление длины подстроки
    long long h1 = h[i1+lent-1];
    if (i1)  h1 -= h[i1-1];// вычисление первого хэша
    long long h2 = h[i2+lent-1];
    if (i2)  h2 -= h[i2-1];// второго
    if (i1 < i2 && h1 * p_pow[i2-i1] == h2 || i1 > i2 && h1 == h2 * p_pow[i1-i2]) return true; //сравнение
    else return false;
}
long long algoplus::hashstring::allhash(){
    return *(--h.end());// хэш от всей строки
}
long long algoplus::hashstring::prefix_hash(size_t i, size_t len){
    long long cur_h = h[i+len-1];// хэш от префикса
    if (i)  cur_h -= h[i-1];
    return cur_h;
}
void algoplus::hashstring::printhashs(){
    for(const auto & aa: h) std::cout << aa <<" "; std::cout <<'\n';// все хэши
    return;
}
long long algoplus::hashstring::poww(size_t i){// стпень в позиции
    return p_pow[i];
}
