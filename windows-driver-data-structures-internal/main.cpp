#include<ntifs.h>
#include<ntddk.h>
#include<wdm.h>

void unload(PDRIVER_OBJECT drv) {};

void slist_test();
extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT drv, PUNICODE_STRING reg) {
	drv->DriverUnload = unload;

	slist_test();
	return STATUS_SUCCESS;
}