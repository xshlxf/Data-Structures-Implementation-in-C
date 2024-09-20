//heap-based priority queue
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct heap_item{
    int priority;
    int data;
} heap_item;
   
heap_item treeNodes[MAXSIZE];

int last = 0;

void swap(int index, int parent){
heap_item temp = treeNodes[index];
treeNodes[index] = treeNodes[parent];
treeNodes[parent] = temp;
}

void reHeapUp(int index){
int parent = (int)(index-1)/2;
while(treeNodes[index].priority > treeNodes[parent].priority){
swap(index, parent);
}
}

void printPriorityArray() {
    int i;
    for (i = 0; i < last; i++) {
        if (treeNodes[i].priority > 0) {
            printf("%d ", treeNodes[i].priority); // Imprimir el campo 'priority' en lugar de la estructura completa
        }
    }
}

void printItemArray() {
    int i;
    for (i = 0; i < last; i++) {
        if (treeNodes[i].data > 0) {
            printf("%d ", treeNodes[i].data); // Imprimir el campo 'data' en lugar de la estructura completa
        }
    }
}

void showPriorityHeap(){
for(int i=0; i<last; i++){
    if(treeNodes[i].priority > 0){
        printf("\nNode: %d ", treeNodes[i].priority);
        int li = 2*i+1;
        int ri = 2*i+2;
        if(treeNodes[li].priority > 0) printf("Left: %d ", treeNodes[li].priority);
        if(treeNodes[ri].priority > 0)printf("Right: %d ", treeNodes[ri].priority);
    }
}
}

void showItemHeap(){
for(int i=0; i<last; i++){
    if(treeNodes[i].priority > 0){
    printf("\nNode: %d ", treeNodes[i].data);
    int li = 2*i+1;
    int ri = 2*i+2;
        if(treeNodes[li].data > 0) printf("Left: %d ", treeNodes[li].data);
        if(treeNodes[ri].data > 0)printf("Right: %d ", treeNodes[ri].data);
    }
}
}

void reHeapDown(int parent){
int left = 2*parent+1;
int right = 2*parent+2;
while(treeNodes[parent].priority < treeNodes[left].priority || treeNodes[parent].priority < treeNodes[right].priority){
    if(treeNodes[left].priority > treeNodes[right].priority){
        swap(parent, left);
        parent = left;
    }else{
        swap(parent, right);
        parent = right;
    }
    left = 2*parent+1;
    right = 2*parent+2;
}
treeNodes[parent].priority = -1; //invalid the last node
}

void enqueue(int item, int priority){
treeNodes[last].data = item;
treeNodes[last].priority = priority;
reHeapUp(last);
last++;
}

void dequeue(){
    last--;
    if(last > 0) {
    treeNodes[0].priority = 0;
    int parent = 0;
    reHeapDown(parent);
}else printf("Queue is empty");

}
int main(){
    int ans = 0;
    int item;
    int priority;
    do{
        printf("\n1. Enqueue\n2. Dequeue\n3. Show Priority Heap\n4. Show Queue\n5. End \nEnter choice: ");
        scanf("%d", &ans); 
        switch(ans){
            
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(item, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                showPriorityHeap();
                break;
            case 4:
                printItemArray();
                break;
            case 5:
                printf("Bye");
                break;
            default:
                printf("Invalid choice");
        }

    }while(ans != 5);


    return 0;
}