#include <stdio.h>

//用户界面

#define LIST_SIZE 5
#define VENDING_NUMBER_DEFAULT ' '//主界面商品显示不可买
#define VENDING_NUMBER_FAULT 'X'  //主界面商品显示没货
#define VENDING_NUMBER_ENABLE '0' //主界面商品显示可买
#define VENDING_GOODS_NUMBER 10   //商品补货数量上限
#define VENDING_GOODS_PRICE 50    //商品价格上限
#

//定义商品结构体
typedef struct Goods
{
    char id;
    char name[10];
    int price;
    int number;
} Goods;

Goods vending_goods[LIST_SIZE];//商品数组

int insert_coin_total;//投入钱币的数量
char choose_goods_name ;//商品出货的显示
int numb1;  //后台收入金额

void display();//主界面

void main_menus();//主菜单

void coin_choice();//硬币菜单

void goods_choice();//商品菜单

void coin_return(); //余额退还