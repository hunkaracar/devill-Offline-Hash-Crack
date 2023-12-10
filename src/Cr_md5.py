#md5 hash crack
import sys
import lenWordlist
import hashlib
import time
import requiredDisplay
from multiprocessing import Pool


def worker(passw, hash_read):
	
    try:
        hashed_password = hashlib.md5(passw.strip().encode('ISO-8859-1', errors='ignore')).hexdigest()
        if hashed_password == hash_read:
            return passw
            
    except Exception as e:
        pass  # Hata durumunda işlem yapma




def crack_md5(format_h,path_wordlist1,target_hash_file):
	
	length_wordlist = lenWordlist.calc_len_wordlist(path_wordlist1)
	
	if format_h.lower() == 'md5':
		
		#passw = None
		if length_wordlist > 100000:
			#process
			#multi processing attack(36 per)
			
			with open(path_wordlist1,"rb") as file:
				password_read = file.read().decode("ISO-8859-1", errors="ignore").splitlines()
				
				
			with open(target_hash_f,"r") as file:
				hash_read = file.readline().strip()
				hash_read = hash_read.lower()
			
			requiredDisplay.requiredDis(path_wordlist1)
			
			pool = Pool(36) #36 işlem kullanarak çoklu işlem havuzu başlatılıyor.
	
			#pool adında bir çoklu işlem havuzunu kullanarak işlemleri başlatır. starmap fonksiyonu, bir işçi fonksiyonunu (bu durumda worker fonksiyonunu) bir veri koleksiyonu üzerinde paralel olarak çalıştırır
			results = pool.starmap(worker,[(passw,hash_read) for passw in password_read])
			
			pool.close() # Havuzu kapatır. İşlemler tamamlandığında, havuzun kapatılması önerilir. 
			pool.join()  # Havuzdaki tüm işlemlerin tamamlanmasını bekler. Tüm işlemler tamamlandığında program sona erer.
			
			for result in results:
				if result is not None:
					
					passw = result  # result değeri passw değişkenine atanıyor
					output = f" ({passw.strip(): <6})    {hash_read: <6}     {format_h})"
					print(output)
					print("$Status:Cracked")
					print("$Devil tool cracked the specified hash value using the brute force method\n")
					sys.exit(1)
				
			print("\nHash could not be Cracked!!!!")
			print("Maybe you can try a different wordlist ;)\n")
			sys.exit(0)
	
	
		else:
		
			with open(path_wordlist1,"r") as file:
				password_read = file.readlines()
			
			
			with open(target_hash_file,"r") as file:
				hash_read = file.readline().strip()
				hash_read = hash_read.lower()
			
			
			requiredDisplay.requiredDis(path_wordlist1)
			
			
			for passw in password_read:
				hashed_password = hashlib.md5(passw.strip().encode('ISO-8859-1',errors='ignore')).hexdigest()
				
				if hashed_password == hash_read:
					#print("Deville started cracking the software")
					output = f" ({passw.strip(): <6})    {hash_read: <6}     {format_h})"
					print(output)
					print("$Status:Cracked")
					print("$Devil tool cracked the specified hash value using the brute force method\n")
					sys.exit(0)
				    
			
			print("\nHash could not be cracked :(")
			print("Maybe you can try a different wordlist ;)\n\n")
			sys.exit(1)
	
		
		
	
	else:
		 print("\nError!!!")
		 print("Invalid format_h value!!! Please Check the Hash Format##\n")
	
	
	

if __name__ == "__main__":
	
	
	#python3 Cr_md5.py md5 path_wordlist target_hashfile
	if len(sys.argv) != 4:
		print("usage: python3 Cr_md5.py md5 path_wordlist target_hashfile")
		sys.exit(1)
		
	format_h = sys.argv[1]
	path_wordlst = sys.argv[2]
	target_hash_f = sys.argv[3]
	
	crack_md5(format_h,path_wordlst,target_hash_f)
