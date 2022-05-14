// https://www.interviewbit.com/problems/colorful-number/

package main

func colorful(A int) int {

	curr := []int{}
	products := map[int]bool{}
	for A > 0 {
		lastDigit := (int)(A % 10)
		A = (int)(A / 10)

		for i, num := range curr {
			curr[i] = num * lastDigit
		}

		curr = append(curr, lastDigit)
		for _, num := range curr {
			if _, exists := products[num]; exists {
				return 0
			}
			products[num] = true
		}
	}

	return 1
}

func main() {
	print(colorful(123))
}
