
Run `make test` to see a working example

### Saving the data in C++

Use macro `MSGPACK_DEFINE` in your class declaration:

```cpp
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
```

Save the data:

```cpp
    vector<example_class> entries;
    
    // store the data in 'entries'

    std::stringstream sbuf;
    msgpack::pack(sbuf, entries);
    ofstream myfile1("output.data");
    myfile1 << sbuf.str();
    myfile1.close();
```

### Loading the data in Python:

```python
import msgpack

with open('output.data', 'rb') as f:
    data = msgpack.load(f)
```

