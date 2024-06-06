## Contents

This part contains problems on these topics:
- Arrays
- Binary search
- Sorting
- Bit manipulation


## Notes

- Check carefully if the questions asks for the "index" or the "number"/"element"

- Binary search
	- Whether the number given is present in the array or not, in a vanilla B.S, the `mid`
will always end up in the element in the array which is closest to the given number.
	- Write vanilla B.S first. Look at what are the constraints on `mid`, and then handle
them inside/outside the loop. Use `while (true)` when the answer is definitely present
or is  guaranteed by the problem.

- To check if a number is power of 2 quickly:
	```
	bool ispowerof2(int n){
		return (n & (n-1)) == 0;
	}
	```
