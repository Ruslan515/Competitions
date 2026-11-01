// https://leetcode.com/problems/find-words-containing-character/description/
package main

import (
	"fmt"
	"slices"
)

func findWordsContaining(words []string, x byte) []int {
	var answer []int
	n := len(words)
	for i := 0; i < n; i++ {
		m := len(words[i])
		for j := 0; j < m; j++ {
			if words[i][j] == x {
				answer = append(answer, i)
				break
			}
		}
	}

	return answer
}
func main() {
	var (
		words  []string
		x      byte
		answer []int
		result []int
	)

	words = []string{"leet", "code"}
	x = 'e'
	answer = []int{0, 1}
	result = findWordsContaining(words, x)
	if !slices.Equal(result, answer) {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}

	words = []string{"abc", "bcd", "aaaa", "cbc"}
	x = 'a'
	answer = []int{0, 2}
	result = findWordsContaining(words, x)
	if !slices.Equal(result, answer) {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}

	words = []string{"abc", "bcd", "aaaa", "cbc"}
	x = 'z'
	answer = []int{}
	result = findWordsContaining(words, x)
	if !slices.Equal(result, answer) {
		fmt.Println("The answer is ", answer, " but result is ", result)
	}
}
