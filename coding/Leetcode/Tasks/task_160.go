// https://leetcode.com/problems/intersection-of-two-linked-lists/description/?envType=problem-list-v2&envId=hash-table
package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	var answer *ListNode
	var (
		mapA = make(map[*ListNode]struct{})
	)
	for headA != nil {
		mapA[headA] = struct{}{}
		headA = headA.Next
	}
	for headB != nil {
		if _, ok := mapA[headB]; ok {
			answer = headB
			break
		}
		headB = headB.Next
	}

	return answer
}

func createLinkedLists(
	intersectVal int,
	listA []int,
	listB []int,
	skipA int,
	skipB int,
) (*ListNode, *ListNode) {
	n := len(listA)
	m := len(listB)
	var (
		headA, headB *ListNode
	)

	if intersectVal == 0 {
		var tail *ListNode
		headA = &ListNode{listA[0], nil}
		tail = headA
		for i := 1; i < n; i++ {
			val := listA[i]
			newNode := &ListNode{val, nil}
			tail.Next = newNode
			tail = newNode
		}
		headB = &ListNode{listB[0], nil}
		tail = headB
		for j := 1; j < m; j++ {
			val := listB[j]
			newNode := &ListNode{val, nil}
			tail.Next = newNode
			tail = newNode
		}
	} else {
		var (
			tailA, tailB, tail *ListNode
		)

		headA = &ListNode{listA[0], nil}
		tailA = headA
		for i := 1; i < skipA; i++ {
			val := listA[i]
			newNode := &ListNode{val, nil}
			tailA.Next = newNode
			tailA = newNode
		}
		headB = &ListNode{listB[0], nil}
		tailB = headB
		for j := 1; j < skipB; j++ {
			val := listB[j]
			newNode := &ListNode{val, nil}
			tailB.Next = newNode
			tailB = newNode
		}

		val := listA[skipA]
		newNode := &ListNode{val, nil}
		tailA.Next = newNode
		tailB.Next = newNode
		tail = newNode
		for i := skipA + 1; i < n; i++ {
			val := listA[i]
			newNode := &ListNode{val, nil}
			tail.Next = newNode
			tail = newNode
		}
	}

	return headA, headB

}
func main() {
	var (
		intersectVal         int
		listA                []int
		listB                []int
		skipA                int
		skipB                int
		answer, headA, headB *ListNode
	)

	intersectVal = 4
	listA = []int{2, 2, 4, 5, 4}
	listB = []int{2, 2, 4, 5, 4}
	skipA = 2
	skipB = 2

	headA, headB = createLinkedLists(intersectVal, listA, listB, skipA, skipB)
	answer = getIntersectionNode(headA, headB)
	fmt.Println(answer)

	intersectVal = 8
	listA = []int{4, 1, 8, 4, 5}
	listB = []int{5, 6, 1, 8, 4, 5}
	skipA = 2
	skipB = 3
	headA, headB = createLinkedLists(intersectVal, listA, listB, skipA, skipB)
	answer = getIntersectionNode(headA, headB)
	fmt.Println(answer)

	intersectVal = 2
	listA = []int{1, 9, 1, 2, 4}
	listB = []int{3, 2, 4}
	skipA = 3
	skipB = 1

	headA, headB = createLinkedLists(intersectVal, listA, listB, skipA, skipB)
	answer = getIntersectionNode(headA, headB)
	fmt.Println(answer)

	intersectVal = 0
	listA = []int{2, 6, 4}
	listB = []int{1, 5}
	skipA = 3
	skipB = 2

	headA, headB = createLinkedLists(intersectVal, listA, listB, skipA, skipB)
	answer = getIntersectionNode(headA, headB)
	fmt.Println(answer)
}
