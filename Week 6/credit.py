from cs50 import get_string

card = get_string("Number: ")
first = 0
second = 0
total = 0

while True:
    if len(card) != 15 and len(card) != 16 and len(card) != 13:
        print("INVALID")
        break
    else:
        for n in range(len(card)):
            if n % 2 == 0:
                buffer = int(card[n]) * 2
                digit_check = len(str(buffer))
                if digit_check > 1:
                    buffer = str(buffer)
                    for d in range(digit_check):
                        first += int(buffer[d])
                else:
                    first += buffer
            else:
                second += int(card[n])
        total = first + second
        if str(total)[1] == "0":
            checksum = True
        else:
            checksum = False
        break

while True:
    if checksum == False:
        print("INVALID")
        break
    else:
        if len(card) == 15 and (card[:2] == "34" or card[:2] == "37"):
            print("AMEX")
            break
        elif len(card) == 16 and (card[:2] == "51" or card[:2] == "52" or card[:2] == "53" or card[:2] == "54" or card[:2] == "55"):
            print("MASTERCARD")
            break
        elif (len(card) == 13 or len(card) == 16) and card[:1] == "4":
            print("VISA")
            break
        else:
            print("INVALID")
            break
