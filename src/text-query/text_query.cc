#include "text_query.h"

using std::cerr;
using std::cin;
using std::istringstream;
using std::make_shared;

TextQuery::TextQuery(const string& file_name)
    : fd_(file_name)
    , content_(make_shared<vector<string>>()) {

    if (!fd_.is_open()) {
        cerr << "[Error] Open file " << file_name << " failed\n";
    }

    string line;
    while (getline(fd_, line)) {

        content_->push_back(line);
        auto          current_line = content_->size() - 1;
        istringstream iss(line);
        string        word;

        while (iss >> word) {

            word.erase(remove_if(word.begin(), word.end(), ispunct),
                       word.end());

            shared_ptr<set<line_no>>& lines = association_[word];

            if (!lines) { lines.reset(new set<line_no>); }

            lines->insert(current_line);
        }
    }

    // for (auto i : *content_) cerr << i << "\n";
    // for (auto i : association_) cerr << i.first << "\n";
}

QueryResult TextQuery::query(const string& word) const {

    auto hit = association_.find(word);

    if (hit != association_.end())
        return QueryResult(word, hit->second, content_);
    else
        return QueryResult(
            word, make_shared<set<line_no>>(), make_shared<vector<string>>());
}
