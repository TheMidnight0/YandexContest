type UserBot struct {
	marker string
}

func NewUserBot() *UserBot {
	return &UserBot{"?"}
}

func (b *UserBot) startGame(marker string) {
	b.marker = marker
}

func (b *UserBot) getMarker() string {
	return b.marker
}

func (b *UserBot) step(board Board) (row, col int, marker string) {
	marker = b.marker
	combinations := [][][]int{{{0, 0}, {1, 1}, {2, 2}}, {{2, 0}, {1, 1}, {0, 2}}, {{0, 0}, {0, 1}, {0, 2}}, {{1, 0}, {1, 1}, {1, 2}},
		{{2, 0}, {2, 1}, {2, 2}}, {{0, 0}, {1, 0}, {2, 0}}, {{0, 1}, {1, 1}, {2, 1}}, {{0, 2}, {1, 2}, {2, 2}}}
	for _, combination := range combinations {
		count := 0
		for _, position := range combination {
			if board[position[0]][position[1]] == b.marker {
				count++
			}
		}
		if count == 2 {
			for _, position := range combination {
				if board[position[0]][position[1]] == " " {
					row, col = position[0], position[1]
					return
				}
			}
		}
	}
	if board[1][1] == " " {
		row, col = 1, 1
		return
	} else {
		if board[1][1] == b.marker {
			for _, combination := range combinations {
				count := 0
				for _, position := range combination {
					if board[position[0]][position[1]] != b.marker && board[position[0]][position[1]] != " " {
						count++
					}
				}
				if count == 2 {
					for _, position := range combination {
						if board[position[0]][position[1]] == " " {
							row, col = position[0], position[1]
							return
						}
					}
				}
			}
			if board[0][0] == b.marker && board[0][2] == b.marker {
				if board[0][1] == " " {
					row, col = 0, 1
					return
				}
				if board[2][2] == " " {
					row, col = 2, 2
					return
				}
				if board[2][0] == " " {
					row, col = 2, 0
					return
				}
			}
			if board[0][0] == b.marker && board[2][0] == b.marker {
				if board[1][0] == " " {
					row, col = 1, 0
					return
				}
				if board[2][2] == " " {
					row, col = 2, 2
					return
				}
				if board[0][2] == " " {
					row, col = 0, 2
					return
				}
			}
			if board[2][2] == b.marker && board[0][2] == b.marker {
				if board[1][2] == " " {
					row, col = 1, 2
					return
				}
				if board[0][0] == " " {
					row, col = 0, 0
					return
				}
				if board[2][0] == " " {
					row, col = 2, 0
					return
				}
			}
			if board[2][2] == b.marker && board[2][0] == b.marker {
				if board[2][1] == " " {
					row, col = 2, 1
					return
				}
				if board[0][0] == " " {
					row, col = 0, 0
					return
				}
				if board[0][2] == " " {
					row, col = 0, 2
					return
				}
			}
			i := 0
			for i < 9 {
				if board[i%3][i/3] == " " {
					row, col = i%3, i/3
					return
				}
				i += 2
			}
			i = 0
			for i < 9 {
				if board[i%3][i/3] == " " {
					row, col = i%3, i/3
					return
				}
				i++
			}
		} else {
			for _, combination := range combinations {
				count := 0
				for _, position := range combination {
					if board[position[0]][position[1]] != b.marker && board[position[0]][position[1]] != " " {
						count++
					}
				}
				if count == 2 {
					for _, position := range combination {
						if board[position[0]][position[1]] == " " {
							row, col = position[0], position[1]
							return
						}
					}
				}
			}

		}
	}
	i := 0
	for i < 9 {
		if board[i%3][i/3] == " " {
			row, col = i%3, i/3
			return
		}
		i++
	}
	return
}

func (b *UserBot) endGame(winner string) {
	// Бот не обучается
}