#include <iostream>
#include <text-query/query-result.hpp>
#include <text-query/text-query.hpp>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    string    file_name(argv[1]);
    TextQuery tq(file_name);
    while (true) {
        string word;
        cout << "enter the word to look for, or q to quit: ";
        if (!(cin >> word) || word == "q") break;
        auto result = tq.query(word);
        result.dump(cout);
    }
}
