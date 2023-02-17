#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using namespace std;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if(tree.size()==0){
    return true;
  }
  stack<Node> next;
  next.push(tree[0]);
  int aux=tree[0].left;
  int parent=tree[0].key;
  while(aux!=-1){
    if(tree[aux].key>=parent){
      return false;
    }
    next.push(tree[aux]);
    aux=tree[aux].left;
  }
  aux=INT_MIN;
  while(next.size()){
    auto current=next.top();
    next.pop();
    if(current.key<aux){
      return false;
    }
    aux=current.key;
    if(current.right!=-1){
      next.push(tree[current.right]);
      current=tree[current.right];
      parent=current.key;
      while(current.left!=-1){
        next.push(tree[current.left]);
        current=tree[current.left];
        if(current.key>=parent){
          return false;
        }
      }
    }

  }
  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
