/**
 * @input A : Integer array
 * @input B : Integer array
 * @input C : Integer array
 *
 * @Output Integer array.
 */
package main

import (
	"sort"
)

func CollectNumbers(arr []int, allNumbersToCount map[int]int) {
	visitedNumbers := map[int]int{}
	for _, num := range arr {
		visitedNumbers[num]++
		if visitedNumbers[num] == 1 {
			allNumbersToCount[num]++
		}
	}
}

func solve(A []int, B []int, C []int) []int {
	allNumbersToCount := map[int]int{}
	CollectNumbers(A, allNumbersToCount)
	CollectNumbers(B, allNumbersToCount)
	CollectNumbers(C, allNumbersToCount)

	ans := []int{}
	for num, count := range allNumbersToCount {
		if count > 1 {
			ans = append(ans, num)
		}
	}
	sort.Ints(ans[:])
	return ans
}
