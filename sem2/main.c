#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Document {
    int id;
    char name[7];
    int lines_total;
    int lines_left;
    struct Document* next;
} document;

typedef struct Printer {
    int id;
    int time;
    struct Document* current_document;
    struct Printer* next;
} printer;

printer* init_printer(int id, int time) {
    printer* new_printer = (printer*)malloc(sizeof(printer));
    if (new_printer == NULL) {
        printf("Error allocating memory for printer.\n");
        exit(EXIT_FAILURE);
    }

    new_printer->id = id;
    new_printer->time = time;
    new_printer->current_document = NULL;
    new_printer->next = NULL;
    return new_printer;
}

printer* init_list_printers(int nr_of_printers) {
    printer* head = init_printer(0, 3);
    printer* current = head;
    int counter = 1;
    while (counter < nr_of_printers) {
        printer* new_printer = init_printer(counter, 3);
        current->next = new_printer;
        current = current->next;
        counter++;
    }
    return head;
}

document* init_document(int id, const char* name, int lines_total, int lines_left) {
    document* new_document = (document*)malloc(sizeof(document));
    if (new_document == NULL) {
        printf("Error allocating memory for document.\n");
        exit(EXIT_FAILURE);
    }
    new_document->id = id;
    strncpy(new_document->name, name, sizeof(new_document->name) - 1);
    new_document->name[sizeof(new_document->name) - 1] = '\0';  // Ensure null-terminated string
    new_document->lines_total = lines_total;
    new_document->lines_left = lines_left;
    new_document->next = NULL;
    return new_document;
}

document* init_documents_list(FILE* file) {
    document* head = NULL;
    document* current = NULL;
    int id, lines_total, lines_left;
    char name[7];

    while (fscanf(file, "%d %6s %d %d\n", &id, name, &lines_total, &lines_left) == 4) {
        document* new_document = init_document(id, name, lines_total, lines_left);
        if (head == NULL) {
            head = new_document;
            current = head;
        } else {
            current->next = new_document;
            current = current->next;
        }
    }
    return head;
}

void distribute_documents(document* head_doc, printer* head_printer) {
    document* current_doc = head_doc;
    printer* current_printer = head_printer;
    while (current_doc != NULL && current_printer != NULL) {
        current_printer->current_document = current_doc;
        current_doc = current_doc->next;
        current_printer = current_printer->next;
    }
}

void print_documents(printer* head) {
    int all_documents_printed = 0;
    while (!all_documents_printed) {
        all_documents_printed = 1;  // Assume all documents are printed until proven otherwise
        for (printer* iterator = head; iterator != NULL; iterator = iterator->next) {
            if (iterator->current_document != NULL) {
                if (iterator->current_document->lines_left > 0) {
                    printf("Printer %d prints document %s line %d\n",
                           iterator->id, iterator->current_document->name,
                           iterator->current_document->lines_total - iterator->current_document->lines_left + 1);
                    iterator->current_document->lines_left--;
                    all_documents_printed = 0;  // Set to 0 if any document is not fully printed
                } else {
                    iterator->current_document = iterator->current_document->next;
                    if (iterator->current_document != NULL) {
                        printf("Printer %d starts printing next document %s\n", iterator->id, iterator->current_document->name);
                        all_documents_printed = 0;  // Set to 0 if any document is not fully printed
                    } else {
                        printf("Printer %d has no more documents in queue\n", iterator->id);
                    }
                }
            }
        }
    }
}

int main() {
    FILE* file = fopen("C:\\Users\\nicud\\Desktop\\SDA\\sem2\\documents.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }
    int nr_of_printers = 10;

    printer* list_of_printers = init_list_printers(nr_of_printers);
    document* list_of_documents = init_documents_list(file);

    distribute_documents(list_of_documents, list_of_printers);
    print_documents(list_of_printers);

    fclose(file);
    return 0;
}
