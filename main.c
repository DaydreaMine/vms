#include <stdio.h>

#define LIST_SIZE 5
#define VENDING_NUMBER_DEFAULT ' '
#define VENDING_NUMBER_FAULT 'X'
#define VENDING_NUMBER_ENABLE '0'

static int insert_coin_total;
static char choose_goods_name='=';

typedef struct Goods
{
    char name[10];
    int price;
    int number;
} Goods;

struct Goods vending_goods[] = {
    {"Juice", 5, 5},
    {"Cola", 3, 1},
    {"Tea", 8, 2},
    {"Water", 2, 1},
    {"Coffee", 10, 9}};

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

