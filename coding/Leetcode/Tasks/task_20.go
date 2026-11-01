// https://leetcode.com/problems/valid-parentheses/description/?envType=daily-question&envId=2026-10-01
package main

import "fmt"

func isValid(s string) bool {
	if len(s) == 1 {
		return false
	}
	closedChar := map[rune]rune{
		')': '(',
		']': '[',
		'}': '{',
	}
	answer := false
	var stack []rune
	for _, ch := range s {
		if len(stack) == 0 {
			if _, exists := closedChar[ch]; exists {
				return answer
			}
			stack = append(stack, ch)
		} else {
			top := stack[len(stack)-1]

			if val, exists := closedChar[ch]; exists {
				if val != top {
					return answer
				}
				stack = stack[:len(stack)-1]
			} else {
				stack = append(stack, ch)
			}

		}

	}
	if len(stack) == 0 {
		answer = true
	}
	return answer
}
func main() {
	var s string
	var answer bool

	s = "){"
	answer = false
	if isValid(s) != answer {
		fmt.Printf("The answer is not valid for string: %s\n", s)
	}

	s = "(("
	answer = false
	if isValid(s) != answer {
		fmt.Printf("The answer is not valid for string: %s\n", s)
	}

	s = "]"
	answer = false
	if isValid(s) != answer {
		fmt.Printf("The answer is not valid for string: %s\n", s)
	}

	s = "()"
	answer = true
	if isValid(s) != answer {
		fmt.Printf("The answer is not valid for string: %s\n", s)
	}

	s = "()[]{}"
	answer = true
	if isValid(s) != answer {
		fmt.Printf("The answer is not valid for string: %s\n", s)
	}

	s = "(]"
	answer = false
	if isValid(s) != answer {
		fmt.Printf("The answer is not valid for string: %s\n", s)
	}

	s = "([])"
	answer = true
	if isValid(s) != answer {
		fmt.Printf("The answer is not valid for string: %s\n", s)
	}

	s = "([)]"
	answer = false
	if isValid(s) != answer {
		fmt.Printf("The answer is not valid for string: %s\n", s)
	}
}
