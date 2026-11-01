// https://leetcode.com/problems/sum-of-squares-of-special-elements/description/?envType=daily-question&envId=2026-10-11
package main

import "fmt"

func sumOfSquares(nums []int) int {
	var answer int
	var n = len(nums)
	for i := 0; i < n; i++ {
		if n%(i+1) == 0 {
			answer += nums[i] * nums[i]
		}
	}

	return answer
}
func main() {
	var nums []int
	var answer int
	var result int

	nums = []int{1, 2, 3, 4}
	answer = 21
	result = sumOfSquares(nums)
	if result != answer {
		fmt.Printf("The nums: %v. result: %d\n", nums, result)
	}

	nums = []int{2, 7, 1, 19, 18, 3}
	answer = 63
	result = sumOfSquares(nums)
	if result != answer {
		fmt.Printf("The nums: %v. result: %d\n", nums, result)
	}

}
