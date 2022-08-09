#include <libstrvec/strvec.hpp>
// ----------------------------------------------------------------------------
StrVec::StrVec(const StrVec& rhs) {
    auto data   = AllocateAndCopy(rhs.begin(), rhs.end());
    elements_   = data.first;
    first_free_ = cap_ = data.second;
}
// ----------------------------------------------------------------------------
StrVec& StrVec::operator=(const StrVec& rhs) {
    Free();
    auto data   = AllocateAndCopy(rhs.begin(), rhs.end());
    elements_   = data.first;
    first_free_ = cap_ = data.second;
    return *this;
}
// ----------------------------------------------------------------------------
void StrVec::push_back(const string& element) {
    CheckAndAllocate();
    allocator_.construct(first_free_++, element);
}
// ----------------------------------------------------------------------------
pair<string*, string*> StrVec::AllocateAndCopy(const string* b,
                                               const string* e) {
    auto data = allocator_.allocate(e - b);

    return {data, std::uninitialized_copy(b, e, data)};
}
// ----------------------------------------------------------------------------
void StrVec::Free() {
    for (auto p = first_free_; p != elements_;) { allocator_.destroy(--p); }
    allocator_.deallocate(elements_, cap_ - elements_);
}
// ----------------------------------------------------------------------------
void StrVec::Reallocate() {
    auto new_capcity = size() ? 2 * size() : 1;
    auto new_data    = allocator_.allocate(new_capcity);
    auto dest        = new_data;
    auto element     = elements_;
    for (auto i = 0; i != size(); ++i) {
        allocator_.construct(dest++, std::move(*element++));
    }
    Free();
    elements_   = new_data;
    first_free_ = dest;
    cap_        = elements_ + new_capcity;
}
// ----------------------------------------------------------------------------
void StrVec::CheckAndAllocate() {
    if (first_free_ == cap_) { Reallocate(); }
}
// ----------------------------------------------------------------------------

void StrVec::reserve(const size_t& n) {
    auto new_data = allocator_.allocate(n);
    auto dest     = new_data;
    auto element  = elements_;

    for (auto i = 0; i != size(); ++i) {
        allocator_.construct(dest++, move(*element++));
    }
    Free();
    elements_   = new_data;
    first_free_ = dest;
    cap_        = elements_ + n;
}

// ----------------------------------------------------------------------------