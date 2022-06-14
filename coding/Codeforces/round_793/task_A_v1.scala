/*
https://codeforces.com/contest/1682/problem/A
 */
//package round_793

import scala.io.StdIn

object task_A_v1 {

    def solving(s: String, n: Int): Int = {
        if (s.groupBy(x => x).map(e => (e._1, e._2.length)).toList.length == 1) {
            n
        }
        else if ( n % 2 == 0) {
            var i = n / 2 - 2
            val start_char = s(i)
            var j = n / 2 + 1
            var count = 2
            while (s(i) == s(j) && s(i) == start_char) {
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
            while (s(i) == s(j) && s(i) == start_char) {
                i -= 1
                j += 1
                count += 2
            }
            count
        }
    }

    def main(args: Array[String]) = {
        val t = StdIn.readLine().toInt
        var sb = new StringBuilder()
        for (i <- 0 until(t)) {
            val n = StdIn.readLine().toInt
            val s = StdIn.readLine()
            sb.append(solving(s, n)).append("\n")
        }
        print(sb)
    }

}

/*
1
4
aaaa
 */
