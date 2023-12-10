//rot13(ceaser cipher) cipher
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// work logical at terminal
// ./devill --format= rot13  <target_file> --decrypt


void rot13_decrypt(char *target_file){
	
     FILE *file;
     
     file = fopen(target_file,"r");
     
     if (file == NULL){
		 perror("\nFile could not be opened error!!!\n");
	 }
	 
	 printf("\n$Decoding process for $[ROT13] encryption method\n");
	 printf("$ROT 13 is not a strong encryption method and is based on Ceaser encryption.\n");
	 printf("$Encrypts characters by shifting them 13 characters to the right or left\n\n");
	 
	 
     printf("Original Text>>> ");
     
     char charac;
     while ((charac = fgetc(file)) != EOF){
		 
		 putchar(charac);
	 }
	 
	 fclose(file);
	 
     
     file = fopen(target_file,"r");
     
     if (file == NULL){
		 perror("\nFile could not be opened error!!!\n");
	 }
	 
	
	 printf("Decrypt text>>> ");
	 
	 char character;
	 while ((character = fgetc(file)) != EOF){
		 
		 if ( character >= 'A' && character <= 'Z'){
			 character = 'A' + (character - 'A' + 13) % 26;
		 }
		 
		 else if (character >= 'a' && character <= 'z'){
			  character = 'a' + (character - 'a' + 13) % 26;
		 }
		 
		 putchar(character);
		 
	 }
	 
	 fclose(file);
	 
	 
	 printf("\n$Cipher Type:Rot13\n");
	 printf("$Status:Decrypted\n");
	 printf("$Encrypted text decrypted by devill tool\n\n");
	 
	 
}
