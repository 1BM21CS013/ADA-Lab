#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TABLE_SIZE 5

int hashTable[TABLE_SIZE];
int insertedTable[TABLE_SIZE];

void init()
{
    int i;
    for(i = 0 ; i < TABLE_SIZE ; i++)
        insertedTable[i] = 0;
}
void printInsertedTable()
{
    int i;
    for(i = 0 ; i < TABLE_SIZE ; i++)
        printf("key: %d, inserted: %d\n",i,insertedTable[i]);
}
void linearProbeInsert(int n)
{
    int key = n % TABLE_SIZE;
    int curr;
    // do linear probing
    if(insertedTable[key])
    {
        curr = key;
        do{
            key = (key + 1) % TABLE_SIZE;
        }while(insertedTable[key] && key != curr);
        if(curr == key)
            printf("HASH TABLE IS FULL\n");
        else
        {
            hashTable[key] = n;
            insertedTable[key] = 1;
        }
    }

    //insert it
    else
    {
        hashTable[key] = n;
        insertedTable[key] = 1;
    }
}
void quadProbeInsert(int n)
{
    int key = n % TABLE_SIZE;
    int curr;
    int i;
    // do quadratic probing
    if(insertedTable[key])
    {
        i = 0;
        curr = key;
        do{
            key = (key + (2*i + 1)) % TABLE_SIZE;
            i++;
        }while(insertedTable[key] && key != curr);
        if(curr == key)
            printf("HASH TABLE IS FULL\n");
        else
        {
            hashTable[key] = n;
            insertedTable[key] = 1;
        }
    }

    //insert it
    else
    {
        hashTable[key] = n;
        insertedTable[key] = 1;
    }
}
void doubleHashInsert(int n)
{
    // do double hashing
}
void printHashTable()
{
    int i;
    for(i = 0; i < TABLE_SIZE ; i++)
    {
        printf("Key: %d, Value: ",i);
        if(insertedTable[i])
            printf("%d\n",hashTable[i]);
        else
            printf("empty\n");
    }
}

int main()
{
    int choice;
    int val;
    init();
    while(1)
    {
        printf("HASH MENU\n");
        printf("1. Insert element (Linear probing)\n");
        printf("2. Insert element (Quadratic probing)\n");
        printf("3. Insert element (Double probing)\n");
        printf("4. Find element\n");
        printf("5. Print hash table\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d",&val);
            linearProbeInsert(val);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d",&val);
            quadProbeInsert(val);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d",&val);
            doubleHashInsert(val);
            break;
        case 4:
            printf("Enter value: ");
            scanf("%d",&val);
            // findElement(val);
            break;
        case 5:
            printHashTable();
            break;
        case 6:
            printf("Exiting....\n");
            //printInsertedTable();
            exit(0);
            break;
        default:
            printf("Enter valid choice\n");
        }
    }
    getch();
    return 0;
}
