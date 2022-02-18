#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
void start();
void main_menu();
void phonebook();
void add_ph();
void read_ph();
void modify_ph();
void delete_ph();
void notepad();
void write_notes();
void read_notepad();
void game();
int game_res(char ,char );
struct Contact
{
    char name[30];
    char mobileno[11];
    char mail[50];
};
int main()
{
    start();
    return 0;
}
void start()
{   char username[8],password[10],ch;
    int i=0;

    printf("\t\t\t\t\tWELCOME USER\n\n\n");
    printf("\t\tUsername:\t");
    scanf("%s",&username);
    printf("\n\t\tPassword:\t");
    while(ch!=13)
    {
        ch=getch();
        if(ch!=8&&ch!=13)
        {
            putchar('*');
            password[i]=ch;
            i++;
        }
    }
    password[i]='\0';
    if(strcmp(username,"Anish")==0 && strcmp(password,"admin")==0)
    {main_menu();}
    else{printf("\nWrong entries\n");getch();
    system("cls");
    start();}
}
void main_menu()
{   system("cls");
    printf("Press the corresponding number to use the functions!");
    getch();system("cls");
    printf("\t\t**********APPLICATIONS**********\n");
    printf("\t\t(1) Phonebook\n\t\t(2) Notepad\n\t\t(3) Game(Rock-Paper-scissor)\n\t\t(4) Exit\n\n\t\t");
    fflush(stdin);

    switch(getch())
    {
        case '1': system("cls");phonebook();
                 break;
        case '2': system("cls"); notepad();
                  break;
        case '3': system("cls"); game();
                  break;
        case '4': system("cls"); exit(1);
                  break;
        default:  system("cls"); main_menu();
    }
}
void phonebook()
{

    fflush(stdin);

    printf("\t\t\t\a<><><><><><><><WELCOME TO PHONEBOOK><><><><><><><>\n");
    printf("\n\tPress the corresponding number to use the functions!\n");
    printf("\n\n\t\t\t\t\t-X-X-X-MENU-X-X-X-\n\n");
    printf("\t\t\t\t(1) Add phone number\n\t\t\t\t(2) Modify contacts\n\t\t\t\t(3) Read contacts\n\t\t\t\t(4) Delete contact\n\t\t\t\t(5) Back\n\t\t\t\t(6) Exit");

    switch(getch())
    {
        case '1': system("cls");add_ph();
                  break;
        case '2': system("cls"); modify_ph();
                  break;
        case '3': system("cls"); read_ph();
                  break;
        case '4': system("cls"); delete_ph();
                  break;
        case '5': system("cls");main_menu();

        case '6': system("cls"); exit(2);
                  break;
        default: system("cls");phonebook();
                 break;
    }
}
void add_ph()
{
    FILE *pt;
    char filename[20], name[20];
    struct Contact p1;
    fflush(stdin);
    printf("Enter name:\t");
    gets(p1.name);
    strcpy(name,p1.name);
    strcpy(filename,strcat(name,".txt"));
    pt=fopen(filename,"w");
    fprintf(pt,"Name: %s\n",p1.name);
    printf("Enter Mobile number:\t");
    scanf("%s",&p1.mobileno);
    fprintf(pt,"Mobile number: %s\n",p1.mobileno);
    printf("Enter e-mail id:");
    fflush(stdin);
    gets(p1.mail);
    fprintf(pt,"E-mail: %s\n",p1.mail);
    fclose(pt);
    printf("\nNew contact added successfully!");getch();
    system("cls");
    phonebook();

}
void modify_ph()
{
    FILE *ptr;
    char filename[20],name[20],ch =EOF;
    struct Contact p;
    long n;
    fflush(stdin);
    printf("Enter name:\t");
    gets(p.name);
    strcpy(name,p.name);
    strcpy(filename,strcat(name,".txt"));
    ptr=fopen(filename,"rb");
    if(ptr==NULL)
    {
      printf("\nFile doesn't exists! Please enter a valid name.\n");
      modify_ph();
    }
    while(fgetc(ptr)!='\n')
    {
        n= ftell(ptr);}
    fseek(ptr,n,0);
    fputc(ch,ptr);
    fclose(ptr);
    ptr=fopen(filename,"rb+");
      fseek(ptr,n,0);
    printf("Enter Mobile number:\t");
    scanf("%s",&p.mobileno);
    fprintf(ptr,"\nMobile number: %s\n",p.mobileno);
    fflush(stdin);
    printf("Enter e-mail id:");
    gets(p.mail);
    fprintf(ptr,"E-mail: %s\n",p.mail );
    printf("\nContact has been modified successfully!");
    fclose(ptr);
    getch();
    system("cls");
    phonebook();
}
void read_ph()
{ char z,ch[20],filename[20];
  FILE *rd;
  printf("\nEnter the contact name:\t");
  gets(ch);
  strcpy(filename,strcat(ch,".txt"));

  rd=fopen(filename,"r");
  if(rd==NULL)
  {
      printf("\nThe entered contact doesn't exist.\n");
      read_ph();
  }
  else{
        z = fgetc(rd);
    while (z != EOF)
    {
        printf ("%c", z);
        z = fgetc(rd);
    }
    getch();
    system("cls");
    fflush(stdin);
    phonebook();
  }


}

