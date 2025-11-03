/*REG NO:PA106/G/28713/25
NAME:RONNY KIMUTAI 
DESCRIPTION:PROGRAM TO DISPLAY INTEGERS AND STORE THEM
*/
#include <stdio.h>
#include <stdlib.h>

// Function to input 10 integers and store them in "input.txt"
void inputIntegersToFile() {
    FILE *file;
    int num;
    
    // Open file for writing
    file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error: Could not create input.txt file!\n");
        return;
    }
    
    printf("Enter 10 integers:\n");
    
    for (int i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &num);
        fprintf(file, "%d\n", num);
    }
    
    fclose(file);
    printf("10 integers successfully written to input.txt\n\n");
}

// Function to read integers, calculate sum and average, and write to output.txt
void processAndWriteResults() {
    FILE *inputFile, *outputFile;
    int num, sum = 0, count = 0;
    float average;
    
    // Open input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input.txt for reading!\n");
        return;
    }
    
    // Read integers and calculate sum
    while (fscanf(inputFile, "%d", &num) != EOF) {
        sum += num;
        count++;
    }
    fclose(inputFile);
    
    // Calculate average
    if (count > 0) {
        average = (float)sum / count;
    } else {
        average = 0;
    }
    
    // Open output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not create output.txt file!\n");
        return;
    }
    
    // Write results to output file
    fprintf(outputFile, "Sum: %d\n", sum);
    fprintf(outputFile, "Average: %.2f\n", average);
    fprintf(outputFile, "Count: %d\n", count);
    
    fclose(outputFile);
    printf("Results successfully written to output.txt\n\n");
}

// Function to display contents of both files
void displayFileContents() {
    FILE *file;
    char line[100];
    
    // Display input.txt contents
    printf("Contents of input.txt:\n");
    printf("=====================\n");
    
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input.txt for reading!\n");
        return;
    }
    
    int count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        count++;
        printf("Number %d: %s", count, line);
    }
    fclose(file);
    
    printf("\nContents of output.txt:\n");
    printf("======================\n");
    
    // Display output.txt contents
    file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open output.txt for reading!\n");
        return;
    }
    
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
    printf("\n");
}

int main() {
    int choice;
    
    printf("=== Integer File Processing Program ===\n\n");
    
    do {
        printf("Menu:\n");
        printf("1. Input 10 integers to input.txt\n");
        printf("2. Process integers and write results to output.txt\n");
        printf("3. Display contents of both files\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                inputIntegersToFile();
                break;
            case 2:
                processAndWriteResults();
                break;
            case 3:
                displayFileContents();
                break;
            case 4:
                printf("Program terminated. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter 1-4.\n\n");
        }
    } while (choice != 4);
    
    return 0;
}