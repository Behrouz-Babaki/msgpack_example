#include <msgpack.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

using std::string;
using std::vector;
using std::to_string;
using std::ofstream;
using std::stringstream;
using std::map;
using std::pair;
using std::make_pair;

class example_class
{
public:
    string s;
    vector<int> v;
    map<double, string> m;
    pair<int, int> p;
    example_class(string s0,
                  vector<int> v0,
                  map<double, string> m0,
                  pair<int, int> p0) :
        s(s0), v(v0), m(m0), p(p0) {}

    MSGPACK_DEFINE(s, v, m, p);
};

example_class create_example_object(int a)
{
    string s = "n"+to_string(a);

    vector<int> v;
    for (int i=0; i<a; i++)
        v.push_back(i);

    map<double, string> mmap;
    mmap[6] = "breakfast";
    mmap[12] = "lunch";
    mmap[7] = "dinner";

    pair<int, int> p;
    p = make_pair(20, 30);

    example_class m(s, v, mmap, p);
    return m;
}

int main(int argc, char **argv)
{
    vector<example_class> entries;
    entries.push_back(create_example_object(8));
    entries.push_back(create_example_object(10));

    std::stringstream sbuf;
    msgpack::pack(sbuf, entries);
    ofstream myfile1(argv[1]);
    myfile1 << sbuf.str();
    myfile1.close();
    return 0;
}


