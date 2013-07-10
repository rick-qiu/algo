#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int max_subsum(const vector<int>& a) {
    int max_sum = 0;
    int sum = 0;
    for(int i = 0; i < a.size(); ++i) {
	if(sum < 0) sum = 0;
	sum += a[i];
	max_sum = max(max_sum, sum);
    }
    return max_sum;
}

int main(int argc, char* argv[]) {
    vector<int> a = {1, -2, 3, 10, -4, 7, 2, -5};
    int max = max_subsum(a);
    cout << "Maximum sum of sunarray: " << max << endl;
    return 0;
}
