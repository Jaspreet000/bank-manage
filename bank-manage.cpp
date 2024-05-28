#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
#define stop Sleep(200);
class Account
{
    public:
    int account_no;
    char account_name[30];
    int deposit;
    char account_type;
    public:

    void random()
    {
        int rand();
        account_no=rand();
    }


    void create_account()
    {
        cout<<"\n Enter the name of account holder : ";
        cin>>account_name;
        /*cout<<"\n Enter the account number : ";
        cin>>account_no;*/
        cout<<"\n Enter the account type(S for savings type and C for current type) : ";
        cin>>account_type;
        cout<<"\n Enter the initial amount you want to deposit (>=500 for savings account and >=1000 for current account) : ";
        cin>>deposit;
        if(account_type=='S'||account_type=='s'&&deposit<500)
        {
            cout<<"\n Minimum balance required for savings account is 500 so deposit Rs. "<<500-deposit<<" more within time.";
        }
        else if(account_type=='C'||account_type=='c'&&deposit<1000)
        {
            cout<<"\n Minimum balance required for current account is 1000, so deposit Rs "<<1000-deposit<<" more within time.";
        }
        else
        {
            animation();
            cout<<"\n \n Account created successfully ........\n";
        }
    }


    void show_account()
    {
        cout<<"\n The name of account holder is : "<<account_name<<"\n The account number is : "<<account_no<<"\n The account type is : "<<account_type<<"\n The account's current balance is : "<<deposit;
    }


    void modify_acc()
    {
        int opt;
        cout<<"\n \n \n WELCOME TO THE MODIFY PANEL OF PATCH'D BANK : ";
        cout<<"\n \n 1. To modify the name of account holder : ";
        cout<<"\n 2. To modify the type of account : ";
        cout<<"\n 3. To exit. ";
        cout<<"\n Enter your choice : ";
        cin>>opt;
        switch(opt)
        {
            case 1:
            cout<<"\n The old name of account holder is : "<<account_name;
            cout<<"\n Enter the new name of account holder : ";
            cin>>account_name;
            cout<<"\n The name is successfully modified to "<<account_name;
            break;

            case 2:
            cout<<"\n The old account type is : "<<account_type;
            cout<<"\n Enter the new account type : ";
            cin>>account_type;
            cout<<"\n The account type is successfully modified to : "<<account_type;
            if(account_type=='c' && deposit<1000)
            {
                cout<<"\n Since you have just modified your account to current type i.e min. balance of bank account should be 1000 but your account balance is less than 1000 and you have to deposit Rs "<<1000-deposit<<" or more to make balance more than minimum .";
                cout<<"\n Enter the amount of money to deposit : ";
                cin>>deposit;
            }
            else
            {
                break;
            }
            break;

            case 3:
            break;

            default:
            cout<<"\n Enter the correct choice.";
            break;
        }

    }


    void deposit_amount(int amt)
    {
        deposit+=amt;
        cout<<"\n The amount is deposited successfully.";
        cout<<"\n The updated account balance is : "<<deposit;
    }


    void withdraw_amount(int amt)
    {
        deposit-=amt;
        cout<<"\n AMOUNT IS WITHDRAWED SUCCESSFULLY.";
        cout<<"\n The updated account balance is : "<<deposit;
    }


    void report()
    { 
        cout.width(10);
        cout<<account_no;
        cout.width(15);
        cout<<account_name;
        cout.width(15);
        cout<<account_type;
        cout.width(12);
        cout<<deposit<<"\n";
    }


    int return_acno()
    {
        return account_no;
    }


    int return_deposit()
    {
        return deposit;
    }


    char return_type()
    {
        return account_type;
    }


    void animation()
{
    cout<<"\n .";
    stop;
    cout<<"\n .";
    stop;
    cout<<"\n .";
    stop;
    cout<<"\n .";
    stop;
    cout<<"\n .";
    stop;
    cout<<"\n .";
    stop;
}


};



