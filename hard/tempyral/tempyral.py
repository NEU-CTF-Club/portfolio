import time

CORRECT_PASSWORD = "superbruh1"

def check_password(user_password: str) -> bool:
    for i in range(min(len(CORRECT_PASSWORD), len(user_password))):
        if user_password[i] != CORRECT_PASSWORD[i]:
            return False

        time.sleep(0.2)  # Introduce a timing delay

    return len(CORRECT_PASSWORD) == len(user_password)


def main():
    user_password = input("Enter the password: ")
    if check_password(user_password):
        print("CTF{s1d3_ch4nn3l_4_u}")
    else:
        print("Incorrect password.")


if __name__ == "__main__":
    main()

