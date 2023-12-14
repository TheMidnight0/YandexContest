int** new_matrix(int rows, int cols, int value) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value;
        }
    }
    return matrix;
}

std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows, int ccols) {
    int result;
    int** new_matrix;
    if (mrows >= crows) {
        new_matrix = new int*[mrows - crows + 1];
        for (int i = 0; i <= mrows - crows; i++) {
            if (mcols >= ccols) {
                new_matrix[i] = new int[mcols - ccols + 1];
            }
            else {
                break;
            }
        }
        for (int i = 0; i < mrows; i++) {
            for (int j = 0; j < mcols; j++) {
                result = 0;
                for (int r = 0; r <= crows; r++) {
                    if (r == crows) {
                        new_matrix[i][j] = result;
                        break;
                    }
                    for (int c = 0; c < ccols; c++) {
                        if (i + r < mrows && j + c < mcols) {
                            result += matrix[i + r][j + c] * core[r][c];
                        }
                        else {
                            r = crows + 1;
                        }
                    }
                }
            }
        }
    }
    return std::make_tuple(new_matrix, mrows - crows + 1, mcols - ccols + 1);
}

std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols) {
    int** matrix = new int*[arows];
    for (int i = 0; i < arows; i++) {
        matrix[i] = new int[bcols];
    }
    for (int i = 0; i < arows; i++) {
        for (int j = 0, result = 0; j < bcols; j++) {
            result = 0;
            for (int n = 0; n < arows + bcols; n++) {
                if (brows > n && acols > n && bcols > j && arows > i) {
                    result += a[i][n] * b[n][j];
                }
                else {
                    break;
                }
            }
            matrix[i][j] = result;
        }
    }
    return std::make_tuple(matrix, arows, bcols);
}

std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value) {
    int** new_matrix = new int*[rows + 1];
    for (int i = 0; i <= rows; i++) {
        new_matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            new_matrix[i][j] = (*matrix)[i][j];
        }
    }
    for (int i = 0; i < cols; i++) {
        new_matrix[rows][i] = value;
    }
    *matrix = new_matrix;
    return std::make_tuple(rows + 1, cols);
}

std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value) {
    int** new_matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        new_matrix[i] = new int[cols + 1];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            new_matrix[i][j] = (*matrix)[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        new_matrix[i][cols] = value;
    }
    *matrix = new_matrix;
    return std::make_tuple(rows, cols + 1);
}

void delete_matrix(int*** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[](*matrix)[i];
    }
    delete[](*matrix);
}

void print(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}