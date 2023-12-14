int* new_array(int len, int value) {
    int* array = new int[len];
    for (int i = 0; i < len; i++) {
        array[i] = value;
    }
    return array;
}

int set_new_length(int** array, int old_len, int new_len) {
    int* saved = new int[old_len];
    for (int i = 0; i < old_len; i++) {
        saved[i] = (*array)[i];
    }
    *array = new int[new_len];
    for (int i = 0; i < new_len; i++) {
        if (i < old_len) {
            (*array)[i] = saved[i];
        }
        else {
            (*array)[i] = 0;
        }
    }
    return new_len;
}

int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array) {
    int* saved = new int[len_dest_array];
    for (int i = 0; i < len_dest_array; i++) {
        saved[i] = (*dest_array)[i];
    }
    *dest_array = new int[len_dest_array + len_src_array];
    for (int i = 0; i < len_dest_array + len_src_array; i++) {
        if (i < len_dest_array) {
            (*dest_array)[i] = saved[i];
        }
        else {
            (*dest_array)[i] = src_array[i - len_dest_array];
        }
    }
    return len_dest_array + len_src_array;
}

int dot(const int* a, const int* b, int len) {
    int result = 0;
    for (int i = 0; i < len; i++) {
        result += a[i] * b[i];
    }
    return result;
}

int* find(int* array, int len, int value) {
    int* result = nullptr;
    for (int i = 0; i < len; i++) {
        if (array[i] == value) {
            result = &array[i];
            break;
        }
    }
    return result;
}

void delete_array(int** array) {
    if (*array != nullptr) {
        delete[] *array;
        *array = nullptr;
    }
}