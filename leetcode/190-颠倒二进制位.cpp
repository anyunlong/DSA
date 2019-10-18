struct Node {
    int value;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
    uint count;
};

bool isEmpty(struct Queue *queue) {
    return queue->count == 0;
}

void queue_in(struct Queue *queue, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    if (isEmpty(queue)) {
        queue->head = newNode;
    } else {
        queue->tail->next = newNode;
    }
    queue->tail = newNode;
    newNode->next = NULL;
    queue->count++;
}

bool queue_out(struct Queue *queue, int *outBit) {
    if (isEmpty(queue)) {
        return false;
    } else {
        queue->count--;
        *outBit = queue->head->value;
        struct Node *freeNode = queue->head;
        queue->head = queue->head->next;
        free(freeNode);
        return true;
    }
}

uint32_t reverseBits(uint32_t n) {
    uint32_t num = 1;
    int bitsCount = 32;

    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->count = 0;
    for (int index = 0; index < bitsCount; ++index) {
        int lastBit = n & num;
        queue_in(queue, lastBit);
        n = n >> 1;
    }

    num = 0;
    for (int index = 0; index < bitsCount; ++index) {
        int outBit = 0;
        queue_out(queue, &outBit);
        num = num | (uint32_t)outBit;
        if ((bitsCount - 1) == index) {

        } else {
            num = num << 1;
        }
    }

    return num;
}