void logo()
{
    cout<<"\n ----------------------------------------------------------------------------------------------------------------------";
    Sleep(200);
    cout<<"\n - **************    **************    **************      **********        ****      ****     **    ************    -       ";
    Sleep(200);
    cout<<"\n - ****       ***    ****      ****    **************    **************      ****      ****     **    *************   -       ";
    Sleep(200);
    cout<<"\n - ****       ***    ****      ****         ****         ****                ****      ****     *     ****      ****  -       ";
    Sleep(200);
    cout<<"\n - **************    **************         ****         ****                **************           ****      ****  -       ";
    Sleep(200);
    cout<<"\n - ****              **************         ****         ****                ****      ****           ****      ****  -       ";
    Sleep(200);
    cout<<"\n - ****              ****      ****         ****         **************      ****      ****           *************   -       ";
    Sleep(200);
    cout<<"\n - ****              ****      ****         ****           **********        ****      ****           ************    -       ";
    Sleep(200);
    cout<<"\n ----------------------------------------------------------------------------------------------------------------------\n";
}



void menu()
{
    cout<<" \n 1. Create account. ";
    cout<<"\n 2. Show account. ";
    cout<<"\n 3. Modify account. ";
    cout<<"\n 4. Delete account. ";
    cout<<"\n 5. To deposit/withdraw money. ";
    cout<<"\n 6. To show the report of all accounts in tabular form. ";
    cout<<"\n 7. Contact us. ";
    cout<<"\n 8. Exit. ";
    cout<<"\n Enter your choice(1-8) : ";
}



void intro()
{
    cout<<"\n \n BANKING MANAGEMENT SYSTEM \n \n ";
    Sleep(1000);
    cout<<"\n \n \n \n MADE BY - JASPREET SINGH \n";
    Sleep(400);
    cout<<"\n ROLL NO. - 21010203022 \n ";
    Sleep(400);
    cout<<"\n COLLEGE - ABVGIET PRAGATINAGAR\n \n ";
    Sleep(400);
    cout<<"\n EMAIL - jaspreetsingh44555@gmail.com";
    Sleep(1000);
    cout<<"\n .";
    Sleep(1000);
    cout<<"\n .";
    Sleep(1000);
    cout<<"\n .";
    Sleep(1000);
    cout<<"\n .";
    cout<<"\n \n";
}



//function to write the record in file...
void write_account()
{
    Account user;
    fstream ofile;
    ofile.open("account.dat",ios::binary|ios::app);
    user.random();
    user.create_account();
    ofile.write((char *)&user,sizeof(Account));
    ofile.close();
}


//function to read specific record from file...
void display_sp(int n)
{
    Account user;
    bool found=false;
    fstream ifile;
    ifile.open("account.dat",ios::binary|ios::in|ios::out);
    if(!ifile)
    {
        user.animation();
        cout<<"\n File could not be opened!!. Press any key to move ahead. ";
        return;
    }
    user.animation();
    cout<<"\n Balance details : \n";
    while(ifile.read((char *)&user,sizeof(Account)))
    {
        if(user.return_acno()==n)
        {
            user.show_account();
            found=true;
            cout<<"\n \n The account is shown successfully.....\n \n ";
        }
    }
    ifile.close();
    if(found==false)
    {
        user.animation();
        cout<<"\n The entered account number doesn't exists.";
    }
}


//function to modify record of file...
void modify_account(int n)
{
    bool found = false;
    Account user;
    fstream file;
    file.open("account.dat",ios::binary|ios::in|ios::out);
    if(!file)
    {
        user.animation();
        cout<<"\n File could not be opened!!!  Press any key..... ";
        return;
    }
    while(file.read((char *)&user,sizeof(Account)))
    {
        if(user.return_acno()==n)
        {
            user.show_account();
            cout<<"\n \n \n";
            user.modify_acc();
            int pos=(-1)*static_cast<int>(sizeof(Account));
            file.seekp(pos,ios::cur);
            file.write((char *)&user,sizeof(Account));
            user.animation();
            cout<<"\n Record is updated successfully. ";
            found = true;
        }
    }
    file.close();
    if(found == false)
    {
        user.animation();
        cout<<"\n No Record is found.";
    }
}


//function to delete record of file.
void delete_account(int n)
{
    Account user;
    bool found = false;
    ifstream infile;
    ofstream outfile;
    infile.open("account.dat",ios::binary);
    if(!infile)
    {
        cout<<"\n Can't open the file. Press any key to exit....";
        return ;
    }
    outfile.open("temp.dat",ios::binary);
    infile.seekg(0,ios::beg);
    while(infile.read((char *)&user,sizeof(Account)))
    {
        if(user.return_acno()!=n)
        {
            outfile.write((char *)&user,sizeof(Account));
            found = true;
        }
    }
    infile.close();
    outfile.close();
    remove("account.dat");
    rename("temp.dat","account.dat");
    cout<<"\n Deletion window closing.";
    user.animation();
    if(found ==false)
    {
        cout<<"\n Account number not exist....";
    }
}


