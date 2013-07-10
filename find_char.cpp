#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef typename string::size_type idx_t;

idx_t find_char(const string& s) {
    vector<int> hash(256, 0);
    for_each(s.begin(), s.end(), [&](char ch) { ++hash[ch]; });
    for(idx_t i = 0; i < s.size(); ++i) {
	if(hash[s[i]] == 1) return i;
    }
    return string::npos;
}


int main(int argc, char* argv[]) {
    string s = "abaccdeff";
    idx_t idx = find_char(s);
    if(idx != string::npos) {
	cout << s[idx] << endl;
    } else {
	cout << "No such character!" << endl;
    }
    return 0;
}
