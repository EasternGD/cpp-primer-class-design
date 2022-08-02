
#ifndef TEXT_QUERY_H_
#define TEXT_QUERY_H_

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <text-query/query-result.hpp>

using std::ifstream;
using std::map;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

class TextQuery {
  using line_no = vector<string>::size_type;

private:
  ifstream fd_;
  shared_ptr<vector<string>> content_;
  map<string, shared_ptr<set<line_no>>> association_;

public:
  TextQuery(const string& file_name);
  QueryResult query(const string& word) const;
};
#endif
