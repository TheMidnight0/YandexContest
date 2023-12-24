type SimpleStack struct {
	slice *[]rune
}

func (stack SimpleStack) empty() bool {
	if len(*stack.slice) == 0 {
		return true
	} else {
		return false
	}
}
func (stack SimpleStack) push(r rune) {
	*stack.slice = append(*stack.slice, r)
}

func (stack SimpleStack) top() rune {
	return (*stack.slice)[len(*stack.slice)-1]
}

func (stack SimpleStack) pop() rune {
	rn := (*stack.slice)[(len(*stack.slice) - 1)]
	*stack.slice = (*stack.slice)[:(len(*stack.slice) - 1)]
	return rn
}

func NewSimpleStack() SimpleStack {
	var stack SimpleStack
	stack.slice = new([]rune)
	return stack
}