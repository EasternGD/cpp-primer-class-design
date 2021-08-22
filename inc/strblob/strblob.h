#ifndef STRBLOB_H_
#define STRBLOB_H_
// ----------------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
// ----------------------------------------------------------------------------
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;
using std::weak_ptr;
// ----------------------------------------------------------------------------
class StrBlobPtr;
class StrBlob {

    friend class StrBlobPtr;

public:
    using size_type = vector<string>::size_type;

    StrBlob()
        : data(make_shared<vector<string>>()) {}

    StrBlob(std::initializer_list<string> il)
        : data(make_shared<vector<string>>(il)) {}

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    void push_back(const string& t) { data->push_back(t); }
    void pop_back();

    StrBlobPtr begin();
    StrBlobPtr end();

    std::string& front();
    std::string& back();

    const std::string& front() const;
    const std::string& back() const;

private:
    void check(size_type i, const string& msg) const {
        if (i >= data->size()) throw std::out_of_range(msg);
    }

private:
    std::shared_ptr<vector<string>> data;
};

class StrBlobPtr {
private:
    weak_ptr<vector<string>> wptr;
    size_t                   curr;

public:
    StrBlobPtr()
        : curr(0) {}

    StrBlobPtr(StrBlob& a, size_t sz = 0)
        : wptr(a.data)
        , curr(sz) {}

    string&     deref() const;
    StrBlobPtr& operator++();
    string&     operator*();
    bool        operator!=(const StrBlobPtr& rhs);

private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
};
#endif
