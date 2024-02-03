#include <stdio.h>


#ifdef _WIN32
#define  PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

void show_device_features(){
	//printf("Dosya yolunda kullanılan karakter:%c\n",PATH_SEPARATOR);
	
	if (PATH_SEPARATOR == '/'){
		//char opSys[30] = "Gnu\\Linux";
		//printf("Operating System = %s\n",opSys);
		
		FILE *fp;
		char buffer[1024];
		
		fp = popen("lscpu | grep 'Model name:' | awk -F': ' '{print $2}'", "r");
		if (fp == NULL){
			printf("Command not working");
			exit(1);
		}
		
		fgets(buffer,sizeof(buffer),fp);
		printf("\n#Device 1: Gnu\\Linux x86_64 hardwareCPU..........%s\n", buffer);
		
		pclose(fp);
	}
	
	else if (PATH_SEPARATOR == '\\'){
		
		FILE *fp;
		char buffer[1024];

		fp = popen("systeminfo", "r");
		if (fp == NULL) {
			printf("systeminfo komutunu çalıştırırken bir hata oluştu\n");
		}


		while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        
			if (strstr(buffer, "Processor(s):") != NULL) {
				printf("%s", buffer);
				break; // İşlemci bilgisini bulduktan sonra döngüden çık
			}
		}

		pclose(fp); // Dosyayı kapat
	}
	
	else{
		exit(1);
	}
}
