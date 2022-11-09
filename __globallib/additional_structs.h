void algoplus::DSU::init(int n){// ?сменить нумерацию можно здесь
    size.assign(n+1,1);
    link.resize(n+1);
    for (size_t i = 1; i <= n; i++) link[i] = i;
}
int algoplus::DSU::find(int x){
    while(x != link[x]) x = link[x];
    return x;
}
bool algoplus::DSU::same(int a, int b){
    return (algoplus::DSU::find(a)==algoplus::DSU::find(b));
}
void algoplus::DSU::unite(int a, int b){
    a = algoplus::DSU::find(a);
    b = algoplus::DSU::find(b);
    if(size[a]<size[b]) std::swap(a,b);
    size[a] += size[b];
    link[b] = a;
}
algoplus::DSU::DSU(){}
algoplus::DSU::DSU(int n){init(n);}
void algoplus::DSUe2::add(int v) {
    parent[v] = v;
    rank[v] = 0;
}
void algoplus::DSUe2::init(int n){// ?сменить нумерацию можно здесь
    parent.resize(n);
    rank.resize(n);
    for (size_t i = 0; i < n; i++) algoplus::DSUe2::add(i);
}
int algoplus::DSUe2::find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = algoplus::DSUe2::find(parent[v]);
}
void algoplus::DSUe2::unite(int a, int b) {
    a = algoplus::DSUe2::find(a);
    b = algoplus::DSUe2::find(b);
    if (a != b) {
        if (rank[a] < rank[b])
            std::swap (a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            ++rank[a];
    }
}
bool algoplus::DSUe2::same(int a, int b){
    return (algoplus::DSUe2::find(a)==algoplus::DSUe2::find(b));
}
algoplus::DSUe2::DSUe2(){}
algoplus::DSUe2::DSUe2(int n){init(n);}
algoplus::treap::node::node() { }
algoplus::treap::node::node (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
algoplus::treap::node::node (int key) : key(key), prior(rand()%(int)(1e9+7)), l(NULL), r(NULL) { }
void algoplus::treap::erase (algoplus::treap::node* t, int key){
    if (t->key == key)
        algoplus::treap::merge (t, t->l, t->r);
    else
        algoplus::treap::erase (key < t->key ? t->l : t->r, key);
}
algoplus::treap algoplus::treap::unite (treap a, treap b) {
    algoplus::treap::node* l = a.root;
    algoplus::treap::node* r = b.root;
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  std::swap (l, r);
    algoplus::treap::node* lt; algoplus::treap::node* rt;
    algoplus::treap::split (r, l->key, lt, rt);
    l->l = algoplus::treap::unite(l->l, lt).root;
    l->r = algoplus::treap::unite(l->r, rt).root;
    return treap(l);
}
void algoplus::treap::split (algoplus::treap::node* t, int key, algoplus::treap::node* & l, algoplus::treap::node* & r) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        algoplus::treap::split (t->l, key, l, t->l),  r = t;
    else
        algoplus::treap::split (t->r, key, t->r, r),  l = t;
}
void algoplus::treap::insert (algoplus::treap::node* & t, algoplus::treap::node* it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        algoplus::treap::split (t, it->key, it->l, it->r),  t = it;
    else
        algoplus::treap::insert (it->key < t->key ? t->l : t->r, it);
}

void algoplus::treap::merge (algoplus::treap::node* & t, algoplus::treap::node* l, algoplus::treap::node* r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        algoplus::treap::merge (l->r, l->r, r),  t = l;
    else
        algoplus::treap::merge (r->l, l, r->l),  t = r;
}
void algoplus::treap::split(int key, treap a, treap b){
    algoplus::treap::split(root,key,a.root,b.root);
}
void algoplus::treap::insert(int key){
    algoplus::treap::node *tmp = new algoplus::treap::node;
    tmp->key = key; tmp->prior = rand()%(int)(1e9+7);
    tmp->l = tmp->r = NULL;
    algoplus::treap::insert(root,tmp);
}
void algoplus::treap::merge(treap a, treap b){
    algoplus::treap::merge(root,a.root,b.root);
}
void algoplus::treap::erase (int key){
    algoplus::treap::node * t = root;
    if (t->key == key)
        algoplus::treap::merge (t, t->l, t->r);
    else
        algoplus::treap::erase (key < t->key ? t->l : t->r, key);
}
algoplus::treap algoplus::treap::unite(treap b){
    return algoplus::treap::unite(*this,b);
}
algoplus::treap::treap(algoplus::treap::node * x){
    this->root = x;
}
algoplus::treap::treap(int x){
    algoplus::treap::node tmp = algoplus::treap::node(x);
    this->root = &tmp;
}
