#include <iostream>

using namespace std;

class Node {
public:
  int data;
  int height;
  Node *left;
  Node *right;

  Node() {
    data = 0;
    height = 0;
    left = nullptr;
    right = nullptr;
  }
  Node(int val) {
    data = val;
    height = 0;
    left = nullptr;
    right = nullptr;
  }
};

// Function Declarations
int ComputeHeight(Node *n);
int ComputeBF(Node *n);
void Rebalance(Node *n);
void AdjustHeight(Node *n);
void RebalanceRight(Node *n);
void RebalanceLeft(Node *n);
Node *LeftDescendant(Node *n);
Node *RightAncestor(Node *n);
bool isUnbalanced(Node *n);
bool hasOnlyLeftChild(Node *n);
bool hasOnlyRightChild(Node *n);
Node *next(Node *root, int val);
Node *rotateLeft(Node *root);
Node *avlDelete(Node *node, int val);
int balanceFactor(Node *n);
Node *search(Node *root, int val);
Node *rotateRight(Node *root);
Node *AVLInsert(Node *node, int val);
bool find(Node *root, int val);
void searchRange(Node *root, int valx, int valy, bool printorsum);
void preorder(Node *node);
void inorder(Node *node);
void postorder(Node *node);
int isLeaf(Node *node);
Node *parent(Node *root, Node *node);
int minVal(Node *node);
int maxVal(Node *node);
int add(Node *root);
Node *deleteNode(Node *node);
Node *avlInsertA(Node *root, Node *tempNode);
int menu();

// Function Definitions
int ComputeHeight(Node *n) {
  if (n == nullptr) {
    return -1;
  }
  return 1 + max(ComputeHeight(n->left), ComputeHeight(n->right));
}

int ComputeBF(Node *n) {
  if (n == nullptr) {
    return 0;
  }
  return ComputeHeight(n->left) - ComputeHeight(n->right);
}

void Rebalance(Node *n) {
  AdjustHeight(n);
  int bf = ComputeBF(n);
  if (bf == -2) {
    RebalanceRight(n);
  } else if (bf == 2) {
    RebalanceLeft(n);
  }
}

void AdjustHeight(Node *n) {
  if (n == nullptr) {
    return;
  }
  n->height = ComputeHeight(n);
  AdjustHeight(n->left);
  AdjustHeight(n->right);
}

void RebalanceRight(Node *n) {
  if (ComputeBF(n->right) > 0) {
    RebalanceLeft(n->right);
  }
  Node *newroot = rotateRight(n);
  Rebalance(newroot);
}

void RebalanceLeft(Node *n) {
  if (ComputeBF(n->left) < 0) {
    RebalanceRight(n->left);
  }
  Node *newroot = rotateLeft(n);
  Rebalance(newroot);
}

Node *LeftDescendant(Node *n) {
  Node *current = n;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}

Node *RightAncestor(Node *n) {
  Node *current = n;
  while (current->data < n->data) {
    current = parent(nullptr, current);
  }
  return current;
}

bool isUnbalanced(Node *n) {
  if (n == nullptr) {
    return false;
  }
  int bf = balanceFactor(n);
  if (bf > 1 || bf < -1) {
    return true;
  }
  return false;
}

int balanceFactor(Node *n) {
  if (n == nullptr) {
    return 0;
  }
  return ComputeHeight(n->left) - ComputeHeight(n->right);
}

Node *AVLInsert(Node *node, int val) {
  if (node == nullptr) {
    return new Node(val);
  }
  if (val < node->data) {
    node->left = AVLInsert(node->left, val);
  } else if (val > node->data) {
    node->right = AVLInsert(node->right, val);
  }
  AdjustHeight(node);
  Rebalance(node);
  return node;
}

bool hasOnlyLeftChild(Node *n) {
  if (n->left != nullptr && n->right == nullptr) {
    return true;
  }
  return false;
}

