/*
https://leetcode.com/problems/palindrome-number/

Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward.
For example, 121 is a palindrome while 123 is not.
 */
object Palindrome_Number extends App {
    def isPalindrome(x: Int): Boolean = {
        if (x >= 0) {
                val s = x.toString
                val n = s.length
                var i = 0
                while ((s(i) == s(n - i - 1)) && (i < n / 2)) {
                    i += 1
                }
                val ans = {
                    if (i == n / 2)
                    {
                        true
                    }
                    else false
                }
                ans
        }
        else {
            false
        }

    }

    println(isPalindrome(9))
    println(isPalindrome(121))
    println(isPalindrome(-121))
    println(isPalindrome(1221))

}
