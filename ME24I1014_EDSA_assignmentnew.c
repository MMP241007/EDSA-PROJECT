#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Part a) Part Delivery and Robot Arm (Queue and Stack)
#define MAX_PARTS 6

typedef struct {
    char* parts[MAX_PARTS];//char array
    int front, rear;
} Queue;

typedef struct {
    char* parts[MAX_PARTS];
    int top;
} Stack;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

void enqueue(Queue* q, char* part) {
    if (q->rear == MAX_PARTS - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->parts[++q->rear] = part;
}

char* dequeue(Queue* q) {
    if (q->front == -1) return NULL;
    char* part = q->parts[q->front];
    if(q->front == q->rear) 
    {
        q->front = q->rear = -1;
    }
    else {
        q->front++;
    }
    return part;
}

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, char* part) {
    if (s->top == MAX_PARTS - 1) {
        printf("Stack is full\n");
        return;
    }
    s->parts[++s->top] = part;
}

char* pop(Stack* s) {
    if (s->top == -1) return NULL;
    return s->parts[s->top--];
}

// Part b) Assembly Storage Unit (Array)
#define GARAGE_CAPACITY 8
char* garage[GARAGE_CAPACITY];
int garageCount = 0;

void addToGarage(char* car) {
    if (garageCount == GARAGE_CAPACITY) {
        printf("Garage full! Shipping out oldest: %s\n", garage[0]);
        // Shift all cars left
        for (int i = 0; i < GARAGE_CAPACITY - 1; i++) {
            garage[i] = garage[i + 1];
        }
        garageCount--;
    }
    garage[garageCount++] = car;
    printf("Added to garage: %s\n", car);
}

// Part c) Repair and Upgrade Tracker (Linked Lists)
typedef struct SingleNode {
    char* car;
    struct SingleNode* next;
} SingleNode;

typedef struct DoubleNode {
    char* car;
    struct DoubleNode* next;
    struct DoubleNode* prev;
} DoubleNode;

SingleNode* defectiveList = NULL;//head pointer of defective list
DoubleNode* repairedList = NULL;//head pointer of repaired list

void addToDefectiveList(char* car) {
    SingleNode* newNode = (SingleNode*)malloc(sizeof(SingleNode));
    newNode->car = car;
    newNode->next = defectiveList;
    defectiveList = newNode;
    printf("Added to defective list: %s\n", car);
}

void moveToRepairedList(char* car) {
    // Remove from defective list
    SingleNode *temp = defectiveList, *prev = NULL;
    while (temp != NULL && strcmp(temp->car, car) != 0) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {//if car not found in list
        printf("Car %s not found in defective list\n", car);
        return;
    }
    
    if (prev == NULL) {
        defectiveList = temp->next;
    }else{
        prev->next = temp->next;
    } 
    
    // Add to repaired list
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->car = car;
    newNode->next = repairedList;
    newNode->prev = NULL;
    
    if (repairedList != NULL) {
        repairedList->prev = newNode;
    }
    repairedList = newNode;
    
    free(temp);//freeing defective
    printf("Moved to repaired list: %s\n", car);
}

// Part d) VIP Priority Upgrades (Circular Linked List)
typedef struct CircularNode {
    char* car;
    struct CircularNode* next;
} CircularNode;

CircularNode* vipList = NULL;

void addToVIPList(char* car) {
    CircularNode* newNode = (CircularNode*)malloc(sizeof(CircularNode));
    newNode->car = car;
    
    if (vipList == NULL) {
        newNode->next = newNode;
        vipList = newNode;
    } else {
        CircularNode* temp = vipList;
        while (temp->next != vipList) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = vipList;
    }
    printf("Added to VIP list: %s\n", car);
}

void traverseVIPList(int rounds) {
    if (vipList == NULL) {
        printf("VIP list is empty\n");
        return;
    }
    
    printf("Traversing VIP list for %d rounds:\n", rounds);
    CircularNode* temp = vipList;
    int count = 0;
    
    do {
        printf("VIP car: %s\n", temp->car);
        temp = temp->next;
        if (temp == vipList) {
            count++;
            if (count < rounds) printf("--- Starting round %d ---\n", count + 1);
        }
    } while (count < rounds);
}

int main() 
{
    printf("=== Robotic Assembly Line Simulator ===\n\n");
    
    // Part a) Part Delivery and Robot Arm
    printf("\n--- Part a) Part Delivery and Robot Arm ---\n");
    Queue conveyorBelt;
    Stack assemblyStack;
    initQueue(&conveyorBelt);//initialising both
    initStack(&assemblyStack);
    
    int choice;
    printf("Do you want to start the process by adding them to conveyor belt: \n1.Engine\n2.Chassis\n3.Wheels\n4.Doors\n5.Battery\n6.Hood\nYes(1) or No(0)");
    scanf("%d",&choice);

    if(choice==1)
    {
        // Enqueue parts
        enqueue(&conveyorBelt, "Engine");
        enqueue(&conveyorBelt, "Chassis");
        enqueue(&conveyorBelt, "Wheels");
        enqueue(&conveyorBelt, "Doors");
        enqueue(&conveyorBelt, "Battery");
        enqueue(&conveyorBelt, "Hood");
    
    
        // Process parts
        printf("\nRobot arm processing parts:\n");
        char* part;
        while ((part = dequeue(&conveyorBelt)) != NULL) {
            printf("Robot arm picked: %s\n", part);
            push(&assemblyStack, part);
        }
        
        // Assembly order
        printf("\nAssembly order:\n");
        while ((part = pop(&assemblyStack)) != NULL) {
            printf("Assembling: %s\n", part);
        }
        
        // Part b) Assembly Storage Unit
            
    printf("\n--- Part b) Assembly Storage Unit ---\n");
    char* carNames[] = {
        "Car1", "Car2", "Car3", "Car4", "Car5",
        "Car6", "Car7", "Car8", "Car9", "Car10"
    };

    for (int i = 0; i < 10; i++) {
        addToGarage(carNames[i]);
    }

        
        // Part c) Defective Prototype Tracker
        printf("\n--- Part c) Defective Prototype Tracker ---\n");
        addToDefectiveList("Car3");
        addToDefectiveList("Car6");
        moveToRepairedList("Car3");
        
        // Part d) VIP Priority Upgrades
        printf("\n--- Part d) VIP Priority Upgrades ---\n");
        addToVIPList("Car1");
        addToVIPList("Car5");
        traverseVIPList(2);
    }
    else
    {
        printf("\nProcess Terminated !!");
    }
    
    return 0;
}