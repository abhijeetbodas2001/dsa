#include<bits/stdc++.h>
#include <utility>
using namespace std;

// Incrementation
void increment(int *c) {
    // *c++; is wrong!
    *c = *c + 1;    // correct
    // Use either the above, or `(*c)++`
}


int main() {
    // This is wrong! (will not allocate memory)
    // int *a = -1;

    // Use this-
    int *a = new int(-1);

    // Or this-
    int b = -1;    // and they use `&b` to get the pointer

    // Call the increment function like this:
    int c = -1;
    increment(&c);

    cout << INT_MAX << endl;  // +2147483647
    cout << INT_MIN << endl;  // -2147483647

    int p[3] = { 1, 2, 3 };       // [1, 2, 3]
    int q[] = { 1, 2, 3, 4 };      // [1, 2, 3, 4]
    int r[6] = { 1, 2, 3, 4 };     // [1, 2, 3, 4, 0, 0]
    int s[3];                   // [garbage, garbage, garbage]
    // Name of the array is also a pointer to the first element of array.


    // Vectors
    vector<int> v1{ 3, 2, 4 };      // [3, 2, 4]
    vector<int> v2(4, 7);          // [7, 7, 7, 7]
    v1.size();      // 3
    sort(v1.begin(), v1.end());     // v1 becomes [2, 3, 4]
    reverse(v1.begin(), v1.end());  // v1 gets reversed in-place
    // about resize
    vector<int> v;
    v.resize(3, 4); // [4, 4, 4]
    v.resize(3, 5); // Will not do anything! (because size already is 3)
    // don't use resize to set all values to somevalue

    // Strings
    string str = "abcd";
    str.length();  // 4

    queue<int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.size();     // 3
    qu.empty();    // false
    qu.front();    // returns 1, does not delete it
    qu.pop();      // deletes 1, does not return it
    qu.back();     // 3 (last in)

    // Stacks
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.size();   // 3
    st.empty();  // false
    st.top();    // returns 3, does not delete it
    st.pop();    // deletes 3, does not return it

    // Sets
    unordered_set<int> se;
    // All following operations are O(1) on average
    se.insert(1);
    se.find(1);       // != s.end()
    se.erase(1);     // deletes `1` from the set
    se.find(1);      // s.end()

    // Maps
    unordered_map<string, int> m;
    m["key"] = 101;
    // `find` is same as that of set structure
    // Traversing an unordered map
    for (auto& x : m) {
        cout << x.first << " " << x.second << endl;     // key <space> 101
        x.second = 3;   // iterating over references means updating inside loop is OK
    }

    return 0;
}
