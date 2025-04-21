#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> table;
    size_t min =0xFFFFFFFF;
    sort(phone_book.begin(), phone_book.end());
    for(string phone : phone_book) {
        if(!table.empty()) {
            for(int i = min; i <= phone.size(); i++) {
                string key = phone.substr(0, i);
                if(table.find(key) != table.end()) return false;
            }
        }
        table.insert(phone);
        if(phone.size() < min) min = phone.size();
    }
    return answer;
}