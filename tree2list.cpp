
template<typename T>
struct node {
    T data;
    node *left;
    node *right;
};

template<typename T>
static void tree2list(node<T>*& root) {
    if(root == nullptr) {
        return;
    }
    tree2list(root->left);
    tree2list(root->right);
    auto p = root->left;
    while(p != nullptr && p->next != nullptr) {
        p = p->right;
    }
    if(p != nullptr) {
        auto head = root->left;
        p->right = root;
        root->left = p;
        root = head;
    }
}
