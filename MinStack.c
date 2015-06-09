typedef struct {
    int capacity;
    int idx_top;
    int *arr_elem;
    int *arr_ref;
} MinStack;


#define MIN(a, b)   (((a) < (b))? (a) : (b))
#define INVALID     (0)


void minStackCreate(MinStack *stack, int maxSize) {
    stack->arr_elem = (int*)malloc(sizeof(int) * maxSize);
    stack->arr_ref = (int*)malloc(sizeof(int) * maxSize);
    stack->capacity = maxSize;
    stack->idx_top = 0;
}

void minStackPush(MinStack *stack, int elem_new) {
    if (stack->idx_top == stack->capacity)
        return;

    int idx = stack->idx_top;
    stack->arr_elem[idx] = elem_new;
    if (idx == 0)
        stack->arr_ref[idx] = elem_new;
    else {
        int elem_old = stack->arr_ref[idx - 1];
        stack->arr_ref[idx] = MIN(elem_old, elem_new);
    }

    stack->idx_top++;
}

void minStackPop(MinStack *stack) {
    if (stack->idx_top == 0)
        return;

    stack->idx_top--;
}

int minStackTop(MinStack *stack) {
    if (stack->idx_top > 0) {
        int idx = stack->idx_top;
        return stack->arr_elem[idx - 1];
    }
    return INVALID;
}

int minStackGetMin(MinStack *stack) {
    if (stack->idx_top > 0) {
        int idx = stack->idx_top;
        return stack->arr_ref[idx - 1];
    }
    return INVALID;
}

void minStackDestroy(MinStack *stack) {
    free(stack->arr_elem);
    free(stack->arr_ref);
}