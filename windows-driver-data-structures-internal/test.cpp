#include<ntifs.h>
#include<ntddk.h>
#include<wdm.h>

#include"slist.h"

template<typename... types>
void print(types... args)
{
	DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, args...);
}

struct example_struc
{
	SLIST_ENTRY entry;
	int a = 0x1;	
};

slist list;

void slist_test() {
	
	example_struc* ex1 = (example_struc*)ExAllocatePoolWithTag(NonPagedPool, sizeof(example_struc), '123');
	ex1->a = 0x12345671; 

	example_struc* ex2 = (example_struc*)ExAllocatePoolWithTag(NonPagedPool, sizeof(example_struc), '123');
	ex2->a = 0x12345672;

	list.InitSlist();
	list.Push(&ex1->entry);
	list.Push(&ex2->entry);

	PSLIST_ENTRY entry = list.Pop();  
	print("pop value %llx\n", ((example_struc*)entry)->a);  //0x12345672

	print("depth list : %d\n", list.Size());
}