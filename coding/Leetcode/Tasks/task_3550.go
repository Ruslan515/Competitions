package main

import "fmt"

func sumDiggits(number int) int {
	answer := 0
	for number > 0 {
		d := number % 10
		answer += d
		number /= 10
	}

	return answer
}
func smallestIndex(nums []int) int {
	answer := -1
	n := len(nums)
	var current int
	for i := 0; i < n; i++ {
		current = nums[i]
		sD := sumDiggits(current)
		if i == sD {
			answer = i
			break
		}
	}
	return answer

}
func main() {
	var nums []int
	var answer int

	nums = []int{1, 10, 11}
	answer = 1
	if smallestIndex(nums) != answer {
		fmt.Println("not eq in case 2")
	}

	nums = []int{1, 3, 2}
	answer = 2
	if smallestIndex(nums) != answer {
		fmt.Println("not eq in case 1")
	}

	nums = []int{1, 2, 3}
	answer = -1
	if smallestIndex(nums) != answer {
		fmt.Println("not eq in case 3")
	}

}
