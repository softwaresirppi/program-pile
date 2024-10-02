package main

import . "fmt"
import . "strings"
import io "bufio"
import . "os"

var digits = [...]string {
	"zero", "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine",
}

// Swallows target from source (exactly one time)
func SwallowString(i int, source, target string) (int, bool) {
	for j := 0; j < len(target); j++ {
		if len(source) <= i + j || source[i + j] != target[j] {
			return i, false
		}
	}
	return i + len(target), true
}

// Swallows target as much as possible from source
func SwallowStrings(i int, source, target string) (int, int) {
	n, success := -1, true
	for success {
		i, success = SwallowString(i, source, target)
		n++
	}
	return i, n
}

// Digit = any one in the `digits` array
func ParseDigit(i int, source string) (int, int, bool) {
	for value, word := range digits {
		if  i + len(word) <= len(source) && source[i:i + len(word)] == word {
			return i + len(word), value, true
		}
	}
	return i, 0, false
}

// Two Digit Number = SmallNumber = Digit | Digit "ty" | Digit "ty" Digit
func ParseSmallNumber(i int, source string) (int, int, bool) {
	var first, second, success = 0, 0, true
	if i, first, success = ParseDigit(i, source); !success { return i, 0, false }
	if i, success = SwallowString(i, source, "ty"); !success { return i, first, true }
	i, _ = SwallowStrings(i, source, " ")
	if i, second, success = ParseDigit(i, source); !success { return i, first * 10, true }
	return i, first * 10 + second, true
}

// Three Digit Number = Number = SmallNumber | SmallNumber "hundred" | SmallNumber "hundred" SmallNumber
func ParseNumber(i int, source string) (int, int, bool) {
	var first, second, success = 0, 0, true
	if i, first, success = ParseSmallNumber(i, source); !success { return i, 0, false }
	i, _ = SwallowStrings(i, source, " ")
	if i, success = SwallowString(i, source, "hundred"); !success { return i, first, true }
	i, _ = SwallowStrings(i, source, " ")
	if i, second, success = ParseSmallNumber(i, source); !success { return i, first * 100, true }
	return i, first * 100 + second, true
}

// BigNumber = Number ("billion" | "million" | "thousand") BigNumber?
func ParseBigNumber(i int, source string) (int, int, bool) {
	first, second, success := 0, 0, true
	if i, first, success = ParseNumber(i, source); !success { return i, 0, false }
	i, _ = SwallowStrings(i, source, " ")

	if i, success = SwallowString(i, source, "billion"); success {
		first *= 1000_000_000
	} else if i, success = SwallowString(i, source, "million"); success {
		first *= 1000_000
	} else if i, success = SwallowString(i, source, "thousand"); success {
		first *= 1000
	} else {
		return i, first, true
	}
	i, _ = SwallowStrings(i, source, " ")
	if i, second, success = ParseBigNumber(i, source); !success { return i, first, true }
	return i, first + second, true
}

func repl(){
	reader := io.NewReader(Stdin)
	text,_ := reader.ReadString('\n')
	i, value, success := ParseBigNumber(0, ToLower(text))
	if !success {
		Println("Thats not a number.")
		return
	}
	if i < len(text) - 1 {
		Printf("Thats partially a number upto %d\n", i)
	}
	Printf("That's %d\n", value)
}

func main(){
	repl()
}
