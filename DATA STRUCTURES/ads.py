if __name__ == '__main__':
    n = int(input())  # number of elements
    integer_list = tuple(map(int, input().split()))  # create tuple from input
    print(hash(integer_list))  # print hash of the tuple