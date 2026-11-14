// https://leetcode.com/problems/relative-ranks/description/?envType=problem-list-v2&envId=heap-priority-queue
package main

import (
	"container/heap"
	"fmt"
	"slices"
)

type Pair struct {
	First, Second int
}
type PairHeap []Pair

func (h PairHeap) Len() int           { return len(h) }
func (h PairHeap) Less(i, j int) bool { return h[i].First > h[j].First }
func (h PairHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *PairHeap) Push(x any) {
	*h = append(*h, x.(Pair))
}
func (h *PairHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func findRelativeRanks(score []int) []string {
	n := len(score)
	answer := make([]string, n)
	h := &PairHeap{}
	heap.Init(h)
	for i := 0; i < len(score); i++ {
		heap.Push(h, Pair{First: score[i], Second: i})
	}

	var idx int
	var current Pair

	current = heap.Pop(h).(Pair)
	idx = current.Second
	answer[idx] = "Gold Medal"

	if h.Len() == 0 {
		return answer
	}
	current = heap.Pop(h).(Pair)
	idx = current.Second
	answer[idx] = "Silver Medal"
	if h.Len() == 0 {
		return answer
	}

	current = heap.Pop(h).(Pair)
	idx = current.Second
	answer[idx] = "Bronze Medal"

	num := 4
	for h.Len() > 0 {
		current = heap.Pop(h).(Pair)
		idx = current.Second
		answer[idx] = fmt.Sprintf("%d", num)
		num++

	}

	return answer
}
func main() {
	var (
		score  []int
		answer []string
		result []string
	)

	score = []int{5, 4, 3, 2, 1}
	answer = []string{"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"}
	result = findRelativeRanks(score)
	if !slices.Equal(answer, result) {
		fmt.Printf("answer is %v. result: %v. score: %v\n", answer, result, score)
	}

	score = []int{10, 3, 8, 9, 4}
	answer = []string{"Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"}
	result = findRelativeRanks(score)
	if !slices.Equal(answer, result) {
		fmt.Printf("answer is %v. result: %v. score: %v\n", answer, result, score)
	}
}
