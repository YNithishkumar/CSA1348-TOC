#include <stdio.h>
#include <string.h>

// Function to derive strings based on the CFG
void derive(char* input, int index) {
    if (input[index] == '\0') {
        return; // End of string
    }

    if (input[index] == '0') {
        printf("S -> 0A1\n");
        input[index] = 'A';
        derive(input, index + 1);
    } else if (input[index] == '1' && input[index + 1] == '\0') {
        printf("S -> 0A1\n");
        input[index] = 'A';
        input[index + 1] = '1';
        derive(input, index + 2);
    } else {
        printf("A -> e\n");
    }
}

// Function to check if the string belongs to the CFG language
int belongs_to_cfg(char* input) {
    derive(input, 0);

    return (strcmp(input, "A1") == 0); // Check if the derived string is 'A1'
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (belongs_to_cfg(input)) {
        printf("String belongs to the CFG language.\n");
    } else {
        printf("String does not belong to the CFG language.\n");
    }

    return 0;
}

