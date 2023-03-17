#include <bits/stdc++.h>
#define el '\n'
using namespace std;
//--------------------------------------------------------------
class Vector {
private:
    int* arr { nullptr };
    int size { 0 };
    int capacity { 0 };
    void expand_capacity();

public:
    Vector(int sz);
    ~Vector();
    int get_size();
    int get_front();
    int get_back();
    int get(int idx);
    void set(int idx, int val);
    void print();
    int find(int val);
    void push_back(int val);
    void right_rot(int times);
};
void Vector::expand_capacity()
{
    capacity = capacity * 2;
    cout << "Expanding capacity to " << capacity << endl;
    int* new_arr = new int[capacity];
    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }
    swap(arr, new_arr);
    delete[] new_arr;
}
Vector::Vector(int sz)
    : size(sz)
{
    if (sz < 0)
        sz = 1;
    capacity = sz + 10;
    arr = new int[capacity];
}
Vector::~Vector()
{
    delete[] arr;
    arr = nullptr;
}
int Vector::get(int idx)
{
    assert(0 <= idx && idx < size);
    return arr[idx];
}

void Vector::set(int idx, int val)
{
    assert(0 <= idx && idx < size);
    arr[idx] = val;
}

void Vector::print()
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int Vector::find(int value)
{
    for (int i = 0; i < size; ++i)
        if (arr[i] == value)
            return i;
    return -1; // -1 for NOT found
}

int Vector::get_front()
{
    return arr[0];
}

int Vector::get_back()
{
    return arr[size - 1];
}

void Vector::push_back(int value)
{
    // we can't add any more
    if (size == capacity)
        expand_capacity();
    arr[size++] = value;
}
void Vector::right_rot(int times)
{
    int calc = times % size;
    if (calc == 0)
        return;
    int rem = size - calc;
    int* new_arr = new int[capacity];
    int k = 0;
    for (int i = rem; i < size; i++) {
        new_arr[k++] = arr[i];
    }
    for (int i = 0; i < rem; i++) {
        new_arr[k++] = arr[i];
    }
    swap(arr, new_arr);
    delete[] new_arr;
}
// right shift by x times
int main()
{
    int n = 5;
    Vector v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);
    v.print();
    v.right_rot(6);
    v.print();
}