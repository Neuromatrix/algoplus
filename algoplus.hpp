
#include <vector>
#include <unordered_map>

namespace algoplus{
    //STATIC RANGE QUERIES
    // @brief structs can find minimum in [l,r) with O(1)
    template <typename T> class sparse_table{
    private:
        std::vector <std::vector <T>> data;
        size_t size_it = 0;
    public:
        // @brief change size
        void resize(size_t);
        // @brief init function
        void init(const std::vector <T>&);
        // @brief find minimum in [l,r)
        // @return minimum in subarray
        T mins(size_t, size_t);
        // @brief debug print
        void print();
        sparse_table(size_t = 0);
        sparse_table(const std::vector <T>&);
        sparse_table(size_t, const std::vector <T>&);

    };
    // @brief structs can find sum in [l,r] with O(1)
    template <typename T> class prefix_sum{
    private:
        std::vector <T> pre_sum;
        size_t size_it;
    public:
        void init(const std::vector <T> &);
        // @brief find sum in [l,r]
        // @warning overflow of returning value
        T sum(ssize_t, ssize_t);
        // @return size of array
        size_t size();
        prefix_sum(const std::vector <T>&);
        prefix_sum();
    };
    //TREES
    class ancestors_tree{
    private:
        int n;
        std::vector<std::vector<int>> gr;
        std::vector<std::vector<int>> data;
        int root = 1;
        inline void dfs(int,int);

    public:
        // @brief init function
        void init(const std::vector<std::vector<int>>&);
        // @brief query of k-th ansector of v
        // @param v
        // @param k
        // @return index of k-th ansector
        int query(int,int);
    };

    class LCA{
    private:
        int n;
        algoplus::sparse_table <int> data;
        std::vector <std::vector <int>> gr;
        std::vector <int> depth;
        algoplus::ancestors_tree ancset;
        std::vector <int> order;
        std::unordered_map <int, int> index;
        inline void dfs(int, int, int = 1);
    public:
        // @brief init function
        // @param graph represented by adjacency lists
        void init(const std::vector <std::vector <int>> &);
        // @brief quety of least common ansector
        // @param index v1
        // @param index v2
        // @return index of lca(v1,v2)
        int query(int, int);
        LCA(){}
    };
    //STRTNGS
    // @brief Z_array struct
    class Z_array
    {
        private:
            size_t size_it;
            std::string inp;
            std::vector <int> z_array;
        public:
            Z_array(const std::string&);
            Z_array();
            size_t size();
            // @brief init function
            void init(const std::string &);
            // @brief get zarray[i]
            int operator[](size_t);
            // @brief print all zarray(debug)
            void print(std::string = " ");
    };
    // @brief hash of string class
    // @warning collisions
     // @warning need init function
    class hashstring {
        private:
            std::string data;
            size_t len;
            const long long p =  31; //911382323
            const unsigned long long mod = 18446744073709551557ULL;
            std::vector <long long> p_pow;
            std::vector <long long> h;
        public:
            // @brief initialization of string
            void init(const std::string&);
            // @brief compare of s1[l1,r1], s2[l2,r2]
            // @return True (if equal) False (else)
            bool compare(size_t,size_t, size_t, size_t);
            // @return all string hash
            long long allhash();
            // @return hash of prefix
            // @param start index
            // @param len of substring
            long long gethash(size_t, size_t);
            // @brief debug funcition, which print all hashes in string
            void printhashs();
            // @return pow in position
            long long poww(size_t);


    };
    // @brief find with RabinKArp algo
    // @return vector  of indexes, where substring starts
    // @warning collisions
    std::vector<size_t> Rabin_Karp(const std::string&,const std::string&); // with hashes
    // @brief find longest common substring from two lines
    // @return longest common string
    std::string lcs(const std::string&, const std::string&);
    // @brief find longest palindrome substring
    // @return len of longest palindrome
    int len_longest_palindrome(const std::string&); //Manaker
    // @brief find all palindrome substrings
    // @return vector of pairs of indexes [l,r], where s[l..r] is palidrome
    // @warning if string have a lot of palidromes , u get memory errors
    std::vector <std::pair <int, int>> pair_palindrome_index(const std::string&);
    // @brief find all palindrome substrings
    // @return amount palindrome substring
    long long count_pair_palindrome_index(const std::string&);
    // @brief Manaker
    // @return longest palindrome substring with len>2
    std::string longest_palindrome(const std::string&);
    // @brief find with Zarray
    // @return vector  of indexes, where substring starts
    std::vector <int> find_substring(const std::string&, const std::string&);
    // @brief Non natutal enumerate with evristic
    class DSUe2//!две евристики и 0_N нумерация

    {
        private:
            std::vector <int> parent;
            std::vector <int> rank;
        public:
            // @brief add node to DSU
            void add(int);
            // @brief initialize DSU of N nodes
            // @param N - amount nodes
            void init(int);
            // @brief find node's v parent
            // @brief return index of parent
            int find(int);
            // @brief unite two nodes
            void unite(int, int);
            // @brief checks if two nodes have the same parents
            // @return True if same False else
            bool same(int, int);
            DSUe2();
            DSUe2(int);
    };
    // @brief Natural numeration without evristic
    class DSU//!наутральная нумерация
    {
        private:
            std::vector <int> link;
            std::vector <int> size;
        public:
            // @brief add node to DSU
            void add(int);
            // @brief initialize DSU of N nodes
            // @param N - amount nodes
            void init(int);
            // @brief find node's v parent
            // @brief return index of parent
            int find(int);
            // @brief unite two nodes
            void unite(int, int);
            // @brief checks if two nodes have the same parents
            // @return True if same False else
            bool same(int, int);
            DSU();
            DSU(int);
    };
    class treap
    {
    private:
        const int MOD = 1e9+7;
        struct node {
            int key, prior;
            node * l, * r;
            node(int,int);
            node(int);
            node();
        };
        node* root;
        void erase (node*, int);
        treap unite (treap, treap);
        void split (node*, int, node* &, node* &);
        void insert (node* &, node*);

        void merge (node* &, node*, node*);
    public:
        // @brief split treap by value  on two treap
        void split(int, treap, treap);
        // @brief insert value in tree
        void insert(int);
        // @brief merge two treps to this
        // @bug maybe wrong desription
        void merge(treap, treap);
        // @brief erase value from treap
        void erase (int);
        // @brief merge this treap and another
        // @return new treap
        treap unite(treap);
        treap(node *);
        treap(int);
    };
}
#include "__globallib/trees.h"
#include "__globallib/range_static_Q.h"
#include "__globallib/stringAlg.h"
#include "__globallib/additional_structs.h"






