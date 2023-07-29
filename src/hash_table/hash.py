def hash_func(k, n):
    return k % n


def hash_func_ascii(k, n):
    k = list(k)
    return (ord(k[0]) + ord(k[1])) % n


n = 10
hash_table = [None] * n

while True:
    print('1 - Insert into hash table')
    print('2 - Remove from hash table')
    print('3 - List table')
    print('4 - Exit')

    op = int(input("Choose an option: "))
    if op == 1:
        key = input("Enter the state: ")
        pos = hash_func_ascii(key, n)
        if hash_table[pos] is None:
            hash_table[pos] = key
        else:
            print("Data already exists in this position!")
    elif op == 2:
        key = int(input('Enter the state to be remove: '))
        pos = hash_func_ascii(key, n)
        if hash_table[pos] == key:
            hash_table[pos] = None
        else:
            print('Value not found')
    elif op == 3:
        print(hash_table)
    elif op == 4:
        print('Exiting...')
        break
    else:
        print('Select another option! \n')
