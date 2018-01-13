from cs50 import get_int
import math

def main():
    card = get_card("Card Number: ")
    check = check_card(card)
    checksum_test(check, card)
    
    
def get_card(prompt):
    """Prompt user for card number"""
    while True:
        n = get_int(prompt)
        if n >= 1:
            break
    return n
    
def check_card(cardnumber):
    """Calculate checksum of cardnumber, return card type of invalid"""
    position = 1
    checksum = 0
    for i in range(1, 17):
        if i == 1:
            checksum = cardnumber % 10
        elif i % 2 == 0:
            working = math.floor((cardnumber % (position * 10)) / position) * 2
            if working > 9:
                checksum += 1 + (working % 10)
            else:
                checksum += working
        else:
            checksum += math.floor((math.floor(cardnumber % (position * 10)) / position))
        position *= 10
        print(checksum)
    return checksum
    
def checksum_test(checksumin, cardnumber):
    if checksumin % 10 == 0:
        if math.floor(cardnumber / 1000000000000000) == 4 or math.floor(cardnumber / 1000000000000) == 4:
            print("VISA")
        elif math.floor(cardnumber / 100000000000000) < 56 and math.floor(cardnumber / 100000000000000) > 50:
            print("MASTERCARD")
        elif math.floor(cardnumber / 10000000000000) == 34 or math.floor(cardnumber / 10000000000000) == 37:
            print("AMEX")
        else:
            print("INVALID")
    else:
        print("INVALID")
        
    
if __name__ == "__main__":
    main()