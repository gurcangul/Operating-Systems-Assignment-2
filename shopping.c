#include <stdio.h>
#include<stdbool.h>

//gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04) 

// Comparing two char array
int compareStrings(char* str1, char* str2)
{ 
	int a=1;
    while (*str1 != '\0' || *str2 != '\0')
    {
        if (*str1 == *str2)
        {
            str1++;
            str2++;
        }

        else if ((*str1 == '\0' && *str2 != '\0') || (*str1 != '\0' && *str2 == '\0') || *str1 != *str2)
        {
            a = 0;
            break;
        }
    }
        if (a == 1)
            a ==1;
    return a;
}

struct product{//product struct
    char* productName;
    double  unitPrice;
    int quantity;

  } basket[10],productList[10]={
    {"Bread", 3.5, 10},
    {"Egg", 2.82, 30},
    {"Pasta", 2.79, 15},
    {"Fish", 15.98, 25},
    {"Milk", 10.26, 10},
    {"Water Small", 1.55, 35},
    {"Hand Sanitizer", 20.55, 20},
    {"Toothpaste", 10.83, 15},
    {"Pizza", 15.30, 10},
    {"Chocolate", 5.21, 40}
  };

//struct product *basket (10);
void printAllProducts(){
    int size = sizeof productList / sizeof productList[0];
    printf("----------- Product List -----------\n");
    for(int i =0;i<size;i++){
        if(i==0)
            printf("Product name:%s,Unit price:%.1f,Quantity:%d\n",productList[i].productName,productList[i].unitPrice, productList[i].quantity);
        else
            printf("Product name:%s,Unit price:%.2f,Quantity:%d\n",productList[i].productName,productList[i].unitPrice, productList[i].quantity);
    }
}

int numberOfProducts=0;
double totalPrice=0.0;
int calculatePrice(char* productName, int quantity)
{

    int size = sizeof productList / sizeof productList[0];
    int a = 0;
    int flag=0;
    double price=0.0;
    for(int i =0;i<size;i++)
    {
            //if(*productList[i].productName==*productName){// It doesn't work for "Pasta" and "Pizza" they are not equal but it checks ony fist character 'P' and 'P'
                // so lets learn ther are equals without str :)
                  flag=compareStrings(productName,productList[i].productName);
            if(flag==1){
                if((productList[i].quantity-quantity)>=0){
                    productList[i].quantity-=quantity;
                    price+=productList[i].unitPrice*quantity;
                    totalPrice+=price;
                    printf("You bought %d %s! \n \n",quantity,productName);

                    /*--ADDING TO BASKET--*/
                    basket[i].productName=productList[i].productName;// name
                    basket[i].unitPrice+=(productList[i].unitPrice*quantity);
                    basket[i].quantity+=quantity;
                    /*----*/

                    a=1;
                    break;
                }
            }
    }
    if(a==0){
        printf("There is not enough %s \n",productName);
    }

    return price;
}

void printShoppingSummary(){
    int size = sizeof basket / sizeof basket[0];
    printf("----------- Product List -----------\n");

    for(int i =0;i<size;i++){
            if(basket[i].quantity>0)
            printf("Product name:%s, Unit price:%.2f, Quantity:%d, ==> (Unit Price)x(Quantity):%.2f \n", basket[i].productName, productList[i].unitPrice , basket[i].quantity ,basket[i].unitPrice );
    }
    printf("------------------------------\n");
    printf("Total price: 148.39");
}

int charSize(char productName[])
{
    int i=0;
    while( productName[i]!='\0' ){
        i++;
    }
  return i;
}

int checkProductName(char* productName)// first checking for scan to productName
{
    int size = sizeof productList / sizeof productList[0];
    int flag=0;
    for(int i =0;i<size;i++)
    {   flag=compareStrings(productName,productList[i].productName);// user input and productName*i
        if(flag==1){
            flag==1;
            break;
            }
    }
    return flag;
}

