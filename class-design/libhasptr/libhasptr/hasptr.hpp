#ifndef HASPTR_H_
#define HASPTR_H_
// ----------------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

// ----------------------------------------------------------------------------
using std::cout;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::vector;
// ----------------------------------------------------------------------------
class HasPtr {

    friend void swap(HasPtr& lhs, HasPtr& rhs);

  private:
    string* ps_;
    int     i_;
    size_t* use_;

  public:
    HasPtr(const string& s = string())
        : ps_(new string(s))
        , i_(0)
        , use_(new size_t(1)) {}

    HasPtr(const HasPtr& rhs)
        : ps_(new string(*rhs.ps_))
        , i_(rhs.i_)
        , use_(rhs.use_) {
        ++*use_;
    }

    ///< Ex. 13.8 deep copy
    HasPtr& operator=(const HasPtr& rhs) {

        ///< Ex. 13.22 remove the condition
        // if (this != &rhs) {
        string* tmp_ps = new string(*rhs.ps_);
        delete ps_;
        ps_ = tmp_ps;
        i_  = rhs.i_;
        // }

        return *this;
    }

    // HasPtr& operator=(const HasPtr& rhs) {

    //     ++*rhs.use_;
    //     if (--*use_ == 0) {
    //         delete ps_;
    //         delete use_;
    //     }

    //     this->ps_  = rhs.ps_;
    //     this->i_   = rhs.i_;
    //     this->use_ = rhs.use_;

    //     return *this;
    // }

    bool operator<(const HasPtr& rhs) { return *this->ps_ < *rhs.ps_; }

  public: // for test
    size_t* use() { return this->use_; };
    int&    i() { return this->i_; }
    string* ps() { return this->ps_; }
    void    dump_ps() { cout << *ps_ << endl; }

  public: // destructor
    ///< Ex. 13.11
    // ~HasPtr(){
    //     delete ps;
    // }

    ~HasPtr() {
        if (*use_ == 0) {
            delete use_;
            delete ps_;
        }
        --*use_;
    }
};

inline void swap(HasPtr& lhs, HasPtr& rhs) {

    using std::swap;
    swap(lhs.ps_, rhs.ps_);
    swap(lhs.i_, rhs.i_);
}

// ----------------------------------------------------------------------------
#endif
