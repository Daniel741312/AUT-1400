def adjacentElementsProduct(inputArray):
   return max([inputArray[i] * inputArray[i + 1] for i in range(0, len(inputArray) - 1)])

def allLongestStrings(inputArray):
   return [x for x in inputArray if len(x) == len(max(inputArray, key = len, default = ""))]

def checkPalindrome(inputString):
   return inputString == inputString[::-1]

def commonCharacterCount(s1, s2):
   return sum([min(s1.count(x), s2.count(x)) for x in set(s1) & set(s2) ])

def areSimilar(A, B):
   return len(A) == len(B) and set([A[i] for i in range(0, len(A)) if A[i] != B[i]]) == set([B[i] for i in range(0, len(A)) if A[i] != B[i]]) and len([A[i] for i in range(0, len(A)) if A[i] != B[i]]) in {0, 2}

def palindromeRearranging(inputString):
   return [inputString.count(x) % 2 for x in set(inputString)].count(1) <= 1

def arrayReplace(inputArray, elemToReplace, substitutionElem):
   return [substitutionElem if i == elemToReplace else i for i in inputArray]

def evenDigitsOnly(n):
   return str(n) == "".join([x for x in str(n) if int(x) % 2 == 0])

def alphabeticShift(inputString):
   return "".join([chr((ord(x) + 1 - 97) % 26 + 97) for x in inputString])

def firstDigit(inputString):
   return [int(x) for x in inputString if x <= '9' and x >= '0'][0]
