#include "customer.h"

Goods vending_goods[] = {
    {'A', "Juice", 5, 5},
    {'B', "Cola", 3, 1},
    {'C', "Tea", 8, 2},
    {'D', "Water", 2, 1},
    {'E', "Coffee", 10, 9}};

int insert_coin_total = 0;    //初始化投入钱币的数量
char choose_goods_name = '='; //初始化商品出货的显示
int numb1 = 0;                //初始化后台收入金额

void display()
{
    printf(
        "*----------------------------*\n"
        "|     Vending   Machine      |\n"
        "*----------------------------*\n");

    printf("|");
    for (int i = 0; i < LIST_SIZE; i++)
    {
        printf("%5c", 'A' + i);
    }
    printf("   |\n");

    printf("|");
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        printf("  ￥%d", vending_goods[i].price);
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
        printf("  [%c]", prodfalg);
    }
    printf("   |\n");
    printf("*----------------------------*\n");
    printf("|                    [$%2d]   |\n", insert_coin_total);
    printf("|                            |\n");
    printf("|         [=%c=]              |\n", choose_goods_name);
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
    int choice2 = 1;

    while (choice2 !=0)
    {
        do
        {
            if (choice2 > 4 || choice2 < 0)
            {
                printf("Please choose invalid choice \n");
            }
            printf("(2) Which coin would you like to insert?");
            for (int i = 0; i < LIST_SIZE; i++)
            {
                printf("%d.￥%d\n", i + 1, vending_goods[i].price);
            }
            printf("0.Go back!\n");
            printf("Your choice :"), scanf("%d", &choice2);
        } while (choice2 > 4 || choice2 < 0);
        if (choice2 != 0)
        {
            insert_coin_total += vending_goods[choice2].price;
            printf("You have inserted $%d\n", insert_coin_total);
            display();
        }
    }
}

void goods_choice()
{
    int choice3 = 1;
    while (choice3 != 0)
    {
        do
        {
            if (choice3 > 4 || choice3 < 0)
            {
                printf("please choose invallid choice.\n");
            }
            printf("(3) Press product button\n");
            for (int i = 0; i < LIST_SIZE; i++)
            {
                printf("%d.%2c\n", i + 1, vending_goods[i].id);
            }
            puts("0. Go back\n\n");
            printf("Your choice :"), scanf("%d", &choice3);
        } while (choice3 > 5 || choice3 < 0);
        if (insert_coin_total < vending_goods[choice3 - 1].price)
        {
            printf("Please choose invalid choice.\n");
        }
        else
        {
            numb1 += vending_goods[choice3 - 1].price;
            insert_coin_total -= vending_goods[choice3 - 1].price;
            vending_goods[choice3 - 1].number--;
            if (vending_goods[choice3 - 1].number <= 0)
            {
                printf("Please choose invalid choice.\n");
            }
            else
            {
                choose_goods_name = vending_goods[choice3 - 1].id;
                printf("You have pressed button %c.\n", vending_goods[choice3 - 1].id);
                vending_goods[choice3 - 1].number--;
            }
        }
    }
}

void coin_return()
{
    printf("Press return button\n");
    printf("¥%2d has been returned.\n", insert_coin_total);
    insert_coin_total = 0;
}
