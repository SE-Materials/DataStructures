/**
 * @input A : Integer array
 * @input B : Integer
 *
 * @Output Integer
 */
package main

func diffPossible(A []int, B int) int {
	numsToIndexMap := map[int]bool{}
	for _, num := range A {
		if _, exists := numsToIndexMap[num-B]; exists {
			return 1
		}

		if _, exists := numsToIndexMap[B+num]; exists {
			return 1
		}

		numsToIndexMap[num] = true
	}

	return 0
}

func main() {

}
