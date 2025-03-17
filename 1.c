#include <stdlib.h>
#include <string.h>
#include "2.h"

typedef struct responsedata {
	void * buf;
	int bufsz;
} responsedata;


static char *foo() {
	workerdata resources = zc_get_buffer();
	char * buf = resources.buf;
	if (buf == NULL) {
		buf = malloc (sizeof(char) * 1024);
	}
  char *buf2 = buf;
  return buf2;
}

int bar(char *buf) {
  char *cmd = strstr(buf, "|");
  int count = atoi(cmd);
  return count;
}

int main() {
  zc_storage_create();
  char *buf = foo();
  int count = bar(buf);
  zc_storage_free();
}
