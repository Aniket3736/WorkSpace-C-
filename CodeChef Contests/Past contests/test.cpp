#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* maxm = new TreeNode<int>(INT_MIN),*smaxm = new TreeNode<int>(INT_MIN);

void getSecond(TreeNode<int>* root){
    for(int i = 0; i<root -> children.size(); i++){
        getSecond(root -> children[i]);
    }
    if(root -> data > maxm -> data){
        smaxm = maxm;
        maxm = root;
    }
    else if(root -> data > smaxm -> data && smaxm -> data != maxm -> data){
        smaxm = root;
    }
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(!root)
        return root;
    maxm -> data = INT_MIN;
    smaxm -> data = INT_MIN;
    getSecond(root);
    return smaxm;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }
    return 0;
}