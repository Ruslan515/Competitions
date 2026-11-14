// https://leetcode.com/problems/keyboard-row/description/?envType=problem-list-v2&envId=hash-table
package main

import (
	"fmt"
	"slices"
	"unicode"
)

func str2set(word string, lineNume int, set map[rune]int) {
	for _, ch := range word {
		set[ch] = lineNume
	}
}
func findWords(words []string) []string {
	var answer []string
	set := make(map[rune]int, 26)
	for i, word := range []string{"qwertyuiop", "asdfghjkl", "zxcvbnm"} {
		str2set(word, i, set)
	}

	var label bool
	for _, word := range words {
		firstSymbol := unicode.ToLower([]rune(word)[0])
		firstNum := set[firstSymbol]
		label = true
		for _, letter := range word {
			currentSymbol := unicode.ToLower(letter)
			if firstNum != set[currentSymbol] {
				label = false
				break
			}
		}
		if label {
			answer = append(answer, word)
		}

	}

	return answer

}
func main() {
	var words []string
	var answer []string
	var result []string

	words = []string{"Hello", "Alaska", "Dad", "Peace"}
	answer = []string{"Alaska", "Dad"}
	result = findWords(words)
	if !slices.Equal(result, answer) {
		fmt.Printf("answer: %q, result: %q\n", answer, result)
	}

	words = []string{"omk"}
	answer = []string{}
	result = findWords(words)
	if !slices.Equal(result, answer) {
		fmt.Printf("answer: %d, result: %d\n", answer, result)
	}

	words = []string{"adsdf", "sfd"}
	answer = []string{"adsdf", "sfd"}
	result = findWords(words)
	if !slices.Equal(result, answer) {
		fmt.Printf("answer: %d, result: %d\n", answer, result)
	}
}
