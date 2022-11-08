
template <typename T> void algoplus::sparse_table<T>::resize(size_t new_size){
    size_t t = std::__lg(new_size)+1;
    data.resize(t);
    for(size_t i = 0; i < t; i++){
        data[i].assign(new_size,INT_MAX);
    }
    size_it = new_size;
}
template <typename T> void algoplus::sparse_table<T>::init(const std::vector <T> &gh){
    resize(gh.size());
    data[0] = gh;
    for (int l = 0; l < std::__lg(size_it); l++){
        for (int i = 0; i + (2 << l) <= size_it; i++){
            data[l+1][i] = std::min(data[l][i], data[l][i + (1 << l)]);
        }
    }
}
template <typename T> T algoplus::sparse_table<T>::mins(size_t l, size_t r){ // [l,r)
    int t = std::__lg(r - l);
    return std::min(data[t][l], data[t][r - (1 << t)]);
}
template <typename T> void algoplus::sparse_table<T>::print(){
    for (int i = 0; i < data.size();i++){
        for (int j = 0; j < data[i].size();j++){
            if(data[i][j]==INT_MAX) std::cout << "-" <<" ";
            else std::cout << data[i][j] << " ";
        }
        std::cout << '\n';
    }
}
template <typename T> algoplus::sparse_table<T>::sparse_table(size_t new_size){
    resize(new_size);
}
template <typename T> algoplus::sparse_table<T>::sparse_table(const std::vector <T> &gh){
    resize(gh.size());
    init(gh);
}
template <typename T> algoplus::sparse_table<T>::sparse_table(size_t new_size, const std::vector <T> &gh){
    resize(new_size);
    init(gh);
}


template <typename T> void algoplus::prefix_sum<T>::init(const std::vector <T> &pool){
    size_it = pool.size();
    pre_sum.resize(size_it);
    pre_sum[0] = pool[0];
    for (size_t i = 1; i < size_it; i++){
        pre_sum[i] = pre_sum[i-1] + pool[i];
    }
}
template <typename T> T algoplus::prefix_sum<T>:: sum(ssize_t l, ssize_t r){ //[l,r]
    assert(!(l < 0  || r < 0 || l > size_it || r > size_it));
    if (std::min(l,r) > 0) return pre_sum[std::max(l,r)]-pre_sum[std::min(l,r)-1];
    else return pre_sum[std::max(l,r)];
}
template <typename T> size_t algoplus::prefix_sum<T>:: size(){
    return size_it;
}
template <typename T>  algoplus::prefix_sum<T>::prefix_sum(const std::vector <T> &pool){
    init(pool);
}
template <typename T> algoplus::prefix_sum<T>::prefix_sum(){
    size_it = 0;
}


