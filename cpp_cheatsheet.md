## Pointers
```
// This is wrong! (will not allocate memory)
int *my_var = -1;

// Use this-
int *my_var = new int(-1);

// Or this-
int my_var = -1;    // and they use `&my_var` to get the pointer

// Incrementation
int count = -1;
void increment(int* count) {
    // *count++; is wrong ❌
    *count = *count + 1;    // ✅✔
    // Use either the abover, or `(*count)++`
}

increment(&count);
```

## Misc
```
cout<<INT_MAX;  // +2147483647
cout<<INT_MIN;  // -2147483647
```

## Arrays
```
int myArray[3] = {1, 2, 3}; // [1, 2, 3]

int myArray[] = {1, 2, 3, 4}    // [1, 2, 3, 4]

int myArray[6] = {1, 2, 3, 4}   // [1, 2, 3, 4, 0, 0]

int myArray[3]; // [garbage, garbage, garbage]

// Name of the array is also a pointer to the first element of array.
```

## Vectors

```
// Initialization
vector<int> myVector1{ 10, 20, 30 };    // [10, 20, 30]
vector<int> myVector2(3, 11);           // [11, 11, 11]

myVector.size();
```

## Strings

```
string myString = "abcd";

myString.length();  // 4
```

## Queue

```
queue<int> myQueue;

myQueue.empty();

myQueue.size();

myQueue.front();    // Reference to first element
myQueue.back();     // Reference to last element

myQueue.push(2);    // Adds element to end of queue
myQueue.pop();      // Deletes first element of queue and DOES NOT RETURN IT
```

## Stack

```
stack<int> myStack;

myStack.push(21);

myStack.size();     // 1

myStack.top();    // 21

myStack.pop();    // Does not return the popped element!
```

## Sets

```
unordered_set<int> mySet;   // Initialization

// All following operations are O(1) on average

mySet.insert(1)

if (mySet.find(key) == mySet.end()) {
    // `key` is present in set
} else {
    // `key` is not present in set
}

mySet.erase(1);     // deletes `1` from the set
```

## Maps

```
unordered_map<string, int> myMap;

myMap["some_key"] = 101

// `find` is same as that of set structure

// Traversing an unordered map
for (auto x : myMap) {
    cout << x.first << " " << x.second << endl;
}
```
