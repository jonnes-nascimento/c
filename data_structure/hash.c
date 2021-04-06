/*
    Description:
        Implementation of a hash table in C (to learning the concepts behind the algorithm).
    Author:
        Jonnes Nascimento
    Date:
        April, 6, 2021
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// defines
#define HASH_SIZE 100

// type definitions
typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;


// Hash is a array of Node
typedef struct {
    Node *list[HASH_SIZE];
} Hash;

// prototypes
Node * createNode(char *key, char *value);
void insertNode(Hash *hash, char *key, char *value);
char * searchKey(Hash *hash, char *key);
unsigned int hashCode(char *key);

int main(int argc, char *argv[]) {

    // this code tests the hashCode function
    //char key[10];
    //printf("Key: ");
    //scanf("%s", &key);
    //printf("Key: %s  Hash: %u", key, hashCode(key));

    Hash *hash = (Hash *) malloc(sizeof(Hash));

    insertNode(hash, "name", "Jonnes"); // insertNode is the same of hash["name"] = "Jonnes"
    insertNode(hash, "phone", "+55 11 98765-4321");
    insertNode(hash, "name", "Foo");
    insertNode(hash, "phone", "Bar");

    printf("\n");

    printf("Name: %s\n", searchKey(hash, "name")); // searchKey is the same of hash["name"]
    printf("Phone: %s\n", searchKey(hash, "phone"));
    printf("Test: %s\n", searchKey(hash, "test"));

    return 0;
}

// implements the hash generation algorithm (djb2 method)
unsigned int hashCode(char *key) {
    unsigned long hash = 7777; // seed
    unsigned int c;

    while (c = *key++) { // while is not the end of string (c != \0)
        hash = ((hash << 5) + hash) + c; // (hash << 5) + hash  === hash * 32
    }

    return hash % HASH_SIZE; // how the hash can be greater than HASH_SIZE, the module operation ensures that the value is less than HASH_SIZE
}

// this functions keeps the node.next parameter as NULL
Node * createNode(char *key, char *value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->value = value;

    return node;
}

void insertNode(Hash *hash, char *key, char *value) {
    // defines the index how the hash code of the key parameter
    unsigned int index = hashCode(key);

    // creates a new node
    Node *new = createNode(key, value);

    // verifies if the hash[index] contains a node already
    if (hash->list[index] == NULL) {        
        // inserts the new node in the hash table
        printf("Creating a new node...\n");
        hash->list[index] = new;
    } else { // finds the last node on hash[index] position and append a new one on that position
        printf("Adding a new node...\n");
        Node *node = hash->list[index];

        while (node->next != NULL) {
            node = node->next;
        }

        // adds the new node on the last position
        node->next = new;
    }
}

char * searchKey(Hash *hash, char *key) {
    // generates the hash of the key parameter
    unsigned int index = hashCode(key);

    // go to index position on the hash.list
    Node *node = hash->list[index];

    // here, finds by key (the first one) and return the value
    if(node) { // check if hash->list[index] is empty
        while(strcmp(node->key, key) != 0) {
            node = node->next;
        }

        return node->value;
    }
    
    return "";
}