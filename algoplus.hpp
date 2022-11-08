
#include <vector>
#include <unordered_map>

namespace algoplus{
    //STATIC RANGE QUERIES
    template <typename T> class sparse_table{
    private:
        std::vector <std::vector <T>> data;
        size_t size_it = 0;
    public:
        void resize(size_t);
        void init(const std::vector <T>&);
        T mins(size_t, size_t);
        void print();
        sparse_table(size_t = 0);
        sparse_table(const std::vector <T>&);
        sparse_table(size_t, const std::vector <T>&);

    };

    template <typename T> class prefix_sum{
    private:
        std::vector <T> pre_sum;
        size_t size_it;
    public:
        void init(const std::vector <T> &);
        T sum(ssize_t, ssize_t);
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
        void init(const std::vector<std::vector<int>>&);
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
        void init(const std::vector <std::vector <int>> &);
        int query(int, int);
        LCA(){}
    };
    //STRTNGS
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
            void init(const std::string &);
            int operator[](size_t);
            void print(std::string = " ");
    };

    class hashstring {
        private:
            std::string data;
            size_t len;
            const long long p =  31; //911382323
            const unsigned long long mod = 18446744073709551557ULL;
            std::vector <long long> p_pow;
            std::vector <long long> h;
        public:
            void init(const std::string&);
            bool compare(size_t,size_t, size_t, size_t);
            long long allhash();
            long long prefix_hash(size_t, size_t);
            void printhashs();
            long long poww(size_t);
    };

    std::vector<size_t> Rabin_Karp(const std::string&,const std::string&); // with hashes
    std::string lcs(const std::string&, const std::string&); //longest common substring
    int len_longest_palindrome(const std::string&); //Manaker
    std::vector <std::pair <int, int>> pair_palindrome_index(const std::string&); //Manaker
    long long count_pair_palindrome_index(const std::string&); //Manaker
    std::string longest_palindrome(const std::string&); //Manaker
    std::vector <int> find_substring(const std::string&, const std::string&); // with Zarray
}
#include "__globallib/trees.h"
#include "__globallib/range_static_Q.h"
#include "__globallib/stringAlg.h"






