#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static const int ALPHA = 26;
static const int MAXN = 1000001;

struct trie
{
    trie *go[ALPHA];
    trie *upTerm;
    int id;

    trie(int id) : id(id) {
        for (int i = 0; i < ALPHA; i++)
            go[i] = NULL;
    }

    trie() : id(-1){
        for (int i = 0; i < ALPHA; i++)
            go[i] = NULL;
    }

    static int allocated;
    static char* buf;

    void* operator new(size_t)
    {
        return buf + (allocated++ * sizeof(trie));
    }
};

int trie::allocated = 0;
char* trie::buf = new char[MAXN * sizeof(trie)];

trie* root;

trie ALL[MAXN];
int sz_cnt;

inline trie* add(const string& s, const int &id)
{
    trie* now = root;
    for (int i = 0; i < s.size(); i++)
    {
        int ch = s[i] - 'a';
        if (now->go[ch] == NULL)
            now->go[ch] = &ALL[sz_cnt++];
        now = now->go[ch];
    }
    now->id = id;
    return now;
}

inline void buildUpTerms(trie* t, trie* p)
{
    if (t->id != -1)
        t->upTerm = p;
    for (int i = 0; i < ALPHA; i++)
        if (t->go[i] != NULL)
            buildUpTerms(t->go[i], t->id == -1 ? p : t);
}

vector<long long> cost;
vector<trie*> pizzas;
vector<int> pizzaSize;

inline long long get(const int &pizza, const int &k)
{
    trie* now = pizzas[pizza];
    long long ans = 0;
    while (now != NULL && pizzaSize[now->id] >= k)
    {
        ans += cost[now->id];
        now = now->upTerm;
    }
    return ans;
}

int main()
{
    ifstream in("pizza.in");
    ofstream out("pizza.out");
    int n, m;
    root = &ALL[sz_cnt++];
    
    ios_base :: sync_with_stdio (0);
    in.tie (0);

    in >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        int c;
        in >> s >> c;
        pizzas.push_back(add(s, i));
        cost.push_back(c);
        pizzaSize.push_back(s.size());
    }
    buildUpTerms(root, NULL);
    for (int i = 0; i < m; i++)
    {
        string type;
        int pizza, c;
        in >> type >> pizza >> c;
        pizza--;
        if (type == "?")
        {
            out << get(pizza, c) << "\n";
        }
        else if (type == "!")
            cost[pizza] += c;
    }
}
