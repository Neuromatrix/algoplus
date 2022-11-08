


int algoplus::ancestors_tree::query(int node, int k){
    int boss = node;
    for(int i=0; i<=20; i++)
        if(k & (1<<i))
            boss = data[i][boss];
    return (boss==0 ? -1 : boss);
}
void algoplus::ancestors_tree::init(const std::vector <std::vector <int>> &graph){
    gr = graph;
    n = gr.size();
    data.resize(n+1);
    data[0].resize(n+1);
    dfs(root, 0);
    for (int i = 1; 1<<i <= n ; i++){
        data[i].resize(n+1);
        for (int j = 0; j <= n ; j++)
            data[i][j] = data[i-1][data[i-1][j]];
    }
}
inline void algoplus::ancestors_tree::dfs(int cur, int prev){
    data[0][cur] = prev;
    for(const auto &nex :gr[cur]){
        if(nex==prev) continue;
        dfs(nex,cur);
    }
}

inline void algoplus::LCA::dfs(int cur, int prev, int d){
    depth.push_back(d);
    order.push_back(cur);
    for(const auto & nex: gr[cur]){
        if(nex==prev) continue;
        dfs(nex,cur,d+1);
        order.push_back(cur);
        depth.push_back(d);
    }
}
void algoplus::LCA::init(const std::vector <std::vector <int>> & graph){//!натуральная нумерация
    n = graph.size();
    gr = graph;
    dfs(1,0);
    for (size_t i = 0; i < order.size(); i++){
        index[order[i]] = i;
    }
    ancset.init(graph);
    data.init(depth);
}
int algoplus::LCA::query(int a, int b){
    return ancset.query(a,depth[index[a]]-data.mins(std::min(index[a],index[b]),std::max(index[a],index[b])+1));
    // return data.mins(min(index[a],index[b]),max(index[a],index[b])+1); высота предка над a и b
}




