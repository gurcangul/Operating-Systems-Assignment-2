#include <stdio.h>  
#include<stdbool.h>  
#include <stdlib.h>
#include "shopping.h"
//gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04) 

int main()
{
    int totalPrice=0;
    int quantity;

    int numberOfProducts=0;
    int choice;
    bool x=true;
    while (x)
    {
        char *productName;
        productName=(char *) malloc(sizeof(char)*5); // allocating memory
        int size = 5;
        int n[50];
        printf("  \n---- MAIN MENU ---- \n 1- Buy a product \n 2- List all products\n 3- Shopping summary \n 4- Exit\n -------------------\n");
        printf("\nEnter the choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1://Buy a product
                printf("Name of product: ");
                scanf("%s", productName);
                if(checkProductName(productName)==0){
                    printf("Product not found!  %s\n", productName);
                    break;
                }
                int sizeofChar = charSize(productName);
                while(sizeofChar>size)
                {
                    productName = (char *)malloc(sizeof(char) * size * 2);
                    size = size * 2;
                }int k=0;

                while(productName[k]!='\0')
                {
                    productName[k] = productName[k];
                    k++;
                }
                printf("Quantity of product:");
                scanf("%d", &quantity);
                calculatePrice(productName,quantity);
                break;
            case 2:
                //List all products
                  printAllProducts();
                break;
            case 3:
                //Shopping summary
                printShoppingSummary(numberOfProducts);
                break;
            case 4://Exit
                x=false;
                break;
            default:
                printf("You entered wrong! \n");
                break;
        }
    }
}
