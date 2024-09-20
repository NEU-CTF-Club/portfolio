import time

correct_password = "superbruh1"

def check_password(user_password):
    for i in range(len(correct_password)):
        if user_password[i] != correct_password[i]:
            return False
        time.sleep(0.1)  # Introduce a timing delay
    return True

def main():
    user_password = input("Enter the password: ")
    if check_password(user_password):
        print("CTF{s1d3_ch4nn3l_4_u}")
    else:
        print("Incorrect password.")

if __name__ == "__main__":
    main()

