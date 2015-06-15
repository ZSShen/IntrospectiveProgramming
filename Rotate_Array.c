void reverse(int *arr, int size)
{
    int bound = size / 2;
    int idx = 0;
    int temp;
    while (idx < bound) {
        temp = arr[idx];
        arr[idx] = arr[size - idx - 1];
        arr[size - idx - 1] = temp;
        idx++;
    }
}

void rotate(int *arr, int size, int ofst)
{
    ofst = ofst % size;
    if (ofst == 0)
        return;

    reverse(arr, size);
    reverse(arr, ofst);
    reverse(arr + ofst, size - ofst);
}