## Contents

This part contains problems on these topics:
- Greedy
- Heap
- Dynamic Programming


## Notes

### When to use DP?

1. When asked to count something, like the number of ways in which something can be done
1. Minimize or maximize a certain value
1. YES/NO questions: is it possible to ... ?

For `2.` and `3.`, it is often possible that the problem can be solved using a simpler **greedy** algorithm.

### Implementing DP

DP algorithms can be implemented both iteratively and recursively.
The iterative solution is generally more concise and faster (because of lesser overhead),
but the recursive solution is easier to implement/understand. Iterative solutions are also
easier to modify/improve, so prefer the **iterative method**.

But before implementing anything at all, one must come up with a recurrence relation, and to
do that one must define the state / what exactly store.
It is important to ask, at each `state`, the question:
```
When at a certain position / after some number of steps, what is important so far?
```

When the `state` is decided / defined, then think about how the state relates to
a smaller state, and try to write it as a combination of smaller states.
IOW, think about the question "how could I have gotten to this state?"
Often, drawing arrow diagrams helps in thinking about this.


### Complexity

When analysing the time complexity of the implementation, it is helpful to draw a tree
of the function calls for a recursive implementation.
