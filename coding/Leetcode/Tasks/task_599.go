// https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/?envType=problem-list-v2&envId=hash-table
package main

import (
	"fmt"
	"slices"
)

func findRestaurant(list1 []string, list2 []string) []string {
	var answer []string
	minVal := 2001
	mapWordIdx1 := make(map[string]int)
	n := len(list1)
	m := len(list2)
	for i := 0; i < n; i++ {
		mapWordIdx1[list1[i]] = i
	}
	mapWordIdx := make(map[string]int)
	for i := 0; i < m; i++ {
		if _, ok := mapWordIdx1[list2[i]]; ok {
			mapWordIdx[list2[i]] = mapWordIdx1[list2[i]] + i
			minVal = min(minVal, mapWordIdx[list2[i]])
		}

	}
	for key, val := range mapWordIdx {
		if val == minVal {
			answer = append(answer, key)
		}
	}

	return answer
}
func main() {
	var list1 []string
	var list2 []string
	var answer []string
	var result []string

	list1 = []string{"Shogun", "Tapioca Express", "Burger King", "KFC"}
	list2 = []string{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"}
	answer = []string{"Shogun"}
	result = findRestaurant(list1, list2)
	if !slices.Equal(result, answer) {
		fmt.Printf("result: %v. answer: %v\n", result, answer)
	}

	list1 = []string{"Shogun", "Tapioca Express", "Burger King", "KFC"}
	list2 = []string{"KFC", "Shogun", "Burger King"}
	answer = []string{"Shogun"}
	result = findRestaurant(list1, list2)
	if !slices.Equal(result, answer) {
		fmt.Printf("result: %v. answer: %v\n", result, answer)
	}

	list1 = []string{"happy", "sad", "good"}
	list2 = []string{"sad", "happy", "good"}
	answer = []string{"sad", "happy"}
	result = findRestaurant(list1, list2)
	if !slices.Equal(result, answer) {
		fmt.Printf("result: %v. answer: %v\n", result, answer)
	}
}
