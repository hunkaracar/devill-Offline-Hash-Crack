from scapy.all import *

def packet_handler(packet):
	
    if packet.haslayer(EAPOL) and packet[EAPOL].type == 3:
        # EAPOL paketi bulundu
        wpa_key_data = packet[EAPOL].load
        return wpa_key_data


def filter_wpa_hash():
	
	# Pcap dosyasını oku
	pcap_file_path = "/root/yazici_wifi-01.cap"
	packets = rdpcap(pcap_file_path)

	# Her paket için paket işleyiciyi çağır
	list_of_values = []

	for packet in packets:
		wpa_key_data = packet_handler(packet)
		if wpa_key_data:
			parts = wpa_key_data.hex().split(":")
			for prt in parts:
				list_of_values.append(prt)

	# 15. indeksi al
	desired_value = list_of_values[14]

	wpa_hash_split = desired_value[190:]

	#print("Split HASH wpa:",wpa_hash_split)
	return wpa_hash_split

print(filter_wpa_hash())

"""

WPA hash cracking is under development

"""
