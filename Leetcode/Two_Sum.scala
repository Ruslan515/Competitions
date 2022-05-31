/*
https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution,
and you may not use the same element twice.
You can return the answer in any order.
 */

object Two_Sum extends App {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        for (i <- 0 until nums.length) {
            val one = nums(i)
            val two = target - one
            for (j <- i + 1 until(nums.length) ){
                if (nums(j) == two) {
                    val ans = Array(i, j)
                    return ans
                }
            }
        }
        val ans = Array(-1, -1)
        ans
    }

    val nums = Array(2, 7, 11, 15)
    val target = 9
    val answer: Array[Int] = twoSum(nums, target)
    println(answer(0), answer(1))
}
