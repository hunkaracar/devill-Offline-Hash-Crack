#md4 hash crack
import sys
import lenWordlist
import time
import requiredDisplay
from multiprocessing import Pool
import hashlib



def worker(passw, hash_read):
	
    try:
		
        hashed_password = hashlib.new('md4')
        hashed_password.update(passw.strip().encode('ISO-8859-1', errors='ignore'))
        hashed_password = hashed_password.hexdigest()
        
        if hashed_password == hash_read:
            return passw
            
            
    except Exception as e:
        pass
        
        

def crack_md4(format_h, path_wordlst1, target_hash_f):
	
    len_wordlist = lenWordlist.calc_len_wordlist(path_wordlst1)
    

    if format_h.lower() == 'md4':
		
        if len_wordlist > 100000:
			
			
            with open(path_wordlst1, "rb") as file:
                password_read = file.read().decode('ISO-8859-1', errors='ignore').splitlines()
                

            with open(target_hash_f, "r") as file:
                hash_read = file.readlines()[0].strip().lower()
                

            requiredDisplay.requiredDis(path_wordlst1)

            pool = Pool(36)
            results = pool.starmap(worker, [(passw, hash_read) for passw in password_read])

            pool.close()
            pool.join()


            for result in results:
                if result is not None:
                    passw = result
                    output = f" ({passw.strip(): <6})    {hash_read: <6}     {format_h})"
                    print(output)
                    print("$Status:Cracked")
                    print("$Devil tool cracked the specified hash value using the brute force method\n")
                    sys.exit(1)

            print("\nHash could not be Cracked!!!!")
            print("Maybe you can try a different wordlist ;)\n")
            sys.exit(0)
            

        else:
			
            with open(path_wordlst1, "r") as file:
                password_read = file.readlines()


            with open(target_hash_f, "r") as file:
                hash_read = file.readline().strip().lower()

            requiredDisplay.requiredDis(path_wordlst1)

            for passw in password_read:
				
                hashed_password = hashlib.new('md4')
                hashed_password.update(passw.strip().encode('ISO-8859-1', errors='ignore'))
                hashed_password = hashed_password.hexdigest()


                if hashed_password == hash_read:
                    output = f" ({passw.strip(): <10})    {hash_read: <10}     {format_h})"
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
	
	
    if len(sys.argv) != 4:
        print("usage: python3 Cr_md4.py md4 path_wordlist target_hashfile")
        sys.exit(1)

    format_h = sys.argv[1]
    path_wordlst = sys.argv[2]
    target_hash_f = sys.argv[3]

    crack_md4(format_h, path_wordlst, target_hash_f)