void delete_ph()
{
       FILE *ptr;
    char filename[20];
    struct Contact p;
    fflush(stdin);
    printf("Enter name:\t");
    gets(p.name);
    strcpy(filename,strcat(p.name,".txt"));
    remove(filename);
    printf("\nFile deleted successfully!");
    getch();
    system("cls");
    phonebook();

}
void notepad()
{
     system("cls");
    printf("Press the corresponding number to use the functions!");
    getch();system("cls");
    printf("\t\t**********MENU**********\n");
    printf("\t\t(1) Read notepad\n\t\t(2) Write in Notepad\n\t\t(3) Exit\n\n");
    fflush(stdin);

    switch(getch())
    {
        case '1': system("cls");read_notepad();
                 break;
        case '2': system("cls"); write_notes();
                  break;
        case '3': system("cls"); exit(3);
                  break;
        default:  system("cls"); notepad();
    }
}
void write_notes()
{   char entry[200];
    printf("\n\t\t\t\a<><><><><><><><WELCOME TO NOTEPAD><><><><><><><>\n\t\t\t");
    printf("\n\t\t\tEnter * to stop writing in the notepad");
    getchar();
    system("cls");
    FILE *npd;
    npd=fopen("Notepad.txt","a+");
    printf("\t\t\t--------------------NOTEPAD IS OPEN---------------------\n");
        scanf("%[^*]", &entry);
            fputs(entry, npd);
            //if you input * the notepad entry will stop
    system("cls");

    fclose(npd);
    printf("\nNotepad closed successfully!");
    getch();
    system("cls");
    fflush(stdin);
    notepad();
}
void read_notepad()
{
    char z;
  FILE *rd;

  rd=fopen("Notepad.txt","r");
  if(rd==NULL)
  {
      printf("\nThe notepad is empty\n");
      notepad();
  }
  else{
        z = fgetc(rd);
    while (z != EOF)
    {
        printf ("%c", z);
        z = fgetc(rd);
    }
    getch();
    system("cls");
    fflush(stdin);
    notepad();
  }

}

void game()
{ fflush(stdin);
char computer,player,ch;
  int num,result;
  srand(time(0));
  num= rand()%3+1;
  printf("\nThis is a game of rock,paper and scissor!");getch();
  if(num==1)
    computer= 'r';
    else if(num==2)
    computer= 'p';
   else computer= 's';
  printf("\nThe computer has chosen. Now, it's your turn.\n");getch();
  printf("\nPress r for rock, p for paper and s for scissors.\n");
  scanf("%c",&player);
  printf("\nComputer chose= %c\nPlayer chose= %c",computer,player);
  result=game_res(player,computer);
  if(result==0)
    printf("\nGame draw!");
  else if(result==1)
    printf("\nPlayer won!");
  else printf("\nComputer won!\n Better luck next time...");
  getch();
  fflush(stdin);
  printf("\nDO you want another round?Press y for yes and n for no.");
  scanf("%c",&ch);
  if(ch=='y'||ch=='Y')
    game();
  else
  {system("cls");
  main_menu();}

}
int game_res(char player,char computer)
{    if(player==computer)
       return 0;
    if(player=='r'&&computer=='p')
        return 2;
    else if(player=='p'&&computer=='r')
        return 1;
    if(player=='s'&&computer=='p')
        return 1;
    else if(player=='p'&&computer=='s')
        return 2;
    if(player=='r'&&computer=='s')
        return 1;
    else if(player =='s'&&computer=='r')
        return 2;
}
