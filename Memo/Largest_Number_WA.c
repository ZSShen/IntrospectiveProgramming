#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/* Mis-understand the problem, and use the bucket sort. */


#define COUNT_DIGIT(x) (floor(log10(x)) + 1)


typedef struct Node_ {
    int patch_num;
    int idx_origin;
    struct Node_ *next;
} Node;

typedef struct Bucket_ {
    Node *head;
    Node *tail;
} Bucket;


int get_max_digit_count(int *nums, int numsSize)
{
    int i;
    int max = nums[0];
    for (i = 1 ; i < numsSize ; i++)
        if (nums[i] > max)
            max = nums[i];

    return (max == 0)? 1 : COUNT_DIGIT(max);
}


int count_total_digit(int *nums, int numsSize)
{
    int total = 0;
    int i;
    for (i = 0 ; i < numsSize ; i++) {
        int num = nums[i];
        total += (num == 0)? 1 : COUNT_DIGIT(num);
    }

    return total;
}


Node* generate_list(int *nums, int numsSize, int max_digit_count)
{
    Node *head = NULL;
    Node *pred;

    int i;
    for (i = 0 ; i < numsSize ; i++) {
        int num = nums[i];
        int last_digit = num % 10;

        int cur_digit_count = (num == 0)? 1 : COUNT_DIGIT(num);
        int patch_num = num * pow(10, (max_digit_count - cur_digit_count));
        int j;
        for (j = max_digit_count - cur_digit_count - 1 ; j >= 0 ; j--)
            patch_num += last_digit * pow(10, j);

        Node *curr = (Node*)malloc(sizeof(Node));
        curr->patch_num = patch_num;
        curr->idx_origin = i;
        curr->next = NULL;

        if (!head) {
            head = curr;
            pred = curr;
        } else {
            pred->next = curr;
            pred = curr;
        }
    }

    return head;
}

void destroy_list(Node *list)
{
    Node *curr = list;
    Node *pred;

    while (curr) {
        pred = curr;
        curr = curr->next;
        free(pred);
    }
}

void distribute_bucket(Bucket *bucket, Node *list)
{
    Node *curr = list;
    while (curr) {
        int radix = curr->patch_num % 10;
        curr->patch_num /= 10;

        if (!(bucket[radix].head)) {
            bucket[radix].head = curr;
            bucket[radix].tail = curr;
        } else {
            (bucket[radix].tail)->next = curr;
            bucket[radix].tail = curr;
        }

        curr = curr->next;
    }
}

Node* merge_list(Bucket *bucket)
{
    Node *head = NULL;
    Node *pred;

    int i;
    for (i = 0 ; i < 10 ; i++) {
        if (!(bucket[i].head))
            continue;

        if (!head) {
            head = bucket[i].head;
            pred = bucket[i].tail;
        } else {
            pred->next = bucket[i].head;
            pred = bucket[i].tail;
        }

        bucket[i].head = bucket[i].tail = NULL;
    }
    pred->next = NULL;

    return head;
}

Node *reverse_list(Node *list)
{
    Node *curr = list;
    Node *pred = NULL;
    Node *succ;
    while (curr) {
        succ = curr->next;
        curr->next = pred;
        pred = curr;
        curr = succ;
    }
    list = pred;

    return list;
}


char *generate_final_string(int *nums, int total_digit, Node *list)
{
    char *sz = (char*)malloc(sizeof(char) * (total_digit + 1));
    memset(sz, 0, sizeof(char) * (total_digit + 1));

    int sz_len = 0;
    while (list) {
        int idx = list->idx_origin;
        int num = nums[idx];
        sprintf(sz + sz_len, "%d", num);
        sz_len = strlen(sz);
        list = list->next;
    }

    return sz;
}


char* largestNumber(int* nums, int numsSize)
{
    int max_digit_count = get_max_digit_count(nums, numsSize);
    Node *list = generate_list(nums, numsSize, max_digit_count);

    Bucket bucket[10];
    int i;
    for (i = 0 ; i < 10 ; i++)
        bucket[i].head = bucket[i].tail = NULL;

    for (i = 0 ; i < max_digit_count ; i++) {
        distribute_bucket(bucket, list);
        list = merge_list(bucket);
    }

    int total_digit = count_total_digit(nums, numsSize);
    list = reverse_list(list);
    char *sz = generate_final_string(nums, total_digit, list);

    if (sz[0] == '0')
        sz[1] = 0;

    destroy_list(list);
    return sz;
}

