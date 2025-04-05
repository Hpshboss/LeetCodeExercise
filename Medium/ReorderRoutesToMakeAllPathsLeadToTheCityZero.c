#define ORGPATH 1
#define NOTORGPATH 0

struct edge {
    int to;
    int org;  // 0: not original path; 1: original path
    struct edge* next;
};

void addEdgeToGraph(struct edge** graph, int from, int to, int original) {
    struct edge* next = NULL;
    if (graph[from] == NULL)
    {
        graph[from] = calloc(1, sizeof(struct edge));
    }
    else
    {
        next = calloc(1, sizeof(struct edge));
        next->to = graph[from]->to;
        next->org = graph[from]->org;
        next->next = graph[from]->next;
    }
    
    graph[from]->to = to;
    graph[from]->org = original;
    graph[from]->next = next;

    return;
}

void dfs(struct edge** graph, int p, int* cnt, int* visited) {
    visited[p] = 1;
    for (struct edge* e = graph[p]; e != NULL; e = e->next) {
        if (visited[e->to] == 0)
        {
            if (e->org == ORGPATH)
                (*cnt) += 1;
            dfs(graph, e->to, cnt, visited);
        }
    }

    return;
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    struct edge** graph = calloc(50000, sizeof(struct edge*));
    int count;
    int from = 0;
    int to = 0;
    int* visited = calloc(50000, sizeof(int));

    for (int i = 0; i < connectionsSize; i++)
    {
        from = connections[i][0];
        to = connections[i][1];

        addEdgeToGraph(graph, from, to, ORGPATH);
        addEdgeToGraph(graph, to, from, NOTORGPATH);
    }

    dfs(graph, 0, &count, visited);

    return count;
}
