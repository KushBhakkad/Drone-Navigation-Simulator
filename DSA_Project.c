#include<stdio.h>
#include<stdlib.h>

// Define a struct to represent a command to the drone
struct structure{
    int x, y;           // x => Command; y => Value
};

// Define a stack to hold the commands
struct structure stack[100];
int top = -1;           // Declaring top of stack = -1

// Push a command onto the stack
void stack_push() {
    printf("Enter command type (1 = move forward, 2 = turn left, 3 = turn right, 4 = hover): ");
    scanf("%d", &stack[++top].x);
    printf("Enter value: ");
    scanf("%d", &stack[top].y);
}

// Simulate the execution of a command
void execute_command(int a, int b) {
    switch (a) {
        case 1: // Move forward
            printf("Moving forward %d meters.\n", b);
            break;
        case 2: // Turn left
            printf("Turning left %d degrees.\n", b);
            break;
        case 3: // Turn right
            printf("Turning right %d degrees.\n", b);
            break;
        case 4: // Hover
            printf("Hovering for %d seconds.\n", b);
            break;
        default:
            printf("Invalid command type.\n");
            break;
    }
}

// Monitor the drone's status
void monitor_status() {
    printf("\n\nMonitoring status...\n");
    // TODO: Implement code to monitor the drone's status
}

int main(){
    int n;

    // Get the number of commands
    printf("Enter the number of commands: ");
    scanf("%d", &n);

    // Get the commands and push them onto the stack
    for (int i = 0; i < n; i++){
        stack_push();
    }

    // Executing the commands in order in which they are popped off
    printf("\nExecuting commands...\n\n");
    while (top != -1){
        execute_command(stack[top].x, stack[top].y);
        --top;
    }

    // Monitor the drone's status
    monitor_status();

    return 0;
}
