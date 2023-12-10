// WPA2 Hash Crack
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/*
 * 
 * 
 *WPA hash cracking is under development 
 * 
 * 
 * 
*/
void packet_filter(pcap_t *handle){
	
	//filtreyi tanımla
	struct  bpf_program fp;
	char filter_exp[] =  "ether proto 0x888e";
    
    
	//filtreyi derle
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Filtre derleme hatası: %s\n", pcap_geterr(handle));
        return;
    }
    
     // Filtreyi ayarla
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Filtre ayarlama hatası\n");
        return;
    }
   
    // Filtre ve pcap işlemcisini kapat
    pcap_freecode(&fp);

}


void packet_handler(unsigned char *user_data, const struct pcap_pkthdr *pkthdr, const unsigned char *packet){
	
	 // Bu fonksiyon, her bir paket okunduğunda çağrılır
	 printf("Packet Capture");
	  
}


int pcap_file_read(const char *path_file){
	
	char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // pcap dosyasını aç
    handle = pcap_open_offline(path_file, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Dosya açılamadı: %s\n", errbuf);
        return 1;
    }

    // Filtreyi uygula
    packet_filter(handle);

    // Paket işleyiciyi tanımla
    pcap_loop(handle, 0, packet_handler, NULL);

    // pcap işlemcisini kapat
    pcap_close(handle);
    
    return 0;
	
}
