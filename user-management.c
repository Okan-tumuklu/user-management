//Linux family my name is Okan Tümüklü, I wrote this code for the community, family and mentality I belong to. I love you free penguins.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void UserList(void);
void UserAdd(void);
void UserDel(void);
void UserGroupSettings(void);
void UserEdit(void);
void UserHistory(void);


int main(void) {

    int choice;

    while(1) {
        printf("\n-------------------------------------\n\n");
        printf("1: User List\n2: User Add\n3: User Delete\n4: User Group Settings\n5: User Edit\n6: User History\n7: Quit.\n\n");
        printf("What action would you like to take:");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                UserList();
                break;
            case 2:
                UserAdd();
                break;
            case 3:
                UserDel();
                break;
            case 4:
                UserGroupSettings();
                break;
            case 5:
                UserEdit();
                break;
            case 6:
                UserHistory();
                break;
            case 7:
                printf("Bye bye\n");
                exit(0);
            default:
                printf("You have not taken any action. Bye bye\n");
        }
    }
    return 0;
}

//This function lists the usernames and their user IDs of all the users on the system whose user IDs fall within the range of 500 to 60000 using the awk command.
void UserList(void) {
    system("sudo awk -F':' '$3>=500 && $3<=60000 {print $1 \" \" $3}' /etc/passwd");
}

//This function adds a new user to the system by taking a username as input from the user and creating a new user with that username using the useradd command. It also sets a password for the new user using the passwd command.

void UserAdd(void) {
    char UserName[50];
    char command[19] = "sudo useradd -m ";
    char commandPasswd[19] = "sudo passwd ";

    printf("Enter a username:");
    scanf("%s", UserName);

    strcat(command, UserName);
    strcat(commandPasswd, UserName);

    system(command);
    system(commandPasswd);
}

//This function deletes an existing user from the system by taking a username as input from the user and deleting the user with that username using the deluser command. It also removes the user's home directory.

void UserDel(void) {
    char UserName[50];
    char command[30] = "sudo deluser --remove-home ";

    UserList();

    printf("-------------------------------------\n\n");
    printf("Enter the username you want to delete:");
    scanf("%s", UserName);

    strcat(command, UserName);

    system(command);
}

//This function provides options to add or remove users from a group by taking the group name and username as input from the user and adding or removing the user from the group using the gpasswd command.

void UserGroupSettings(void) {
    int option;
    char command[19] = "sudo gpasswd -a ";
    char command2[19] = "sudo gpasswd -d ";
    char GroupName[30];
    char UserName[51];

    printf("1: Adding users to a group\n2: Removing a user from a group\nOption:");
    scanf("%d", &option);

    if(option == 1) {
        printf("Enter the username:");
        scanf("%s", UserName);
        printf("Enter the group name:");
        scanf("%s", GroupName);

        strcat(command, UserName);
        strcat(command, " ");
        strcat(command, GroupName);

        system(command);
    }
    else if(option == 2) {
        printf("Enter the user name:");
        scanf("%s", UserName);
        printf("Enter the group name:");
        scanf("%s", GroupName);

        strcat(command2, UserName);
        strcat(command2, " ");
        strcat(command2, GroupName);

        system(command2);
    }
    else {
        printf("You made the wrong choice, bye\n");
    }
}

//This function allows the user to change the password for an existing user by taking the username as input and changing the password using the passwd command.

void UserEdit(void) {
    char UserName[50];
    char command[50] = "sudo passwd ";

    UserList();

    printf("-------------------------------------\n\n");
    printf("Enter the name of the user whose username and password you want to change:");
    scanf("%s",UserName);

    strcat(command, UserName);

    system(command);
}

//This function shows the password and group change history and user add and delete history for a particular user by taking the username as input and using the grep command to search the auth.log file for relevant entries.

void UserHistory(void) {
    char UserName[50];
    char command[100] = "sudo grep -e \"passwd\\|group\" /var/log/auth.log | grep ";
    char command2[100] = "sudo grep -e \"useradd\\|userdel\" /var/log/auth.log | grep ";

    UserList();

    printf("-------------------------------------\n\n");
    printf("Enter the name of the user whose history you want to see:");
    scanf("%s", UserName);

    strcat(command, UserName);
    strcat(command2, UserName);

    printf("\n\nPassword and group change history:\n\n");
    system(command);
    printf("\n\nUser add and delete history:\n\n");
    system(command2);
}

