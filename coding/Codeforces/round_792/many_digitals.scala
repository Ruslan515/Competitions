/*
https://codeforces.com/contest/1684/problem/0

1234 => 2134 => 213 => 312 => 31 => 13 => 1
1234 => 1324 => 132 => 123 => 12 => 21 => 2

1) 2d. XY => YX => Y
2) > 2d. XYZAm => XmZAY =>... => XmZ => ZmX => Zm => mZ

 */

import scala.io.StdIn

object many_digitals{

    def main(args: Array[String]): Unit = {
        def solving(n: String) = {
            if (n.length == 2) {
                println(n(1))
            }
            else {
                val answer = n.split("").map(x => x.toInt).min
                println(answer)
            }
        }

        val t = StdIn.readLine().toInt
        val in = new Array[String](t)
        for (i <- 0 until(t)) {
            //        val n = StdIn.readLine().toInt
            in(i) = StdIn.readLine()
        }

        in.foreach(solving _)

    }
}
