## Observations

The README files of all parts contain extensive notes specific to that
part. This file contains non-trivial but commonly used techniques for
which are very generic.

- For rotating/cyclic arrays, it is sometimes useful to make a copy
of that array and join it at the end of the array. So, `[1, 2, 3]`
becomes `[1, 2, 3, 1, 2, 3]`. Then do whatever is asked, while keeping
a track of the length of the subsequence being considered (`<= 3`) if
necessary.

- Sorting / doing operations in lexicographic order can help when there's
a need to avoid repetions.