## Sets

- `unordered_set<int> mySet;`
    - All operations are `O(1)` on average
    - `mySet.insert(1)`
    - `mySet.find(key)` returns `mySet.end()` if `key` is not in `mySet`

## Maps

- `unordered_map<string, int> myMap;`
    - `myMap["some_key"] = 101`
    - `myMap.find(my_key)` returns `myMap.end()` if it doesn't have `my_key` as a key
    - Traversing an unordered map
        ```
            for (auto x : myMap) {
                cout << x.first << " " << x.second << endl;
            }
        ```

## String

- `str.length()`