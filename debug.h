#include <bits/stdc++.h>
#define el '\n'
// #define int long long
using namespace std;
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char* x) { cout << '\"' << x << '\"'; }
void __print(const string& x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V>& x)
{
    cout << '{';
    __print(x.first);
    cout << ',';
    __print(x.second);
    cout << '}';
}
template <typename T>
void __print(const T& x)
{
    int f = 0;
    cout << '{';
    for (auto& i : x)
        cout << (f++ ? "," : ""), __print(i);
    cout << "}";
}
void _print() { cout << "]" << endl; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cout << ", ";
    _print(v...);
}
#define deb(x...)         \
    cout << #x << " = ["; \
    _print(x)
template <typename T, typename T1>
T amax(T& a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

// map
template <typename T, typename T1>
void deb_map(map<T, T1> mp)
{
    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }
}
// 2d vector
template <typename T>
void deb_2d_vector(vector<vector<T>> v)
{
    for (auto it : v) {
        print_vector(it);
    }
}
// pair
template <typename T, typename T1>
void deb_pair(pair<T, T1> p)
{
    cout << p.first << " " << p.second << endl;
}
// array
template <typename T>
void deb_array(T arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// 2d array
template <typename T>
void deb_2d_array(T arr[][100], int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
// queue
template <typename T>
void deb_queue(queue<T> q)
{
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
// stack
template <typename T>
void deb_stack(stack<T> s)
{
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
// graph
template <typename T>
void deb_graph(vector<vector<T>> g)
{
    for (int i = 0; i < g.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
// dfs graph traversal
template <typename T>
void deb_dfs(vector<vector<T>> g, int s, vector<bool>& vis)
{
    vis[s] = true;
    cout << s << " ";
    for (auto it : g[s]) {
        if (!vis[it]) {
            deb_dfs(g, it, vis);
        }
    }
}
// bfs graph traversal
template <typename T>
void deb_bfs(vector<vector<T>> g, queue<int> q, vector<bool>& vis)
{
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        vis[s] = true;
        cout << s << " ";
        for (auto it : g[s]) {
            if (!vis[it]) {
                q.push(it);
            }
        }
    }
}
// print multiset
template <typename T>
void deb_multiset(multiset<T> s)
{
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
}
// print deque
template <typename T>
void deb_deque(deque<T> s)
{
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
}