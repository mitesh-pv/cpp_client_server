//Tcp Server Code

#include <bits/stdc++.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

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



struct itemEntry
{
    float unit_price;
    int quant;
    int id;
    char name[20];
    char brand[20];

};

class Server
{
public:
	int numItem;
	struct itemEntry dataBase[100];

	Server()
	{
	  numItem=0;
	}

	void insertItem(char itemName[],char brand[],int pid,int c,float p);
	void deleteItem(char itemName[],int pid);
	itemEntry *searchi(char itemName[],int pid);
	void updateItem(char itemName[],int pid,int total,float price);
	void countItem();
	void readCountItem();
	void deleteDuplicate();
	void createStock();
	void insertStock();
	Server readStock();
	void StockMenu();
};

Server Server :: readStock()
{

    int i;
    ifstream file("stock.txt");
    i=0;
    cout<<BOLDGREEN<<left<<setw(10)<<"id"<<setw(10)<<"Name"<<setw(10)<<"brand"<<setw(10)<<"quant"<<setw(10)<<"Price"<<right<<BOLDYELLOW<<endl;
    cout<<BOLDBLACK<<left<<setw(10)<<"==="<<setw(10)<<"====="<<setw(10)<<"====="<<setw(10)<<"====="<<setw(10)<<"====="<<right<<BOLDYELLOW<<endl;
    //cout<<BOLDBLACK<<left<<setw(10)<<"---"<<setw(10)<<"-----"<<setw(10)<<"-----"<<setw(10)<<"-----"<<setw(10)<<"-----"<<right<<BOLDYELLOW<<endl;

    while(file>>dataBase[i].id>>dataBase[i].name>>dataBase[i].brand>>dataBase[i].quant>>dataBase[i].unit_price)
    {
       // cout<<dataBase[i].id<<" "<<dataBase[i].name<<" "<<dataBase[i].brand<<" "<<dataBase[i].quant<<" "<<dataBase[i].unit_price<<endl;

        cout<<left<<setw(10)<<dataBase[i].id<<setw(10)<<dataBase[i].name<<setw(10)<<dataBase[i].brand<<setw(10)<<dataBase[i].quant<<setw(10)<<dataBase[i].unit_price<<right<<endl;
        if(++i!= numItem)
            continue;  
    }


    return *this;
}



void Server :: insertItem(char itemName[],char brand[],int pid,int c,float p )
{
    strcpy(dataBase[numItem].name,itemName);
    strcpy(dataBase[numItem].brand,brand);
    dataBase[numItem].id=pid;
    dataBase[numItem].quant=c;
    dataBase[numItem].unit_price=p;
    cout<<"\nItem inserted successfully\n";
    ++numItem;

}

void Server :: deleteItem(char itemName[],int pid)
{
    int i;
    for(i=0;i<numItem;++i)
    {
        if ((strcmp(itemName,dataBase[i].name)==0) && (dataBase[i].id==pid))
        {
            dataBase[i].quant--;
            cout<<BOLDGREEN"Item Deleted Successfully"<<RESET<<endl;
            return;
        }
        cout<<"\n\nItem Not Found\n";
    }
}

itemEntry *  Server::searchi(char itemName[],int pid)
{
    int i;

    ifstream file("stock.txt");


    i=0;
    cout<<"\nData:";
    while(file>>dataBase[i].id>>dataBase[i].name>>dataBase[i].brand>>dataBase[i].quant>>dataBase[i].unit_price)
    {
        cout<<dataBase[i].id<<" "<<dataBase[i].brand;
        if(++i< numItem)
            continue;
    }
      file.close();

    for( i=0;i<numItem;++i)
    {
        if((strcmp(itemName,dataBase[i].name) == 0) &&(dataBase[i].id == pid))
               return &dataBase[i];
    }
    return NULL;
}

void Server :: updateItem(char itemName[],int pid,int total,float price)
{
    itemEntry *item=searchi(itemName,pid);

    if(item==NULL)
    {
        cout<<"\n\nitem not found";
        return ;
    }
    item->quant+=total;
    item->unit_price=price;
}


void Server:: insertStock()
{
    ofstream file("stock.txt",ios::app);

    for(int i=0;i < numItem;++i)
    {
        //file<<"product"<<" "<<"Name"<<" "<<"brand"<<" "<<" "<<"quant"<<" "<<"unit price"<<endl;
        file<<dataBase[i].id<<" "<<dataBase[i].name<<" "<<dataBase[i].brand<<" "<<dataBase[i].quant<<" "<<dataBase[i].unit_price<<endl;

    }
   file.close();

    return ;

}

