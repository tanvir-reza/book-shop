#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<windows.h>
using namespace std;
/**************************** ALL Functions     ********************/
void admin(void);
void login(void);
void registration(void);
/**************************** END ALL Functions ********************/
char phone[20],pass[20];
int loginFail=0;
string fname,lname,a,b;
class admin_Panel
{
public:
    void insertR();
    void displayR();
    void searchR();
    void updateR();
    void deleteR();
};
/**************************** Data Insert ***********************/
void admin_Panel::insertR()
{
    string b_name,a_name;
    int b_id,b_copy;
     system("cls");
    ofstream file("book.txt",ios::out|ios::app);
    if(!file)
    {
        cout<<"File create not Successful";
    }
    else
    {
        cout<<"\n\t\t\t\t Enter BOOK Information  "<<endl;
        cout<<"\n\n\n\t\t\t BOOK Name : ";
        cin>>b_name;
        cout<<"\n\n\n\t\t\t Author Name : ";
        cin>>a_name;
        cout<<"\n\n\n\t\t\t Book id Number : ";
        cin>>b_id;
        cout<<"\n\n\n\t\t\t available copy numbe : ";
        cin>>b_copy;
        file<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<b_copy<<"\n";
        file.close();
    }
}
/**************************** End Data Insert ********************/

/****************************  Data SHOW ************************/
void admin_Panel::displayR()
{
    system("cls");
    string b_name,a_name;
    int b_id,b_copy;
    ifstream file("book.txt",ios::in);
    if(!file)
    {
        cout<<"File create not Successful";
    }
    else
    {
        cout<<"\n\n\t\t\t\t ******* Storage Books Data   **********";
        cout<<"\n\n\n\t\t\t"<<"BOOK ID "<<" "<<" BOOK NAME "<<" "<<" AU. Name "<<" "<<" AVILABLE COPY "<<"\n";
        file>>b_id>>b_name>>a_name>>b_copy;
        while(!file.eof())
        {
            cout<<"\n\n\t\t\t"<<b_id<<"\t "<<b_name<<"\t\t"<<a_name<<"\t\t"<<b_copy<<"\n";
            file>>b_id>>b_name>>a_name>>b_copy;
        }
        cout<<"\n\n\n";
        file.close();

    }

}
/**************************** End Data Show ********************/

/**************************** Book Search ********************/
void admin_Panel::searchR()
{
    system("cls");
    string b_name,a_name;
    int b_id,b_copy,u_in_id,count = 0;
    ifstream file("book.txt",ios::in);
    if(!file)
    {
        cout<<"File create not Successful";
    }
    else
    {
        cout<<"\n\n\t\t\t\t ******* Search Specific Book   **********";
        cout<<"\n\n\t\t\t   Enter Book Id : ";
        cin>>u_in_id;
        //cout<<"\n\n\n\t\t\t"<<"BOOK ID "<<" "<<" BOOK NAME "<<" "<<" AU. Name "<<" "<<" AVILABLE COPY "<<"\n";
        file>>b_id>>b_name>>a_name>>b_copy;
        while(!file.eof())
        {
            if(b_id==u_in_id)
            {
                cout<<"\n\n\t\t\tBook Id : "<<b_id;
                cout<<"\n\n\t\t\tBook Author name : "<<a_name;
                cout<<"\n\n\t\t\tBook Copy Number : "<<b_copy;
                count++;
                break;
            }
            file>>b_id>>b_name>>a_name>>b_copy;
        }
        cout<<"\n\n\n";
        file.close();
        if(count==0)
        {
            cout<<"\t\t\t\t\t Sorry No Data Found"<<endl;

        }

    }
}
/**************************** End Book Search ********************/


