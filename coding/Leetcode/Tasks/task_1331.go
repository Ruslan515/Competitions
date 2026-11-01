// https://leetcode.com/problems/rank-transform-of-an-array/description/
package main

import (
	"fmt"
	"slices"
)

func arrayRankTransform(arr []int) []int {
	var answer []int
	n := len(arr)
	if n == 0 {
		return answer
	}
	copyArr := slices.Clone(arr)
	slices.Sort(arr)
	rank := 1
	var (
		prev int = arr[0]
	)
	for _, current := range arr {
		if !(current == prev) {
			prev = current
			rank++
		}
		answer = append(answer, rank)
	}

	mapRank := make(map[int]int)
	var (
		key int
		val int
	)
	for i := 0; i < n; i++ {
		key = arr[i]
		val = answer[i]
		mapRank[key] = val
	}
	for i := 0; i < n; i++ {
		key = copyArr[i]
		val = mapRank[key]
		answer[i] = val
	}

	return answer
}
func main() {
	var (
		arr    []int
		answer []int
		result []int
	)

	arr = []int{40, 10, 20, 30}
	answer = []int{4, 1, 2, 3}
	result = arrayRankTransform(arr)
	if !slices.Equal(result, answer) {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}

	arr = []int{100, 100, 100}
	answer = []int{1, 1, 1}
	result = arrayRankTransform(arr)
	if !slices.Equal(result, answer) {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}

	arr = []int{37, 12, 28, 9, 100, 56, 80, 5, 12}
	answer = []int{5, 3, 4, 2, 8, 6, 7, 1, 3}
	result = arrayRankTransform(arr)
	if !slices.Equal(result, answer) {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}
}
