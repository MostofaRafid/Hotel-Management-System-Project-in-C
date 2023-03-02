/***Mostofa Rafid
213902097*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct hoteln
{
    int room;
    char name[50];
    int phone;
    int days;
    int bill;
    struct hoteln *next;
}* head;

struct hoteln* midl(struct hoteln* first, struct hoteln* last)
{
    if(first==NULL)
        return NULL;

    struct hoteln* slow=first;
    struct hoteln* fast=first->next;

    while(fast!=last)
    {
        fast=fast->next;
        if(fast!=last)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    return slow;
}
struct hoteln* binary(struct hoteln *head, int room)
{
    struct hoteln* first=head;
    struct hoteln* last=NULL;

    do
    {
        struct hoteln* mid=midl(first, last);

        if(mid==NULL)
            return NULL;

        if(mid->room==room)
            return mid;

        else if(mid->room<room)
            first=mid->next;

        else
            last = mid;
    }
    while (last==NULL||last!=first);
    return NULL;
}

void insert(int room, char* name, int phone, int days, int bill)
{
    struct hoteln * hotel=(struct hoteln *) malloc(sizeof(struct hoteln));
    hotel->room=room;
    strcpy(hotel->name, name);
    hotel->phone=phone;
    hotel->days=days;
    hotel->bill=bill;
    hotel->next=NULL;

    if(head==NULL)
    {
        head=hotel;
    }
    else
    {
        hotel->next=head;
        head=hotel;
    }
}

void search(int room)
{
    struct hoteln *temp=head;

    if(binary(head,room)==NULL)
    {
        printf("No information found!!!");
    }
    else
    {
        printf("\t\t\t\t\t\tRoom Number: %d\n", temp->room);
        printf("\t\t\t\t\t\tName: %s\n", temp->name);
        printf("\t\t\t\t\t\tPhone: %d\n", temp->phone);
        printf("\t\t\t\t\t\tDays: %d\n", temp->days);
        printf("\t\t\t\t\t\tBill: %d\n\n", temp->bill);
        return;
    }
}

int  display()
{
    int count=0;
    struct hoteln * temp = head;
    while(temp!=NULL)
    {
        printf("\t\t\t\t\t\tRoom Number: %d\n", temp->room);
        printf("\t\t\t\t\t\tName: %s\n", temp->name);
        printf("\t\t\t\t\t\tPhone: %d\n", temp->phone);
        printf("\t\t\t\t\t\tDays: %d\n", temp->days);
        printf("\t\t\t\t\t\tBill: %d\n\n", temp->bill);
        temp = temp->next;
        count++;
    }
    return count;
}
void swap(struct hoteln *a, struct hoteln *b)
{
    int temp=a->room;
    a->room=b->room;
    b->room=temp;
}
void sorting(int count)
{
    int swapped, i;
    struct hoteln *ptr1;
    struct hoteln *lptr = NULL;
    if (head==NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = head;
        while(ptr1->next!=lptr)
        {
            if(ptr1->room>ptr1->next->room)
            {
                swap(ptr1, ptr1->next);
                swapped=1;
            }
            ptr1=ptr1->next;
        }
        lptr=ptr1;
    }
    while(swapped);
    display();
}

void update(int room)
{
    struct hoteln *temp=head;
    while(temp!=NULL)
    {
        if(temp->room==room)
        {
            printf("Enter Days: ");
            scanf("%d", &temp->days);
            printf("Enter bill: ");
            scanf("%d", &temp->bill);
            printf("\n\t\t\t\t\t\tUpdate Successful!!!\n");
            return;
        }
        temp=temp->next;
    }
    printf("\n\t\t\t\t\t\tNo information found!!!\n");
}
void delete(int room)
{
    struct hoteln *temp1=head;
    struct hoteln *temp2=head;
    while(temp1!=NULL)
    {
        if(temp1->room==room)
        {
            if(temp1==temp2)
            {
                head=head->next;
                free(temp1);
            }
            else
            {
                temp2->next=temp1->next;
                free(temp1);
            }
            printf("\n\t\t\t\t\t\tDeletion successful!!!\n");
            return;
        }
        temp2=temp1;
        temp1=temp1->next;
    }
    printf("\n\t\t\t\t\t\tNo information found!!!\n");
}

int main()
{
    head=NULL;
    int ch, kop, room, phone, days, bill;
    char name[50];
    system("cls");
    while(1)
    {
        system("cls");
        printf("\t\t----------------------------------------------------------------------------\n");
        printf("\t\t|**************************** HOTEL MANAGEMNET SYSTEM *********************|\n");
        printf("\t\t----------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\t\t1. Book a room");
        printf("\n\t\t\t\t\t\t2. Search");
        printf("\n\t\t\t\t\t\t3. View");
        printf("\n\t\t\t\t\t\t4. Update");
        printf("\n\t\t\t\t\t\t5. Delete");
        printf("\n\t\t\t\t\t\t6. exit");
        printf("\n\n\t\t\t\t\t\tEnter choice(1-6): ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            system("cls");
            printf("\n\t\t\t\t\t\tEnter room number: ");
            scanf("%d", &room);
            printf("\t\t\t\t\t\tEnter name: ");
            fflush(stdin);
            gets(name);
            printf("\t\t\t\t\t\tEnter mobile number: ");
            scanf("%d", &phone);
            printf("\t\t\t\t\t\tEnter Days: ");
            scanf("%d", &days);
            printf("\t\t\t\t\t\tEnter bill: ");
            scanf("%d", &bill);
            insert(room, name, phone, days, bill);
            break;
        case 2:
            system("cls");
            printf("\n\t\t\t\t\t\tEnter the room number: ");
            scanf("%d", &room);
            search(room);
            break;
        case 3:
            system("cls");
            sorting(kop);
            break;
        case 4:
            system("cls");
            printf("\n\t\t\t\t\t\tEnter the room number: ");
            scanf("%d", &room);
            update(room);
            break;
        case 5:
            system("cls");
            printf("\n\t\t\t\t\t\tEnter the room number: ");
            scanf("%d", &room);
            delete(room);
            break;
        case 6:
            exit(1);
        }
        printf("\n\n\t\t\t\t\t\tContinue to Again!!!");
        getch();
    }
}
