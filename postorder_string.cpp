#include <string>
#include <cassert>
#include <cstdio>

using namespace std;

string postorder_string(const string& preorder, const string& inorder) {
    assert(preorder.size() == inorder.size());
    if(preorder.size() <= 1) {
        return preorder;
    }
    auto root = *preorder.begin();
    auto root_idx = inorder.find_first_of(root);
    auto inorder_left = inorder.substr(0, root_idx);
    auto inorder_right = inorder.substr(root_idx + 1);
    auto preorder_left = preorder.substr(1, inorder_left.size());
    auto preorder_right = preorder.substr(inorder_left.size() + 1);
    return postorder_string(preorder_left, inorder_left) + 
        postorder_string(preorder_right, inorder_right) + string(1, root);
}


int main(int argc, char *argv[]) {
    string preorder("ABDHECFG");
    string inorder("HDBEAFCG");
    string postorder = postorder_string(preorder, inorder);
    printf("preorder = %s, inorder = %s, postorder = %s\n", preorder.c_str(), inorder.c_str(), postorder.c_str());
    return 0;
}
