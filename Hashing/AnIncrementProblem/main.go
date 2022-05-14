package main

import (
	"fmt"
)

type IntHeap []int

func (h IntHeap) Len() int            { return len(h) }
func (h IntHeap) Less(i, j int) bool  { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func solve(A []int) []int {
	numsToIndex := map[int]*IntHeap{}

	for idx, num := range A {
		if indices, exists := numsToIndex[num]; exists {
			curridx := indices.Pop().(int)
			indices.Push(idx)

			A[curridx]++
			incNumber := A[curridx]

			if numsToIndex[incNumber] == nil {
				numsToIndex[incNumber] = &IntHeap{}
			}
			pindices := numsToIndex[incNumber]
			pindices.Push(curridx)
		} else {
			if numsToIndex[num] == nil {
				numsToIndex[num] = &IntHeap{}
			}
			indices := numsToIndex[num]
			indices.Push(idx)
		}
	}
	return A
}

func main() {
	arr := []int{1, 2, 3, 2, 3, 1, 4, 2, 1, 3}
	ans := solve(arr)
	fmt.Println(ans)
}

// Your submission failed for the following input
// A : [ 1, 2, 3, 2, 3, 1, 4, 2, 1, 3 ]

// The expected return value:
// 4 5 3 2 3 2 4 2 1 3
// 4 5 3 2 3 2 4 2 1 3]
// Your function returned the following:
// 3 4 5 2 3 1 4 2 1 3
