#include <stdio.h>
#include <string.h>

// DFA transition function
int dfa_transition(int current_state, char input) {
    switch (current_state) {
        case 0:
            if (input == 'a') {
                return 1;  // Move to state 1 if 'a' is encountered
            } else {
                return -1; // Invalid transition, go to error state
            }
        case 1:
            if (input == 'a') {
                return 1;  // Stay in state 1 if 'a' is encountered
            } else {
                return -1; // Invalid transition, go to error state
            }
        default:
            return -1; // Error state
    }
}

// DFA simulation function
int simulate_dfa(const char* input) {
    int current_state = 0,i; // Initial state
    
    for (i = 0; i < strlen(input); i++) {
        char symbol = input[i];
        int result = dfa_transition(current_state, symbol);

        if (result == -1) {
            return 0; // String is not accepted by DFA, it is rejected
        }

        current_state = result;
    }

    // Check if the final state is the accepting state (state 1)
    return (current_state == 1);
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (simulate_dfa(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}

