//This project was made by Nicolás Serrrano García & Marcos Berbel Pascual 5/12/2024
//This project simulates the database of a small business. You can register a series of products, and you can edit them, remove them, search them, print them and much more 

#include <stdio.h> // user interface and UI
#include <ctype.h> //tolower() function 
#include <string.h> // strcmp() function
#include <stdbool.h> //booleans
#include <time.h> // ticket numeric code is generated based on the day
#include <stdlib.h> // ticket numeric code is randomised 

//constants

#define MAXPRODUCTS 50
#define DESCRIPTIONLENGTH 30
#define MAXTICKETS 100
#define MAXTICKETLINES 10


//struct declaration

    //auxiliary structs
    
typedef struct {

    char letters[3];
    int number;

} TProductCode;

typedef struct {
    
    int year;
    int month;
    int day;

} TDate;

typedef struct {
    
    int hour;
    int minute;

} Ttime;

    //principal structs

typedef struct {
    TProductCode productCode;
    char TicketLineDescrpition[DESCRIPTIONLENGTH];
    int soldUnits;
    int unitPrice;
    int discount;
    
} TticketLine;

typedef struct {
    int ticketNumberCode;
    TDate date;
    Ttime time;
    int totalSales;
    TticketLine ticketLines[MAXTICKETLINES];
    int numberOfTicketLinesIntroduced;

} Tticket;

typedef struct {
    
    TProductCode productCode;
    char description[DESCRIPTIONLENGTH];
    int stock;
    int minimumStock;
    float unitPrice;
    float discount;

} TProduct;

//function declaration

void printMenu(){
    
    printf("---------------------------------\n");
    printf("1. New product\n");
    printf("2. Remove product\n");
    printf("3. Edit a product\n");
    printf("4. Search for a product\n");
    printf("5. New ticket\n");
    printf("6. Search for/Remove a ticket\n");
    printf("7. Check stock\n");
    printf("8. Exit");
    printf("\n");
}

void printProductInfo(TProduct prod){
        printf("Product code: %s%d\n", prod.productCode.letters, prod.productCode.number);
        printf("Product description: %s\n", prod.description);
        printf("Stock: %d\n", prod.stock);
        printf("Minimum stock: %d\n", prod.minimumStock);
        printf("Unit price: %.2f\n", prod.unitPrice);
        printf("Discount(%%): %.2f\n", prod.discount);
}

int ticketCodeToday(){
    time_t t = time(NULL);
    struct tm * date = localtime(&t);
    int ticketCode = (date->tm_year + 1900) * 10000 + (date->tm_mon + 1) * 100 + date->tm_mday;
    return ticketCode;
}

void printTicket(Tticket ticket, TProduct product[MAXPRODUCTS], int lastProduct){
    printf("Ticket code: %d\n", ticket.ticketNumberCode);
    printf("Year of creation: %d\n", ticket.date.year);
    printf("Month of creation: %d\n", ticket.date.month);
    printf("Day of creation: %d\n", ticket.date.day);
    printf("Time of creation: %d:%d\n", ticket.time.hour, ticket.time.minute);
    printf("Total sales of the ticket: %d\n", ticket.totalSales);
    printf("Ticket Lines: \n\n");

    /*here*/
    for(int i=0; i < ticket.numberOfTicketLinesIntroduced; i++){
        for(int j = 0; j < lastProduct; j++){
            if((strcmp(product[j].productCode.letters, ticket.ticketLines[i].productCode.letters)==0) && (ticket.ticketLines[i].productCode.number == product[j].productCode.number)){
                printf("%d -> Product code: %3s%d\n\t~Product description: %s\n\t~Units of the product sold: %d\n\t~Price of one product: %f\n\t~Discount of the product(%%): %f\n", i + 1, ticket.ticketLines[i].productCode.letters, ticket.ticketLines[i].productCode.number, product[j].description, ticket.ticketLines[i].soldUnits, product[j].unitPrice, product[j].discount);
            }
        }
    }
    printf("\n");
}

void fillTicketTimeANDCode(Tticket * newTicket){
    time_t t = time(NULL);
    struct tm * dateNow = localtime(&t);

    newTicket->ticketNumberCode = ticketCodeToday();
    newTicket->date.year = dateNow -> tm_year + 1900;
    newTicket->date.month = dateNow -> tm_mon + 1;
    newTicket->date.day = dateNow -> tm_mday;
    newTicket->time.hour = dateNow -> tm_hour;
    newTicket->time.minute = dateNow -> tm_min;
}

void fillNewProduct(TProduct * prod, bool enableCodeChange){ //boolean parameter allows for code change. e.g when editing product ""= false" so as not to let code changes
    if(enableCodeChange){
        printf("Introduce the three letters of the product code: ");
        scanf(" %3s", prod->productCode.letters);
        printf("Introduce the number of the product code: ");
        scanf("%d", &prod->productCode.number);
    }
    printf("Introduce a brief description of the product: ");
    scanf("%s", prod->description);
    printf("Introduce the stock of the product: ");
    scanf("%d", &prod->stock);
    printf("Introduce the minimum stock: ");
    scanf("%d", &prod->minimumStock);
    printf("Introduce the unitary price of the product: ");
    scanf("%f", &prod->unitPrice);
    printf("Introduce the discount applied to the product: ");
    scanf("%f", &prod->discount);
}

