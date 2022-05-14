/**
 * @input A : Integer array
 * @input B : Integer
 *
 * @Output Integer array.
 */

package main

func twoSum(A []int, B int) []int {

	nums := map[int]int{}

	for i, num := range A {
		if idx, exists := nums[B-num]; exists {
			return []int{idx + 1, i + 1}
		}

		if _, exists1 := nums[num]; !exists1 {
			nums[num] = i
		}
	}
	return []int{}
}

func main() {

}
