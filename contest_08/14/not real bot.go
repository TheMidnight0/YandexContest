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
	if marker == "X" {
		marker = "O"
	} else {
		marker = "X"
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