void newProduct(TProduct product[MAXPRODUCTS], int * lastProduct){
    
    char check;

    TProduct newProd = {0};
    do{
        fillNewProduct(&newProd, true);

        printf("\n\n");

        printf("Here is your product\n\n");
        printf("\n");

        printProductInfo(newProd);

    printf("\n");
        printf("Do you want to save this product? (y/n): ");  
        scanf(" %1c", &check);
    }
    while(tolower(check) != 'y');

    if(tolower(check)=='y'){
        printf("Your product was saved succesfully!\n");
    }

    product[*lastProduct] = newProd;
    
    *lastProduct+=1;
}

void removeProduct(TProduct product[MAXPRODUCTS], int * lastProduct){
    
    char charactersToRemove[3];
    int numberToRemove;

    int indexToRemove; //will store the index of the element that user wants to delete

    printf("Introduce the letter code of the product you want to remove: ");
    scanf("%s", charactersToRemove);
    printf("Introduce the numeric code of the product you want to remove: ");
    scanf("%d", &numberToRemove);
    printf("\n");

    bool found=false;

    //search for the product
    for(int i=0; (i<*lastProduct) && !found; i++){
        if((strcmp(charactersToRemove,product[i].productCode.letters)==0) && (numberToRemove==product[i].productCode.number)){
            indexToRemove=i;
            found=true;
        }
    }

    char delete;

    if(!found){
        printf("\nThere are no products with that code!\n");
        return;
    } else{
        printProductInfo(product[indexToRemove]);

        printf("Do you want to delete this ticket? (y/n): ");  
        scanf(" %c", &delete);
        printf("\n");
    }

    if(tolower(delete) == 'y'){
        //delete product and compact memory
        for(int i=indexToRemove; i<*lastProduct + 1 /*+ 1 is for eliminate last product*/; i++){
            product[i]=product[i+1];
        }
    }

    printf("product %s%d was deleted succesfully!\n", charactersToRemove, numberToRemove);

    *lastProduct-=1;
}

void editProduct(TProduct product[MAXPRODUCTS], int lastProduct){

    char letterCodeToEdit[3];
    int numberCodeToEdit;


    printf("Introduce the letter product code: ");
    scanf(" %s", letterCodeToEdit);
    printf("Introduce the number of the product code: ");
    scanf("%d", &numberCodeToEdit);

    printf("\n");

    for(int i=0; i<lastProduct; i++){ //search and compare each product code with the one the user inputed
        if((strcmp(product[i].productCode.letters, letterCodeToEdit)==0) && (numberCodeToEdit == product[i].productCode.number)){ //compare product code
            printf("We found a coincidence!\n\n");
            printProductInfo(product[i]);
            printf("This is your old product\n");
            printf("Introduce the new product info\n");
            printf("---------------------------------\n");
            fillNewProduct(&product[i], false); // false because product is already created and code cannot be changed
            printf("---------------------------------\n\n");
            printf("Changes saved succesfully!\n\n");
            return;
        }
    }
    printf("There were no coincidences!\n\n");
}

void searchProduct(TProduct product[MAXPRODUCTS], int lastProduct){
 char letterCodeToEdit[3];
    int numberCodeToEdit;


    printf("Introduce the letter product code: ");
    scanf(" %s", letterCodeToEdit);
    printf("Introduce the number of the product code: ");
    scanf("%d", &numberCodeToEdit);

    printf("\n");

    for(int i=0; i<lastProduct; i++){
        if((strcmp(product[i].productCode.letters, letterCodeToEdit)==0) && (numberCodeToEdit == product[i].productCode.number)){ //Search product code
            printf("We found a coincidence!\n");
            printf("This is your product\n\n");
            printf("---------------------------------\n");
            printProductInfo(product[i]);
            printf("---------------------------------\n\n");
            return;
        }
    }
    printf("There were no coincidences!\n\n");
}

