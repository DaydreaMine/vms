#include <stdio.h>
#include <stdlib.h>


#define LIST_SIZE 5
#define VENDING_NUMBER_DEFAULT ' '
#define VENDING_NUMBER_FAULT 'X'
#define VENDING_NUMBER_ENABLE '0'

static int insert_coin_total;
static char choose_goods_name = '=';

typedef struct Goods
{
    char id;
    char name[10];
    int price;
    int number;
} Goods;

Goods vending_goods[] = {
    {'A', "Juice", 5, 5},
    {'B', "Cola", 3, 1},
    {'C', "Tea", 8, 2},
    {'D', "Water", 2, 1},
    {'E', "Coffee", 10, 9}};

void display()
{
    printf(
        "*----------------------------*\n"
        "|     Vending   Machine     |\n"
        "*----------------------------*\n");

    printf("|");
    for (int i = 0; i < LIST_SIZE; i++)
    {
        printf("%5c", 'A' + i);
    }
    printf("     |\n");

    printf("|");
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        printf("    ￥%d", vending_goods[i].price);
    }
    printf("  |\n");

    printf("|");
    char prodfalg;
    for (int i = 0; i < LIST_SIZE; i++)
    {
        prodfalg = VENDING_NUMBER_DEFAULT;
        if (vending_goods[i].number == 0)
        {
            prodfalg = VENDING_NUMBER_FAULT;
        }
        else if (vending_goods[i].price <= insert_coin_total)
        {
            prodfalg = VENDING_NUMBER_ENABLE;
        }
        printf("   [%c]", prodfalg);
    }
    printf("   |\n");
    printf("*----------------------------*\n");
    printf("|                     [$%2d]  |\n", insert_coin_total);
    printf("|                            |\n");
    printf("|            [=%c=]           |\n", choose_goods_name);
    printf("*----------------------------*\n");
    printf("\n");
}

void main_menus()
{
    printf("What would you like to do?\n");
    printf(" 1. Read product information\n");
    printf(" 2. Insert coin\n");
    printf(" 3. Press product button\n");
    printf(" 4. Press return button\n");
    printf(" 9. Open service menu (code required)\n");
    printf(" 0. Quit\n\n");
}

void coin_choice()
{
    int choice2;
    printf("(2) Insert coin?\n");
    printf("1. ¥1\n");
    printf("2. ¥2\n");
    printf("3. ¥5\n");
    printf("4. ¥10\n");
    printf("0. Go back\n\n");
    printf("your choice:  ");
    scanf("%d", &choice2);
    if (choice2 == 0)
    {
        return;
    }
    switch (choice2)
    {
    case 1:
        insert_coin_total += 1;
        printf("Your choice is ¥1 \n");
        break;
    case 2:
        insert_coin_total += 2;
        printf("Your choice is ¥2 \n");
        break;
        ;
    case 3:
        insert_coin_total += 5;
        printf("Your choice is ¥5 \n");
        break;
    case 4:
        insert_coin_total += 10;
        printf("Your choice is ¥10 \n");
        break;
    default:
        printf("Please choose invalid choice \n");
        break;
    }
    main_menus();
}

void goods_choice()
{
    int choice3;
    printf("(3) Press product button\n");
    for (int i = 0; i < LIST_SIZE; i++)
    {
        printf("%d.%2c\n", i + 1, vending_goods[i].id);
    }
    puts("0. Go back\n\n");
    printf("Your choice :"), scanf("%d", &choice3);
    if (insert_coin_total < vending_goods[choice3 - 1].price)
    {
        printf("Please choose invalid choice \n");
    }
    else
    {
        insert_coin_total -= vending_goods[choice3 - 1].price;
        choose_goods_name = vending_goods[choice3 - 1].id;
        printf("You have pressed button %c.\n", vending_goods[choice3 - 1].id);
        main_menus();
    }

    void return_button();
    {
        printf("Press return button\n");
        printf("¥%2d has been returned.\n", insert_coin_total);
        insert_coin_total = 0;
        main_menus();
    }

    void service_menu();
    {
        int secret;
        int choice9;
        printf("(9) Opening service menu. Access code is required.\n");
        printf("Enter access code:");
        scanf("%d", &secret);
        if (secret != 1110)
        {
            printf("Please choose invalid choice \n");
        }
        else
        {
            printf("Correct code!\n");
            printf("(9) What would you like to do?\n");
            printf("1. Inspect machine status\n");
            printf("2. Withdraw all money\n");
            printf("3. Refill product\n");
            printf("4. Change product\n");
            printf("0. Go back\n\n");
            printf("Your choice:");
            scanf("%d", &choice9);
            if (choice9 == 0)
            {
                printf("Going back!\n");
                return;
            }
            switch (choice9)
            {
            case 1:
                printf("(9-1)Machine status\n");

                break;
            }
        }
    }
}
int main()
{
    int choice;
    display();
    while (1)
    {
        main_menus();
        printf("which is your choice:\n");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            printf("(1) Read product information:\n");
            for (int i = 0; i < LIST_SIZE; i++)
            {
                printf("%d %s($%c)\n", vending_goods[i].id, vending_goods[i].name, vending_goods[i].price);
            }

        case 2:
            coin_choice();
        case 3:
            goods_choice();
        case 4:
            return_button();
        }
    }
}
