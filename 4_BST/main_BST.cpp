#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#include "../debug.h"
#else
#define deb(x...)
#endif
using namespace std;

class BinarySearchTree {
private:
    int value {};
    BinarySearchTree* left {};
    BinarySearchTree* right {};

public:
    BinarySearchTree(int v, BinarySearchTree* l = nullptr, BinarySearchTree* r = nullptr)
        : value(v)
        , left(l)
        , right(r)
    {
    }

    void get_inorder(vector<int>& values)
    {
        if (left)
            left->get_inorder(values);
        values.push_back(value);
        if (right)
            right->get_inorder(values);
    }
    void insert(int target)
    {
        if (target < value) {
            if (!left) {
                left = new BinarySearchTree(target);
            } else
                left->insert(target);
        } else if (target > value) {
            if (!right)
                right = new BinarySearchTree(target);
            else
                right->insert(target);
        } // else: exists already
    }
    bool is_bst1(int mn = INT_MIN, int mx = INT_MAX)
    {
        bool status = mn < value && value < mx;

        if (!status)
            return false;

        bool left_bst = !left || left->is_bst1(mn, value);

        if (!left_bst)
            return false;

        bool right_bst = !right || right->is_bst1(value, mx);
        return right_bst;
    }

    bool is_bst2()
    {
        vector<int> values;
        get_inorder(values);

        for (int i = 1; i < (int)values.size(); ++i) {
            if (values[i] < values[i - 1])
                return false;
        }
        return true;
    }

    bool search(int target)
    {
        if (target == value)
            return true;

        if (target < value) {
            if (left)
                return left->search(target);
            else
                return false;
        } else {
            if (right)
                return right->search(target);
            else
                return false;
        }
    }

    BinarySearchTree* build_bst_sorted_arr(vector<int>& values, int st, int end)
    {
        if (st > end)
            return nullptr;
        int mid = st + (end - st) / 2;
        BinarySearchTree* root = new BinarySearchTree(values[mid]);
        root->left = build_bst_sorted_arr(values, st, mid - 1);
        root->right = build_bst_sorted_arr(values, mid + 1, end);
        return root;
    }

    void displayInorder()
    {
        if (left)
            left->displayInorder();
        cout << value << " ";
        if (right)
            right->displayInorder();
    }

    void printBFS()
    {
        queue<pair<BinarySearchTree*, int>> q;
        q.push({ this, 0 });
        int currLevel = 0;
        while (!q.empty()) {
            BinarySearchTree* curr = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level > currLevel) {
                cout << "\n";
                currLevel = level;
            }
            cout << curr->value << " ";
            if (curr->left)
                q.push({ curr->left, level + 1 });
            if (curr->right)
                q.push({ curr->right, level + 1 });
        }
    }
    int kth_smallest(int k)
    {
        stack<BinarySearchTree*> s;
        BinarySearchTree* curr = this;
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if (--k == 0)
                return curr->value;
            curr = curr->right;
        }
        return -1;
    }
};

int main()
{
    BinarySearchTree* bst = new BinarySearchTree(5);
    bst->insert(4);
    bst->insert(6);
    bst->insert(3);
    bst->insert(7);

    cout << bst->is_bst1() << "\n";
    cout << bst->is_bst2() << "\n";

    int k = 3;
    cout << bst->kth_smallest(k) << "\n";

    vector<int> values = { 1, 2, 3, 4, 5, 6, 7 };
    BinarySearchTree* bst2 = bst->build_bst_sorted_arr(values, 0, values.size() - 1);
    bst2->displayInorder();
    cout << "\n";
    deb(bst2->kth_smallest(1)); // 1
    deb(bst2->kth_smallest(10)); // -1

    return 0;
}