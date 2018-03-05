//Tcp Client Code
#include <bits/stdc++.h>

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>


#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;


unsigned int m=500000;

struct itemEntry
{
    float unit_price;
    int quant;
    int id;
    char name[20];
    char brand[20];

};

class Client
{
public:
      int numItem;
      struct itemEntry dataBase[100];

      Client()
      {
          numItem=0;
      }

      void insertItem(char itemName[],char brand[],int pid,int c,float p);
      void deleteItem(char itemName[],int pid);
      itemEntry *searchi(char itemName[],int pid);
      void updateItem(char itemName[],int pid,int total,float price);
      void deleteDuplicate();
      void createStock();
      void insertStock();
      void readStock();
      void currentOrder();
};
void Client :: insertItem(char itemName[],char brand[],int pid,int c,float p )
{
    strcpy(dataBase[numItem].name,itemName);
    strcpy(dataBase[numItem].brand,brand);
    dataBase[numItem].id=pid;
    dataBase[numItem].quant=c;
    dataBase[numItem].unit_price=p;
    cout<<"\nItem inserted successfully\n";
    ++numItem;

}

void Client :: readStock()
{

    int i;
    ifstream file("tempStock.txt");
    i=0;

    cout<<BOLDGREEN<<left<<setw(10)<<"id"<<setw(10)<<"Name"<<setw(10)<<"brand"<<setw(10)<<"quant"<<setw(10)<<"Price"<<right<<BOLDYELLOW<<endl;
    cout<<BOLDBLACK<<left<<setw(10)<<"==="<<setw(10)<<"====="<<setw(10)<<"====="<<setw(10)<<"====="<<setw(10)<<"====="<<right<<BOLDYELLOW<<endl;
   
    while(file>>dataBase[i].id>>dataBase[i].name>>dataBase[i].brand>>dataBase[i].quant>>dataBase[i].unit_price)
    {
       // cout<<left<<setw(10)<<"id"<<setw(10)<<"Name"<<setw(10)<<"brand"<<setw(10)<<"quant"<<setw(10)<<"Price"<<right<<endl;
        cout<<left<<setw(10)<<dataBase[i].id<<setw(10)<<dataBase[i].name<<setw(10)<<dataBase[i].brand<<setw(10)<<dataBase[i].quant<<setw(10)<<dataBase[i].unit_price<<right<<endl;
        if(++i!= numItem)
            continue;
    }
  

//    return *this;
}

void Client::createStock()
{
    ofstream file("order.txt",ios::out);

    for(int i=0;i < numItem;++i)
    {
        //file<<"product"<<" "<<"Name"<<" "<<"brand"<<" "<<" "<<"quant"<<" "<<"unit price"<<endl;
        file<<dataBase[i].id<<" "<<dataBase[i].name<<" "<<dataBase[i].brand<<" "<<dataBase[i].quant<<" "<<dataBase[i].unit_price<<endl;

    }
   file.close();

    return ;

}
void Client :: currentOrder()
{

    int i;
    ifstream file("order.txt");
    i=0;

    while(file>>dataBase[i].id>>dataBase[i].name>>dataBase[i].brand>>dataBase[i].quant>>dataBase[i].unit_price)
    {
        cout<<dataBase[i].id<<" "<<dataBase[i].name<<" "<<dataBase[i].brand<<" "<<dataBase[i].quant<<" "<<dataBase[i].unit_price<<endl;
        if(++i!= numItem)
            continue;
    }


}

