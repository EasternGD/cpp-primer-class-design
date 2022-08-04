#include <algorithm>
#include <iostream>
#include <set>
#include <string>
// ----------------------------------------------------------------------------
using std::set;
using std::string;
// ----------------------------------------------------------------------------

class Message;

class Folder {
  private:
    std::set<Message*> msg_list_;

  public:
    void AddMsg(Message* msg);
    void RemMsg(Message* msg);

    // For test
    std::set<Message*> msg_list();
};

class Message {
    friend class Folder;
    friend void Swap(Message&, Message&);

  private:
    string       content_;
    set<Folder*> folders_;

  public:
    explicit Message(const string& str = "")
        : content_(str) {};

    Message(const Message& m);
    Message& operator=(const Message& rhs);

    // for test
    string            content();
    std::set<Folder*> folders();

    void Save(Folder& f);
    void Remove(Folder& f);

    void AddToFolders(const Message& m);
    void RemoveFromFolders();

    ~Message() { RemoveFromFolders(); }
};

void inline Swap(Message& lhs, Message& rhs) {

    using std::swap;

    for (auto& lf : lhs.folders_) { lf->RemMsg(&lhs); }
    for (auto& rf : rhs.folders_) { rf->RemMsg(&rhs); }

    swap(lhs.folders_, rhs.folders_);
    swap(lhs.content_, rhs.content_);

    for (auto& lf : lhs.folders_) { lf->AddMsg(&lhs); }
    for (auto& rf : rhs.folders_) { rf->AddMsg(&rhs); }
}

// ----------------------------------------------------------------------------
