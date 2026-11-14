// https://leetcode.com/problems/shortest-completing-word/description/?envType=problem-list-v2&envId=hash-table
package main

import (
	"fmt"
	"unicode"
)

func getFreq(word string) map[rune]int {
	freq := map[rune]int{}
	for _, ch := range word {
		freq[ch]++
	}
	return freq
}
func shortestCompletingWord(licensePlate string, words []string) string {
	var answer string
	var minLen int = 1001
	freqPlate := map[rune]int{}
	for _, ch := range licensePlate {
		if unicode.IsLetter(ch) {
			freqPlate[unicode.ToLower(ch)]++
		}
	}

	var indexes []int
	for i, word := range words {
		freq := getFreq(word)
		label := true
		for key, valuePlate := range freqPlate {
			value, ok := freq[key]
			if !ok || (valuePlate > value) {
				label = false
				break
			}
		}
		if label {
			indexes = append(indexes, i)
			minLen = min(minLen, len(word))
		}
	}

	for _, idx := range indexes {
		if len(words[idx]) == minLen {
			answer = words[idx]
			break
		}
	}

	return answer
}
func main() {
	var (
		licensePlate string
		words        []string
		answer       string
		result       string
	)

	licensePlate = "1s3 PSt"
	words = []string{"step", "steps", "stripe", "stepple"}
	answer = "steps"
	result = shortestCompletingWord(licensePlate, words)
	if result != answer {
		fmt.Printf("licensePlate: %s, words: %v, answer: %s, result: %s\n", licensePlate, words, answer, result)
	}

	licensePlate = "1s3 456"
	words = []string{"looks", "pest", "stew", "show"}
	answer = "pest"
	result = shortestCompletingWord(licensePlate, words)
	if result != answer {
		fmt.Printf("licensePlate: %s, words: %v, answer: %s, result: %s\n", licensePlate, words, answer, result)
	}

}
