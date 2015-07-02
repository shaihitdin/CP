#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static const int ALPHA = 26;

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
};

trie* root;
trie* add(const string& s, int id)
{
    trie* now = root;
    for (int i = 0; i < s.size(); i++)
    {
        int ch = s[i] - 'a';
        if (now->go[ch] == NULL)
            now->go[ch] = new trie();
        now = now->go[ch];
    }
    now->id = id;
    return now;
}

void buildUpTerms(trie* t, trie* p)
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

long long get(int pizza, int k)
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
    
    ios_base :: sync_with_stdio (0);
    cin.tie (0);

    int n, m;
    root = new trie();
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
