#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <ctype.h>
#include <unistd.h>


#include "hashidentify.h"
#include "musedhash.h"
#include "musedencrypt.h"
#include "hashtype/lenWordlist.h"
#include "crackmd5.h"
#include "cracksha1.h"
#include "cracksha224.h"
#include "cracksha256.h"
#include "cracksha384.h"
#include "cracksha512.h"
#include "cracksha3_224.h"
#include "cracksha3_256.h"
#include "cracksha3_384.h"
#include "cracksha3_512.h"
#include "rot13decrypt.h"
#include "rot47decrypt.h"
#include "crackcrc32.h"
#include "crackmd4.h"
#include "crackblake2b.h"
#include "crackblake2s.h"
#include "crackntlm.h"
#include "crackwhirlpool.h"
#include "compareFhash.h"
#include "version.h"





int main(int argc, char *argv[]) {
	

    if (argc == 2 && strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
		
        printf("\n$Devill Hash Identify And Crack Tool:::fast,strong,aggressive  [GNU\\Linux]\n");
        printf("$Developer: Hunkar Acar _!?!?!\n");
        printf("$Github: https://github.com/hunkaracar\n");
        printf("$Devill software is an offline hash cracking tool and uses its own algorithm in the attack.\n\n");

        printf("Usage: ./devill [options] .... [params] ..\n\n");
        printf("Options:\n\n");

        printf("\t+ --hI: Used to detect hash via API (intuitive)\n");
        printf("\t+ --format= [NAME]: Specifies which hash to attack\n");
        printf("\t\t Supported Hash Type:\n");
        printf("\t\t 1.md4\n");
        printf("\t\t 2.md5\n");
        printf("\t\t 3.sha-1\n");
        printf("\t\t 4.sha_224\n");
        printf("\t\t 5.sha_256\n");
        printf("\t\t 6.sha_384\n");
        printf("\t\t 7.sha_512\n");
        printf("\t\t 8.sha3_224\n");
        printf("\t\t 9.sha3_256\n");
        printf("\t\t 10.sha3_384\n");
        printf("\t\t 11.sha3_512\n");
        printf("\t\t 12.whirlpool\n");
        printf("\t\t 13.crc32\n");
        printf("\t\t 14.blake2b\n");
        printf("\t\t 15.blake2s\n");
        printf("\t\t 16.ntlm (NT hash)\n\n");
        printf("\t+ --wordlist= [path//wordlist]: Give a wordlist to perform cracking on\n");
        printf("\t+ --crack: After the format, wordlist and hash file are given, the cracking process is started with --crack.\n");
        printf("\t+ -hL: Returns a list of supported hash algorithms\n");
        printf("\t+ -fL: Returns a list of to inform encrypted file hash algorithms\n");
        printf("\t+ -V: Provides detailed display of time transactions\n");
        //printf("\t+ --info: Providing information about password improvements (suggestions)\n");
        printf("\t+ --decrypt: It is used for rot13, rot47 methods and must be given (wordlist is not used in these methods).\n");
        printf("\t\t Supported Encryption Type:\n");
        printf("\t\t 1.rot13\n");
        printf("\t\t 2.rot47\n\n");
        printf("\t+ --compare or -C: extracts and compares the md5 and sha1 hash value of two files(For S3cur1ty)\n");
        printf("\t+  -v or --version: Shows version information of devil software\n\n\n");
        //printf("\t+ conVhash: Converts encrypted files to specific hash value\n\n\n");
	
		printf("$Devill hash cracking tool offers many features, details, supports and provides information.$\n");
		printf("$Information retrieval, password weakness checking, performance monitoring and reporting, fast cracking, file hash extraction and cracking, etc.$\n");
		printf("\nExample uses for Devil software\n");
		printf("\t ./devill -hL \n");
		printf("\t ./devill --hI <hash> \n");
		printf("\t ./devill --format= crc32 --wordlist= /usr/share/wordlists/rockyou.txt /path/to/crc32.txt --crack  \n");
		printf("\t ./devill --format= crc32 --wordlist= /usr/share/wordlists/rockyou.txt /path/to/crc32.txt --crack -V\n");
		printf("\t ./devill --format= rot47 /path/to/rot47.txt --decrypt\n");
		printf("\t ./devill /path/to/rot13.txt /path/to/hashf --compare\n\n");
        printf("$!!!Break the hashes and don't forgive those who try to break you in your life ;)!!!$\n");
    }

    else if (argc == 3 && strcmp(argv[1], "--hI") == 0) {
        hashidtfy(argv[2]);
    }

    else if (argc == 2 && strcmp(argv[1], "-hL") == 0) {
        get_mostused_hash();
    }
    
    else if (argc == 2 && strcmp(argv[1], "-fL") == 0) {
		get_mostused_encrypt();
	}
	
	else if (argc == 2 &&  strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
		version_info();
	}
	
	
	//./devill [file1] [file2] --compare
	else if (argc == 4 && strcmp(argv[3], "--compare") == 0 || strcmp(argv[3],"-C") == 0) {
		printf("\n$devill software hash comparison module\n");
		printf("$This module tries to make basic security detection by comparing dangerous files with the original file format by making md5 and sha1 hash comparisons between files.\n");
		printf("$Be careful if the hashes are different, good luck !!;))\n\n");
		sleep(1);
		control_hash_compare(argv[1],argv[2]);
		
	}
	
	else if (argc == 5 && strcmp(argv[1], "--format=") == 0 && strcmp(argv[4], "--decrypt") == 0){
		
		//char *ch = tolower(argv[2]);
		
		if (strcmp(argv[2], "rot13") == 0){
			rot13_decrypt(argv[3]);
		}
		else if (strcmp(argv[2], "rot47") == 0){
			rot47_decrypt(argv[3]);
		}
		
		else {
			printf("\nEnter the format value in lowercase letters!!!\n");
		}
		
		
	}
	
	
	else if (argc == 7 && strcmp(argv[1],"--format=") == 0  && strcmp(argv[3],"--wordlist=") == 0 && strcmp(argv[6], "--crack") == 0) {
		//printf("$Verbose Mode:OFF\n");
		
		
		if (strcmp(argv[2],"md5") == 0){
			printf("$Verbose Mode:OFF\n");
		    BruteForce_attack_md5(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2],"sha1") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_sha1(argv[2],argv[4],argv[5]);
			
		}
		
		else if (strcmp(argv[2], "sha224") == 0) {
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_sha224(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "sha256") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_sha256(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "sha384") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_sha384(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "sha512") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_sha512(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2],"sha3_224") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_sha3_224(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "sha3_256") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_sha3_256(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "sha3_384") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_sha3_384(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "sha3_512") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_sha3_512(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "crc32") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_crc32(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "md4") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_md4(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "blake2b") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_blake2b(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "blake2s") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_blake2s(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "ntlm") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_ntlm(argv[2],argv[4],argv[5]);
		}
		
		else if (strcmp(argv[2], "whirlpool") == 0){
			printf("$Verbose Mode:OFF\n");
			BruteForce_attack_whirlpool(argv[2],argv[4],argv[5]);
		}
		
		else {
			printf("\nHash format is incorrect,cannot be proccessed!! Hash FOrmat CHECK--\n");
		}
		
		
	}
	
	else if (argc == 8 && strcmp(argv[1],"--format=") == 0  && strcmp(argv[3],"--wordlist=") == 0 && strcmp(argv[6], "--crack") == 0 && strcmp(argv[7], "-V") == 0 || strcmp(argv[8],"--info") == 0) {
		//printf("$Verbose Mode:ON\n");
		
		
		if (strcmp(argv[2],"md5") == 0){
			printf("$Verbose Mode:ON\n");
				
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_md5(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
			
		}
		
		else if (strcmp(argv[2], "sha1") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_sha1(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
			
		}
		
		else if (strcmp(argv[2], "sha224") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_sha224(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
		}
		
		else if (strcmp(argv[2], "sha256") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_sha256(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
		}
		
		else if (strcmp(argv[2], "sha384") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_sha384(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
        }
        
        else if (strcmp(argv[2], "sha512") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_sha512(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
	   
        }
        
        else if (strcmp(argv[2], "sha3_224") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_sha3_224(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
		}
		
		else if (strcmp(argv[2], "sha3_256") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_sha3_256(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
		}
		
		else if (strcmp(argv[2], "sha3_384") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_sha3_384(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
        }
        
        else if (strcmp(argv[2], "sha3_512") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_sha3_512(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
	   
        }
        
        else if (strcmp(argv[2], "crc32") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_crc32(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
        }
        
        else if (strcmp(argv[2], "md4") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_md4(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [32] workers (32 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
	   
        }
        
        else if (strcmp(argv[2], "blake2b") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_blake2b(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
        }
        
        else if (strcmp(argv[2], "blake2s") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_blake2s(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
	   
        }
        
        else if (strcmp(argv[2], "ntlm") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_ntlm(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
        }
        
        else if (strcmp(argv[2], "whirlpool") == 0){
			printf("$Verbose Mode:ON\n");
			
			struct timeval start_time, end_time;
			double elapsed_time;

			gettimeofday(&start_time, NULL);  // Başlangıç zamanını al

			BruteForce_attack_whirlpool(argv[2],argv[4],argv[5]);

			gettimeofday(&end_time, NULL);    // Bitiş zamanını al

			elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;  // Geçen süreyi saniyeye dönüştürerek hesapla

			printf("It works with [36] workers (36 child processing power)\n");
			printf("VERBOSE MODE::Calculate Hash Crack or Try Time\n");
			printf("Hash Cracking Or Try Time:%.6f seconds!! Fast?\n\n",elapsed_time);
			
        }
        
        //printf("if the hash is easily cracked, you can use the --info parameter for additional information!!!->>> If it's not broken you can ignore it\n");
        
        else {
			printf("\nHash format is incorrect,cannot be proccessed!! Hash FOrmat CHECK--\n");
			
		}
		
	}
	
    else {
        printf("\nUsage: Invalid arguments or usage. Use --help or -h for more information.\n");
    }

    return 0;
    
}
