# BinarySearchTree

## Overview
This project implements a Binary Search Tree (BST) for integers using lazy deletion, following the CS 260 Binary Search Tree Lab specification. The tree supports insertion, search, lazy removal, recursive traversals, and two advanced operations: `findLarger` and `removeLarger`.

All functionality is implemented in the `Tree` class.

## Node Structure
Each node contains:

- `int value` — stored integer  
- `bool flag` — `true` if present, `false` if lazily deleted  
- `Node* leftc` — pointer to left child  
- `Node* rightc` — pointer to right child  

Lazy deletion preserves the tree structure while marking nodes as removed.

## Implemented Methods

### insertValue(int value)
- Inserts `value` following BST rules.  
- If the value exists but is marked deleted, it is reactivated.  
- If the value exists and is present, no action is taken.

void Tree::insertValue(int v){
    if(!root){
        Node* newNode = new Node;
        newNode->value = v;
        newNode->flag = true;
        newNode->leftc = nullptr;
        newNode->rightc = nullptr;

        root = newNode;
        return;
    }

    Node* curr = root;

    while(true){
        if(v == curr->value){
            curr->flag = true;
            return;
        }
        else if(v < curr->value){
            if(curr->leftc == nullptr){
                Node* newNode = new Node;
                newNode->value = v;
                newNode->flag = true;
                newNode->leftc = nullptr;
                newNode->rightc = nullptr;

                curr->leftc = newNode;
                return;
            }
            curr = curr->leftc;
        }
        else {
            if(curr->rightc == nullptr){
                Node* newNode = new Node;
                newNode->value = v;
                newNode->flag = true;
                newNode->leftc = nullptr;
                newNode->rightc = nullptr;

                curr->rightc = newNode;  
                return;
            }
            curr = curr->rightc;
        }
    }
}  

### findValue(int value) → bool
- Returns `true` if the node exists and is marked present.  
- Returns `false` otherwise.

### removeValue(int value) → bool
- Performs lazy deletion by setting `flag = false`.  
- Returns `true` if the value was present.  
- Returns `false` if the value does not exist or is already deleted.

### Traversal Methods
All traversal methods are implemented recursively.

- **preOrder()** — prefix traversal  
- **inOrder()** — infix traversal  
- **postOrder()** — postfix traversal  

Deleted nodes are suffixed with `D` (e.g., `30D`).

### Destructor
Recursively frees all nodes to prevent memory leaks.

## Advanced Methods

### findLarger(int value) → int
Returns the smallest present value that is **greater than or equal to** the input.

- If `value` exists and is present → returns `value`.  
- Otherwise → returns the next larger present value.  
- If no such value exists → returns `-1`.

### removeLarger(int value) → int
Removes and returns the same value that `findLarger(value)` would return.

- Calls `findLarger(value)` to determine the target.  
- If the result is `-1`, returns `-1`.  
- Otherwise marks the target node as deleted and returns it.

## Example Behavior

Given the tree:

10
/  \
6    14
/ \   / \
4  8 12 16


| Operation | Output |
|----------|---------|
| `findLarger(6)` | 6 |
| `findLarger(9)` | 10 |
| `findLarger(12)` | 12 |
| `findLarger(13)` | 14 |
| `findLarger(17)` | -1 |

## Assumptions
- Only positive integers are stored.  
- `-1` is used as the sentinel for “not found.”  
- Traversal output formatting matches the provided driver.

## Testing
The implementation was tested using the provided driver. Tests included:

- Inserting unique and duplicate values  
- Reviving deleted nodes  
- Searching for present and deleted values  
- Lazy deletion behavior  
- Recursive traversal correctness  
- Successor and successor-removal operations  
- Edge cases where no larger value exists  