void welcomeMessage()
{
   cout<<"\n \n \n \n";
   cout<<BOLDRED<<"               ##      ## ######## ##        ######   #######  ##     ## ########"<<RESET<<endl;  usleep(m);
   cout<<BOLDBLUE<<"               ##  ##  ## ##       ##       ##    ## ##     ## ###   ### ##       "<<RESET<<endl; usleep(m);
   cout<<BOLDGREEN<<"               ##  ##  ## ##       ##       ##       ##     ## #### #### ##       "<<RESET<<endl; usleep(m);
   cout<<BOLDCYAN<<"               ##  ##  ## ######   ##       ##       ##     ## ## ### ## ######   "<<RESET<<endl; usleep(m);
   cout<<BOLDYELLOW<<"               ##  ##  ## ##       ##       ##       ##     ## ##     ## ##       "<<RESET<<endl; usleep(m);
   cout<<BOLDMAGENTA<<"               ##  ##  ## ##       ##       ##    ## ##     ## ##     ## ##       "<<RESET<<endl; usleep(m);
   cout<<BOLDRED<<"                ###  ###  ######## ########  ######   #######  ##     ## ######## "<<RESET<<endl;usleep(m+m);
  //system("clear");

   cout<<endl;
   cout<<BOLDRED"                                   #####  ####   "<<RESET<<endl; usleep(m);
   cout<<BOLDRED"                                     #   #    #   "<<RESET<<endl; usleep(m);
   cout<<BOLDMAGENTA"                                     #   #    #   "<<RESET<<endl; usleep(m);
   cout<<BOLDMAGENTA"                                     #   #    #   "<<RESET<<endl; usleep(m);
   cout<<BOLDBLUE"                                     #   #    #   "<<RESET<<endl; usleep(m);
   cout<<BOLDBLUE"                                     #    ####    "<<RESET<<endl; usleep(m);

  cout<<endl;

//system("clear");


   cout<<endl;
   cout<<BOLDMAGENTA<<"                             _                 _ _______ _     _  "<<RESET<<endl;    usleep(m);
   cout<<BOLDMAGENTA<<"                            | |               (_|_______) |   | | "<<RESET<<endl;      usleep(m);
   cout<<BOLDMAGENTA<<"                         ___| |__   ___  ____  _ _____  | |___| |  "<<RESET<<endl;     usleep(m);
   cout<<BOLDCYAN<<"                        /___)  _ \\ / _ \\|  _ \\| |  ___) |_____  |  "<<RESET<<endl;     usleep(m);
   cout<<BOLDGREEN<<"                       |___ | | | | |_| | |_| | | |      _____| |  "<<RESET<<endl;       usleep(m);
   cout<<BOLDRED<<"                       (___/|_| |_|\\ __/|  __/|_|_|     (_______|  "<<RESET<<endl;        usleep(m);
   cout<<BOLDRED<<"                                        | |                        "<<RESET<<endl;      usleep(m);      
   cout<<BOLDRED<<"                                        |_|                        "<<RESET<<endl;        

   usleep(m);
   usleep(m);
   usleep(m);

   system("clear");

return ;

}

void exitMessage()
{
    cout<<"................THANK YOU FOR SHOPPING WITH US......................";
}

struct auth
{
  char name[20];
  char password[20];
};

