/*
https://codeforces.com/contest/1682/problem/A
 */
package round_793

import scala.collection.mutable
import scala.io.StdIn

object task_A{

    def solving(s: String, n: Int): Int = {
        var count = 0
        for (k <- 0 until(n)) {
            val s_temp = s.substring(0, k) + s.substring(k + 1)
            var i = 0
            var j = s_temp.length - 1
            while (i < j && (s_temp(i) == s_temp(j))) {
                i += 1
                j -= 1
            }
            if (i >= j) {
                count += 1
            }

        }

//        for (i <- 0 until(n)) {
//            val s_temp = s.substring(0, i) + s.substring(i + 1)
//            if (s_temp.reverse.equals(s_temp)) {
//                count += 1
//            }
//        }
        count
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
