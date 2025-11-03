 #include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_QUEUE_SIZE 50 
#define NAME_SIZE 50 
#define COMPLAINT_SIZE 100 
// Global arrays to simulate the queue 
char names[MAX_QUEUE_SIZE][NAME_SIZE]; 
char complaints[MAX_QUEUE_SIZE][COMPLAINT_SIZE]; 
int triageLevels[MAX_QUEUE_SIZE]; 
int currentSize = 0; 
 
// Function to check if the queue is full 
int isFull() { 
    return currentSize == MAX_QUEUE_SIZE; 
} 
 
// Function to check if the queue is empty 
int isEmpty() { 
    return currentSize == 0; 
} 
 
// Function to insert a new patient while maintaining priority order 
void maintainPriority(char name[], char complaint[], int triageLevel) { 
    int i = currentSize - 1; 
 
    // Shift elements with LOWER priority (higher triageLevel) to the right 
    while (i >= 0 && triageLevels[i] > triageLevel) { 
        strcpy(names[i + 1], names[i]); 
        strcpy(complaints[i + 1], complaints[i]); 
        triageLevels[i + 1] = triageLevels[i]; 
        i--; 
    } 
 
    // Insert the new patient data 
    strcpy(names[i + 1], name); 
    strcpy(complaints[i + 1], complaint); 
    triageLevels[i + 1] = triageLevel; 
} 
 
// Function to register a new patient 
void registerPatient() { 
    char name[NAME_SIZE]; 
    char complaint[COMPLAINT_SIZE]; 
    int triageLevel; 
    char buffer[COMPLAINT_SIZE]; 
 
    if (isFull()) { 
        printf("\nQueue is full! Cannot register more patients.\n"); 
        return; 
    } 
 
    printf("\n--- Register New Patient ---\n"); 
 
    printf("Enter patient name: "); 
    scanf("%s", name); 
 
    printf("Enter chief complaint (e.g., Chest Pain, Fever): "); 
    while (getchar() != '\n'); // clear buffer 
    fgets(buffer, COMPLAINT_SIZE, stdin); 
    buffer[strcspn(buffer, "\n")] = 0; // remove newline 
    strcpy(complaint, buffer); 
 
    printf("Enter Triage Level (1-5, 1=URGENT, 5=NON-URGENT): "); 
    scanf("%d", &triageLevel); 
 
    if (triageLevel < 1 || triageLevel > 5) { 
        printf("Invalid Triage Level (%d). Defaulting to 5 (Non-Urgent).\n", triageLevel); 
        triageLevel = 5; 
    } 
 
    // Insert patient with priority 
    maintainPriority(name, complaint, triageLevel); 
    currentSize++; 
 
    printf("\nPatient %s registered with Triage Level %d. Added to queue successfully!\n",  
           name, triageLevel); 
} 
 
// Function to call the next highest-priority patient 
void callNextPatient() { 
    if (isEmpty()) { 
        printf("\nNo patients currently in the triage queue.\n"); 
        return; 
    } 
 
    printf("\n--- NEXT PATIENT TO BE TREATED ---\n"); 
    printf("Name: %s\n", names[0]); 
    printf("Triage Level: %d (Highest Priority)\n", triageLevels[0]); 
    printf("Chief Complaint: %s\n", complaints[0]); 
    printf("Please direct this patient to the treatment area immediately.\n"); 
 
    // Remove the first patient by shifting others forward 
    for (int i = 0; i < currentSize - 1; i++) { 
        strcpy(names[i], names[i + 1]); 
        strcpy(complaints[i], complaints[i + 1]); 
        triageLevels[i] = triageLevels[i + 1]; 
    } 
    currentSize--; 
} 
 
// Main function 
int main() { 
    int choice; 
 
    do { 
        printf("\n*** Hospital Emergency Triage System ***\n"); 
        printf("1. Register New Patient\n"); 
        printf("2. Call Next Patient for Treatment\n"); 
        printf("3. Exit\n"); 
        printf("Enter choice: "); 
 
        if (scanf("%d", &choice) != 1) { 
            while (getchar() != '\n'); 
            choice = 0; 
        } 
 
        switch (choice) { 
            case 1: 
                registerPatient(); 
                break; 
            case 2: 
                callNextPatient(); 
                break; 
            case 3: 
                printf("Exiting Triage System...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while (choice != 3); 
 
    return 0; 
}
