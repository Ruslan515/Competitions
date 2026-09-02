// https://leetcode.com/problems/two-sum/description/?envType=problem-list-v2&envId=hash-table
package main

import (
	"fmt"
	"slices"
)

func twoSum(nums []int, target int) []int {
	answer := make([]int, 2)
	m := make(map[int][]int)
	n := len(nums)
	for i := 0; i < n; i++ {
		key := nums[i]
		m[key] = append(m[key], i)
		//if vec, ok := m[key]; ok {
		//	m[key] = append(vec, i)
		//} else {
		//	m[key] = []int{i}
		//}
	}
	for k, v := range m {
		diff := target - k
		if diff == k {
			if len(v) > 1 {
				answer[0] = v[0]
				answer[1] = v[1]
			}
		} else if vec, ok := m[diff]; ok {
			answer[0] = v[0]
			answer[1] = vec[0]
			break
		}
	}
	return answer
}
func main() {
	var nums []int
	var target int
	var answer []int

	nums = []int{2, 7, 11, 15}
	target = 9
	answer = []int{0, 1}
	expected := twoSum(nums, target)
	if !slices.Equal(answer, expected) {
		fmt.Printf("Fail on the test. answer: %v. Expected: %v\n", answer, expected)
	}

	nums = []int{3, 2, 4}
	target = 6
	answer = []int{1, 2}
	expected = twoSum(nums, target)
	if !slices.Equal(answer, expected) {
		fmt.Printf("Fail on the test. answer: %v. Expected: %v\n", answer, expected)
	}

	nums = []int{3, 3}
	target = 6
	answer = []int{0, 1}
	expected = twoSum(nums, target)
	if !slices.Equal(answer, expected) {
		fmt.Printf("Fail on the test. answer: %v. Expected: %v\n", answer, expected)
	}
}