void newTicket(Tticket ticket[MAXTICKETS], TProduct product[MAXPRODUCTS], int * lastTicket, int lastProduct){

    Tticket newTicket = {0};
    
    fillTicketTimeANDCode(&newTicket);
    
    bool userWantsNewLine;
    int soldUnitsSum = 0;

    for(int j = 0; (j < 10) && userWantsNewLine; j++){

        printf("Introduce the three letters of the product code: ");
        scanf("%3s", newTicket.ticketLines[j].productCode.letters);

        printf("Introduce the number of the product code: ");
        scanf("%d", &newTicket.ticketLines[j].productCode.number);

        bool found = false; // end the loop when a similarity is found

        int userProductPosition;

        for(int i = 0; (i < lastProduct) && !found; i++){
            if((strcmp(newTicket.ticketLines[j].productCode.letters, product[i].productCode.letters)==0) &&
               (newTicket.ticketLines[j].productCode.number == product[i].productCode.number)){

                printf("The product was found!!\n");
                printf("---------------------------\n");

                printProductInfo(product[i]);
                userProductPosition=i;
            
                if(product[i].discount > 0){
                    float discountPrice = product[i].unitPrice - (product[i].unitPrice * (product[i].discount / 100));
                    printf("Price after the discount is applied: %.2f\n", discountPrice);
                }
                bool isEnough = true; // if the user enters a higher number of products than the stock the program will ask for it again

                do{
                    printf("How many units do you want to sell? (0 to leave): ");
                    scanf("%d", &newTicket.ticketLines[j].soldUnits);

                    if((newTicket.ticketLines[j].soldUnits > product[userProductPosition].stock)){
                    
                        printf("You do not have enough products to sell\n\n");
                        printf("Please try again\n\n");

                        isEnough = false;

                    } else if(newTicket.ticketLines[j].soldUnits==0){
                        isEnough = true;
                    }
                    soldUnitsSum+=newTicket.ticketLines[j].soldUnits;

                } while(!isEnough);

                newTicket.totalSales=soldUnitsSum;

                found = true;
            } 
            else{
                printf("There was no product with that code!\n");
            }
        }

        char temp;
        printf("Do you want to create another ticket line?(y/n): ");
        scanf(" %c", &temp);
        userWantsNewLine = (temp == 'y') ? true : false; // converts the temp character to bool. If user pressed 'y' then saves true in userWantsNewLine. Can be replaced with an if-else
        newTicket.numberOfTicketLinesIntroduced +=1;
    }
    ticket[*lastTicket] = newTicket;
    *lastTicket+=1;
}

void removeORSearchTicket(Tticket ticket[MAXTICKETS], TProduct product[MAXPRODUCTS], int * lastTicket, int lastProduct){

    int numericCodeToday;
    int ticketSelected;

    printf("Introduce the numeric code of the ticket (all the tickets created on that day will be displayed): ");
    scanf("%d", &numericCodeToday);


    do{
        for(int i=0; i<*lastTicket;i++){
            if(ticket[i].ticketNumberCode == numericCodeToday){
                printf("Ticket number %d\n", i);
                printTicket(ticket[i], product, lastProduct);
                printf("\n");
            }
        }
        printf("Which ticket do you want to remove?(enter -1 to leave): ");
        scanf("%d", &ticketSelected);

        if((ticketSelected > -1) && (ticketSelected < *lastTicket)){
            for(int j = ticketSelected; j < *lastTicket + 1; j++){
                ticket[j] = ticket[j + 1];
            }
            printf("The ticket has been removed succesfully\n");
            *lastTicket -=1;
        }
        else if((ticketSelected < -1) || (ticketSelected > *lastTicket)){
            printf("That ticket is not identified\n");
        }
        
    } while(ticketSelected != -1);
}

//main function

int main(){

    TProduct products[MAXPRODUCTS];
    Tticket tickets[MAXTICKETS];

    int productCount = 0;
    int ticketCount = 0;

    int option;

    do{
        printMenu();
        scanf("%d", &option);
        fflush(stdin);

        switch(option){
            case 1: // new product
                newProduct(products, &productCount);
                break;
            case 2: // remove product
                
                if(productCount==0){
                    printf("\nThere are no products!\n\n");
                }
                else{
                    removeProduct(products, &productCount);
                }
                break;
            case 3: // edit a product

                if(productCount==0){
                    printf("\nThere are no products to edit!\n\n");
                } else{
                    editProduct(products, productCount);
                }
                break;
            case 4: // search for a product
            
                if(productCount==0){
                    printf("\nThere are no products!\n\n");
                } else{
                    searchProduct(products, productCount);
                }
                break;
            case 5: // new ticket
                if(productCount==0){
                    printf("There are no products, you can't create a ticket!\n");
                } else{    
                    newTicket(tickets, products, &ticketCount, productCount);
                }
                break;
            case 6: // search for/remove a ticket
                if(ticketCount==0){
                    printf("There are no tickets to search!\n");
                } else{
                    removeORSearchTicket(tickets, products, &ticketCount, productCount);
                }
                break;
            case 7: // check stock
                break;
            case 8: // exit program
                break;
            default: // user entered incorrect number
                break;
        }
    } while(option != 8);

    return 0;
}

//todo: 
// - When creating a new product (newProduct funct.), make a way to check if the user entered a product code that already exists
// - Implement a way to let user exit from any menu at any time by pressing exit
// - Everytime the program asks the user to introduce information there is no way to make sure the input is correct. Program crashes when introducing something incorrect.
// - in function printTicket, starting on comment /*here*/, for the line tickets to print correctly, for each 
// iteration of the ticket line, program must get the information of the product related to that ticket line, so as to print it when needed. Need to implement the 
// produts array as a parameter and in each iteration search for the product inside the products list. When found, then print the information as such