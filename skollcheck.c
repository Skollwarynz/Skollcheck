#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> // Added for 'true' keyword

void print_list(char** events, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d %s\n",(i + 1),events[i]);
    }
    return;
}

char** create_event_list(int i) {
    char** mat = (char**)malloc(sizeof(char*) * i);
    for(int j = 0; j < i; j ++) {
        mat[j] = NULL;
    }
    return mat;
}

void add_event(char*** events, char* event, int size){ 
    //triple pointer to modify directly the array of events
    char** events_realloc = (char**)realloc(*events, size * sizeof(char*));

    if(events_realloc == NULL){
        perror("realloc issue");
        exit(2);
    }
    *events = events_realloc;
    (*events)[size - 1] = event;
}


void initialize_list(char** commitments, int i ) {
    char c;
    for(int k = 0; k < i; k++) {
    printf("Commitment %d: ",(k + 1));
    if(k == 0 ){
        getchar();
    }
    char buffer[256];
    fgets(buffer, 256, stdin);
    printf("\n");
    int len = strlen(buffer) + 1;
    char* commitment = (char*)malloc(sizeof(char) * len);
    commitment = strcpy(commitment,buffer);
    commitments[k] = commitment;
    }
}

void save_list(char** commitments, int size, char* path) {
    FILE* file = fopen(path, "w");
    for(int k = 0; k < size; k++) {
        fprintf(file, "%d.%s\n", (k +1), commitments[k]);
    }
    fclose(file);
}

int main(){
    // printf("Do you want to save your events?\n");
    char a[1];
    printf("How many events do you want to add?\n");
    int i;
    scanf("%d", &i);
    char ** commitments = create_event_list(i);
    initialize_list(commitments, i);
    while(true) {
            printf("I ====== %d\n",i);
            printf("Select the next action to do:");
            printf("\n1 - Add an event");
            printf("\n2 - Remove an event");
            printf("\n3 - Save events to a file");
            printf("\n4 - Load a file");
            printf("\n5 - Print the commitment list");
            printf("\n6 - Exit the program\n");
            scanf("%s",a);
            getchar();
            if (a[0] == '1') {
                printf("Insert your new task\n");
                char buffer[256];
                fgets(buffer, 256, stdin);
                printf("\n");
                int len = strlen(buffer) + 1;
                char* commitment = (char*)malloc(sizeof(char) * len);
                commitment = strcpy(commitment,buffer);
                add_event(&commitments, commitment, i + 1);
                i++;
            } else if (a[0] == '2') {
                printf("Service currently unavailable\n");
            } else if (a[0] == '3') {
                printf("Where do you want to save it?\n");
                char path[512];
                scanf("%s", path);
                save_list(commitments, i, path);
            } else if (a[0] == '4') {
                printf("Service currently unavailable\n");
            } else if (a[0] == '5') {
                print_list(commitments, i);
            } else if (a[0] == '6') {
                exit(1);
            } else {
                printf("Invalid selection.\n");
            }
        }
}
