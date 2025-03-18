#include <queue>

template <typename T>
struct BSTNode {
    T value;            
    BSTNode* left;      
    BSTNode* right;     

    BSTNode(const T& val) : value(val), left(nullptr), right(nullptr) {}
};


template <typename T>
class RandomBinaryTree {
    BSTNode<T> *root;
public:
    RandomBinaryTree() : root(nullptr) {} 
    ~RandomBinaryTree() { delete root; } 
    bool empty() const { return root == nullptr; }
    T& top() { assert(root != nullptr); return root->value; } 
    void insert(const T& item) { root = insert(root, item); }
    T* search(const T& item) const {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }
    T calc_total_rek() const {
        return calc_total_rek(root);
    }
    T calc_total_rek(BSTNode<T>* node) const;
    T calc_total_iter() const;
    BSTNode<T> * insert(BSTNode<T> *node, const T& item); 
    BSTNode<T> * search(BSTNode<T> *node, const T& item) const;
};

template <class T>
T RandomBinaryTree<T>::calc_total_rek(BSTNode<T>* node) const {
    if (node == nullptr) {
        return T(0); 
    } else {
        return node->value + calc_total_rek(node->left) + calc_total_rek(node->right);
    }
}

template <typename T>
T RandomBinaryTree<T>::calc_total_iter() const {
    T total = T(0);
    if (root == nullptr) return total;

    std::queue<BSTNode<T>*> queue; 
    queue.push(root);

    while (!queue.empty()) {
        BSTNode<T>* current = queue.front();
        queue.pop();
        total += current->value;

        if (current->left != nullptr) queue.push(current->left);
        if (current->right != nullptr) queue.push(current->right);
    }

    return total;
}

template <typename T>
BSTNode<T>* RandomBinaryTree<T>::insert(BSTNode<T>* node, const T& item) {
    if (node == nullptr) {
        return new BSTNode<T>(item);
    }
    if (item < node->value) {
        node->left = insert(node->left, item);
    } else if (item > node->value) {
        node->right = insert(node->right, item);
    }
    return node;
}

template <typename T>
BSTNode<T>* RandomBinaryTree<T>::search(BSTNode<T>* node, const T& item) const {
    if (node == nullptr || node->value == item) {
        return node;
    }
    if (item < node->value) {
        return search(node->left, item);
    } else {
        return search(node->right, item);
    }
}


