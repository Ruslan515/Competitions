// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/?envType=daily-question&envId=2026-11-03
package main

import "fmt"

func minMoves(nums []int) int {
	var answer int
	globalMax := 0
	for _, num := range nums {
		globalMax = max(globalMax, num)
	}
	for _, num := range nums {
		answer += globalMax - num
	}

	return answer
}
func main() {
	var nums []int
	var answer int
	var result int

	nums = []int{2, 1, 3}
	answer = 3
	result = minMoves(nums)
	if result != answer {
		fmt.Printf("answer is %d, result is %d\n", result, answer)
	}

	nums = []int{4, 4, 5}
	answer = 2
	result = minMoves(nums)
	if result != answer {
		fmt.Printf("answer is %d, result is %d\n", result, answer)
	}

}
