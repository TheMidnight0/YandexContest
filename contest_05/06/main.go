package main

import (
	"fmt"
	"math/rand"
)

type Cat struct {
	state int
}

func (cat Cat) is_alive() bool {
	if cat.state == 0 {
		return true
	} else {
		return false
	}
}

type Box struct{}

func (box Box) open() Cat {
	var cat Cat
	cat.state = rand.Int() % 2
	return cat
}

func main() {
	var box Box
	cat := box.open()
	if cat.is_alive() {
		fmt.Print("alive")
	} else {
		fmt.Print("dead")
	}
}
