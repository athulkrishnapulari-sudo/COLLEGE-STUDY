class SeatNotBookedError(Exception):
    pass

class Ticket:
    def __init__(self,Name,Email,FlightNo,SeatNo):
        self.Name = Name
        self.Email = Email
        self.FlightNo = FlightNo
        self.SeatNo = SeatNo
        self.booked  = False
        self.lounge_access = False
    def book_ticket(self):
        if "@" not in self.Email or "." not in self.Email:
            print("Invalid Email ID")
            return
        if not self.booked:
            self.booked = True
            print("Booked Successfully")
        else:
            print("Already Booked")
    def cancel_ticket(self):
        if not self.booked:
            raise SeatNotBookedError('Seat Already Not Booked!!!')
        else:
            self.booked=False
            print("Booking Canceled")



class EconomyTicket(Ticket):
    def __init__(self,Name,Email,FlightNo,SeatNo):
        super().__init__(Name,Email,FlightNo,SeatNo)
    def meal_choice(self):
        print("MEAL MENU")
        print("1.Biriyani\n2.Parotta\n3.Appam\n")
        print('-'*10)
        self.choice = input("Enter Your Meal Choice (Name)")


class BusinessTicket(Ticket):
    def __init__(self,Name,Email,FlightNo,SeatNo):
        super().__init__(Name,Email,FlightNo,SeatNo)
    def lounge_access(self):
        Ticket.lounge_access=True


# Creating Economy Ticket object
e1 = EconomyTicket("Athul", "athul@gmail.com", "AI101", 25)

# Creating Business Ticket object
b1 = BusinessTicket("Arun", "arun@gmail.com", "AI102", 10)


# Booking Operations
print("\n--- BOOKING ---")
e1.book_ticket()
b1.book_ticket()


try:
    e1.cancel_ticket()
    e1.cancel_ticket()  

except SeatNotBookedError as e:
    print("Error:", e)