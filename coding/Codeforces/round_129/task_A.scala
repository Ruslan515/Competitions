/*
https://codeforces.com/contest/1681/problem/A
 */
//package round_129

import scala.collection.mutable
import scala.io.StdIn

object task_A extends App {
    def solving(x: Array[Int], y: Array[Int]) = {
        val max_x = x.max
        val max_y = y.max
        if (max_x > max_y) {
            1
        }
        else if (max_x < max_y) {
            -1
        }
        else {
            0
        }
    }

    var sb = new StringBuilder()
    val t = StdIn.readLine().toInt
    for (i <- 0 until(t)) {
        val n = StdIn.readLine().toInt
        val a = StdIn.readLine().split(" ").map(_.toInt)
//        val a = Array(n)
//        for (ii <- 0 until(n)) a(ii) = StdIn.readLine().split(" ").toInt
        val m = StdIn.readLine().toInt
        val b = StdIn.readLine().split(" ").map(_.toInt)
//        val b = Array(m)
//        for (ii <- 0 until(m)) b(ii) = StdIn.readLine().toInt
        val ans = solving(a, b)
        if (ans == 1) {
//            println("Alice")
//            println("Alice")

            sb.append("Alice").append("\n").append("Alice").append("\n")
        }
        else if (ans == -1) {
//            println("Bob")
//            println("Bob")

            sb.append("Bob").append("\n").append("Bob").append("\n")
        }
        else {
//            println("Alice")
//            println("Bob")

            sb.append("Alice").append("\n").append("Bob").append("\n")

        }
    }

    print(sb)
}
