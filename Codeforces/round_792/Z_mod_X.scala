/*
https://codeforces.com/contest/1684/problem/B

a = 1 b = 3 c = 4 => x = b * c, y = x - a, z = y - b


in: 127 234 421
out: 1063 234 1484

x mod y = a
y mod z = b
z mod x = c

x = m * y + a
y = n * z + b
z = k * x + c

x = m * (n * z + b) + a
y = n * z + b
z = k * x + c

x = m * (n * (k * x + c) + b) + a => x = m*n*k*x + m*n*c + m*b + a =>
=> x(1 - m*n*k) = m*n*c + m*b + a => x == (m*n*c + m*b + a) / (1 - m*n*k)
m = 1, n = 1, k = 1, x = (1 + b + a) / (1 - 3) = (1 + b + a) / (-2)
x = 2 * (1 + 127 + 234) = 724
z = k * x + c = 2 * 724 + 421 = 1869
y = 1 * z + b = 1869 + 234 =2103


a = 127 b = 234 c = 421 =>
x = 234 * 411 = 96174,
y = 96174 - 127 = 96047,
z = 96174 + 421 =96595

 */
package round_792

import scala.io.StdIn

object Z_mod_X {
    def solving(n: String) = {
        ???
    }

    val t = StdIn.readLine().toInt
    val in = new Array[String](t)
    for (i <- 0 until(t)) {
        in(i) = StdIn.readLine()
    }

    in.foreach(solving _)

}
