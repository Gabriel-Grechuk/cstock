#ifndef _CSTOCK_H_
#define _CSTOCK_H_


typedef unsigned int item_code;


int list_all(void);
int search_by_name(const char *name);
int search_by_code(item_code code);
int register_item(int amount, const char *name);
int add_item_by_name(int amount, const char *name);
int add_item_by_code(int amount, item_code code);
int delete_item_by_name(const char *name);
int delete_item_by_code(item_code code);
int withdrawal_item_by_name(int amount, const char *name);
int withdrawal_item_by_code(int amount, item_code code);

#endif // _CSTOCK_H_
