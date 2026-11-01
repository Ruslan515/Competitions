package main

import "fmt"
import "math"

func longestCommonPrefix(strs []string) string {
	answer := ""

	minLen := math.MaxInt32
	for _, word := range strs {
		minLen = min(len(word), minLen)
	}

	for i := 0; i < minLen; i++ {
		ch := strs[0][i]
		for _, word := range strs[1:] {
			if word[i] != ch {
				return answer
			}
		}
		answer += string(ch)

	}

	return answer
}
func main() {
	var (
		strs   []string
		answer string
		result string
	)

	strs = []string{"flower", "flow", "flight"}
	answer = "fl"
	result = longestCommonPrefix(strs)
	if result != answer {
		panic(fmt.Sprintf("strs: %s. answer: %s, result: %s", strs, answer, result))
	}

	strs = []string{"dog", "racecar", "car"}
	answer = ""
	result = longestCommonPrefix(strs)
	if result != answer {
		panic(fmt.Sprintf("strs: %s. answer: %s, result: %s", strs, answer, result))
	}

}
