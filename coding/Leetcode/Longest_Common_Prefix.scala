/*
https://leetcode.com/problems/longest-common-prefix/
 */
object Longest_Common_Prefix extends App {
    def longestCommonPrefix(strs: Array[String]): String = {
        var ans = ""
        val min_len = strs.map(_.length).min
        if (min_len == 0) {
            return ans
        }
        var label = true
        var i = 0
        while (label && i < min_len) {
            val start_char = strs(0)(i)
            var j = 1
            while (j < strs.length && strs(j)(i) == start_char) {
                j += 1
            }
            if (j == strs.length){
                ans += start_char
                i += 1
            }
            else {
                label = false
            }

        }
        ans
    }

    val strs2 = Array("a")
    println("3", longestCommonPrefix(strs2))

    val strs = Array("flower","flow","flight")
    println("1", longestCommonPrefix(strs))

    val strs1 = Array("dog","racecar","car")
    println("2", longestCommonPrefix(strs1))

}
