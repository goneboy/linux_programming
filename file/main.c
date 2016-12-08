#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
	FILE *f;
	//char tbt_fname[1024];
	
	const char *name = "Bao Trung\n";
	char const *honey = "Ngoc Tuyen";

	f = fopen("/root/Desktop/baotrung/file/log_file.txt", "w+");
	
	fprintf(f, "%s", name);	
	fprintf(f, "%s", honey);	

	fclose(f);

	return 0;
}

