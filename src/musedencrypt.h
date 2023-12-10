#include <stdio.h>
#include <stdlib.h>

void get_mostused_encrypt() {
     
     printf("\n>--- The following hash types are the most commonly used hash types ---<\n\n");
	 
     FILE *file = fopen("hashinfo/mostencryptFile.txt","r");
     
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
	printf("\n>--- is for informational purposes only :))\n");
}
