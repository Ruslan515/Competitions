// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/?envType=problem-list-v2&envId=array
package main

import (
	"fmt"
	"slices"
)

func sortInPlace(nums []int) {
	n := len(nums)
	i := 0
	var val int
	var correctedIdx int
	for i < n {
		val = nums[i]
		correctedIdx = val - 1
		if val == nums[correctedIdx] {
			i++
		} else {
			nums[i], nums[correctedIdx] = nums[correctedIdx], nums[i]
		}
	}
}

func findDisappearedNumbers(nums []int) []int {
	answer := []int{}
	n := len(nums)
	var val int
	sortInPlace(nums)
	for i := 0; i < n; i++ {
		val = nums[i]
		if val != (i + 1) {
			answer = append(answer, i+1)
		}
	}

	return answer
}
func main() {
	var nums []int
	var answer []int
	var result []int

	nums = []int{4, 3, 2, 7, 8, 2, 3, 1}
	answer = []int{5, 6}
	result = findDisappearedNumbers(nums)
	if !slices.Equal(result, answer) {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}

	nums = []int{1, 1}
	answer = []int{2}
	result = findDisappearedNumbers(nums)
	if !slices.Equal(result, answer) {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}
}
