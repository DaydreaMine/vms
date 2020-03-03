#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "backstage.h"



int main()
{
    int choice;
    int lock;
    while (lock)
    {
        display();
        main_menus();
        printf("which is your choice:\n");
        scanf("%d", &choice);
        if (choice == 0)
        {
            return 0;
        }
        switch (choice)
        {
        case 1:
            printf("(1) Read product information:\n");
            for (int i = 0; i < LIST_SIZE; i++)
            {
                printf("%c %s($%d)\n", vending_goods[i].id, vending_goods[i].name, vending_goods[i].price);
            }

            break;

        case 2:
            coin_choice();
            break;

        case 3:
            goods_choice();
            break;

        case 4:
            coin_return();
            break;

        case 9:
            service_menu();
            break;
            
        case 0:
            lock = 0;
            break;
        }
    }
}
