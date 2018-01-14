import crypt
import sys

salt = ""
hashedpw = ""
foundpassword = None

def main():
    global hashedpw
    global foundpassword
    global salt
    if len(sys.argv) != 2:
        print ("One single hashed password please.")
        return 1
    hashedpw = sys.argv[1]
    salt = hashedpw[0:2]
    for j in range(1, 5):
        lettercycle(j)
        if foundpassword != None:
            print(foundpassword)
            return 0
        
    
def lettercycle(passsize, inpw=""):
    for i in range(52):
        global hashedpw
        global foundpassword
        global salt
        if i < 26:
            ascii = i + 65
        else:
            ascii = i + 71
        testpass = inpw + chr(ascii)
        testhash = crypt.crypt(testpass, salt)
        if hashedpw == testhash:
            foundpassword = testpass
            return
        if passsize > 1:
            lettercycle(passsize - 1, testpass)
            
if __name__ == "__main__":
    main()