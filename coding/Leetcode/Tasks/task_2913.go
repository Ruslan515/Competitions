// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/?envType=daily-question&envId=2026-10-15
package main

import "fmt"

func sumCounts(nums []int) int {
	var answer int
	n := len(nums)
	for cnt := 1; cnt <= n; cnt++ {
		for i := 0; i < n-cnt+1; i++ {
			freq := make(map[int]int)
			var val int
			for idx := i; idx < i+cnt; idx++ {
				val = nums[idx]
				freq[val]++
			}
			lenFreq := len(freq)
			answer += lenFreq * lenFreq
		}
	}

	return answer
}

func main() {
	var nums []int
	var answer int
	var result int

	nums = []int{1, 2, 1}
	answer = 15
	result = sumCounts(nums)
	if result != answer {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}

	nums = []int{1, 1}
	answer = 3
	result = sumCounts(nums)
	if result != answer {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}
}
