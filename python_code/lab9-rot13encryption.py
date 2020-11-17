# filename lab9-rot13encryption.py
# author Zachary McBride

import personalLibrary


def encrypt(input_string, n):
    encoding_wheel = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[{]}|;:'\"\\/,<.>? "
    output_string = ""
    for char in input_string:
        # output = rotation on encoding_wheel from index of
        #         input char in the  encoding_wheel +
        #         rotation factor % length of encoding wheel
        output_string += encoding_wheel[(encoding_wheel.index(char) + n) %
                                        len(encoding_wheel)]
    return output_string


def main():

    while True:
        # Welcome and get input for string to be encrypted
        print("Welcome to the ROT(N) encryption program!")
        string_to_be_encrypted = input("Please enter string to be encrypted. ")
        print(f"You have entered: {string_to_be_encrypted}.")
        # get input for degree of encryption (n)
        rotN = int(input("Enter rotation factor"))
        if type(rotN) is not int:
            rotN = int(input("Invalid entry."))

        # send string to encryption function
        print(encrypt(string_to_be_encrypted, rotN))
        if input("Would you like to encrypt another string? Press ENTER to continue, type 'quit' to exit program. ") != "":
            break


main()
