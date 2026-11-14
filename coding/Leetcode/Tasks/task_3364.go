// https://leetcode.com/problems/minimum-positive-sum-subarray/description/?envType=daily-question&envId=2026-11-14
package main

import "fmt"

func minimumSumSubarray(nums []int, l int, r int) int {
	answer := -1
	n := len(nums)
	prefixSum := make([]int, n+1)
	sum := 0
	for i := 0; i < n; i++ {
		sum += nums[i]
		prefixSum[i+1] = sum
	}
	var currSum int
	minSum := 1<<32 - 1
	for start := 0; start < n+1; start++ {
		for end := start + l; end < n+1 && end <= start+r; end++ {
			currSum = prefixSum[end] - prefixSum[start]
			if currSum > 0 && currSum < minSum {
				minSum = currSum
			}

		}
	}
	if minSum != 1<<32-1 {
		answer = minSum
	}
	return answer
}

func main() {
	var (
		nums           []int
		l, r           int
		answer, result int
	)

	nums = []int{4, -10}
	l = 1
	r = 1
	answer = 4
	result = minimumSumSubarray(nums, l, r)
	if result != answer {
		fmt.Printf("nums: %v, answer: %d, result: %d, l: %d, r: %d\n", nums, answer, result, l, r)
	}

	nums = []int{3, -2, 1, 4}
	l = 2
	r = 3
	answer = 1
	result = minimumSumSubarray(nums, l, r)
	if result != answer {
		fmt.Printf("answer: %d, result: %d, l: %d, r: %d\n", answer, result, l, r)
	}

	nums = []int{-2, 2, -3, 1}
	l = 2
	r = 3
	answer = -1
	result = minimumSumSubarray(nums, l, r)
	if result != answer {
		fmt.Printf("answer: %d, result: %d, l: %d, r: %d\n", answer, result, l, r)
	}

	nums = []int{1, 2, 3, 4}
	l = 2
	r = 4
	answer = 3
	result = minimumSumSubarray(nums, l, r)
	if result != answer {
		fmt.Printf("answer: %d, result: %d, l: %d, r: %d\n", answer, result, l, r)
	}
}
