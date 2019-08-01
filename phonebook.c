//<<<<----My first project---->>>>
//<<<<---Team Name   :--->>>>
//<<<<---Team Members:--->>>>
//<<<<---Project Name: Phonebook_Application--->>>>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Contact
{
    char name[40];
    char number[20];
    struct Contact *next;
} con;

con *head = NULL;
con *temp = NULL;

void Add_contact()
{
    int i,n;
    printf("\tHow many contacts you want to save : ");
    scanf("%d", &n);
    printf("\n");
    for(i=0; i<n; i++)
    {
        con *nnode = (con*)malloc(sizeof(con));
        printf("\tName of the Contact   : ");
        getchar();
        scanf("%[^\n]s", &nnode -> name);
        printf("\tNumber of the Contact : ");
        scanf("%s", &nnode -> number);
        nnode -> next = NULL;
        if(head == NULL)
        {
            head = nnode;
        }
        else
        {
            temp = head;

            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = nnode;
        }
    }
    system("cls");
}

void search_contact()
{
    char str[40];

    printf("\tWhich contact you want to search: ");
    scanf("%s", &str);
    printf("\n");
    temp=head;
    if((strcmp(temp->name,str)==0) || (strcmp(temp->number,str)==0))
    {
        printf("\t\tName");
        printf("\t\tContact\n");
        printf("\n");
        printf("\t\t%s", temp->name);
        printf("\t\t%s\n", temp->number);
    }
    else
    {
        while(temp!='\0' && ((strcmp(temp->name,str)!=0) &&(strcmp(temp->number,str)!=0)))
        {
            temp=temp->next;

        }
        if(temp=='\0')
        {
            printf("\tContact Does noT exist!!!\n");
        }
        else
        {
            printf("\t\tName");
            printf("\t\tContact\n");
            printf("\n");
            printf("\t\t%s", temp->name);
            printf("\t\t%s\n", temp->number);
        }
    }

}

void Modify_contact()
{
    char a[40];
    char c[40];
    int b;

    printf("\tWhich Contact you want to Modify: ");
    scanf("%s", &a);
    printf("\t\t1.Modify Name\n");
    printf("\t\t2.Modify Number\n");
    printf("\tEnter your choise: ");
    scanf("%d", &b);
    printf("\n");
    temp=head;
    if(strcmp(temp->name,a)==0 || (strcmp(temp->number,a)==0 ))
    {
        if(b==1)
        {
            printf("\tInseart Name: ");
             getchar();
            scanf("%{^\n]s", &c);
            strcpy(temp->name,c);
        }
        else
        {
            printf("\tInseart Number: ");
            scanf("%s", &c);
            strcpy(temp->number,c);
        }
    }

    else
    {
        while(temp!='\0' && strcmp(temp->name,a)!=0)
        {
            temp=temp->next;

        }
        if(temp=='\0')
        {
            printf("\tContact does not exist!!!\n");
        }
        else
        {
            if(b==1)
            {
                printf("\tInseart Name: ");
                scanf("%s", &c);
                strcpy(temp->name,c);
            }
            else
            {
                printf("\tInseart Number: ");
                scanf("%s", &c);
                strcpy(temp->number,c);
            }
        }
    }

}

int Delete_contact()
{
    char a[40];
    printf("\tWhich contact you want to Delete: ");
    scanf("%s",&a);
    temp=head;
    if(strcmp(temp->name,a)==0)
    {
        head=head->next;
        free(temp);
    }
    else
    {
        con *prevous = NULL;
        while(temp!='\0' && strcmp(temp->name,a)!=0)
        {
            prevous = temp;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("\tContact does not exist!!!\n");
        }
        else
        {
            printf("\n   Information of %s has deleted successfully \n\n",temp->name);
            prevous->next=temp->next;
            free(temp);
        }
    }


}

void swap(con *temp, con *temp2)
{
    con *temp3 = (con*) malloc(sizeof(con));
    strcpy(temp3->name, temp->name);
    strcpy(temp3->number, temp->number);
    strcpy(temp->name, temp2->name);
    strcpy(temp->number, temp2->number);
    strcpy(temp2->name, temp3->name);
    strcpy(temp2->number, temp3->number);
}

void sortbyname(con *temp)
{
    con *temp2, *temp3=NULL;
    int swapped = 1;
    while(swapped)
    {
        swapped = 0;
        temp2 = temp;
        while(temp2->next!=temp3)
        {
            if(strcmp(temp2->name, temp2->next->name)==1)
            {
                swap(temp2, temp2->next);
                swapped = 1;
            }
            temp2=temp2->next;
        }
        temp3 = temp2;
    }
}

void Display_contact()
{
    temp = head;
    sortbyname(temp);
    if(temp==NULL)
    {
        printf("\t\tSorry !! There is no contact\n");
        return;
    }

    printf("\t\tName");
    printf("\t\tContact\n");
    printf("\n");

    while(temp!= NULL)
    {
        printf("\t\t%s", temp->name);
        printf("\t\t%s\n", temp->number);
        temp = temp->next;
    }

    printf("\n");


}

void clear_screen()
{
    system("cls");
}
/*void file()
{
    char name [40];
    char number[20];
    FILE *file;

    file=fopen("phonebook.txt","a");
    if(file==NULL)
        printf("File dosen't exist !");
    else
    {
        printf("file is open \n");
         printf("\t\tName");
            printf("\t\tContact\n");
            printf("\n");
            printf("\t\t%s", temp->name);
            printf("\t\t%s\n", temp->number);
        //printf("\nFile is written successfully");
        fclose(file);

    }*/
int main()
{
    printf("\n\t\t\t<<<< Welcome To Our Project >>>>\n");
    printf("       \t\t\t  <<< Phonebook Application >>>\n");
    printf("\t\t\t    << Team: Code Warriors >>\n");
    int ch;
    system("color 5f");


    while(1)
    {


        printf("\n\t\tWhat do you want to do : \n\n");
        printf("\t\t\t1. Add record\n");
        printf("\t\t\t2. View List in Ascending Order\n");
        printf("\t\t\t3. Search record\n");
        printf("\t\t\t4. Delete record\n");
        printf("\t\t\t5. Modify record\n");
        printf("\t\t\t6. Clear Screen \n");

        printf("\t\t\t0. Exit\n");
        printf("\tEnter your choice : ");
        scanf("%d",&ch);
        printf("\n");

        if(ch==1)
            Add_contact();
        else if(ch==2)
            Display_contact();
        else if(ch==3)
            search_contact();
        else if(ch==4)
            Delete_contact();
        else if(ch==5)
            Modify_contact();
        else if(ch==6)
            clear_screen();

        else if(ch==0)
            break;

    }

    return 0;
}
