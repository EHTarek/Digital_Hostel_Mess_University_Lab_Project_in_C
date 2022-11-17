#include<stdio.h>
#include<windows.h>
#include<conio.h>

typedef struct member
{
    int id;
    char name[30];
    int semester;
    int room;
    struct member *next;
} node;

node *header=NULL;

node *get_node()
{
    return((node *)malloc(sizeof(node)));
}

int count_size=0;

void menu();
void insert();
void del();
void display();
void search();
void countmember();

void gotoxy(short int x,short int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


int main()
{
    menu();

    return 0;
}


void menu()
{
    system("cls");
    printf("\n\n\n     *********************************************************************\n");
    printf("\n     ______________________::  HOSTEL MANAGEMENT  ::______________________\n");
    printf("\n     *********************************************************************\n\n");



    int choice;
    printf("\n\t1 - Insert Member Record\t\t2 - Delete Member Record\n\n\t3 - Search Member Record\t\t4 - Display Member Record\n\n\t\t\t    5 - Count Total Records\n\n\t\t\t    0 - Press to EXIT APP !\n");

    gotoxy(30,20);
    printf("Enter Choise: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1 :
        insert();
        break;
    case 2 :
        del();
        break;
    case 3 :
        search();
        break;
    case 4 :
    {
        display();
        break;
    }
    case 5 :
    {
        countmember();
        break;
    }
    default :
        exit(0);
        break;
    }
}




void insert()
{
    system("cls");
    int id,semester,room;
    char name[30];

    node *temp,*data;

    data=get_node();
    temp=get_node();

    gotoxy(25,5);
    printf("****** Add Member Information ******");

    gotoxy(32,8);
    printf("Member ID: ");
    scanf("%d",&id);

    gotoxy(32,10);
    printf("Member Name: ");
    fflush(stdin);
    gets(name);


    gotoxy(32,12);
    printf("Batch: ");
    scanf("%d",&semester);


    gotoxy(32,14);
    printf("Room No: ");
    scanf("%d",&room);

    if(header==NULL)
    {
        header=temp;
        header->id=id;
        strcpy(header->name,name);
        header->semester=semester;
        header->room=room;
        header->next=NULL;
        count_size++;
        gotoxy(27,21);
        printf("Your Data Inserted Successuffly.");

        getch();

        menu();
        return;
    }

    data->id=id;
    strcpy(data->name,name);
    data->semester=semester;
    data->room=room;
    data->next=NULL;

    temp=header;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=data;
    count_size++;
    gotoxy(27,21);
    printf("Your Data Inserted Successuffly.");

    getch();

    menu();

    return;
}

void del()
{

    system("cls");
    if(header==NULL)
    {
        gotoxy(23,10);
        printf("There Are No Member In The Record!!!");
        getch();
        menu();
        return;
    }

    gotoxy(17,5);
    printf("***** Member Information Delete Operation *****");

    gotoxy(13,6);
    printf("_______________________________________________________");


    int id;
    gotoxy(21,8);
    printf("Enter The Member Id You Want To Delete: ");
    scanf("%d",&id);


    int i=0;
    node *temp,*delete_d,*temp_1,*c_data,*prev;
    temp=header;
    delete_d=header;
    temp_1=header;
    int count=1;

    int flag=0;

    while(temp_1!=NULL)
    {
        if(temp_1->id==id)
        {
            flag=1;
            break;

        }
        count++;
        temp_1=temp_1->next;
    }

    if(flag==0)
    {
        gotoxy(23,14);
        printf("Your Enter Member ID Not Founded!!!");
        getch();
        menu();
        return;
    }

    if(count==1)
    {
        delete_d=header;
        c_data=delete_d;

        header=header->next;

        gotoxy(22,12);
        printf("The Following Record Is Deleted.");

        gotoxy(17,16);
        printf("Member ID: %d",c_data->id);

        gotoxy(40,16);
        printf("Member Name: %s",c_data->name);


        gotoxy(40,18);
        printf("Member Batch: %d",c_data->semester);


        gotoxy(40,20);
        printf("Member Room: %d",c_data->room);

        count_size--;
        free(delete_d);

        getch();

        menu();

        return;
    }

/// for last element deletion

            for(i=0; i<count-1; i++)
            {
                delete_d=temp;
                temp=temp->next;
                c_data=temp;
                if(temp==NULL)
                    break;
            }


            if(count==count_size)
            {
                count_size--;
                delete_d->next=NULL;
            }
            else
            {

               count_size--;
                delete_d->next=delete_d->next->next;

            }

    gotoxy(22,12);
    printf("The Following Record Is Deleted.");

    gotoxy(17,16);
    printf("Member ID: %d",c_data->id);

    gotoxy(40,16);
    printf("Member Name: %s",c_data->name);


    gotoxy(40,18);
    printf("Member Batch: %d",c_data->semester);


    gotoxy(40,20);
    printf("Member Room: %d",c_data->room);

    free(temp);

    getch();

    menu();


    return;

}

void display()
{

    system("cls");

    node *temp;
    if(header==NULL)
    {

        gotoxy(25,10);
        printf("There are no member in the record !!!\n");
        getch();
        menu();
        return;
    }
    else
    {
        int i=9;
        gotoxy(25,5);
        printf("****** All Member Record ******\n");
        gotoxy(17,7);
        printf("_______________________________________________");

        temp=header;
        while(temp!=NULL)
        {
            gotoxy(17,i);
            printf("Member ID: %d",temp->id);

            gotoxy(40,i);
            printf("Member Name: %s",temp->name);

            gotoxy(40,i+2);
            printf("Member Batch: %d",temp->semester);

            gotoxy(40,i+4);
            printf("Member Room: %d",temp->room);

            i+=8;
            temp=temp->next;
        }

        getch();

        menu();

        return;
    }
}

void search()
{

    system("cls");
    if(header==NULL)
    {
        gotoxy(30,10);
        printf("There Is No Data!!!");
        getch();
        menu();
    }

    else
    {
        gotoxy(21,5);
        printf("****** Member Data Searching ******");
        gotoxy(16,6);
        printf("_____________________________________________");
        int id;
        node *temp;
        gotoxy(28,8);
        printf("Enter The Member ID: ");
        scanf("%d",&id);

        for(temp=header; temp!=NULL; temp=temp->next)
        {
            if(id==temp->id)
            {

                gotoxy(17,11);
                printf("Member ID: %d",temp->id);

                gotoxy(40,11);
                printf("Member Name: %s",temp->name);


                gotoxy(40,13);
                printf("Member Batch: %d",temp->semester);


                gotoxy(40,15);
                printf("Member Room: %d",temp->room);

                getch();
                menu();

                return;
            }
        }

        gotoxy(27,12);
        printf("Member Record Not Found!!!");
        getch();
        menu();
        return;
    }
}


void countmember()
{
    int count=0;
    system("cls");
    if(header==NULL)
    {
        gotoxy(30,10);
        printf("There Is No Data!!!");
        getch();
        menu();
    }

    else
    {
        gotoxy(25,4);
        printf("****** Member Records ******");
        gotoxy(24,6);
        printf("_____________________________________________");
        node *temp;

        for(temp=header; temp!=NULL; temp=temp->next)
        {
            count++;
        }
        gotoxy(24,10);
        printf("Total Member Record : %d",count);
        getch();
        menu();
        return;
    }
}
