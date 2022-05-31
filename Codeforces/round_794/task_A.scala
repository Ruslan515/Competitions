// https://codeforces.com/contest/1686/problem/0
//package round_794

import scala.io.StdIn

object task_A extends App {
    def solving(a: Array[Int], n: Int): String = {
        val avg = a.sum.toFloat / n
        var i = 0
        while (i < n && a(i) != avg) {
            i += 1
        }
        if (i == n) {
            "NO"
        }
        else {
            "YES"
        }
    }

    val t = StdIn.readLine().toInt
    var sb = new StringBuilder()
    for (i <- 0 until(t)) {
        val n = StdIn.readLine().toInt
        val a: Array[Int] = StdIn.readLine().split(" ").map(x => x.toInt)
        sb.append(solving(a, n)).append("\n")
    }
    print(sb)

}
