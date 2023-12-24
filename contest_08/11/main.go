func (m *Matrix) Rows() int {
	return len(m.data)
}

func (m *Matrix) Cols() int {
	if len(m.data) != 0 {
		return len(m.data[0])
	}
	return 0
}

func NewMatrix(rows, cols, value int) Matrix {
	var new Matrix
	var empty []int
	for new.Rows() < rows {
		new.data = append(new.data, empty)
		for len(new.data[len(new.data)-1]) < cols {
			new.data[len(new.data)-1] = append(new.data[len(new.data)-1], value)
		}
	}
	return new
}

func (m *Matrix) Set(row, col, value int) {
	m.data[row][col] = value
}

func (m *Matrix) Get(row, col int) int {
	if row < m.Rows() {
		if col < m.Cols() {
			return m.data[row][col]
		}
	}
	return 0
}

func (m *Matrix) Convolution(core *Matrix) Matrix {
	var new Matrix
	var empty []int
	i := 0
	for i < m.Rows() {
		j := 0
		for j < m.Cols() {
			mult := 0
			r := 0
			for r < core.Rows() {
				c := 0
				for c < core.Cols() {
					if i+r < m.Rows() && j+c < m.Cols() {
						mult += m.data[i+r][j+c] * core.data[r][c]
					} else {
						r = -1
						break
					}
					c++
				}
				if r == -1 {
					break
				}
				r++
			}
			if r != -1 {
				if i >= new.Rows() {
					new.data = append(new.data, empty)
				}
				new.data[i] = append(new.data[i], mult)
			}
			j++
		}
		i++
	}
	return new
}

func (a *Matrix) Multiplication(b *Matrix) *Matrix {
	var new Matrix
	var empty []int
	i := 0
	for i < a.Rows() {
		j := 0
		new.data = append(new.data, empty)
		for j < b.Cols() {
			result := 0
			n := 0
			for n < a.Rows()+b.Cols() {
				if b.Rows() > n && a.Cols() > n && b.Cols() > j && a.Rows() > i {
					result += a.data[i][n] * b.data[n][j]
				} else {
					break
				}
				n++
			}
			new.data[i] = append(new.data[i], result)
			j++
		}
		i++
	}
	return &new
}

func (m *Matrix) AddRow(value int) {
	var empty []int
	(*m).data = append((*m).data, empty)
	j := 0
	for j < m.Cols() {
		(*m).data[len(m.data)-1] = append(m.data[len(m.data)-1], value)
		j++
	}
}

func (m *Matrix) AddCol(value int) {
	i := 0
	for i < m.Rows() {
		(*m).data[i] = append((*m).data[i], value)
		i++
	}
}

func (m *Matrix) String() string {
	var result string
	i := 0
	for i < len(m.data) {
		j := 0
		for j < len(m.data[i]) {
			result += fmt.Sprintf("%d", m.data[i][j]) + " "
			j++
		}
		result += "\n"
		i++
	}
	return result
}