func printTypes(data []interface{}) {
	var i int
	i = 0
	for i < len(data) {
		switch data[i].(type) {
		case int:
			fmt.Printf("int ")
			break
		case string:
			fmt.Printf("string ")
			break
		case Human:
			fmt.Printf("Human ")
			break
		case *Human:
			fmt.Printf("*Human ")
			break
		default:
			fmt.Printf("interface ")
		}
		i += 1
	}
}