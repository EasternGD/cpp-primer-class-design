#ifndef STRVEC_HPP
#define STRVEC_HPP
// ----------------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

// ----------------------------------------------------------------------------
using std::cout;
using std::endl;
using std::pair;
using std::string;
// ----------------------------------------------------------------------------
class StrVec {
  private:
    string*                elements_;
    string*                first_free_;
    string*                cap_;
    std::allocator<string> allocator_;

  private:
    pair<string*, string*> AllocateAndCopy(const string* b, const string* e);
    void                   Free();
    void                   Reallocate();
    void                   CheckAndAllocate();

  public:
    StrVec()
        : elements_(nullptr)
        , first_free_(nullptr)
        , cap_(nullptr) {};

    StrVec(const StrVec& rhs);

    StrVec& operator=(const StrVec& rhs);

    string& operator[](const int& n) {
        if (n >= size()) throw std::out_of_range("out of range");
        return *(elements_ + n);
    }
    
    string& back() { return *(elements_ + size() - 1); }

    std::string* begin() const { return elements_; }
    std::string* end() const { return first_free_; }

    size_t size() { return first_free_ - elements_; }
    size_t capacity() { return cap_ - elements_; }

    void push_back(const string& element);
    void reserve(const size_t& n);
    void resize(const size_t& n, const string& init = string());

};

// ----------------------------------------------------------------------------
#endif
