/*
https://leetcode.com/problems/roman-to-integer/
 */

object Roman_to_Integer extends App {
    def romanToInt(s: String): Int = {
        import scala.collection.mutable
        val roman_numerals = mutable.HashMap(
            "I" -> 1,
            "V" -> 5,
            "X" -> 10,
            "L" -> 50,
            "C" -> 100,
            "D" -> 500,
            "M" -> 1000
        )

        var answer: Int = 0

        val len_string = s.length
        for (i <- 0 until(len_string)) {
            val symbol = s(i)
            if ((i + 1) == len_string || (roman_numerals(symbol.toString) >= roman_numerals(s(i + 1).toString)))
                answer += roman_numerals(symbol.toString)
            else
                answer -= roman_numerals(symbol.toString)
        }
        answer
    }

    assert(romanToInt("III") == 3)
    println(f"III == ${romanToInt("III")}")

    assert(romanToInt("LVIII") == 58)
    println(f"LVIII == ${romanToInt("LVIII")}")

    assert(romanToInt("MCMXCIV") == 1994)
    println(f"MCMXCIV == ${romanToInt("MCMXCIV")}")

}