//function to make deposit or withdraw function workable....
void deposit_withdraw(int n)
{
    int amt,bal;
    bool found = false;
    Account user;
    fstream file;
    file.open("account.dat",ios::binary|ios::in|ios::out);
    if(!file)
    {
        user.animation();
        cout<<"\n Can't open file.";
        return;
    }
    while(file.read((char *)&user,sizeof(Account)))
    {
        if(user.return_acno()==n)
        {
            user.show_account();

            user.animation();

            cout<<"\n Which operation you want to perform - ";
            cout<<"\n 1. Deposit money. ";
            cout<<"\n 2. Withdraw money. ";
            cout<<"\n 3. Exit. ";
            cout<<"\n Enter choice : ";
            int choice;
            cin>>choice;
            switch(choice)
            {
                case 1:
                cout<<"\n Enter the amount of money you want to deposit : ";
                cin>>amt;
                user.deposit_amount(amt);
                break;

                case 2:
                cout<<"\n Enter the amount of money you want to withdraw : ";
                cin>>amt;
                bal= user.return_deposit()-amt;
                if(bal<500 && user.return_type()=='s'||user.return_type()=='S')
                {
                    cout<<"\n Insufficient Balance...";
                }
                if(bal<1000 && user.return_type()=='c'||user.return_type()=='C')
                {
                    cout<<"\n Insufficient Balance...";
                }
                else
                {
                    user.withdraw_amount(amt);
                }

                break;

                case 3:
                return;
                break;

                default:
                cout<<"\n Enter the correct choice. ";
                break;
            }
            int pos=(-1)*int(sizeof(Account));
            file.seekp(pos,ios::cur);
            file.write((char *)&user,sizeof(Account));
            user.animation();
            cout<<"\n Record updated...";

            found=true;
        }
    }
    file.close();
    if(found==false)
    {
        user.animation();
        cout<<"\n \n Record not found...";
    }

}


//function to show record of all persons......
void display_all()
{
    Account user;
    fstream fdiss;
    fdiss.open("account.dat",ios::binary|ios::in);
    cout<<"\n \n GENERATING REPORT :";
    user.animation();
    cout<<"\n ********************************************************************************************************************************** \n";
    cout.width(10);
    cout<<" ACCOUNT NUMBER";
    cout.width(15);
    cout<<"ACCOUNT NAME";
    cout.width(15);
    cout<<"ACCOUNT TYPE";
    cout.width(10);
    cout<<"BALANCE"<<"\n";
    if(!fdiss)
    {
        user.animation();
        cout<<"\n Can't open the file. Press any key to continue.....";
        return;
    }

    while(fdiss.read((char *)&user,sizeof(Account)))
    {
        user.report();
    }
    cout<<"\n ********************************************************************************************************************************** \n";
    fdiss.close();
}


//main function
int main()
{
    int ch,acc_no;
    logo();
    cout<<"\n WELCOME TO THE BANKING MANAGEMENT OF PATCH'D ORGANISATION : ";
    Sleep(1000);
    cout<<"\n \n";
    do
    {
        menu();
        cin>>ch;
        switch(ch)
        {
            case 1:
            write_account();
            break;

            case 2:
            display_all();
            cout<<"\n Enter the account number whose details you want to see : ";
            cin>>acc_no;
            display_sp(acc_no);
            break;

            case 3:
            display_all();
            cout<<"\n Enter the account number whose details you wanna modify : ";
            cin>>acc_no;
            modify_account(acc_no);
            break;

            case 4:
            display_all();
            cout<<"\n Enter the account number of account which you want to delete : ";
            cin>>acc_no;
            delete_account(acc_no);
            break;

            case 5:
            display_all();
            cout<<"\n Enter the account number to which you want to deposit/withdraw money : ";
            cin>>acc_no;
            deposit_withdraw(acc_no);
            break;

            case 6:
            display_all();
            break;

            case 7:
            intro();
            logo();
            break;

            case 8:
            cout<<"\n Thanks for being a customer of PATCH'D Bank. \n \n";
            logo();
            return 0;
            break;

            default:
            cout<<"\n The option you entered or choose doesn't hold any operation above. ";
            break;

        }
    }while(ch!='8');  
    return 0;
}