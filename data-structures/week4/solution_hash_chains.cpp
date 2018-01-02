#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using std::string;
using std::vector;
using std::cin;
using std::list;

struct Query {
    string type, s;
    size_t ind;
};

/*
 * Possible solution is ---- Vector of list or list of list doesn't matter
 * using pointer to pointer
 * using hash set from cpp stl
 */

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector <list <string > > mylist;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {
    	mylist.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            vector <list <string> >::iterator itr = mylist.begin();
        	list <string>::iterator stritr;
        	for (stritr = itr[query.ind].begin(); stritr != itr[query.ind].end(); stritr++)
        	{
        		std::cout << *stritr << " ";
        	}
            std::cout << "\n";
        } else {

            size_t index = hash_func(query.s);
            vector <list <string> >::iterator itr = mylist.begin();
            list <string> s = itr[index];
            list <string>::iterator stritr = std::find(s.begin(), s.end(),query.s);

        	if (query.type == "find")
                writeSearchResult(stritr != s.end());
            else if (query.type == "add") {
                if (stritr == s.end()) {
                    //if
                	s.push_front(query.s);
                	list <string> stemp = s;
                	mylist.erase(mylist.begin() + index);
                	mylist.insert(mylist.begin() + index, stemp);
                }
            } else if (query.type == "del") {
                if (stritr != s.end())
                    s.erase(stritr);
                	list <string> stemp = s;
                	mylist.erase(mylist.begin() + index);
                	mylist.insert(mylist.begin() + index, stemp);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