void Server::createStock()
{
    ofstream file("stock.txt",ios::out);

    for(int i=0;i < numItem;++i)
    {
        //file<<"product"<<" "<<"Name"<<" "<<"brand"<<" "<<" "<<"quant"<<" "<<"unit price"<<endl;
        file<<dataBase[i].id<<" "<<dataBase[i].name<<" "<<dataBase[i].brand<<" "<<dataBase[i].quant<<" "<<dataBase[i].unit_price<<endl;

    }
   file.close();

   countItem();

    return ;

}

void Server::countItem()
{
    ofstream file("num.txt",ios::out | ios::trunc);
    file<<numItem;
    file.close();

    return ;
}

void Server::readCountItem()
{

   int i;
    ifstream file("num.txt");
    i=0;

    while(file>>numItem){
        cout<<endl<<"Total no of Items Already present : "<<numItem<<endl;
    }
    file.close();

   
}


void Server::deleteDuplicate()
{
    int ch;
    cout<<"Enter postion to delete duplicate: ";  cin>>ch;

    for(int j=ch;j<numItem;++j)
    {
        dataBase[j-1].unit_price=dataBase[j].unit_price;
        dataBase[j-1].id=dataBase[j].id;
        dataBase[j-1].quant=dataBase[j].quant;

        strcpy(dataBase[j-1].name,dataBase[j].name);
        strcpy(dataBase[j-1].brand,dataBase[j].brand);


    }
    numItem--;
}  


void Server :: StockMenu()
{

    int i;
    ifstream file("stock.txt");

    ofstream fout("stockMenu.txt");

    i=0;
    cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
    fout<<BOLDGREEN<<left<<setw(10)<<"id"<<setw(10)<<"Name"<<setw(10)<<"brand"<<setw(10)<<"quant"<<setw(10)<<"Price"<<right<<BOLDYELLOW<<endl;
    fout<<BOLDBLACK<<left<<setw(10)<<"==="<<setw(10)<<"====="<<setw(10)<<"====="<<setw(10)<<"====="<<setw(10)<<"====="<<right<<BOLDYELLOW<<endl;
    //cout<<BOLDBLACK<<left<<setw(10)<<"---"<<setw(10)<<"-----"<<setw(10)<<"-----"<<setw(10)<<"-----"<<setw(10)<<"-----"<<right<<BOLDYELLOW<<endl;

    while(file>>dataBase[i].id>>dataBase[i].name>>dataBase[i].brand>>dataBase[i].quant>>dataBase[i].unit_price)
    {
       // cout<<dataBase[i].id<<" "<<dataBase[i].name<<" "<<dataBase[i].brand<<" "<<dataBase[i].quant<<" "<<dataBase[i].unit_price<<endl;

        fout<<left<<setw(10)<<dataBase[i].id<<setw(10)<<dataBase[i].name<<setw(10)<<dataBase[i].brand<<setw(10)<<dataBase[i].quant<<setw(10)<<dataBase[i].unit_price<<right<<endl;
        if(++i!= numItem)
            continue;  
    }
	fout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
}




