#Fetching information for Hash Cracking information

import lenWordlist

def requiredDis(path_wordlist):
	
	length_wordlist = lenWordlist.calc_len_wordlist(path_wordlist)
	
	print("\n$Devil hash cracking software started the cracking process with the appropriate algorithm")
	print("$The hash format to be cracked is $[HASH]")
	print(f"$Wordlist Length:{length_wordlist}")
	print(f"$The wordlist length is {length_wordlist} and the appropriate algorithm for cracking will be run")
	print("$You can use [ctrl+c] parameter to terminate or end the process")
	#time.sleep(1)
