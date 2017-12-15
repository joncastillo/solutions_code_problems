def __main__():
    string1 = input("Enter first string: ")
    string2 = input("Enter second string: ")
    string3 = input("Enter third string: ")

    idx_string1 = 0;
    idx_string2 = 0;
    idx_string3 = 0;

    while (idx_string3 < len(string3)):

        if idx_string1 < len(string1) and string3[idx_string3] == string1[idx_string1]:
            idx_string1+=1
        elif idx_string2 < len(string2) and string3[idx_string3] == string2[idx_string2]:
            idx_string2+=1
        else:
            break
        idx_string3+=1

    if idx_string3 == len(string3):
        print("matched")
    else:
        print("mismatched")

if __name__ == "__main__":
    __main__()