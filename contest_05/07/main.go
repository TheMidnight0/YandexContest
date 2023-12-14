package main

import ("fmt")

type Water struct {
	grad int
}

type Teapot struct {
	water Water
}

func NewWater(t int) Water {
	var water Water
	water.grad = t
	return water
}

func NewTeapot(water_new Water) Teapot {
	var teapot Teapot
	teapot.water = water_new
	return teapot
}

func (teapot *Teapot) heat_up(t int) {
	teapot.water.grad += t
}

func (teapot Teapot) is_boiling() bool {
	if (teapot.water.grad > 99) {
		return true
	} else {
		return false
	}
}

func main() {
    var temperature, count int
    fmt.Scan(&temperature, &count)

    heat := NewQueue()
    for i := 0; i < count; i++ {
        var t int
        fmt.Scan(&t)
        heat.Push(t)
    }

    water := NewWater(temperature)
    teapot := NewTeapot(water)
    
    for !teapot.is_boiling() {
        teapot.heat_up(heat.Pop())
    }
    
    for !heat.IsEmpty() {
        fmt.Print(heat.Pop(), " ")
    }
}