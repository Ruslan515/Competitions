// https://leetcode.com/problems/degree-of-an-array/description/?envType=problem-list-v2&envId=hash-table
package main

import (
	"fmt"
	"math"
)

//func findShortestSubArray(nums []int) int {
//	answer := math.MaxInt32
//	freq := make(map[int]int)
//	maxFreq := 0
//	for _, num := range nums {
//		freq[num]++
//		maxFreq = max(maxFreq, freq[num])
//	}
//	n := len(nums)
//	for i := 0; i < n; i++ {
//		for j := i + 1; j <= n; j++ {
//			currMaxFreq := 0
//			currFreq := make(map[int]int)
//			for k := i; k < j; k++ {
//				currFreq[nums[k]]++
//				currMaxFreq = max(currFreq[nums[k]], currMaxFreq)
//			}
//			if currMaxFreq == maxFreq {
//				answer = min(answer, j-i)
//			}
//
//		}
//	}
//
//	return answer
//}

func findShortestSubArray(nums []int) int {
	answer := math.MaxInt32
	freq := make(map[int]int)
	maxFreq := 0
	for _, num := range nums {
		freq[num]++
		maxFreq = max(maxFreq, freq[num])
	}
	var sliceFreq []int
	for k, v := range freq {
		if v == maxFreq {
			sliceFreq = append(sliceFreq, k)
		}
	}
	n := len(nums)
	for _, num := range sliceFreq {
		var (
			diff, left, right int
		)
		for i := 0; i < n; i++ {
			if nums[i] == num {
				left = i
				break
			}
		}
		for i := n - 1; i >= 0; i-- {
			if nums[i] == num {
				right = i
				break
			}
		}
		diff = right - left + 1
		answer = min(answer, diff)
	}

	return answer
}
func main() {
	var (
		nums   []int
		answer int
		result int
	)

	nums = []int{1, 2, 2, 3, 1, 4, 2}
	answer = 6
	result = findShortestSubArray(nums)
	if result != answer {
		fmt.Printf("nums: %v,\n answer: %d, result: %d\n", nums, answer, result)
	}

	nums = []int{1, 2, 2, 3, 1}
	answer = 2
	result = findShortestSubArray(nums)
	if result != answer {
		fmt.Printf("nums: %v,\n answer: %d, result: %d\n", nums, answer, result)
	}

}
