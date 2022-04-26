#include <stdio.h>

#include "cstock.h"


int list_all(void)
{
  printf("Showing all.\n");
  return 0;
}

int search_by_name(const char *name)
{
  printf("Searching by name [%s].\n", name);
  return 0;
}

int search_by_code(item_code code)
{
  printf("Search by item code [%d].\n", code);
  return 0;
  
}

int register_item(int amount, const char *name)
{
  printf("Registering item [%s]. Amount: %d.\n", name, amount);
  return 0;
}

int add_item_by_name(int amount, const char *name)
{
  printf("Adding item [%s] by name. Amount; %d.\n", name, amount);
  return 0;
}

int add_item_by_code(int amount, item_code code)
{
  printf("Adding item [%d] by code. Amount: %d.\n", code, amount);
  return 0;
}

int delete_item_by_name(const char *name)
{
  printf("Deleteing item [%s] by name.\n", name);
  return 0;
}

int delete_item_by_code(item_code code)
{
  printf("Deleteing item [%d] by code.\n", code);
}

int withdrawal_item_by_name(int amount, const char *name)
{
  printf("Withdrawaling item [%s] by name. Amount: %d.\n", name, amount);
  return 0;
}

int withdrawal_item_by_code(int amount, item_code code)
{
  printf("Withdrawaling item [%d] by code. Amount: %d.\n", code, amount);
  return 0;
}

