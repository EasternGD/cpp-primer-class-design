// ----------------------------------------------------------------------------
#include <libmail-handle/mail_handle.hpp>

// ----------------------------------------------------------------------------
void Folder::AddMsg(Message* msg) { msg_list_.insert(msg); }
// ----------------------------------------------------------------------------

void Folder::RemMsg(Message* msg) { msg_list_.erase(msg); }
// ----------------------------------------------------------------------------
void Message::Save(Folder& f) {
    this->folders_.insert(&f);
    f.AddMsg(this);
}
// ----------------------------------------------------------------------------
void Message::Remove(Folder& f) {
    this->folders_.erase(&f);
    f.RemMsg(this);
}
// ----------------------------------------------------------------------------
// Copy Control, the copy should appear in
// the same original message's folders
Message::Message(const Message& m)
    : content_(m.content_)
    , folders_(m.folders_) {
    this->AddToFolders(m);
}

Message& Message::operator=(const Message& rhs) {
    this->RemoveFromFolders();
    this->content_ = rhs.content_;
    this->folders_ = rhs.folders_;
    this->AddToFolders(rhs);
    return *this;
}

// ----------------------------------------------------------------------------
void Message::AddToFolders(const Message& m) {

    for (auto f : m.folders_) { f->AddMsg(this); }
}
// ----------------------------------------------------------------------------
void Message::RemoveFromFolders() {

    for (auto f : folders_) { f->RemMsg(this); }
}
// ----------------------------------------------------------------------------

// For google test
std::set<Message*> Folder::msg_list() { return msg_list_; }

std::set<Folder*> Message::folders() { return folders_; }
string            Message::content() { return content_; }
