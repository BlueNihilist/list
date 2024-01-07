struct lnode {
    struct lnode *next;
    void *data;
};

typedef struct lnode * list_t;

// Returns pointer to head
list_t *lcreate(void *data);

void lfree(list_t *list);

// Returns 0 on success, -1 on failure
int lpush(list_t *list, void *data);

void *lpop(list_t *list);