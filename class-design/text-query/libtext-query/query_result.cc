#include "query_result.h"

void QueryResult::dump(ostream& output)
{
  output << "\"" << word_ << "\" occurs " << lines_->size() << " time(s)\n";

  for (auto num : *lines_)
  {
    output << "\t(line: " << num + 1 << ") ";
    output << content_->at(num) << "\n";
  }
}
