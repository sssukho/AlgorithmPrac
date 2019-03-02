////균형 잡힌 이진 검색 트리 '트립' 구현/////
#include <iostream>
#include <utility>
using namespace std;

/************* 트립의 노드를 표현하는 객체의 구현 ****************/

typedef int KeyType;
//트립의 한 노드를 저장한다.
struct Node {
    //노드에 저장된 원소
    KeyType key;
    //이 노드의 우선순위(priority)
    //이 노드를 루트로 하는 서브트리의 크기(size)
    int priority, size;
    //두 자식 노드의 포인터
    Node *left, *right;
    //생성자에서 난수 우선순위를 생성하고, size와 left/right를 초기화한다.
    Node(const KeyType& _key) : key(_key), priority(rand()),
        size(1), left(NULL), right(NULL) {
        
    }
    
    void setLeft(Node* newLeft) {
        left = newLeft;
        calcSize();
    }
    
    void setRight(Node* newRight) {
        right = newRight;
        calcSize();
    }
    //size 멤버를 갱신한다.
    void calcSize() {
        size = 1;
        if(left)
            size = size + left->size;
        if(right)
            size = size + right->size;
    }
};

/************* 트립에서의 노드 추가와 트립 쪼개기 구현 ****************/

typedef pair<Node*, Node*> NodePair;
//root를 루트로 하는 트립을 key 미만의 값과 이상의 값을 갖는 두개의 트립으로 분리
NodePair split(Node* root, KeyType key) {
    if(root == NULL)
        return NodePair(NULL, NULL);
    //루트가 key 미만이면 오른쪽 서브트리를 쪼갠다.
    if(root->key < key) {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }
    //루트가 key 이상이면 왼쪽 서브트리를 쪼갠다.
    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}

//root를 루트로 하는 트립에 새 노드 node를 삽입한 뒤 결과 트립의 루트를 반환한다.
Node* insert(Node* root, Node* node) {
    if(root == NULL)
        return node;
    //node가 루트를 대체해야 한다. 해당 서브트리를 반으로 잘라 각각 자손으로 한다.
    if(root->priority < node->priority) {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    }
    else if(node->key < root->key)
        root->setLeft(insert(root->left, node));
    else
        root->setRight(insert(root->right, node));
    
    return root;
}

/************* 트립에서 노드의 삭제와 합치기 연산의 구현 ****************/

//a와 b가 두 개의 트립이고, max(a) < min(b)일 때 이 둘을 합친다.
Node* merge(Node* a, Node* b) {
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    if(a->priority < b->priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }
    a->setRight(merge(a->right, b));
    return a;
}

//root를 루트로 하는 트립에서 key를 지우고 그 결과 트립의 루트를 반환한다.
Node* erase(Node* root, KeyType key) {
    if(root == NULL)
        return root;
    //root를 지우고 양 서브트리를 합친 뒤 반환한다.
    if(root->key == key) {
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if(key < root->key)
        root->setLeft(erase(root->left, key));
    else
        root->setRight(erase(root->right, key));
    return root;
}
