#Calculate Wordlist Length
import sys

def calc_len_wordlist(path_wordlist):
	
	try:
		count = 0
		with open(path_wordlist, "r",encoding="ISO-8859-1", errors="ignore") as file: #rockyou.txt dosyasi calisirken hata veriyor : cozum :encoding=ISO-8859-1
			for line in file:
				count += 1

		return count
	
	except KeyboardInterrupt:
		pass

"""
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py wordlist.txt")
        sys.exit(1)

    path_wordlist1 = sys.argv[1]
    #line_count = calc_len_wordlist(path_wordlist1)

    #print(f"\n'The word list file '{path_wordlist1}' consists of {line_count} lines.")

"""
