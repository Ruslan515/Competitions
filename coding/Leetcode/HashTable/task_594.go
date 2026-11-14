// https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=problem-list-v2&envId=hash-table
package main

import (
	"fmt"
	"slices"
)

func findLHS(nums []int) int {
	var answer int
	freqMap := make(map[int]int)
	for _, num := range nums {
		freqMap[num]++
	}
	n := len(freqMap)
	keys := make([]int, 0, n)
	for k, _ := range freqMap {
		keys = append(keys, k)
	}
	slices.Sort(keys)
	for i := 0; i < n-1; i++ {
		prevKey := keys[i]
		currKey := keys[i+1]
		diff := currKey - prevKey
		if diff == 1 {
			answer = max(answer, freqMap[prevKey]+freqMap[currKey])
		}
	}

	return answer
}
func main() {
	var (
		nums   []int
		answer int
		result int
	)

	nums = []int{1, 3, 2, 2, 5, 2, 3, 7}
	answer = 5
	result = findLHS(nums)
	if result != answer {
		fmt.Printf("nums: %v,\n answer: %d, result: %d\n", nums, answer, result)
	}

	nums = []int{1, 2, 3, 4}
	answer = 2
	result = findLHS(nums)
	if result != answer {
		fmt.Printf("nums: %v,\n answer: %d, result: %d\n", nums, answer, result)
	}

	nums = []int{1, 1, 1, 1}
	answer = 0
	result = findLHS(nums)
	if result != answer {
		fmt.Printf("nums: %v,\n answer: %d, result: %d\n", nums, answer, result)
	}
}
