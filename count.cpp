#include <iostream>
#include <vector>

using namespace std;

vector<int> count(const vector<int>& a) {
    int len = a.size();
    vector<int> ret(len, 0);
    bool found = false;
    while(false == found) {
	found = true;
	for(int i = 0; i < len; ++i) {
	    int count = 0;
	    for(int j = 0; j < len; ++j) {
		if(ret[j] == a[i]) {
		    ++count;
		}
	    }
	    if(count != ret[i]) {
		ret[i] = count;
		found = false;
	    }
	}
    }
    return ret;
}

int test0() {
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> expected = {6, 2, 1, 0, 0, 0, 1, 0, 0, 0};
    if(expected == count(a)) {
	cout << "test0 passed" << endl;
	return 0;
    } else {
	cout << "test0 failed" << endl;
	return -1;
    }
}

int main(int argc, char* argv[]) {
    test0();
    return 0;
}