bool hasOnlyRightChild(Node *n) {
  if (n->left == nullptr && n->right != nullptr) {
    return true;
  }
  return false;
}

Node *search(Node *root, int val) {
  if (root == nullptr || root->data == val) {
    return root;
  }
  if (root->data < val) {
    return search(root->right, val);
  }
  return search(root->left, val);
}

Node *rotateLeft(Node *root) {
  Node *tmp = root->right;
  root->right = tmp->left;
  tmp->left = root;
  AdjustHeight(root);
  AdjustHeight(tmp);
  return tmp;
}

Node *avlDelete(Node *node, int val) {
  if (node == nullptr) {
    return nullptr;
  } else if (val < node->data) {
    node->left = avlDelete(node->left, val);
  } else if (val > node->data) {
    node->right = avlDelete(node->right, val);
  } else {
    if (node->left == nullptr && node->right == nullptr) { // Case 1: No child.
      delete node;
      node = nullptr;
    } else if (node->left == nullptr &&
               node->right !=
                   nullptr) { // Case 2: One child & it is the right child.
      Node *temp = node;
      node = node->right;
      delete temp;
    } else if (node->left != nullptr &&
               node->right ==
                   nullptr) { // Case 2: One child & it is the left child.
      Node *temp = node;
      node = node->left;
      delete temp;
    } else { // Case 3: Two children.
      int value;
      if (node->left->height >
          node->right->height) { // Choosing to remove from the left subtree.
        value = maxVal(node->left);
        node->data = value;
        node->left = avlDelete(node->left, value);
      } else { // Choosing to remove from the right subtree.
        value = minVal(node->right);
        node->data = value;
        node->right = avlDelete(node->right, value);
      }
    }
    AdjustHeight(node);
    Rebalance(node);
  }
  return node;
}

Node *rotateRight(Node *root) {
  Node *newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  AdjustHeight(root);
  AdjustHeight(newRoot);
  return newRoot;
}

bool find(Node *root, int val) {
  if (root == nullptr) {
    return false;
  }
  if (root->data == val) {
    return true;
  } else if (val < root->data) {
    return find(root->left, val);
  } else {
    return find(root->right, val);
  }
}

void searchRange(Node *root, int valx, int valy, bool printorsum) {
  Node *temp = search(root, valx);
  if (temp == NULL) { // If node is not in the tree finding the next element.
    temp = next(root, valx);
  }
  int range = valy - valx, arr[range], count = 0;
  while (temp != NULL && temp->data <= valy) { // Filling the array.
    arr[count] = temp->data;
    count++;
    temp = next(root, temp->data);
    if (temp == NULL) { // If there is nothing else to put into the array.
      break;
    }
  }
  if (printorsum) { // Printing the array of elements.
    if (count == 0) {
      cout << "There are no elements between the rage of " << valx << " & "
           << valy << endl;
    } else {
      for (int i = 0; i < count; i++) {
        if (i + 1 < count) {
          cout << arr[i] << ", ";
        } else {
          cout << arr[i] << endl;
        }
      }
    }
  } else { // Printing the sum of all elements in the array.
    int sum = 0;
    for (int i = 0; i < count; i++) {
      sum += arr[i];
    }
    cout << "The sum is: " << sum << endl;
  }
  cout << endl;
}

void preorder(Node *node) {
  if (node == nullptr) {
    return;
  }
  cout << node->data << " ";
  preorder(node->left);
  preorder(node->right);
}

void inorder(Node *node) {
  if (node == nullptr) {
    return;
  }
  inorder(node->left);
  cout << node->data << " ";
  inorder(node->right);
}

void postorder(Node *node) {
  if (node == nullptr) {
    return;
  }
  postorder(node->left);
  postorder(node->right);
  cout << node->data << " ";
}

int isLeaf(Node *node) {
  return (node->left == nullptr && node->right == nullptr);
}

Node *parent(Node *root, Node *node) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->left == node || root->right == node) {
    return root;
  }
  if (node->data < root->data) {
    return parent(root->left, node);
  } else {
    return parent(root->right, node);
  }
}