void authentication()
{
  struct auth a;

  char name[20],password[10];
  FILE *fp;
  int ch;

  cout<<BOLDBLACK<<"--------------------------------------------------------------------------------------------------"<<RESET<<endl;
  cout<<BOLDBLUE<<"                                SIGN UP/LOGIN TO SHOP                 "<<RESET<<endl;
  cout<<BOLDBLACK<<"---------------------------------------------------------------------------------------------------"<<RESET<<endl;

  cout<<BOLDMAGENTA<<"                                 1: LOGIN"<<endl;
  cout<<"                                 2: SIGNUP"<<RESET<<endl;
  cin>>ch;

  switch(ch)
  {
    case 1:
            a:cout<<"Enter your username : "; cin>>name;
              cout<<"Enter your password : "; cin>>password;

              fp=fopen("auth.txt","a+");

              while(fscanf(fp,"%s%s",a.name,a.password)!=EOF)
              {
                    if(!strcmp(name,a.name) && strcmp(password,a.password))
                    { system("clear");
                      cout<<RED<<"........................INCORRECT PASSWORD.........................."<<RESET<<endl;  usleep(m); system("clear"); usleep(m);
                      cout<<RED<<"........................INCORRECT PASSWORD.........................."<<RESET<<endl;  usleep(m); system("clear"); usleep(m);
                      cout<<RED<<"........................INCORRECT PASSWORD.........................."<<RESET<<endl;  usleep(m); system("clear"); 
                      system("clear");
                     
                      cout<<GREEN<<"TRY AGAIN"<<RESET<<endl;
                      usleep(m);
                      usleep(m);
                      
                      system("clear");
                      goto a;
                    }
                    else if(!strcmp(password,a.password) && strcmp(name,a.name))
                    {
                      cout<<RED<<"........................INCORRECT USERNAME.........................."<<RESET<<endl;
                      cout<<GREEN<<"TRY AGAIN"<<RESET<<endl;
                      usleep(m);
                      usleep(m);
                      
                      system("clear");
                      goto a;
                    }

                    if(!strcmp(name,a.name) && !strcmp(password,a.password))
                    {
                      cout<<GREEN<<"........................LOGIN SUCCESS.........................."<<RESET<<endl;
                      usleep(m);
                      usleep(m);
                      
                      system("clear");
                      return;
                    }
              }

              cout<<RED<<"!!!!!!!!!!!!!!!!!!!!!!!! NOT ALREADY A USER !!!!!!!!!!!!!!!!!!!!!"<<endl;
              cout<<".....................PLEASE SIGNUP BEFORE SHOP......................"<<RESET<<endl;
              usleep(m);
              usleep(m);
              system("clear");
             

    case 2:
              cout<<"Choose any user name within 8 characters  : ";  cin>>name;
              cout<<"Choose your password within 6 characters  : ";  cin>>password;
              fp=fopen("auth.txt","r+");
              fprintf(fp,"%s\t%s\n",name,password);
              cout<<GREEN<<"........................SIGNED UP SUCCESSFULLY......................"<<endl;
              cout<<GREEN<<"        REMEMBER THE USERID AND PASSWORD FOR FUTURE REFERENCE"<<RESET<<endl;
              fclose(fp); 
              usleep(m);
              usleep(m);
              system("clear");
              break;
   default :
              cout<<RED<<"................INVALID OPTION.............."<<RESET<<endl;
              cout<<".................PLEASE SELECT CORRECT OPTION..............."<<RESET<<endl;


  }

  fclose(fp);
}


