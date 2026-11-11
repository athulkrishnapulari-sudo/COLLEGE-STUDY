class InsufficientFundsError(Exception):
    pass

class BankAccount:
    def __init__(self):
        self.balance=0

    def Deposit(self,Amount):
        self.balance+=Amount
    def Withdraw(self,Amount):
        try:
            if Amount>self.balance:
                raise InsufficientFundsError("Insuffiecient Account Balance")
            else:
                self.balance-=Amount

        except InsufficientFundsError as e:
            print(e)

class SavingsAccount(BankAccount):
    def __init__(self):
        super().__init__()
        self.interest_rate = 5
    def apply_interest(self):
        interest = (self.balance*self.interest_rate*1)/100
        self.balance+=interest


class CurrentAccount(BankAccount):
    def __init__(self):
        super().__init__()
        self.limit=5000
    def Withdraw(self, Amount):
        try:
            if Amount<=self.balance+Amount<self.limit:
                self.balance-=Amount
            else:
                raise InsufficientFundsError("Ecxceeded Overdraft Limit")
        except InsufficientFundsError as e:
            print(e)

Acc1=SavingsAccount()
Acc2=CurrentAccount()

Acc1.Deposit(1000)
print(Acc1.balance)

Acc2.Deposit(6000)
print(Acc2.balance)

Acc1.Withdraw(2000)
Acc1.Withdraw(500)
print(Acc1.balance)

Acc2.Withdraw(6000)
print(Acc2.balance)