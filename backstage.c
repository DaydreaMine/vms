#include "customer.h"
#include "backstage.h"

#define PWD 1110 //密码

void backstage()
{
    printf("Correct code!\n");
    printf("(9) What would you like to do?\n");
    printf("1. Inspect machine status\n");
    printf("2. Withdraw all money\n");
    printf("3. Refill product\n");
    printf("4. Change product\n");
    printf("0. Go back\n\n");
    return;
}

void profit_menu()
{
    printf("(9-1)Machine status\n");
    printf("Amount of revenue: ¥%d\n", numb1);
    printf("Amount of inserted coins: ¥%d\n", insert_coin_total);
    for (int i = 0; i < LIST_SIZE; i++)
    {
        printf("%c. %s (¥%d) (%d left)\n", vending_goods[i].id, vending_goods[i].name, vending_goods[i].price, vending_goods[i].number);
    }
}

void withdrawn_menu()
{
    printf("(9-2) All money is being withdrawn.\n");
    printf("¥%d is withdrawn.\n", numb1);
    numb1 = 0;
}

void fuill_menu()
{
    int choice4 = 1;
    do
    {
        if (choice4 < 0 || choice4 >= LIST_SIZE)
        {
            printf("Please choose invalid choice \n");
        }
        else
        {
            printf("(9-3) Which product would you like to refill?\n");
            for (int i = 0; i < LIST_SIZE; i++)
            {
                printf("%d. %c\n", i + 1, vending_goods[i].id);
            }
            printf("0.Go back\n");
        }
        printf("Your choice: \n");
        scanf("%d", &choice4);
    } while (choice4 < 0 || choice4 >= LIST_SIZE);
    printf("You have refilled product %c to full.\n", vending_goods[choice4].id);
    vending_goods[choice4 - 1].number = VENDING_GOODS_NUMBER;
}

void change_menue()
{
    int choice5 = 1;
    do
    {
        if (choice5 < 0 || choice5 >= LIST_SIZE)
        {
            printf("Please choose invalid choice \n");
        }
        else
        {
            printf("(4-4) Which product would you like to change?\n");
            for (int i = 0; i < LIST_SIZE; i++)
            {
                printf("%d. %c\n", i + 1, vending_goods[i].id);
            }
            printf("0.Go back\n");
            printf("Your choice: \n");
            scanf("%d", &choice5);
        }
    } while (choice5 < 0 || choice5 >= LIST_SIZE);
    if (choice5 > 0 && choice5 < LIST_SIZE)
    {
        printf("You are changing product %c.", vending_goods[choice5].id);
        printf("Enter new product name: ");
        scanf("%s", vending_goods[choice5 - 1].name);
        printf("Enter new product price: ");
        scanf("%d", &vending_goods[choice5 - 1].price);
        do
        {
            if (vending_goods[choice5 - 1].price > 50 || vending_goods[choice5 - 1].price <= 0)
            {
                printf("product's price can't greater than 50 or less than 1");
                printf("Enter new product price: ");
                scanf("%d", &vending_goods[choice5 - 1].price);
            }
            else
            {
                vending_goods[choice5 - 1].number = VENDING_GOODS_NUMBER;
                printf("The new product %c has been filled to full.\n", vending_goods[choice5 - 1].id);
            }
        } while (vending_goods[choice5 - 1].price > 50 || vending_goods[choice5 - 1].price <= 0);
        vending_goods[choice5 - 1].number = VENDING_GOODS_NUMBER;
        printf("You have refilled product %c to full.\n", vending_goods[choice5 - 1].id);
    }
}

void service_menu()
{
    int lock = 1;
    int secret;
    int choice9;

    printf("(9) Opening service menu. Access code is required.\n");
    printf("Enter access code:");
    scanf("%d", &secret);
    if (secret != PWD)
    {
        printf("Please choose invalid choice \n");
    }
    else
    {
        while (lock)
        {
            int choice9;
            display();
            backstage();
            do
            {
                printf("Your choice:");
                scanf("%d", &choice9);
                switch (choice9)
                {
                case 1:
                    profit_menu();
                    break;

                case 2:
                    withdrawn_menu();
                    break;

                case 3:
                    fuill_menu();
                    break;

                case 4:
                    change_menue();
                    break;

                case 0:
                    lock = 0;
                    break;

                default:
                    printf("Please choose invalid choice \n");
                    break;
                }

            } while (choice9 < 0 || choice9 > 5);
        }
    }
}
