
typedef struct Node_ {
    int node_id;
    struct Node_ *next;
} Node;


#define WHITE       (0)
#define GRAY        (1)
#define BLACK       (2)


void init_graph(int num_course, int **preq, int count_row, Node ***p_adj_list, char **p_visit)
{
    *p_adj_list = (Node**)malloc(sizeof(Node*) * num_course);
    *p_visit = (char*)malloc(sizeof(char) * num_course);

    Node **adj_list = *p_adj_list;
    char *visit = *p_visit;
    int i;
    for (i = 0 ; i < num_course ; i++) {
        adj_list[i] = NULL;
        visit[i] = WHITE;
    }

    for (i = 0 ; i < count_row ; i++) {
        int node_src = preq[i][0];
        int node_tge = preq[i][1];

        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->node_id = node_tge;
        if (!(adj_list[node_src])) {
            new_node->next = NULL;
            adj_list[node_src] = new_node;
        } else {
            new_node->next = adj_list[node_src];
            adj_list[node_src] = new_node;
        }
    }

    return;
}

void deinit_graph(int num_course, Node **adj_list, char *visit)
{
    int i;
    for (i = 0 ; i < num_course ; i++) {
        Node *curr = adj_list[i];
        Node *pred;
        while (curr) {
            pred = curr;
            curr = curr->next;
            free(pred);
        }
    }

    free(adj_list);
    free(visit);
    return;
}

bool find_back_edge(Node **adj_list, char *visit, int node_src)
{
    visit[node_src] = GRAY;
    bool back_edge = false;

    Node *rover = adj_list[node_src];
    while (rover) {
        int node_tge = rover->node_id;
        if (visit[node_tge] == WHITE) {
            back_edge = find_back_edge(adj_list, visit, node_tge);
            if (back_edge)
                break;
        } else if (visit[node_tge] == GRAY) {
            back_edge = true;
            break;
        }
        rover = rover->next;
    }

    visit[node_src] = BLACK;
    return back_edge;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize)
{
    Node **adj_list;
    char *visit;

    /* Early return for no prerequisites. */
    if (prerequisitesRowSize == 0)
        return true;

    init_graph(numCourses, prerequisites, prerequisitesRowSize, &adj_list, &visit);

    /* DFS driver loop. */
    bool back_edge = false;
    int i;
    for (i = 0 ; i < numCourses ; i++) {
        if (visit[i] != WHITE)
            continue;
        back_edge = find_back_edge(adj_list, visit, i);
        if (back_edge)
            break;
    }

    deinit_graph(numCourses, adj_list, visit);
    return (back_edge)? false : true;
}