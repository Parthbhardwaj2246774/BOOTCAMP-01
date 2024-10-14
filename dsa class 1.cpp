#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of the stack

// Stack structure
struct Stack {
    int arr[MAX];  // Array to store stack elements
    int top;       // Variable to track the top of the stack
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;  // Stack is initially empty
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to add an element to the stack (Push)
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }
    stack->top++;               // Increment top to next position
    stack->arr[stack->top] = value;  // Add value to the top
    printf("Pushed %d to stack\n", value);
}

// Function to remove an element from the stack (Pop)
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! No elements to pop.\n");
        return -1;  // Return -1 if stack is empty
    }
    int poppedValue = stack->arr[stack->top];  // Get the top element
    stack->top--;  // Decrease the top index
    printf("Popped %d from stack\n", poppedValue);
    return poppedValue;
}

// Function to view the top element of the stack (Peek)
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No top element.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Function to display stack elements
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

// Main function to test the stack implementation
int main() {
    struct Stack stack;  // Create a stack
    initialize(&stack);  // Initialize the stack

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);  // Output: 10 20 30

    pop(&stack);
    display(&stack);  // Output: 10 20

    int topElement = peek(&stack);
    if (topElement != -1) {
        printf("Top element is: %d\n", topElement);  // Output: 20
    }

    return 0;
}

