package round_793

/*
https://codeforces.com/contest/1682/problem/A
 */
//package round_793

import scala.io.StdIn

object task_A_v3 {

    def solving(s: String, n: Int): Int = {
        if (n == 2 && s(0) == s(1)) {
            2
        }
        else if ( n % 2 == 0) {
            var i = n / 2 - 2
            val start_char = s(i)
            var j = n / 2 + 1
            var count = 2
            while (i >= 0 && j < n && s(i) == s(j) && s(i) == start_char) {
                i -= 1
                j += 1
                count += 2
            }
            count
        }
        else {
            val start_char = s(n / 2)
            var i = n / 2 - 1
            var j = n / 2 + 1
            var count = 1
            while (i >= 0 && j < n && s(i) == s(j) && s(i) == start_char) {
                i -= 1
                j += 1
                count += 2
            }
            count
        }
    }

    def main(args: Array[String]) = {

        val t = StdIn.readLine().toInt
        val in = new Array[String](t)
        val in_n = new Array[Int](t)
        for (i <- 0 until(t)) {
            in_n(i) = StdIn.readLine().toInt
            in(i) = StdIn.readLine()
        }

        for (i <- 0 until (t)) {
            println(solving(in(i), in_n(i)))
        }

    }

}

/*
1
4
aaaa
 */
