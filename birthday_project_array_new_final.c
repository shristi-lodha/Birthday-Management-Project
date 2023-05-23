#include <stdio.h>
#include <string.h>

typedef struct node
{
    char name[30];
    char birth_date[20];
    char email_id[40];
    int phone_no[10];
} s;

int Insertion(s s1[], int s_indeX)
{
    int count[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char str_count[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char enter_key;
    int check_phone_no[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int flag = 0;
    int flag2 = 0;
    int check_flag = 0;
    char check_email[40];
    int check_flag2 = 0;
    s_indeX++;
    int name_flag = 0;
again_name:
    printf("Enter the Name :");
    scanf(" %[^\n]", s1[s_indeX].name);

    int name_length = strlen(s1[s_indeX].name);
  //  printf(" %d", name_length);
    // printf("%s", s1[s_indeX].name);

// int name_length = strlen(s1[s_indeX].name);


    for (int i = 0; i < name_length; i++)
    {
        name_flag = 0;
        for (int j = 0; j < 10; j++)
        {
            if (s1[s_indeX].name[i] == str_count[j])
            {

                name_flag = 1;
                break;
            }
        }
        if (name_flag == 1)
        {

            break;
        }
    }
    if (name_flag == 1)
    {
        printf("\nEnter Valid Name Format i.e. name surname!!\n");
        goto again_name;
    }
again_birth_date:
    printf("\n(Space is not allowed in Date Format)-\nEnter the Birth Date :");
    scanf("%s", s1[s_indeX].birth_date);

    if (s1[s_indeX].birth_date[2] == '/' && s1[s_indeX].birth_date[5] == '/')
    {
    }
    else
    {
        printf("Enter Valid Format of Birth Date i.e dd/mm/yyyy");
        goto again_birth_date;
    }

again_email_id:
    printf("\nEnter the Email ID :");
    scanf("%s", s1[s_indeX].email_id);
    int email_id_length = strlen(s1[s_indeX].email_id);

    int up_email = 0;
    int copy1 = s_indeX;
    while (copy1 > 0)
    {
        printf("%d",copy1);

        // for (int k = 0; k < 10; k++)
        // {
        //     check_phone_no[k] = s1[up].phone_no[k];
        // }
        //printf("hi");
        strcpy(check_email, s1[up_email].email_id);
       
            check_flag2 = 0;
            if (strcmp(s1[s_indeX].email_id, check_email) == 0)
            {
                check_flag2 = 1;
            }

            if (check_flag2 == 1)
            {
                printf("Can't Insert that email_id as already EXIST at indeX : %d !!", up_email);
                goto again_email_id;
            }
            else
            {

            }
     

        up_email++;
        copy1--;
    }
    if (s1[s_indeX].email_id[email_id_length - 1] == 'm' || s1[s_indeX].email_id[email_id_length - 1] == 'i' || s1[s_indeX].email_id[email_id_length - 1] == 'n')
    {
    }
    else
    {
        printf("\n Enter Valid Format of Email ID i.e ends with -\n.com\n.ai\n.in\n");
        goto again_email_id;
    }

again_phone_no:
    printf("\nEnter the Phone no. :");
    printf("+91 ");
    int index = 0;
    while (index < 10)
    {
        scanf("%1d", &s1[s_indeX].phone_no[index]);
        index++;
    }
    flag = 1;
    printf("%d", index);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (s1[s_indeX].phone_no[i] == count[j])
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            printf("\nEnter Valid Phone No.\n");
            break;
        }
    }

    int up = 0;
    int copy = s_indeX;
    while (copy > 0)
    {

        for (int k = 0; k < 10; k++)
        {
            check_phone_no[k] = s1[up].phone_no[k];
        }

        
            check_flag = 1;
            for (int j = 0; j < 10; j++)
            {

                if (s1[s_indeX].phone_no[j] == check_phone_no[j])
                {
                    check_flag = 1;
                }
                else
                {
                    check_flag = 0;
                    break;
                }
            }
            if (check_flag == 1)
            {
                printf("Can't Insert that phone no. as already EXIST at indeX : %d !!", up);
                goto again_phone_no;
            }
            else
            {
            }

        up++;
        copy--;
        }

    

    return s_indeX;
}

int name(s s1[], int indeX, char ch)
{
    int flag, i;

    char new_name[30];

    char enter_key;
    int count = 0;

    printf("\nEnter the Name :");
    scanf(" %[^\n]", new_name);

    for (i = 0; i <= indeX; i++)
    {
        flag = 0;
        if (strcmp(s1[i].name, new_name) == 0)
        {
            if (ch == 'd')
            {
                flag = 1;

                if (flag == 1)
                {
                    printf("\nThe name %s is found at %dth row/indeX and 1st column", new_name, i);
                    return i;
                }
                else
                {
                    printf("Can't do Operations by this name as it is not in list !!");
                    return -1;
                }
            }
            else
            {
                flag = 1;
                if (flag == 1)
                {
                    count++;
                    printf("\nThe name %s is found at %dth row/indeX and 1st column", new_name, i);

                    printf("\nThe Searched Row Details are:\n");
                    printf("    %s        %s        %s      +91 ", s1[i].name, s1[i].birth_date, s1[i].email_id);
                    for (int ind = 0; ind < 10; ind++)
                    {
                        printf("%d", s1[i].phone_no[ind]);
                    }
                    printf("      \n");
                }
            }
        }
    }
            if (count == 0)
            {
                printf("Can't do Operations by this name as it is not in list !!");
                return -1;
            }
           else
            {
                return 0;
            }
        }


int birth_date(s s1[], int indeX, char ch)
{
    int flag = 0;
    int count = 0;
    char new_birth_date[20];
    int i;
    printf("Enter the Birth_Date :");
    scanf("%s", new_birth_date);
    int len = strlen(new_birth_date);
    printf("%d", len);

    for (i = 0; i <= indeX; i++)
    {

        printf("%s\n%s", s1[i].birth_date, new_birth_date);
        if (strcmp(s1[i].birth_date, new_birth_date) == 0)
        {
            flag = 1;
            if (ch == 'd')
            {

                if (flag == 1)
                {
                    printf("\nThe Birth_date %s is found at %dth row/indeX and 2nd column", new_birth_date, i);
                    return i;
                }
                else
                {
                    printf("\nCan't do Operations by this Birth date as it is not in list !!");
                    return -1;
                }
            }
            else
            {
                if (flag == 1)
                {
                    count++;
                    printf("\nThe Birth_date %s is found at %dth row/indeX and 2nd column", new_birth_date, i);

                    printf("\nThe Searched Row Details are:\n");
                    printf("    %s        %s        %s      +91 ", s1[i].name, s1[i].birth_date, s1[i].email_id);
                    for (int ind = 0; ind < 10; ind++)
                    {
                        printf("%d", s1[i].phone_no[ind]);
                    }
                    printf("      \n");
                }
            }
        }
    }
            if (count == 0)
            {
                printf("Can't do Operations by this name as it is not in list !!");
                return -1;
            }
            else
            {
                return 0;
            }
        }
    
int email_id(s s1[], int indeX)
{
    int flag = 0;
    char new_email_id[40];
    int i;
    printf("Enter the Email_ID :");
    scanf("%s", new_email_id);

    int len = strlen(new_email_id);
    printf("%d", len);
    // new_email_id[len-1] = '\0';
    for (i = 0; i <= indeX; i++)
    {
        printf("%s\n%s", s1[i].email_id, new_email_id);
        if (strcmp(s1[i].email_id, new_email_id) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\nThe email_id %s is found at %dth row/indeX and 3rd column", new_email_id, i);
        
                    printf("\nThe Searched Row Details are:\n");
                    printf("    %s        %s        %s      +91 ", s1[i].name, s1[i].birth_date, s1[i].email_id);
                    for (int ind = 0; ind < 10; ind++)
                    {
                        printf("%d", s1[i].phone_no[ind]);
                    }
                    printf("      \n");
        return 0;
    }
    else
    {
        printf("Can't do Operations by this Email_id as it is not in list !!");
        return -1;
    }
}

int phone_no(s s1[], int indeX)
{
    int flag;
    int new_phone_no[10];
    int i=0;
    printf("Enter the Phone_no :");
    for (i = 0; i < 10; i++)
    {
        scanf("%1d", &new_phone_no[i]);
    }
    i=0;
   while(i<=indeX)
    {
            flag =1;        
        for (int j = 0; j < 10; j++)
        {
                                                                                                          ;
            if (s1[i].phone_no[j] != new_phone_no[j])
            {

                flag = 0;
                break;
               
            }
        }
    
        if (flag == 0)
        {
          i++;
        }else{
            if(flag ==1){
            printf("\nThe Phone_no is found at %dth row/indeX and 4th column", i);
             
                    printf("\nThe Searched Row Details are:\n");
                    printf("    %s        %s        %s      +91 ", s1[i].name, s1[i].birth_date, s1[i].email_id);
                    for (int ind = 0; ind < 10; ind++)
                    {
                        printf("%d", s1[i].phone_no[ind]);
                    }
                    printf("      \n");
                    return 0;
                    
                  
        }
        
    }
    }
    if(flag ==0){

             printf("Can't do Operations by this Phone no. as it is not in list !!");
            return -1;
        
    }
    
        

}

int related_data(s s1[], int indeX)
{
    int flag = 0;
    char new_str[50];
    char *ptr;
    printf("Enter the String :");

    scanf("%s", new_str);

    int len;
    printf("\nThe Related Data are :\n");

    for (int i = 0; i <= indeX; i++)
    {
        // len = strlen(s1[i].name);
        printf("\nIn name -");

        ptr = strstr(s1[i].name, new_str);
        printf("%s", ptr);

        printf("\n");
    }
    for (int i = 0; i <= indeX; i++)
    {
        len = strlen(s1[i].birth_date);
        printf("\nIn Birth_date - \n");
        for (int j = 0; j < len; j++)
        {
            if (s1[i].birth_date[j] == new_str[j])
            {
                printf("%c", s1[i].birth_date[j]);
            }
        }
        printf("\n");
    }
    for (int i = 0; i <= indeX; i++)
    {
        len = strlen(s1[i].email_id);
        printf("\nIn Email_ID - \n");
        for (int j = 0; j < len; j++)
        {
            if (s1[i].email_id[j] == new_str[j])
            {
                printf("%c", s1[i].email_id[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
int Deletion(int indeX, s s1[])
{
    char ch, del;
    int result;
    int choice;
    ch = 'y';
    del = 'd';
    do
    {
        if (ch == 'y')
        {

            printf("\nBy which way you want to delete-\n"
                   "1 : enter for name\n"
                   "2 : enter for Birth_date\n"
                   "3 : enter for Email_ID \n"
                   "4 : enter for Phone_no.\n"
                   "5 : enter for Related data\n");
            printf("Enter Your Choice :");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                result = name(s1, indeX, del);
                break;
            case 2:
                result = birth_date(s1, indeX, del);
                break;
            case 3:
                result = email_id(s1, indeX);
                break;
            case 4:
                result = phone_no(s1, indeX);
                break;
            case 5:
                result = related_data(s1, indeX);

                break;
            default:
                printf("\nPlease Enter Valid Choice !!\n");
                break;
            }

            if (result != -1)
            {
                printf("\nThe Deleted Row is :");
                printf("    %s        %s        %s      +91 ", s1[result].name, s1[result].birth_date, s1[result].email_id);
                for (int ind = 0; ind < 10; ind++)
                {
                    printf("%d", s1[result].phone_no[ind]);
                }

                printf("      \n");
                for (int j = result; j <= indeX; j++)
                {
                    strncpy(s1[j].name, s1[j + 1].name, 20);
                    strncpy(s1[j].birth_date, s1[j + 1].birth_date, 20);
                    strncpy(s1[j].email_id, s1[j + 1].email_id, 30);

                    for (int i = 0; i < 10; i++)
                    {

                        s1[j].phone_no[i] = s1[j + 1].phone_no[i];
                    }
                }

                indeX = indeX - 1;
                printf("%d", indeX);
            }
            else
            {
                printf("\nCan't Delete as it is not in the list !!\n");
            }
        }
        else
        {
            printf("\nYou can enter 'y' or 'n' only !!\n");
        }
        printf("\nDo you want to Delete more(y/n)? :");
        scanf("%s", &ch);

    } while (ch != 'n');
    return indeX;
}

void Searching(s s1[], int indeX)
{
    char search, sch;
    int choice;
    search = 'y';
    int search_indeX;
    sch = 's';
    do
    {
        if (search == 'y')
        {
            printf("What you want to search if-\n"
                   "1 : enter for name\n"
                   "2 : enter for Birth_date\n"
                   "3 : enter for Email_ID \n"
                   "4 : enter for Phone_no.\n"
                   "5 : enter for Related data\n");
            printf("Enter your choice :");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                search_indeX = name(s1, indeX, sch);
                break;
            case 2:
                search_indeX = birth_date(s1, indeX, sch);
                break;
            case 3:
                search_indeX = email_id(s1, indeX);
                break;
            case 4:
                search_indeX = phone_no(s1, indeX);
                break;
            case 5:
                search_indeX = related_data(s1, indeX);

                break;
            default:
                printf("\nPlease enter Valid Choice !!\n");
            }
            if (search_indeX != -1)
            {
            }
            else
            {
                printf("\nCan't Search as not in list !!\n");
            }
        }
        else
        {
            printf("\nYou can enter 'y' or 'n' only !!\n");
        }
        printf("\nDo you want to Search more (y/n)? :");
        scanf("%s", &search);
    } while (search != 'n');
}
// update_indeX means at that indeX i wanna to update.
void allupdate(s s1[], int update_indeX, int choice)
{
    char str[50];
    int i = 0;
    char enter_key;
    int str_phone[10];
    int str_len;

    int temp;
    if (choice != 4)
    {
        printf("\n(This is For name ,birth_date and email_id)\n");
        printf("\nEnter the String :");
       scanf(" %[^\n]",str);
       int len =strlen(str);
        if (choice == 1)
        {
            strcpy(s1[update_indeX].name, str);
            s1[update_indeX].name[len] = '\0';
        }
        else if (choice == 2)
        {

            strcpy(s1[update_indeX].birth_date, str);
            s1[update_indeX].birth_date[len] = '\0';
            if (s1[update_indeX].birth_date[0] == '\n')
            {

                for (int i = 0; i < len; i++)
                {
                    s1[update_indeX].birth_date[i] = s1[update_indeX].birth_date[i + 1];
                }
            }
        }
        else if (choice == 3)
        {
            strcpy(s1[update_indeX].email_id, str);
            s1[update_indeX].email_id[len] = '\0';
            if (s1[update_indeX].email_id[0] == '\n')
            {

                for (int i = 0; i < len; i++)
                {
                    s1[update_indeX].email_id[i] = s1[update_indeX].email_id[i + 1];
                }
            }
        }
        else
        {
        }
    }

    //printf(" %s", s1[update_indeX].birth_date);
    if (choice == 4)
    {
        printf("\nEnter the Updated Phone no.:");
        for (int i = 0; i < 10; i++)
        {
            scanf("%1d", &str_phone[i]);
        }
        for (int ind = 0; ind < 10; ind++)
        {
            s1[update_indeX].phone_no[ind] = str_phone[ind];
        }
    }
}
void Updation(s s1[], int indeX)
{
    char update;
    int choice;
    int len;
    int update_indeX;
    update = 'y';
    do
    {

        if (update == 'y')
        {
            printf("\nEnter at which row/indeX do you want to update :");
            scanf("%d", &update_indeX);
            if (update_indeX == -1)
            {
            }
            printf("\nWhat you want to update :\n"
                   "1 : enter for name\n"
                   "2 : enter for Birth_date\n"
                   "3 : enter for Email_ID \n"
                   "4 : enter for Phone_no.\n"
                   "5 : enter for Related data\n");
            printf("enter your choice number :");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                allupdate(s1, update_indeX, choice);
                break;
            case 2:
                allupdate(s1, update_indeX, choice);
                break;
            case 3:

                allupdate(s1, update_indeX, choice);
                break;
            case 4:
                allupdate(s1, update_indeX, choice);
                break;
            case 5:
                allupdate(s1, update_indeX, choice);
                break;
            default:
                printf("\nPlease Enter Valid Choice !!\n");
                break;
            }
        }
        else
        {
            printf("\n You can enter 'y' or 'n' only !!");
        }

        printf("\nThe Updated Row is :");
        printf("    %s        %s        %s       +91 ", s1[update_indeX].name, s1[update_indeX].birth_date, s1[update_indeX].email_id);
        for (int ind = 0; ind < 10; ind++)
        {
            printf("%d", s1[update_indeX].phone_no[ind]);
        }
        printf("      \n");

        printf("\nDo you want to Update More :");
        scanf("%s", &update);
    } while (update != 'n');
}

void Printlist(s s1[], int indeX)
{
    int i = 0;
    printf("\n--------------------------------------------------------------------\n");
    printf("\n|    Name    |    Birth Date    |    Email_ID    |    Phone_No.    |\n");
    printf("\n--------------------------------------------------------------------\n");
    while (i <= indeX)
    {
        printf("  %s          %s           %s          +91 ", s1[i].name, s1[i].birth_date, s1[i].email_id);
        for (int ind = 0; ind < 10; ind++)
        {
            printf("%d", s1[i].phone_no[ind]);
        }
        printf("      \n");
        i++;
    }
}

int main()
{

    s s1[100];

    int choice;
    char ch;
    int indeX = -1;
    printf("\n******WELCOME TO MY PROJECT******\n");
    printf("Hello !\nThis is my Birthday Diary.\n");
    ch = 'y';
    do
    {
        if (ch == 'y')
        {

            printf("\nSome Operations in My Birthday Diary are -\n"
                   "1 : enter for Inserting Information (INSERTION) \n"
                   "2 : enter for Updating Information (UPDATION)\n"
                   "3 : enter for Deleting any Information (DELETION) \n"
                   "4 : enter for Searching any Information (SEARCHING)\n"
                   "5 : enter for Printing list (PRINTLIST)\n"
                   "0 : enter for Exiting from operations (EXIT)\n");
            printf("Enter your Choice :");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                indeX = Insertion(s1, indeX);
                break;
            case 2:
                Updation(s1, indeX);
                break;
            case 3:
                indeX = Deletion(indeX, s1);

                break;
            case 4:
                Searching(s1, indeX);
                break;
            case 5:
                Printlist(s1, indeX);
                break;
            case 0:
                printf("You Are EXit From Operations !!!\n");
                break;
            default:
                printf("Please enter a Valid Choice !!\n");
                break;
            }
        }
        else
        {
            printf("\nYou can enter 'y' and 'n' only !!\n");
        }
        printf("\nDo you want to do more (y/n)? :");
        scanf("%s", &ch);

    } while (ch != 'n');
    return 0;
}