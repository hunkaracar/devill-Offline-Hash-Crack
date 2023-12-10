#include <stdio.h>
#include <stdlib.h>


void get_mostused_hash(){
	 
	 printf("\n>--- The following types of file encryption algorithms are the most commonly used types of algorithms ---<\n");
	 printf(">--- Devill software supports cracking encrypted files with the following algorithms ---<\n\n");
	 
     FILE *file = fopen("hashinfo/mostusedhash.txt","r");
     
     if (file == NULL) {
		 perror("File open error!!");
		 //return 1;
	 }
	 
	 char line[150];
	 while(fgets(line,sizeof(line),file) != 0) {
		 printf("%s",line);
	}
	
	//dosyayı kapat
	fclose(file);
	printf("\n>--- Happy Hash Crack :))\n");
	
}