void adminMenu(){

	Server st;
    char name[20],brand[20];
    int product_id,quant,unit_price,option;
    char ch[4];

	do{
         // system("clear");

        cout<<BOLDBLUE<<"\n-----------------------------------------------------------------------------"<<RESET<<endl;
        cout<<BOLDMAGENTA<<"                                         MENU"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                 ______________________"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                [                      ]\n"; 
        cout<<BOLDCYAN<<"                                | 1: Insert            |"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                | 2: Delete            |"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                | 3: Search            |"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                | 4: Update            |"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                | 5: Read Stock        |"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                | 6: Delete Duplicate  |"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                | 7: Exit Menu         |"<<RESET<<endl;
        cout<<BOLDCYAN<<"                                [______________________]"<<RESET<<endl<<endl;
        cout<<BOLDBLUE<<"-----------------------------------------------------------------------------"<<RESET<<endl;
       

        cout<<BOLDMAGENTA<<"Your Option :"; cin>>option;
        system("clear");

        
        switch(option)
        {    
	        case 1:  //insert

					st.readStock();
					st.readCountItem();
					cin.getline(name,80);
					cout<<BOLDMAGENTA<<"Enter name of item : ";  cin.getline(name,80);
					cout<<"Enter brand        : ";  cin.getline(brand,80);
					cout<<"Enter product id   : ";  cin>>product_id;
					cout<<"Enter quantity     : ";  cin>>quant;
					cout<<"Enter unit price   : ";  cin>>unit_price;
					cout<<RESET<<endl;
					st.insertItem(name,brand,product_id,quant,unit_price);
					st.countItem();
					st.createStock();
					break;

	        case 2:  //delete

					st.readStock();
					st.readCountItem();
					cin.getline(name,80);
					cout<<BOLDRED<<"\n\nEnter Name of item : ";
					cin.getline(name,80);
					cout<<"\n\nEnter product  id  : ";
					cin>>product_id;
					cout<<RESET<<endl;
					st.deleteItem(name,product_id);
					st.countItem();
					st.createStock();

					break;

	        case 3:  //search
					st.readStock();
					st.readCountItem();
					cin.getline(name,80);
					cout<<"\n\nEnter name of item : ";
					cin.getline(name,80);
					cout<<"\n\nEnter product id   : ";
					cin>>product_id;
					itemEntry *t;
					t = st.searchi(name,product_id);

					if(t!=NULL){
						cout<<"\n\n---------searching--------\n";
						cout<<"\nfound\n";
						cout<<"Name of item : "<<t->name<<endl;
						cout<<"brand name :"<<t->brand<<endl;
						cout<<"product id: "<<t->id<<endl;
						cout<<"quantity   :"<<t->quant<<endl;
						cout<<"unit price :"<<t->unit_price<<endl;
					}
					else{
						cout<<"\nitem not foud \n";
					}
					break;

	        case 4:  //update
					st.readStock();
					st.readCountItem();
					cout<<"Enter details for update :"<<endl;
					cin.getline(name,80);
					cout<<"Enter name of item       : ";  cin.getline(name,80);
					//cout<<"Enter brand        : ";  cin.getline(brand,80);
					cout<<"Enter product id         : ";  cin>>product_id;
					cout<<"Enter no of new entries  : ";  cin>>quant;
					cout<<"Enter new price          : ";  cin>>unit_price;
					st.updateItem(name,product_id,quant,unit_price);
					st.createStock();
					break;
	        case 5:
	                st=st.readStock();
	                break;

	        case 6: //delete duplicate  
	                st.readStock();
	                st.deleteDuplicate();
	                st.createStock();
	                break;

	        case 7: st.StockMenu();
	        		return;


        }

      }while(1);


}

//function to calculate total amount to be written on to the bill by search operation
// itemEntry Server :: findItem(int pid, int q, Server st1)
// {
//     int i,newQuant;
//     //st1.readCountItem();

//     ifstream file("stock.txt");

    
//     for( i=0;i<numItem;++i)
//     {

//         if((st1.dataBase[i].id == pid) && (q <= st1.dataBase[i].quant))
// 		{     
// 			newQuant=st1.dataBase[i].quant-q;
// 			//cout<<st1.dataBase[i].name<<" "<<st1.dataBase[i].id<<" "<<newQuant<<" "<<st1.dataBase[i].unit_price;
// 			st1.updateI(st1.dataBase[i].name,st1.dataBase[i].id,newQuant,st1.dataBase[i].unit_price);
// 			//return &dataBase[i];
// 			return st1.dataBase[i].;
// 		} 
//     }
//     return 0;
// }

