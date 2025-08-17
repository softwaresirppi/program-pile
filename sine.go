package main

import . "fmt"

// sin(x) = x^1/1! - x^3/3! + x^5/5! - ...
// it computes the first 64 terms of mcclauren series.
func Sin(cycles float64) float64 {
	var factorial float64 = 1
	var exes float64 = cycles
	var sum float64
	for i := 1; i < 64; i ++ {
		if i & 1 == 0 {
			sum -= exes / factorial
		} else {
			sum += exes / factorial
		}
		factorial *= float64(2 * i) * float64(2 * i + 1)
		exes *= cycles * cycles
	}
	return sum
}
const CYCLE = 6.283185307179586
func main(){
	Println(Sin(0.25 * CYCLE))
}
