//
//  프로그래머스_길찾기게임_level3.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/08/25.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node {
    int num;
    int x, y;
    node *left;
    node *right;
}node;

bool comp(node &a, node &b) {
    if(a.y == b.y) {
        return a.x < b.x;
    }
    return a.y > b.y;
}

// 뿌리 -> 왼쪽 자식 -> 오른쪽 자식
void preOrder(vector<int> &answer, node *n) {
    if(n == NULL)
        return;
    
    answer.push_back(n->num);
    preOrder(answer, n->left);
    preOrder(answer, n->right);
}

// 왼쪽자식 -> 오른쪽 자식 -> 뿌리
void postOrder(vector<int> &answer, node *n) {
    if(n == NULL)
        return;
    
    postOrder(answer, n->left);
    postOrder(answer, n->right);
    answer.push_back(n->num);
}

void addNode(node &parent, node &child) {
    if(child.x < parent.x) {
        if(parent.left == NULL) {
            parent.left = &child;
        }
        else {
            addNode(*parent.left, child);
        }
    }
    else {
        if(parent.right == NULL) {
            parent.right = &child;
        }
        else {
            addNode(*parent.right, child);
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    answer.resize(2); //vector[0][i] = preOrder, vector[1][i] = postOrder
    
    vector<node> n;
    
    for(int i = 0; i < nodeinfo.size(); i++) {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        n.push_back({i+1, x, y, NULL, NULL});
    }
    
    sort(n.begin(), n.end(), comp);
    for(int i = 1; i < nodeinfo.size(); i++) {
        addNode(n[0], n[i]);
    }
    
    preOrder(answer[0], &n[0]);
    postOrder(answer[1], &n[0]);
    
    return answer;
}