int minVal(Node *node) {
  Node *current = node;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current->data;
}

int maxVal(Node *node) {
  Node *current = node;
  while (current->right != nullptr) {
    current = current->right;
  }
  return current->data;
}

int add(Node *root) {
  if (root == nullptr) {
    return 0;
  }
  return root->data + add(root->left) + add(root->right);
}

Node *next(Node *root, int val) {
  // Creating a temp node to change until get we want.
  Node *temp = search(root, val);
  Node *highestnumber = root;
  if (temp == NULL) { // If the node does not exist in the tree.
    while (highestnumber->right != NULL) {
      highestnumber = highestnumber->right;
    }
    while (temp == NULL) { // Runs unitl we find an element that does exist.
      val++;
      temp = search(root, val);
      if (val > highestnumber->data) {
        break;
        return NULL;
      }
    }
    return temp; // returng the node we found.
  }
  if (temp->right != NULL) { // If the right child exist.
    temp = temp->right;
    while (temp->left != NULL) { // If the right child has a left child.
      temp = temp->left;
    }
    return temp;                           // Returning the node we found.
  } else if (parent(root, temp) != NULL) { // If right child doesn't exitst.
    Node *temp2 = parent(root, temp);
    while (temp2 != NULL) { // If the left childe has a right child.
      if (temp2->data < temp->data) {
        temp2 = parent(root, temp2);
      } else {
        break;
      }
    }
    return temp2; // Returning the node we found.
  } else {
    return NULL; // Returning NULL becuause their is no next element.
  }
}

Node *deleteNode(Node *node) {
  int size;
  cout << "How many items would you like to delete: ";
  cin >> size;
  int *list = new int[size];
  cout << "The list of items now please:" << endl;
  for (int i = 0; i < size; i++) {
    cin >> list[i];
  }
  for (int i = 0; i < size; i++) {
    node = avlDelete(node, list[i]);
  }
  cout << "List has been deleted from the tree." << endl;
  delete[] list;
  return node;
}

Node *avlInsertA(Node *root, Node *tempNode) {
  if (root == nullptr) {
    return tempNode;
  }
  if (tempNode->data < root->data) {
    root->left = avlInsertA(root->left, tempNode);
  } else if (tempNode->data > root->data) {
    root->right = avlInsertA(root->right, tempNode);
  } else {
    return root;
  }
  root->height = 1 + max(ComputeHeight(root->left), ComputeHeight(root->right));
  int balanceFactor = ComputeBF(root);
  if (balanceFactor > 1 && tempNode->data < root->left->data) {
    return rotateRight(root);
  }
  if (balanceFactor < -1 && tempNode->data > root->right->data) {
    return rotateLeft(root);
  }
  if (balanceFactor > 1 && tempNode->data > root->left->data) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
  }
  if (balanceFactor < -1 && tempNode->data < root->right->data) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
  }
  return root;
}

