/*
https://codeforces.com/contest/1681/problem/B
 */
package round_129

import scala.io.StdIn

object task_B_v1 extends App {
    def solving(a: Array[Int], b: Array[Int]): Int = {
        val ss = b.sum % a.length
        a(ss)
    }

    var sb = new StringBuilder()
    val t = StdIn.readLine().toInt
    for (_ <- 0 until(t)) {
        val n = StdIn.readLine().toInt
        val a = StdIn.readLine().split(" ").map(_.toInt)
        val m = StdIn.readLine().toInt
        val b = StdIn.readLine().split(" ").map(_.toInt)
        sb.append(solving(a, b)).append("\n")
    }
    print(sb)
}
