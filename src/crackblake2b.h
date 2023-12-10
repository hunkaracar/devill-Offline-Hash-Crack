#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void BruteForce_attack_blake2b(char *format_h,char *path_wordlist,char *target_hash_file){
	
	char command[400];
	
	//command and combining
	snprintf(command,sizeof(command),"python3 Cr_blake2b.py \"%s\" \"%s\" \"%s\"",format_h,path_wordlist,target_hash_file);
	
	
	int result = system(command);
	
	if (result == 0){
		//printf("Command Successfuly Working");
	}
	
	else{
		//printf("Command Failed");
	}
	
     
}