int menu(bool OfforOn) {
  int ans;
  if (OfforOn == false) {
    cout << "Here are your choices.\n";
    cout << "1. Insert an item into your tree.\n";
    cout << "2. Delete an item from your tree.\n";
    cout << "3. Search for an item in your tree.\n";
    cout << "4. Print the sum of the nodes. \n";
    cout << "5. Print the next element of the node with key x.\n";
    cout << "6. Find elements between x and y:  \n";
    cout << "7. Find the height of the tree: \n";
    cout << "8. Print the sum of the list of elements between x and y: \n";
    cout << "9 Print out an inorder traversal: \n";
    cout << "10. Exit.\n";
  }
  cin >> ans;
  cout << endl;
  return ans;
}
int main() {
  Node *myRoot = NULL;
  Node *tempNode;
  int ans = 0, val = 0, valx = 0, valy = 0;
  bool toggle = false;
  while (1) {
    ans = menu(toggle);
    if (ans == 1) {
      // Get value to insert.
      cout << "What value would you like to insert: ";
      cin >> val;
      cout << endl;
      tempNode = new Node(val); // Create the node.
      myRoot = avlInsertA(myRoot, tempNode);
    } else if (ans == 2) {
      cout << "What value would you like to delete: ";
      cin >> val;
      if (myRoot == NULL) {
        cout << "Sorry that value isn't in the tree to delete.\n";
      } else {
        myRoot = avlDelete(myRoot, val);
        cout << "The new root is: ";
        inorder(myRoot);
        cout << endl;
      }
    } else if (ans == 3) {
      cout << "What value would you like to search for: ";
      cin >> val;
      cout << endl;
      if (find(myRoot, val)) {
        cout << "Found " << val << " in the tree.\n";
      } else {
        cout << "Did not find " << val << " in the tree.\n";
      }
    } else if (ans == 4) {
      if (myRoot == NULL) {
        cout << "The tree is empty." << endl;
      } else {
        cout << "The sum of the nodes in your tree is " << add(myRoot) << "\n";
      }
    } else if (ans == 5) {
      cout << "Which element do you wish to find the next node in the tree? \n";
      cin >> val;
      cout << endl;
      if (myRoot == NULL) {
        cout << "The tree is empty." << endl;
      } else {
        tempNode = next(myRoot, val);
        if (tempNode != NULL) {
          cout << "The next element is: " << tempNode->data << endl;
        } else {
          cout << "There is no next element in the tree." << endl;
        }
      }
    } else if (ans == 6) {
      cout << "Please enter x value: ";
      cin >> valx;
      cout << "Please enter y value: ";
      cin >> valy;
      cout << endl;
      if (myRoot == NULL) {
        cout << "The tree is empty." << endl;
      } else if (valx < valy) {
        searchRange(myRoot, valx, valy, true);
      } else {
        searchRange(myRoot, valy, valx, true);
      }
    } else if (ans == 7) {
      cout << "What element's height would you like to know: " << endl;
      cin >> val;
      cout << endl;
      tempNode = search(myRoot, val);
      if (tempNode != NULL) {
        cout << "The height of root " << val << " is: " << tempNode->height
             << endl;
      } else {
        cout << "The root does not exist so the height is 0." << endl;
      }
    } else if (ans == 8) {
      cout << "Please enter x value: ";
      cin >> valx;
      cout << "Please enter y value: ";
      cin >> valy;
      cout << endl;
      if (myRoot == NULL) {
        cout << "The tree is empty." << endl;
      } else if (valx < valy) {
        cout << "Elements in the range [" << valx << ", " << valy << "]: ";
        searchRange(myRoot, valx, valy, false);
        cout << endl;
      } else {
        searchRange(myRoot, valy, valx, false);
        cout << endl;
      }
    } else if (ans == 9) {
      // Print the resulting tree.
      cout << "Which order would you like to traverse the tree: " << endl;
      cout << "1. preorder(VLR)" << endl
           << "2. inorder(LVR)" << endl
           << "3. postorder(LRV)" << endl;
      cin >> val;
      cout << endl;
      if (myRoot == NULL) { // If there is nothing in the tree.
        cout << "The tree is empty." << endl;
      } else if (val == 1) { // Displays the tree in preorder.
        cout << "Preorder: ";
        preorder(myRoot);
        cout << endl;
      } else if (val == 2) { // Displays the tree in inorder.
        cout << "Inorder: ";
        inorder(myRoot);
        cout << endl;
      } else if (val == 3) { // Displays the tree in postorder.
        cout << "Postorder: ";
        postorder(myRoot);
        cout << endl;
      } else { // If they did not put in an actual option.
        cout << "I'm sorry but that was not an option." << endl;
      }
    } else if (ans == 10) {
      exit(0);
    } else if (ans > 10 || ans < 0) {
      cout << "That is not a valid choice, please try again. " << endl;
    }
  }
  return 0;
}
