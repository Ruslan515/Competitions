// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/?envType=daily-question&envId=2026-11-05
package main

import (
	"fmt"
	"math"
)

func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
	var answer int
	n := len(arr1)
	m := len(arr2)
	var val1, val2 int
	for i := 0; i < n; i++ {
		val1 = arr1[i]
		label := true
		for j := 0; j < m; j++ {
			val2 = arr2[j]
			diff := int(math.Abs(float64(val1 - val2)))
			if diff <= d {
				label = false
				break
			}
		}
		if label {
			answer++
		}
	}

	return answer
}
func main() {
	var (
		arr1   []int
		arr2   []int
		d      int
		answer int
		result int
	)

	arr1 = []int{4, 5, 8}
	arr2 = []int{10, 9, 1, 8}
	d = 2
	answer = 2
	result = findTheDistanceValue(arr1, arr2, d)
	if answer != result {
		fmt.Printf("answer: %d. result: %d\n", answer, result)
		fmt.Printf("arr1: %v. arr2: %v. \n", arr1, arr2)
	}

	arr1 = []int{1, 4, 2, 3}
	arr2 = []int{-4, -3, 6, 10, 20, 30}
	d = 3
	answer = 2
	result = findTheDistanceValue(arr1, arr2, d)
	if answer != result {
		fmt.Printf("answer: %d. result: %d\n", answer, result)
		fmt.Printf("arr1: %v. arr2: %v. \n", arr1, arr2)
	}

	arr1 = []int{2, 1, 100, 3}
	arr2 = []int{-5, -2, 10, -3, 7}
	d = 6
	answer = 1
	result = findTheDistanceValue(arr1, arr2, d)
	if answer != result {
		fmt.Printf("answer: %d. result: %d\n", answer, result)
		fmt.Printf("arr1: %v. arr2: %v. \n", arr1, arr2)
	}
}
