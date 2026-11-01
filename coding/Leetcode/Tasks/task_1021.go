// https://leetcode.com/problems/remove-outermost-parentheses/description/?envType=daily-question&envId=2026-10-08
package main

import "fmt"

func removeOuterParentheses(s string) string {
	var ans, st []rune
	for _, c := range s {
		if c == ')' {
			st = st[:len(st)-1]
		}
		if len(st) > 0 {
			ans = append(ans, c)
		}
		if c == '(' {
			st = append(st, c)
		}
	}
	return string(ans)
}
func main() {
	var s string
	var answer string
	var result string

	s = "(()())(())"
	answer = "()()()"
	result = removeOuterParentheses(s)
	if result != answer {
		fmt.Printf("faile for string: %s\n. your result: %s. need answer: %s", s, result, answer)
	}

	s = "(()())(())(()(()))"
	answer = "()()()()(())"
	result = removeOuterParentheses(s)
	if result != answer {
		fmt.Printf("faile for string: %s\n. your result: %s. need answer: %s", s, result, answer)
	}

	s = "()()"
	answer = ""
	result = removeOuterParentheses(s)
	if result != answer {
		fmt.Printf("faile for string: %s\n. your result: %s. need answer: %s", s, result, answer)
	}

	s = "((()()))(())"
	answer = "()()()"
	result = removeOuterParentheses(s)
	if result != answer {
		fmt.Printf("faile for string: %s\n. your result: %s. need answer: %s", s, result, answer)
	}

}
