# NTLM(NT hash) hash crack
import sys
import lenWordlist
import hashlib
import time
import requiredDisplay
from multiprocessing import Pool



def worker(passw, hash_read):
	
    try:
		
        hashed_password = hashlib.new('md4', passw.encode('utf-16le')).hexdigest()
        if hashed_password == hash_read:
            return passw
            
            
    except Exception as e:
        pass  # Hata durumunda işlem yapma




def crack_ntlm(format_h, path_wordlist1, target_hash_file):
	
    length_wordlist = lenWordlist.calc_len_wordlist(path_wordlist1)

    if format_h.lower() == 'ntlm':
		
        if length_wordlist > 100000:
            # process
            # multi processing attack(36 per)
            
            
            with open(path_wordlist1, "rb") as file:
                password_read = file.read().decode("ISO-8859-1", errors="ignore").splitlines()
                

            with open(target_hash_file, "r") as file:
                hash_read = file.readline().strip().lower()
                

            requiredDisplay.requiredDis(path_wordlist1)

            pool = Pool(36)
            results = pool.starmap(worker, [(passw, hash_read) for passw in password_read])

            pool.close()
            pool.join()


            for result in results:
                if result is not None:
					
                    passw = result  # result değeri passw değişkenine atanıyor
                    output = f" ({passw.strip(): <6})    {hash_read: <6}     {format_h}(nt hash))"
                    print(output)
                    print("$Status:Cracked")
                    print("$Devil tool cracked the specified hash value using the brute force method\n")
                    sys.exit(1)
                    

            print("\nHash could not be Cracked!!!!")
            print("Maybe you can try a different wordlist ;)")
            print("$Status:Not Cracked\n")
            sys.exit(0)
            
            

        else:
			
            with open(path_wordlist1, "rb") as file:
                password_read = file.read().decode("ISO-8859-1", errors="ignore").splitlines()
                

            with open(target_hash_file, "r") as file:
                hash_read = file.readline().strip().lower()

            requiredDisplay.requiredDis(path_wordlist1)


            for passw in password_read:
                hashed_password = hashlib.new('md4', passw.encode('utf-16le')).hexdigest()

                if hashed_password == hash_read:
                    # print("Deville started cracking the software")
                    output = f" ({passw.strip(): <6})    {hash_read: <6}     {format_h}(nt hash))"
                    print(output)
                    print("$Status:Cracked")
                    print("$Devil tool cracked the specified hash value using the brute force method\n")
                    sys.exit(1)
                    

            print("\nHash could not be cracked :(")
            print("Maybe you can try a different wordlist ;)\n\n")
            print("$Status:Not Cracked\n")
            sys.exit(1)
            
    else:
		
        print("\nError!!!")
        print("Invalid format_h value!!! Please Check the Hash Format##\n")



if __name__ == "__main__":
	
    # python3 Cr_ntlm.py ntlm path_wordlist target_hashfile
    if len(sys.argv) != 4:
        print("usage: python3 Cr_ntlm.py ntlm path_wordlist target_hashfile")
        sys.exit(1)

    format_h = sys.argv[1]
    path_wordlst = sys.argv[2]
    target_hash_f = sys.argv[3]

    crack_ntlm(format_h, path_wordlst, target_hash_f)
