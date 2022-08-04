// -----------------------------------------------------------------------------
#include "libstrblob/strblob.hpp"
// -----------------------------------------------------------------------------
// StrBlob
// -----------------------------------------------------------------------------
void StrBlob::pop_back() {

    check(0, "pop_back on empty StrBlob");

    data->pop_back();
}
// -----------------------------------------------------------------------------
string& StrBlob::front() {

    check(0, "front on empty StrBlob");

    return data->front();
}
// -----------------------------------------------------------------------------
string& StrBlob::back() {

    check(0, "back on empty StrBlob");

    return data->back();
}
// -----------------------------------------------------------------------------
const string& StrBlob::front() const {

    check(0, "front on empty StrBlob");

    return data->front();
}
// -----------------------------------------------------------------------------
const string& StrBlob::back() const {

    check(0, "back on empty StrBlob");

    return data->back();
}
// -----------------------------------------------------------------------------
StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }
// -----------------------------------------------------------------------------
// StrBlobPtr
// -----------------------------------------------------------------------------
bool StrBlobPtr::operator!=(const StrBlobPtr& rhs) {
    return (curr != rhs.curr);
}

// -----------------------------------------------------------------------------
StrBlobPtr& StrBlobPtr::operator++() {

    check(curr++, "increment past end of StrBlobPtr");

    return *this;
}
// -----------------------------------------------------------------------------
string& StrBlobPtr::operator*() {

    auto p = check(curr, "dereference past end");

    return p->at(curr);
}
// ----------------------------------------------------------------------------
shared_ptr<vector<string>> StrBlobPtr::check(size_t        sz,
                                             const string& msg) const {
    auto ret = wptr.lock();

    if (!ret) throw std::runtime_error("unbound StrBlobPtr");

    if (sz >= ret->size()) throw std::out_of_range(msg);

    return ret;
}
// ----------------------------------------------------------------------------
