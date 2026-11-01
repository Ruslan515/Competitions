// https://leetcode.com/problems/find-target-indices-after-sorting-array/description/?envType=daily-question&envId=2026-10-19
package main

import (
	"fmt"
	"slices"
)

func targetIndices(nums []int, target int) []int {
	var answer []int
	slices.Sort(nums)
	n := len(nums)
	for i := 0; i < n; i++ {
		if nums[i] == target {
			answer = append(answer, i)
		}
	}

	return answer
}
func main() {
	var (
		nums   []int
		target int
		answer []int
		result []int
	)

	nums = []int{1, 2, 5, 2, 3}
	target = 2
	answer = []int{1, 2}
	result = targetIndices(nums, target)
	if !slices.Equal(result, answer) {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}

	nums = []int{1, 2, 5, 2, 3}
	target = 3
	answer = []int{3}
	result = targetIndices(nums, target)
	if !slices.Equal(result, answer) {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}

	nums = []int{1, 2, 5, 2, 3}
	target = 5
	answer = []int{4}
	result = targetIndices(nums, target)
	if !slices.Equal(result, answer) {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}
}
