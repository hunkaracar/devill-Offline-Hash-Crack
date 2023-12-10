// ./devill [file1] [file2] --compare

// argv[1] = file1(get path)

// argv[2] = file2(get path)

// argv[3] = --compare

// for file1 => md5 hash and sha1  hash calculate

// for file2 => md5 hash and sha1 hash calculate

// > compare sha1 and md5 hash value  for S3cur1ty(Checking change status on a file)  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/evp.h>


void calculate_hash_md5(const char *filename_path, char *md5_result){
	
    FILE *file = fopen(filename_path, "rb");
    EVP_MD_CTX *md5Context = EVP_MD_CTX_new();
    unsigned char data[1024];
    size_t bytesRead;
    unsigned char md5Digest[MD5_DIGEST_LENGTH];

    EVP_DigestInit_ex(md5Context, EVP_md5(), NULL);


    while ((bytesRead = fread(data, 1, sizeof(data), file)) != 0) {
        EVP_DigestUpdate(md5Context, data, bytesRead);
    }


    EVP_DigestFinal_ex(md5Context, md5Digest, NULL);

    fclose(file);

    EVP_MD_CTX_free(md5Context);


    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&md5_result[i * 2], "%02x", md5Digest[i]);
    }
    
}

void calculate_hash_sha1(const char *filename_path, char *sha1_result){
    
    FILE *file = fopen(filename_path, "rb");
    EVP_MD_CTX *sha1Context = EVP_MD_CTX_new();
    unsigned char data[1024];
    size_t bytesRead;
    
    unsigned char sha1Digest[SHA_DIGEST_LENGTH];

    EVP_DigestInit_ex(sha1Context, EVP_sha1(), NULL);


    while ((bytesRead = fread(data, 1, sizeof(data), file)) != 0) {
        EVP_DigestUpdate(sha1Context, data, bytesRead);
    }


    EVP_DigestFinal_ex(sha1Context, sha1Digest, NULL);

    fclose(file);

    EVP_MD_CTX_free(sha1Context);


    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        sprintf(&sha1_result[i * 2], "%02x", sha1Digest[i]);
    }
    
}


int control_hash_compare(const char *filename_path1, const char *filename_path2){
	
	char md5_result1[MD5_DIGEST_LENGTH*2 + 1]; 
    char md5_result2[MD5_DIGEST_LENGTH*2 + 1]; 
	char sha1_result1[SHA_DIGEST_LENGTH*2 + 1];
	char sha1_result2[SHA_DIGEST_LENGTH*2 + 1];
	
	calculate_hash_md5(filename_path1,md5_result1);
	calculate_hash_md5(filename_path2,md5_result2);
	calculate_hash_sha1(filename_path1,sha1_result1);
	calculate_hash_sha1(filename_path2,sha1_result2);
	
	if (strcasecmp(md5_result1,md5_result2) == 0){
		
		printf("\n ---> (: MD5 hashes are Equal :)\n\n");
		printf("    File                                                                          MD5 hash value\n");
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("%s                    %s     \n",filename_path1, md5_result1);
		printf("%s                    %s     \n\n",filename_path2, md5_result2);
		
		
	}
	
	else{
		printf("\n ---> MD5 hashes are Different !!!!(Not Equal)!!!!!\n\n");
		printf("    File                                                                          MD5 hash value\n");
		printf("---------------------------------------------------------------------------------------------------\n");
		printf("%s                    %s     \n",filename_path1, md5_result1);
		printf("%s                    %s     \n\n",filename_path2, md5_result2);
		
	}
	
	if (strcasecmp(sha1_result1,sha1_result2) == 0){
		
		printf("\n ---> (: SHA-1 hashes are Equal :)\n\n");
		printf("    File                                                                          SHA-1 hash value\n");
		printf("-------------------------------------------------------------------------------------------------------\n");
		printf("%s                   %s     \n",filename_path1, sha1_result1);
		printf("%s                   %s     \n\n",filename_path2, sha1_result2);
		
	}
	
	else{
		printf("\n ---> SHA-1 hashes are Different !!!!(Not Equal)!!!!!\n\n");
		printf("   File                                                                              SHA-1 hash value\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("%s                   %s     \n",filename_path1, sha1_result1);
		printf("%s                   %s     \n\n",filename_path2, sha1_result2);
		
	}
	
	return EXIT_SUCCESS;
}
