//package round_129

import scala.io.StdIn

object task_B extends App {
    def solving(a: Array[Int], b: Array[Int]): Int = {
        var temp = a
        for (bb <- b) {
            temp = Array.concat(temp.slice(bb, temp.length), temp.slice(0, bb))
        }
        temp(0)
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
