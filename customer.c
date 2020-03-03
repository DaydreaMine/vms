#include "customer.h"

Goods vending_goods[] = {
    {'A', "Water", 2, 1},
    {'B', "Cola", 3, 1},
    {'C', "Juice", 5, 5},
    {'D', "Tea", 8, 2},
    {'E', "Coffee", 10, 9}};

int coin[5] = {1, 2, 3, 5, 10};

int insert_coin_total = 0;    //初始化投入钱币的数量
char choose_goods_name = '='; //初始化商品出货的显示
int num1 = 0;                 //初始化
char prodfalg[LIST_SIZE];     //初始化信号灯

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
    for (int i = 0; i < LIST_SIZE; i++)
    {
        prodfalg[i] = VENDING_NUMBER_DEFAULT;
        if (vending_goods[i].number <= 0)
        {
            prodfalg[i] = VENDING_NUMBER_FAULT;
        }
        else if (vending_goods[i].price < insert_coin_total)
        {
            prodfalg[i] = VENDING_NUMBER_ENABLE;
        }
        printf("  [%c]", prodfalg[i]);
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

    while (choice2 != 0)
    {
        do
        {
            display();
            if (choice2 > LIST_SIZE || choice2 < 0)
            {
                printf("Please choose invalid choice \n");
            }
            printf("(2) Which coin would you like to insert?\n");
            for (int i = 1; i < LIST_SIZE+1; i++)
            {
                printf("%d.￥%d\n", i, coin[i - 1]);
            }
            printf("0.Go back!\n");
            printf("Your choice :"), scanf("%d", &choice2);
        } while (choice2 > LIST_SIZE || choice2 < 0);
        if (choice2 != 0)
        {
            insert_coin_total += vending_goods[choice2-1].price;
            for (int i = 0; i < LIST_SIZE+1; i++)
            {
                if (insert_coin_total < vending_goods[i - 1].price)
                {
                    prodfalg[i - 1] = VENDING_NUMBER_DEFAULT;
                }
                else
                {
                    prodfalg[i - 1] = VENDING_NUMBER_ENABLE;
                }
            }

            printf("You have inserted $%d\n", insert_coin_total);
        }
    }
}

void goods_choice()
{
    int choice3 = 1;
    while (choice3)
    {
        do
        {
            display();
            if (choice3 > LIST_SIZE || choice3 < 0)
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
        } while (choice3 > LIST_SIZE || choice3 < 0);
        if (insert_coin_total < vending_goods[choice3 - 1].price)
        {
            printf("Please choose invalid choice.\n");
            prodfalg[choice3 - 1] = VENDING_NUMBER_DEFAULT;
        }
        else if (vending_goods[choice3 - 1].number <= 0)
        {
            printf("Please choose invalid choice.\n");
            prodfalg[choice3 - 1] = VENDING_NUMBER_FAULT;
        }
        else
        {
            numb1 += vending_goods[choice3 - 1].price;
            insert_coin_total -= vending_goods[choice3 - 1].price;
            vending_goods[choice3 - 1].number--;
            choose_goods_name = vending_goods[choice3 - 1].id;
            printf("You have pressed button %c.\n", vending_goods[choice3 - 1].id);
        }
    }
}

void coin_return()
{
    printf("Press return button\n");
    printf("¥%2d has been returned.\n", insert_coin_total);
    insert_coin_total = 0;
}