void AddToCart(){


	char ch;
	int product_id,quant;
	ofstream fout("order.txt",ios::out);

	do{
		cout<<"Enter product id   : ";  cin>>product_id;
		cout<<"Enter quantity     : ";  cin>>quant;
		fout<<product_id<<" "<<quant<<"\n";
		cout<<"\nDo you want to add more items (y|n):";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
}

/*
void userMenu(){


    //Client st;
    //char name[20],brand[20];
    //int product_id,quant,unit_price,option;
    char ch;
    int option;
    char buffer[1024];
    FILE *fp;

	do{
        //system("clear");
        cout<<BOLDBLUE<<"\n-----------------------------------------------------------------------------"<<RESET<<endl;
        cout<<BOLDMAGENTA<<"                                         MENU"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                 _______________________"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                [                       ]\n"; 
        cout<<BOLDCYAN<<"                                | 1: Show items         |"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                | 2: Add to cart        |"<<RESET<<endl;
        //cout<<BOLDCYAN<<"                                | 3: Show current order |"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                | 3: Place the order    |"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                [_______________________]"<<RESET<<endl<<endl;
        cout<<BOLDBLUE<<"-----------------------------------------------------------------------------"<<RESET<<endl;
       

        cout<<BOLDMAGENTA<<"Your Option :"; 
        cin>>option;
        //system("clear");

        
        switch(option)
        {    
	        case 1: //display the items
	        		fp = fopen("tempStock.txt","r");
					//reading the stock menu file
					while(fgets(buffer,sizeof(buffer),fp)){
						printf("%s",buffer);
						bzero(buffer,sizeof(buffer));
					}
					fclose(fp);
	        		break;

	        case 2:  //add to cart
	        		AddToCart();
					break;
	        case 3: 
	        		cout<<"\n Do you want to coonfirm the order (y/n) :";
	        		cin>>ch;
	        		if(ch=='y'||ch=='Y'){
	        			cout<<"\nPlacing the order...";
	        			return;
	        		}
	        		else
	        			break;
        }

      }while(1);


}

*/

void tcpConnectionSetUp(int &sockfd, int port){

	struct sockaddr_in server;

	//Step 1: Intialise sockect file discriptor i.e sockfd
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bzero((char*)&server,sizeof(server));


	//Step 2: Intialise structure members
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	//Step 3: binding
	connect(sockfd,(struct sockaddr *)&server,sizeof(server));

	cout<<"\nClient is connected with server...";
}

int main(){


	//Step 0: Login system
	authentication();

	cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	cout<<BOLDMAGENTA<<"\n                                   Client is ready"<<RESET<<endl;
	cout<<BOLDBLUE"\n============================================================================="<<RESET<<endl;


	//Step 1: Connection Setup
	int sockfd, port;
	cout<<"\nPort No. : ";
	cin>>port;
	tcpConnectionSetUp(sockfd, port);

	
	//Step 2: Greeting Conversation
	char buffer[1024];
	bzero(buffer,sizeof(buffer));

	cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	recv(sockfd,buffer,100,0);
	//welcomeMessage();
	cout<<"\n\tServer: "<<buffer;
	cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	//send greeting
	char *greeting = "Hello..server!!";
	send(sockfd,greeting,strlen(greeting),0);
	

	//Step 3: Read the menu from server
	bzero(buffer,strlen(buffer));

	ofstream fout("tempStock.txt",ios::out);

	while(recv(sockfd,buffer,1024,0)>0) {
        if(strcmp(buffer,"end")==0){
        	//cout<<"\nInside..";
        	bzero(buffer,strlen(buffer));
        	break;
        }
        else{
        	printf("%s",buffer);
        	fout<<buffer;
        }
        bzero(buffer,strlen(buffer));
    }
    fout.close();

    cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
    cout<<"\nMenu is recieved..";
    cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	
    bzero(buffer,sizeof(buffer));

    cout<<"\n\n";
    //Step 4: Display the menu for User
    //userMenu();
    char ch;
    // do{
    		
    // }while(ch!='y'||ch!='Y');
    		
    AddToCart();
	cout<<"\n Do you want to confirm the order (y/n) :";
    cin>>ch;		

    if(ch == 'y' || ch == 'Y'){
    	//Step 5: Placing the order
	   	FILE *fp = fopen("order.txt","r");
		while(fgets(buffer,sizeof(buffer),fp)){
			//cout<<"\ninside while";
			send(sockfd,buffer,sizeof(buffer),0);
			bzero(buffer,sizeof(buffer));
			//puts(buffer);
		}
		strcpy(buffer,"end");
		send(sockfd,buffer,strlen(buffer),0);

		cout<<"\n\n";
		cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
		cout<<"\nOrder is placed..";
		cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
		fclose(fp);


		//Step 6: Recieving the bill
		bzero(buffer,strlen(buffer));

		while(recv(sockfd,buffer,1024,0)>0) {
	        printf("%s",buffer);
	        if(strcmp(buffer,"end")==0){
	        	//cout<<"\nInside..";
	        	bzero(buffer,strlen(buffer));
	        	break;
	        }
	        bzero(buffer,strlen(buffer));
	    }

	    cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	    cout<<"\nBill is recieved..";
	    cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
		
    }
    else{
    	cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	    cout<<"\nOrder is cancelled..";
	    cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
		
    }

    printf("\n");
    return 0;
}
