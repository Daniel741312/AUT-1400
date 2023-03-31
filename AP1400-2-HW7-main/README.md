# Advanced Programming - HW7
<p  align="center"> <b>Homework 7 - Spring 2022 Semester <br> Deadline: Frifay khordad 27th - 11:59 pm</b> </p>

## Outline
In this homework, we are going to warm up with matplotlib and comprehension lists in python.

***Note.*** use python3 for the entire hw7.

</br>
</br>

# Oneline functions
Implement the following functions in the `src/oneline_funcs.py` file and note that your functions should only have one line including return - something like this:

```py
def myfunc():
	return ...
```
</br>

- **adjacentElementsProduct**
	
	Find the adjacent elements that have the largest product in a given array of ints and return that product.
	```py
	def adjacentElementsProduct(inputArray)
	```
	For example, the output for  [3, 6, -2, -5, 7, 3] is 21.

</br>

- **allLongestStrings**
	
	Find the longest strings in an array of strings.
	```py
	def allLongestStrings(inputArray)
	```
	For example, the output for  ["aba", "aa", "ad", "vcd", "aba"] is ["aba", "vcd", "aba"].

</br>

- **checkPalindrome**

	Palindrome is a string that doesn't change when reversed i.e. it reads the same backward and forward.

	Given the string, check if it is a palindrome.
	```py
	def checkPalindrome(inputString)
	```
	For example, the output for  `aabaa` is True.

</br>

- **commonCharacterCount**
	
	Given two strings, find the number of common characters between them.
	```py
	def commonCharacterCount(s1, s2)
	```
	For example, the output for `aabcc` and `adcaa` is 3.

</br>

- **areSimilar**
	
	Two arrays are similar if one can be obtained from another by swapping at `most` one pair of elements in one of the arrays.Given two arrays a and b, check whether they are similar.
	```py
	def areSimilar(A, B)
	```
	For example, the output for [1, 2, 3] and [2, 1, 3] is true.

</br>

- **palindromeRearranging**
	
	find out if a string can be rearranged to form a palindrome string.
	```py
	def palindromeRearranging(inputString)
	```
	For example, the output for `aabb` is true (because it can be rearranged to `abba`).


</br>

- **arrayReplace**
	
	Given an array of integers, replace all the occurrences of `elemToReplace` with `substitutionElem`.
	```py
	def arrayReplace(inputArray, elemToReplace, substitutionElem)
	```
	For example, the output for [1, 2, 1] with `elemToReplace=1` and `substitutionElem=3` is [3, 2, 3].

</br>

- **evenDigitsOnly**
	
	Check if all digits of an integer are even.
	```py
	def evenDigitsOnly(n)
	```
	For example, the output for 248622 is true.

</br>

- **alphabeticShift**
	
	replace each of the characters of a string by the next character in the English alphabet (replace `a` with `b`, `b` with `c`, ..., and `z` with `a`)
	```py
	def alphabeticShift(inputString)
	```
	For example, the output for `crazy` is `dsbaz`.

</br>

- **firstDigit**
	
	Find the first digit that appears in a string.
	```py
	def firstDigit(inputString)
	```
	For example, the output for `var_1__Int` is 1.

</br>
</br>

# Matplotlib
Using the image in `resources/image.jpg` implement the following plot using matplotlib in `src/daemon_figure.py` and show the figure at the end.
(see `resources/image.gif` if *following plot* is not loading)


<br>
<p align="center">
<img src="resources/image.gif" alt="minor"
title="plot" width="500" align="middle" />
</p>
<br>


</br>

# Finally
Please do not alter other files already populated except otherwise indicated. only write your code in `src/oneline_funcs.py` and `src/daemon_figure.py` files.


<br/>
<p  align="center"> <b>GOOD LUCK</b> </p>
