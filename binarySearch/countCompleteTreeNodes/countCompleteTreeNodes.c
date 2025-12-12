#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode Node;

int exists(Node *root, int index, int h) {
  int low = 1;
  int high = h > 0 ? 1 << (h - 1) : 0;
  int mid;

  for (int i = 0; i < (h - 1); i++) {
    mid = low + (high - low) / 2;
    if (index <= mid) {
      root = root->left;
      high = mid;
    } else {
      root = root->right;
      low = mid + 1;
    }
  }

  return root != NULL;
}

int countNodes(struct TreeNode *root) {
  int h = 0;
  Node *n = root;

  while (n != NULL) {
    h++;
    n = n->left;
  }

  // Partial result, now has the number of nodes not in the last level
  int result = h > 0 ? (1 << (h - 1)) - 1 : 0;

  // The nodes in the last level can be indexed from 1 to 2^h
  int low = 1;
  int high = h > 0 ? 1 << (h - 1) : 0;
  int mid;

  while (low <= high) {
    mid = low + (high - low) / 2;
    if (exists(root, mid, h)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return result + high;
}

// Small helper to create a node
static Node* new_node(int v) {
  Node* p = (Node*)malloc(sizeof(Node));
  if (!p) return NULL;
  p->val = v;
  p->left = p->right = NULL;
  return p;
}

int main(void) {
  Node* nodes[7];
  for (int i = 1; i <= 6; i++) nodes[i] = new_node(i);

  Node* root = nodes[1];
  root->left = nodes[2];
  root->right = nodes[3];

  nodes[2]->left = nodes[4];
  nodes[2]->right = nodes[5];

  nodes[3]->left = nodes[6];
  nodes[3]->right = NULL;

  printf("Constructed tree with 6 nodes. Calling countNodes()...\n");
  int cnt = countNodes(root);
  printf("Result: countNodes = %d\n", cnt);

  // free nodes
  for (int i = 1; i <= 6; i++) free(nodes[i]);
  return 0;
}