//rot47(ceaser cipher) cipher
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// work logical at terminal
// ./devill --format= rot47  <target_file> --decrypt

void rot47_decrypt(char *target_file){
      
      FILE *file;
      
      file = fopen(target_file,"r");
      
      if (file == NULL){
		  perror("\nFile could not be opened error!!!\n");
		  return;
	  }
	  
	  printf("\n$Decoding process for $[ROT47] encryption method\n");
	  printf("$ROT 47 is not a strong encryption method and is based on Ceaser encryption.\n");
	  printf("$Encrypts characters by shifting them 47 characters to the right or left\n\n");
	  
	  printf("Original Text>>> ");
	  
	  char charac;
	  while ((charac = fgetc(file)) != EOF){
		  putchar(charac);
	  }
	  
	  fclose(file);
	  
	  file = fopen(target_file, "r");
	  
	  if (file == NULL){
		  perror("\nFile could not be opened error!!!\n");
		  return;
		
	  }
	  
	  printf("Decrypt text>>> ");
	  
	  char character;
	  while ((character = fgetc(file)) != EOF){
		  if (character >= '!' && character <= 'z'){
			  character = '!' + (character - '!' + 47) % 94;
		  
	      }
	      
	      putchar(character);
	  }
	  
	  fclose(file);
	  
	 printf("\n$Cipher Type:Rot47\n");
	 printf("$Status:Decrypted\n");
	 printf("$Encrypted text decrypted by devill tool\n\n");
	  
}
