import unittest
import oneline_funcs as f


class Test(unittest.TestCase):
    ## ---------------- adjacentElementsProduct ----------------
    def test_adjacentElementsProduct1(self):
        self.assertEqual(f.adjacentElementsProduct([3, 6, -2, -5, 7, 3]), 21)

    def test_adjacentElementsProduct2(self):
        self.assertEqual(f.adjacentElementsProduct([-1, -2]), 2)   

    def test_adjacentElementsProduct3(self):
        self.assertEqual(f.adjacentElementsProduct([5, 1, 2, 3, 1, 4]), 6)   

    def test_adjacentElementsProduct4(self):
        self.assertEqual(f.adjacentElementsProduct([1, 2, 3, 0]), 6)   

    def test_adjacentElementsProduct5(self):
        self.assertEqual(f.adjacentElementsProduct([9, 5, 10, 2, 24, -1, -48]), 50)   

    def test_adjacentElementsProduct6(self):
        self.assertEqual(f.adjacentElementsProduct([5, 6, -4, 2, 3, 2, -23]), 30)   

    def test_adjacentElementsProduct7(self):
        self.assertEqual(f.adjacentElementsProduct([4, 1, 2, 3, 1, 5]), 6)   

    def test_adjacentElementsProduct8(self):
        self.assertEqual(f.adjacentElementsProduct([-23, 4, -3, 8, -12]), -12)   

    def test_adjacentElementsProduct9(self):
        self.assertEqual(f.adjacentElementsProduct([1, 0, 1, 0, 1000]), 0)   
    ## ---------------- AllLongestStrings ----------------
    def test_AllLongestStrings1(self):
        self.assertEqual(f.allLongestStrings(["aba", "aa", "ad", "vcd", "aba"]), ["aba", "vcd", "aba"])
    
    def test_AllLongestStrings2(self):
        self.assertEqual(f.allLongestStrings(["aa"]), ["aa"])
    
    def test_AllLongestStrings3(self):
        self.assertEqual(f.allLongestStrings(["abc", "eeee", "abcd", "dcd"]), ["eeee", "abcd"])
    
    def test_AllLongestStrings4(self):
        self.assertEqual(f.allLongestStrings(["a",   "abc",   "cbd", "zzzzzz", "a", "abcdef", "asasa", "aaaaaa"]), ["zzzzzz", "abcdef", "aaaaaa"])
    
    def test_AllLongestStrings5(self):
        self.assertEqual(f.allLongestStrings(["enyky", "benyky", "yely", "varennyky"]), ["varennyky"])
    
    def test_AllLongestString6(self):
        self.assertEqual(f.allLongestStrings(["abacaba", "abacab", "abac", "xxxxxx"]), ["abacaba"])
    
    def test_AllLongestStrings7(self):
        self.assertEqual(f.allLongestStrings(["young", "yooooooung", "hot", "or", "not", "come", "on", "fire", "water", "watermelon"]), ["yooooooung", "watermelon"])
    
    def test_AllLongestStrings8(self):
        self.assertEqual(f.allLongestStrings(["onsfnib", "aokbcwthc", "jrfcw"]), ["aokbcwthc"])
    
    ## ---------------- checkPalindrome ----------------
    def test_checkPalindrome1(self):
        self.assertEqual(f.checkPalindrome("aabaa"), True)
    
    def test_checkPalindrome2(self):
        self.assertEqual(f.checkPalindrome("abac"), False)
    
    def test_checkPalindrome3(self):
        self.assertEqual(f.checkPalindrome("a"), True)
    
    def test_checkPalindrome4(self):
        self.assertEqual(f.checkPalindrome("az"), False)
    
    def test_checkPalindrome5(self):
        self.assertEqual(f.checkPalindrome("abacaba"), True)
    
    def test_checkPalindrome6(self):
        self.assertEqual(f.checkPalindrome("z"), True)
    
    def test_checkPalindrome7(self):
        self.assertEqual(f.checkPalindrome("aaabaaaa"), False)
    
    def test_checkPalindrome8(self):
        self.assertEqual(f.checkPalindrome("zzzazzazz"), False)
    ## ---------------- commonCharacterCount ----------------
    def test_commonCharacterCount1(self):
        self.assertEqual(f.commonCharacterCount("aabcc", "adcaa"), 3)
    
    def test_commonCharacterCount2(self):
        self.assertEqual(f.commonCharacterCount("zzzz", "zzzzzzz"), 4)
    
    def test_commonCharacterCount3(self):
        self.assertEqual(f.commonCharacterCount("abca", "xyzbac"), 3)
    
    def test_commonCharacterCount4(self):
        self.assertEqual(f.commonCharacterCount("a", "b"), 0)
    
    def test_commonCharacterCount5(self):
        self.assertEqual(f.commonCharacterCount("a", "aaa"), 1)
    
    ## ---------------- areSimilar ----------------
    def test_areSimilar1(self):
        self.assertEqual(f.areSimilar([1, 2, 3], [1, 2, 3]), True)

    def test_areSimilar2(self):
        self.assertEqual(f.areSimilar([1, 2, 3], [2, 1, 3]), True)

    def test_areSimilar3(self):
        self.assertEqual(f.areSimilar([1, 2, 2], [2, 1, 1]), False)

    def test_areSimilar4(self):
        self.assertEqual(f.areSimilar([1, 1, 4], [1, 2, 3]), False)

    def test_areSimilar5(self):
        self.assertEqual(f.areSimilar([1, 2, 3], [1, 10, 2]), False)

    def test_areSimilar6(self):
        self.assertEqual(f.areSimilar([2, 3, 1], [1, 3, 2]), True)

    def test_areSimilar7(self):
        self.assertEqual(f.areSimilar([2, 3, 9], [10, 3, 2]), False)

    def test_areSimilar8(self):
        self.assertEqual(f.areSimilar([832, 998, 148, 570, 533, 561, 894, 147, 455, 279], [832, 998, 148, 570, 533, 561, 455, 147, 894, 279]), True)

    ## ---------------- palindromeRearranging ----------------
    def test_palindromeRearranging1(self):
        self.assertEqual(f.palindromeRearranging("aabb"), True)

    def test_palindromeRearranging2(self):
        self.assertEqual(f.palindromeRearranging("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaabc"), False)

    def test_palindromeRearranging3(self):
        self.assertEqual(f.palindromeRearranging("abbcabb"), True)

    def test_palindromeRearranging4(self):
        self.assertEqual(f.palindromeRearranging("zyyzzzzz"), True)

    def test_palindromeRearranging5(self):
        self.assertEqual(f.palindromeRearranging("z"), True)

    def test_palindromeRearranging6(self):
        self.assertEqual(f.palindromeRearranging("zaa"), True)

    def test_palindromeRearranging7(self):
        self.assertEqual(f.palindromeRearranging("abca"), False)

    def test_palindromeRearranging8(self):
        self.assertEqual(f.palindromeRearranging("abcad"), False)

    ## ---------------- arrayReplace ----------------
    def test_arrayReplace1(self):
        self.assertEqual(f.arrayReplace([1, 2, 1], 1, 3), [3, 2, 3])

    def test_arrayReplace2(self):
        self.assertEqual(f.arrayReplace([1, 2, 3, 4, 5], 3, 0), [1, 2, 0, 4, 5])

    def test_arrayReplace3(self):
        self.assertEqual(f.arrayReplace([1, 1, 1], 1, 10), [10, 10, 10])

    def test_arrayReplace4(self):
        self.assertEqual(f.arrayReplace([1, 2, 1, 2, 1], 2, 1), [1, 1, 1, 1, 1])

    def test_arrayReplace5(self):
        self.assertEqual(f.arrayReplace([1, 2, 1, 2, 1], 2, 2), [1, 2, 1, 2, 1])

    def test_arrayReplace6(self):
        self.assertEqual(f.arrayReplace([3, 1], 3, 9), [9, 1])

    def test_arrayReplace7(self):
        self.assertEqual(f.arrayReplace([10, 10], 0, 9), [10, 10])

    ## ---------------- evenDigitsOnly ----------------
    def test_evenDigitsOnly1(self):
        self.assertEqual(f.evenDigitsOnly(248622), True)

    def test_evenDigitsOnly2(self):
        self.assertEqual(f.evenDigitsOnly(642386), False)

    def test_evenDigitsOnly3(self):
        self.assertEqual(f.evenDigitsOnly(248842), True)

    def test_evenDigitsOnly4(self):
        self.assertEqual(f.evenDigitsOnly(1), False)

    def test_evenDigitsOnly5(self):
        self.assertEqual(f.evenDigitsOnly(8), True)

    def test_evenDigitsOnly6(self):
        self.assertEqual(f.evenDigitsOnly(2462487), False)

    ## ---------------- alphabeticShift ----------------
    def test_alphabeticShift1(self):
        self.assertEqual(f.alphabeticShift("crazy"), "dsbaz")
    
    def test_alphabeticShift2(self):
        self.assertEqual(f.alphabeticShift("z"), "a")
    
    def test_alphabeticShift3(self):
        self.assertEqual(f.alphabeticShift("aaaabbbccd"), "bbbbcccdde")
    
    def test_alphabeticShift4(self):
        self.assertEqual(f.alphabeticShift("fuzzy"), "gvaaz")

    ## ---------------- firstDigit ----------------
    def test_firstDigit1(self):
        self.assertEqual(f.firstDigit("var_1__Int"), 1)    
    
    def test_firstDigit2(self):
        self.assertEqual(f.firstDigit("q2q-q"), 2)    
    
    def test_firstDigit3(self):
        self.assertEqual(f.firstDigit("0ss"), 0)    
    
    def test_firstDigit4(self):
        self.assertEqual(f.firstDigit("_Aas_23"), 2)    
    
    def test_firstDigit5(self):
        self.assertEqual(f.firstDigit("a a_933"), 9)    
    
    def test_firstDigit6(self):
        self.assertEqual(f.firstDigit("ok0"), 0)    

if __name__=='__main__':
    unittest.main()