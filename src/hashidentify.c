#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "hashidentify.h"



size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size = size * nmemb;
    printf("%.*s", (int)total_size, (char *)contents);
    return total_size;
}


void hashidtfy(const char *hash) {
	
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl) {
        const char *target_url = "https://hashes.com/en/api/identifier?hash=";
		
		printf("\n$Devill Hash Identify Detect Engine::::::::::::::\n\n");
		printf("Data coming via API is being processed\n");
		printf("The value will be displayed in [Json] format\n");
		printf("Hash is being analyzed...\n");
		printf("If you wait too long, press [ctrl-c], check your [internet connection] and try again.\n");
		printf("Possible hash is shown above in algorithms");
        // URL oluştur
        char full_URL[2048];
        snprintf(full_URL, sizeof(full_URL), "%s%s", target_url, hash);

        curl_easy_setopt(curl, CURLOPT_URL, full_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		
        res = curl_easy_perform(curl);
		
		
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            printf("-curl is not connecting to the internet, check your connection-\n\n");
        }
		
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    
}
