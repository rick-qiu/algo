#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int find_num(const vector<int>& v, int n) {
    int ret = -1;
    int i = 0;
    while(i < v.size()) {
        if(v[i] == n) {
            ret = i;
            break;
        } else {
            i += abs(v[i] - n);
        }
    } 
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> v{4,5,6,7,8,9,10,9};
    cout << find_num(v, 7) << ' ' << find_num(v, -3) << ' ' << find_num(v, 9) << endl;
    return 0;
}
