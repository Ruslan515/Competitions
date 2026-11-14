// https://leetcode.com/problems/distribute-candies/description/?envType=problem-list-v2&envId=hash-table
package main

import "fmt"

func distributeCandies(candyType []int) int {
	var answer int
	setCandies := make(map[int]struct{}, len(candyType))
	for _, candy := range candyType {
		setCandies[candy] = struct{}{}
	}
	n := len(candyType)
	m := len(setCandies)
	answer = min(n/2, m)

	return answer

}
func main() {
	var candyType []int
	var answer int
	var result int

	candyType = []int{1, 1, 2, 2, 3, 3}
	answer = 3
	result = distributeCandies(candyType)
	if result != answer {
		fmt.Printf("answer is %d, result is %d\n", answer, result)
		fmt.Printf("candyType: %v\n", candyType)
	}

	candyType = []int{6, 6, 6, 6}
	answer = 1
	result = distributeCandies(candyType)
	if result != answer {
		fmt.Printf("answer is %d, result is %d\n", answer, result)
		fmt.Printf("candyType: %v\n", candyType)
	}

	candyType = []int{1, 1, 2, 3}
	answer = 2
	result = distributeCandies(candyType)
	if result != answer {
		fmt.Printf("answer is %d, result is %d\n", answer, result)
		fmt.Printf("candyType: %v\n", candyType)
	}

}