void generateBill()  
{	

	Server st;
	st.readCountItem();

	cout<<"\nStock before shopping..\n";
	st.readStock();

	float total_price; 

	FILE *fout;
    fout = fopen("bill.txt","w");
    
    
    fprintf(fout, "%4s%10s%10s%10s%10s\n", "id","name","price","quantity","amount");
    fprintf(fout, "%4s%10s%10s%10s%10s\n", "====","====","========","=====","======");

    int flag = 0;
    float amount;
    int pid,quant;
    int i;

    ifstream fin("order.txt");
    
    while(fin >> pid >> quant)
    {
    	
    	for(i=0;i<st.numItem;++i)
    	{
	        if((st.dataBase[i].id == pid) && (quant <= st.dataBase[i].quant))
			{     
				st.dataBase[i].quant = st.dataBase[i].quant - quant;
				flag=1;
				break;
			} 
	    }
    	if(flag){
    		amount = st.dataBase[i].unit_price * quant;
    		fprintf(fout, "%4d%10s%10.2f%10d%10.2f\n", st.dataBase[i].id,st.dataBase[i].name,st.dataBase[i].unit_price,quant,amount);
    		total_price+=amount;
    	}
    	else {
    		fprintf(fout, "%4d%10s%10.2f%10d%10.2f\n", st.dataBase[i].id,st.dataBase[i].name,st.dataBase[i].unit_price,0,0);
    		cout<<st.dataBase[i].name<<" is not present in adequate amount";
    		
    	}
    	
    }
    fprintf(fout, "%40s\n", "===============================================");

    fprintf(fout,"\n\t\tTotal Amount : %.2f\n",total_price);
	

    cout<<"\nStock after shopping..\n";
    st.createStock();
	st.readStock();


	fin.close();
	fclose(fout);


    //updateStock

    // ofstream fp("stock.txt",ios::trunc);

    // cout<<"\nStock after shopping..\n";
    // for(i=0;i < st.numItem;++i)
    // {
    //     //file<<"product"<<" "<<"Name"<<" "<<"brand"<<" "<<" "<<"quant"<<" "<<"unit price"<<endl;
    //     fp<<st.dataBase[i].id<<" "<<st.dataBase[i].name<<" "<<st.dataBase[i].brand<<" "<<st.dataBase[i].quant<<" "<<st.dataBase[i].unit_price<<endl;

    // }
    // fp.close();


	

	return;

}



void tcpConnectionSetUp(int &newSockfd,int port){

	struct sockaddr_in server, client;

	//Step 1: Intialise sockect file discriptor i.e sockfd
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	bzero((char*)&server,sizeof(server));


	//Step 2: Intialise structure members
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	//Step 3: binding
	bind(sockfd,(struct sockaddr *)&server,sizeof(server));

	//Step 4: 
	listen(sockfd,1);
	socklen_t clientLen = sizeof(client);
	newSockfd = accept(sockfd,(struct sockaddr*)&client,&clientLen);

	cout<<"\nServer is connected with client...";
}


int main(){

	cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	cout<<BOLDMAGENTA<<"\n                                   Server is ready"<<RESET<<endl;
	cout<<BOLDBLUE"\n============================================================================="<<RESET<<endl;

	//Step 1: Show the admin menu
	adminMenu();

	//Step 2: Connection Setup
	int newSockfd, port;
	cout<<"\nPort No. : ";
	cin>>port;
	tcpConnectionSetUp(newSockfd, port);
	
	

	//Step 3: Greeting Conversation
	char *greeting = "Welcome to shopify";
	send(newSockfd,greeting,strlen(greeting),0);

	//recieve the first text..
	char buffer[1024];
	cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	recv(newSockfd,buffer,100,0);
	cout<<"\n\tClient: "<<buffer;
	cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;

	//Step 4: Send the menu to the client
	FILE *fp = fopen("stockMenu.txt","r");
	//sending the stock file
	while(fgets(buffer,sizeof(buffer),fp)){
		//cout<<"\ninside while";
		send(newSockfd,buffer,sizeof(buffer),0);
		bzero(buffer,sizeof(buffer));
		//puts(buffer);
	}
	fclose(fp);

	bzero(buffer,sizeof(buffer));
	strcpy(buffer,"end");
	send(newSockfd,buffer,strlen(buffer),0);
	
	cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	cout<<"\nFile sent..";
	cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	cout<<"\n\n";

	//Step 5: Recieve the order.

	ofstream fout("tempOrder.txt",ios::out);
	bzero(buffer,strlen(buffer));
    while(recv(newSockfd,buffer,1024,0)>0) {
        
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
    cout<<"\nOrder is recieved..\n";
    cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	cout<<"\n\n";

	//Step 6: Process the order.
	generateBill();


	//Step 7: Send the bill to user.
    fp = fopen("bill.txt","r");
	//sending the stock file
	while(fgets(buffer,sizeof(buffer),fp)){
		//cout<<"\ninside while";
		send(newSockfd,buffer,sizeof(buffer),0);
		bzero(buffer,sizeof(buffer));
		//puts(buffer);
	}
	fclose(fp);
	
	bzero(buffer,sizeof(buffer));
	strcpy(buffer,"end");
	send(newSockfd,buffer,strlen(buffer),0);

	cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
    cout<<"\nBill is sent..\n";
    cout<<BOLDBLUE<<"\n============================================================================="<<RESET<<endl;
	

	//Step 8: End of program
	printf("\n");
 
	return 0;
}