/**************************** Book Data Update **********************/
void admin_Panel::updateR()
{
    system("cls");
    fstream file,file1;
    string b_name,b_na,a_name,a_na;
    int b_id,b_idu,b_copy,no_co,u_in_id,count = 0;
    cout<<"\n\n\t\t\t Update Book";
    file1.open("book1.txt",ios::app|ios::out);
    file.open("book.txt",ios::in);
    if(!file)
    {
        cout<<"File Open Fail";
    }
    else
    {
        cout<<"\n\n\t Enter Book Id : ";
        cin>>b_id;
        file>>b_idu>>b_name>>a_name>>b_copy;
        while(!file.eof())
        {
            if(b_id == b_idu)
            {
                cout<<"Book new Name : ";
                cin>>b_na;
                cout<<"Book Auth Name : ";
                cin>>a_na;
                cout<<"Book Copy : ";
                cin>>no_co;
                file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n";
                count ++;
                break;
            }
            else
            {
                file1<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<b_copy<<"\n";
                file>>b_idu>>b_name>>a_name>>b_copy;
            }

        }
        if(count==0)
        {
            cout<<"No Data Found .....";
            system("cls");
        }
    }
    file.close();
    file1.close();
    remove("book.txt");
    rename("book1.txt","book.txt");

}



/**************************** End Book Data Update ********************/


/**************************** Book Data Delete ***********************/
void admin_Panel::deleteR()
{
system("cls");
    fstream file,file1;
    string b_name,b_na,a_name,a_na;
    int b_id,b_idu,b_copy,no_co,u_in_id,count = 0;
    cout<<"\n\n\t\t\t Update Book";
    file1.open("book1.txt",ios::app|ios::out);
    file.open("book.txt",ios::in);
    if(!file)
    {
        cout<<"File Open Fail";
    }
    else
    {
        cout<<"\n\n\t Enter Book Id : ";
        cin>>b_id;
        file>>b_idu>>b_name>>a_name>>b_copy;
        while(!file.eof())
        {
            if(b_id == b_idu)
            {
                system("cls");
                cout<<"\n\n\t\t\t Delete Book Record";
                cout<<"\n\n\t\t\t One Book Record Delete Successfully";
                break;
            }
            else
            {
                file1<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<b_copy<<"\n";
                file>>b_idu>>b_name>>a_name>>b_copy;
            }

        }
        if(count==0)
        {
            cout<<"No Data Found .....";
        }
    }
    file.close();
    file1.close();
    remove("book.txt");
    rename("book1.txt","book.txt");
}


/**************************** End Book Data Delete ********************/


/************************   DashBoard      *********************/

class dashboard:public admin_Panel
{
public:
    void functionality();
};

void dashboard::functionality()
{
    int choise;
    system("cls");
    cout<<"\n\t\t\t****\t Welcome "<<a<<" "<<b<<" To Your DashBoard  ****"<<endl;
    cout<<"\n\n\n\t\t\t 1. Books Data Entry  ";
    cout<<"\n\n\n\t\t\t 2. Show Books  ";
    cout<<"\n\n\n\t\t\t 3. Search Book  ";
    cout<<"\n\n\n\t\t\t 4. Update Book Data  ";
    cout<<"\n\n\n\t\t\t 5. Delete Book Data  ";
    cout<<"\n\n\n\t\t\t 6. EXIT  ";
    cout<<"\n\n\n\n\n\t\t\t chose your Option  ";
    cin>>choise;

    switch (choise)
    {
    case 1:
        {
            insertR();
            functionality();
            break;
        }
    case 2:
        {
            displayR();
            system("pause");
            functionality();
            break;
        }
    case 3:
        {
            searchR();
           system("pause");
           functionality();
            break;
        }
    case 4:
        {
            updateR();
            system("pause");
            break;
        }
    case 5:
        {
            deleteR();
            system("pause");
            break;
        }
    case 6:
        {
            exit(0);
        }

    default:
        cout<<"\n\n\n\t\t\t Invalid Input...... Try Again";
        system("pause");
        functionality();
        break;
    }


}


/************************  END DashBoard      *********************/



