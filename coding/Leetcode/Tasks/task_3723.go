// https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/?envType=daily-question&envId=2026-10-14
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func maxSumOfSquares(num int, sum int) string {

	var answer string
	nine := 9
	if nine*num < sum {
		return answer
	}
	currentSum := 0
	var sb strings.Builder
	sb.Grow(num)

	for i := 0; i < num; i++ {
		for digit := nine; digit > 0; digit-- {
			preSum := digit + currentSum
			if preSum <= sum {
				currentSum += digit
				sb.WriteString(strconv.Itoa(digit))
				if preSum == sum {
					for j := i + 1; j < num; j++ {
						sb.WriteString("0")
					}
					return sb.String()
				}
				break
			}
		}
	}
	answer = sb.String()
	return answer
}
func main() {
	var num int
	var sum int
	var answer string
	var result string

	num = 2
	sum = 3
	answer = "30"
	result = maxSumOfSquares(num, sum)
	if result != answer {
		fmt.Println("The answer is ", answer, "The result is ", result)
	}

	num = 2
	sum = 17
	answer = "98"
	result = maxSumOfSquares(num, sum)
	if result != answer {
		fmt.Println("The answer is ", answer, "The result is ", result)
	}

	num = 1
	sum = 10
	answer = ""
	result = maxSumOfSquares(num, sum)
	if result != answer {
		fmt.Println("The answer is ", answer, "The result is ", result)
	}
}
