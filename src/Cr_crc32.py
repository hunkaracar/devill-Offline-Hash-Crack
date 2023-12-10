#CRC32 Hash Crack
import sys
import lenWordlist
import requiredDisplay
import time
import zlib
from multiprocessing import Pool


def worker(passw, hash_read):
	
    try:
        hashed_password = zlib.crc32(passw.strip().encode('ISO-8859-1', errors='ignore'))
        hashed_password_hex = format(hashed_password & 0xFFFFFFFF, '08x')
        if hashed_password_hex == hash_read:
            return passw
            
    except Exception as e:
        pass  # Hata durumunda işlem yapma
        
        
        
def crack_crc32(format_h, path_wordlst1, target_hash_f):
	
    len_wordlist = lenWordlist.calc_len_wordlist(path_wordlst1)

    if format_h.lower() == 'crc32':
		
        # passw = none
        if len_wordlist > 100000:
            # process
            # multi processing attack(36 per)
            
            
            with open(path_wordlst1, "rb") as file:
                password_read = file.read().decode("ISO-8859-1", errors="ignore").splitlines()
                #password_read = format(password_read & 0xFFFFFFFF, '08x')


            with open(target_hash_f, "r") as file:
                hash_read = file.readline().strip()
                hash_read = hash_read.lower()
                

            requiredDisplay.requiredDis(path_wordlst1)

            pool = Pool(36)

            # pool adında bir çoklu işlem havuzunu kullanarak işlemleri başlatır.
            # starmap fonksiyonu, bir işçi fonksiyonunu (bu durumda worker fonksiyonunu)
            # bir veri koleksiyonu üzerinde paralel olarak çalıştırır
            results = pool.starmap(worker, [(passw, hash_read) for passw in password_read])

            pool.close()
            pool.join()


            for result in results:
                if result is not None:
					
                    output = f" ({result.strip(): <6})    {hash_read: <6}     {format_h})"
                    print(output)
                    print("$Status:Cracked")
                    print("$Devil tool cracked the specified hash value using the brute force method\n")
                    sys.exit(1)
                    

            print("\nHash could not be Cracked!!!!")
            print("Maybe you can try a different wordlist ;)\n")
            sys.exit(1);


        else:
			
            with open(path_wordlst1, "r") as file:
                password_read = file.readlines()
                
                
            with open(target_hash_f, "r") as file:
                hash_read = file.readline().strip()
                hash_read = hash_read.lower()
                

            requiredDisplay.requiredDis(path_wordlst1)
            

            for passw in password_read:
                hashed_password = zlib.crc32(passw.strip().encode('ISO-8859-1', errors='ignore'))
                hashed_password_hex = format(hashed_password & 0xFFFFFFFF, '08x')

                if hashed_password_hex == hash_read:
                    output = f" ({passw.strip(): <6})    {hash_read: <6}     {format_h})"
                    print(output)
                    print("$Status:Cracked")
                    print("$Devil tool cracked the specified hash value using the brute force method\n")
                    sys.exit(1)
                    

            print("\nHash could not be cracked :(")
            print("Maybe you can try a different wordlist ;)\n\n")
            sys.exit(1)


    else:
        print("\nError!!!")
        print("Invalid format_h value!!! Please Check the Hash Format##\n")




if __name__ == "__main__":
    # python3 Cr_crc32.py crc32 path_wordlist target_hashfile
    if len(sys.argv) != 4:
        print("usage: python3 Cr_crc32.py crc32 path_wordlist target_hashfile")
        sys.exit(1)

    format_h = sys.argv[1]
    path_wordlst = sys.argv[2]
    target_hash_f = sys.argv[3]

    crack_crc32(format_h, path_wordlst, target_hash_f)
