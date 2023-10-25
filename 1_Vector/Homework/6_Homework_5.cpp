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
    int find_transposition(int value);
    void left_shift(int times);
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
Vector::Vector(int sz = 0)
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
void Vector::left_shift(int times)
{
    int calc = times % size;
    if (calc == 0)
        return;
    int rem = size - calc;
    int* new_arr = new int[capacity];
    int k = 0;
    for (int i = calc; i < size; i++) {
        new_arr[k++] = arr[i];
    }
    for (int i = 0; i <= calc - 1; i++) {
        new_arr[k++] = arr[i];
    }
    swap(arr, new_arr);
    delete[] new_arr;
}
int Vector::find_transposition(int value)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            if (i == 0)
                return 0;
            else {
                swap(arr[i], arr[i - 1]);
                return i - 1;
            }
        }
    }
    return -1;
}
int main()
{
    Vector v;
    int n = 5;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }
    v.print();
    int pos = v.find_transposition(3);
    cout << "pos : " << pos << el;
    v.print();
}