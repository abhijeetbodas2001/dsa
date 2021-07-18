## Pointers
```
// This is wrong! (will not allocate memory)
int *a = -1;

// Use this-
int *a = new int(-1);

// Or this-
int a = -1;    // and they use `&a` to get the pointer
```

```
// Incrementation

void increment(int* a) {
    // *a++; is wrong ❌

    *a = *a + 1;    // ✅✔

    // Use either the above, or `(*a)++`
}

int a = -1;
increment(&a);
```

## Misc
```
cout << INT_MAX;  // +2147483647
cout << INT_MIN;  // -2147483647
```

## Arrays
```
int a[3] = {1, 2, 3};       // [1, 2, 3]

int b[] = {1, 2, 3, 4}      // [1, 2, 3, 4]

int c[6] = {1, 2, 3, 4}     // [1, 2, 3, 4, 0, 0]

int d[3];                   // [garbage, garbage, garbage]

// Name of the array is also a pointer to the first element of array.
```

## Vectors

```
vector<int> v1{ 3, 2, 4 };      // [3, 2, 4]
vector<int> v2(4, 7);          // [7, 7, 7, 7]

v1.size();      // 3

sort(v1.begin(), v1.end());     // v1 becomes [2, 3, 4]

reverse(v1.begin(), v1.end());  // v1 gets reversed in-place
```

## Strings

```
string s = "abcd";

s.length();  // 4
```

## Queue

```
queue<int> q;

q.push(1);
q.push(2);
q.push(3);

q.size();     // 3
q.empty();    // false

q.front();    // returnd 1, does not delete it
q.pop();      // deletes 1, does not return it

q.back();     // 3 (last in)
```

## Stack

```
stack<int> s;

s.push(1);
s.push(2);
s.push(3);

s.size();   // 3
s.empty();  // false

s.top();    // returns 3, does not delete it
s.pop();    // deletes 3, does not return it
```

## Sets

```
unordered_set<int> s;

// All following operations are O(1) on average

s.insert(1);

s.find(1)       // != s.end()

s.erase(1);     // deletes `1` from the set

s.find(1);      // s.end()
```

## Maps

```
unordered_map<string, int> m;

m["key"] = 101

// `find` is same as that of set structure

// Traversing an unordered map
for (auto x : m) {
    cout << x.first << " " << x.second << endl;     // key <space> 101
}
```
