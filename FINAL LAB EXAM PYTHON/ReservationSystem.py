import pickle



def AddReservation():
    name = input("Enter your name : ")
    age = int(input("Enter your age : "))
    print("\n========== AVAILABLE TRAINS ==========")
    print("1. Kerala Express       - 12625")
    print("2. Rajdhani Express     - 12431")
    print("3. Vande Bharat Express - 20634")
    print("4. Malabar Express      - 16629")
    print("5. Venad Express        - 16302")
    print("6. Parasuram Express    - 16649")
    print("7. Jan Shatabdi Express - 12082")
    print("8. Island Express       - 16526")
    print("================================")
    trainNo = int(input("Enter the train Number"))
    seats_info=[]
    file = open('train_data.txt','r')
    seats = file.readlines()
    for i in seats:
        print(i)
        seats_info.append(i)
    print(seats_info)
    print(seats)
    file = open("train.dat","rb")
    data = file.load()
    available = []
    # for i in seats:

    # for i in train:
    #     flag=0
    #     for j in data:
    #         if i==j["seat_no"]:
    #             flag=1
    #     if flag==0:
    #         available.append(i)
    # print("\nAvailable Seat Numbers:")
    # for seat in available:
    #     print(seat, end=" ")


AddReservation()