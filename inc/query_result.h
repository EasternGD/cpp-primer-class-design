#ifndef QUERY_RESULT_H_
#define QUERY_RESULT_H_

#include <string>
#include <vector>
#include <set>
#include <memory>
#include <ostream>

using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

class QueryResult {
  using line_no = vector<string>::size_type;

private:
  string word_;
  shared_ptr<set<line_no>> lines_;
  shared_ptr<vector<string>> content_;

public:
  QueryResult(const string& word, shared_ptr<set<line_no>> lines,
              shared_ptr<vector<string>> content)
      : word_(word)
      , lines_(lines)
      , content_(content)
  {}

  void dump(ostream& outpu);
};

#endif