/************************   Loader Class   *********************/
class dataStore
{
    int i;
public:
    void loader()
    {
        system("cls");
        cout<<"\n\n\t\t\t Data Storing ! \n\n\t\t\t\t\t\tPLEASE WAIT \n\n\n\t\t\t";
        for(i=0; i<=30; i++)
        {
            Sleep(100);
            cout<<"**";
        }
        cout<<"\n\n\t\t\t\t\t\t 100% Done";
    }
    void loader2()
    {
        system("cls");
        cout<<"\n\n\t\t\t Data Find ! \n\n\t\t\t\t\t\tPLEASE WAIT \n\n\n\t\t\t";
        for(i=0; i<=30; i++)
        {
            Sleep(100);
            cout<<"**";
        }
        cout<<"\n\n\t\t\t\t\t\t 100% Done";
    }
};
/************************   Admin (Login/Registration)   *********************/
void login()
{
    char inphone[20],inpass[20],sphone[20],spass[20];
    string sfname,slname;
    bool f_on = false;
    int res;
    ifstream file("admin.txt",ios::in);
    if(!file)
    {
        cout<<"File create not Successful";
    }
    else
    {
        system("cls");
        if(loginFail==1)
        {
            int j;
            cout<<"\n\n\n\t\t\t Login Fail  !!!";
            cout<<"\n\n\n\t\t\t\t\t Try Again ";
            cout<<"\n\n\n\t\t\t\t\t Go To main Menu "<<"\n\n\n\t\t\t\t\t Press  1 ";
            cin>>j;
            if(j==1)
            {
                system("cls");
                admin();
            }
        }
        else{
        cout<<"\n\n\n\t\t\t Your phone Number : ";
        cin>>inphone;
        cout<<"\n\n\n\t\t\t Your Password : ";
        cin>>inpass;
        dashboard d;
        dataStore s;
        s.loader2();
        while(!file.eof())
        {
            file>>sphone;
            file>>spass;
            file>>sfname;
            file>>slname;

        try
        {
            if((strcmp(sphone,inphone)==0) && (strcmp(spass,inpass)==0))
            {
                a = sfname;
                b = slname;
                d.functionality();
            }
            else

            {
                throw 1;
            }
        }
        catch(int b)
        {
            loginFail = 1;
            login();
        }
    }
        file.close();
    }
}

}
void registration()
{
    system("cls");
    ofstream file("admin.txt",ios::out|ios::app);
    if(!file)
    {
        cout<<"File create not Successful";
    }
    else
    {
        cout<<"\n\t\t\t\t Enter Your Information  "<<endl;
        cout<<"\n\n\n\t\t\t Your First Name : ";
        cin>>fname;
        cout<<"\n\n\n\t\t\t Your Last Name : ";
        cin>>lname;
        cout<<"\n\n\n\t\t\t Your phone Number : ";
        cin>>phone;
        int checkn;
        checkn = strlen(phone);
        if(checkn!=11)
        {
            cout<<"\n\n\t\t\tInvalid Phn Number   !!! \n";
            system("pause");
            registration();
        }
        else if(checkn==11)
        {


        cout<<"\n\n\n\t\t\t Your Password : ";
        cin>>pass;

        file<<phone<<endl;//<<pass<<" "<<fname<<" "<<lname;
        file<<pass<<endl;
        file<<fname<<endl;
        file<<lname<<endl;
        file.close();
        dataStore d;
        d.loader();
        admin();
        }
    }
}
void admin()
{
    system("cls");
    int chose;
    cout<<"\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t Select Your Option : Login  / Registration";
    cout<<"\n\n\n\t\t\t 1 . Login";
    cout<<"\n\n\t\t\t 2 . Registration "<<endl;
    cout<<"\n\n\t\t\t\t Enter :  ";
    cin>>chose;
    switch (chose)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    default:
        break;
    }
}
/************************   Main Function   *********************/
int main()
{
    admin();
    getch();
}
