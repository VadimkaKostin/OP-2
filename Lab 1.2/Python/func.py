from os import remove, rename
import pickle

class date:
    def __init__(self,day,monht,year):
        self.day = day
        self.month=monht
        self.year=year

class worker:
    def __init__(self,name,birth,hiring):
        self.name = name
        self.birth = birth
        self.hiring = hiring


def create_file(name,n):
    with open(name, 'wb') as outFile:
        for i in range(n):
            print("\nWorker #",i+1,sep="")
            Name = input("Enter name: ")
            b_day, b_monht, b_year = map(int,input("Enter the date of birth: ").split())
            h_day, h_monht, h_year = map(int,input("Enter the date of hiring: ").split())
            birth = date(b_day,b_monht,b_year)
            hiring = date(h_day,h_monht,h_year)
            worker1 = worker(Name,birth,hiring)
            if check_date(worker1):
                pickle.dump(worker1,outFile)
            else:
                print("Incorrect date")

def check_date(b):
    from datetime import date
    today = date.today()
    if b.birth.day <= 0 or b.birth.day > 31 or b.birth.month <= 0 or b.birth.month > 12 or b.birth.year > today.year:
        return False
    if b.hiring.day <= 0 or b.hiring.day > 31 or b.hiring.month <= 0 or b.hiring.month > 12 or b.hiring.year > today.year:
        return False
    return True

def output_file(name,n):
    with open(name, 'rb') as inFile:
        print("\nContaining of the file \"" + name + ":")
        for i in range(n):
            w = pickle.load(inFile)
            print(w.name)
            print(w.birth.day,w.birth.month,w.birth.year, sep=" ")
            print(w.hiring.day,w.hiring.month,w.hiring.year, sep=" ")

def amount_of_years(day,month,year):
    from datetime import date
    today = date.today()
    Year = today.year
    Month = today.month
    Day = today.day
    amount = Year - year
    if Month<month:
        amount -= 1
    elif Month==month and Day<day:
        amount -= 1
    return amount
    

def output_first_list_of_workers(name,n):
    print("\nWorkers older then 40:")
    with open(name, 'rb') as inFile:
        for i in range(n):
            w = pickle.load(inFile)
            if amount_of_years(w.birth.day,w.birth.month,w.birth.year)>40:
                print(w.name)

def output_second_list_of_workers(name,n):
    print("\nWorkers who works more then 20 years:")
    with open(name, 'rb') as inFile:
        for i in range(n):
            w = pickle.load(inFile)
            if amount_of_years(w.hiring.day,w.hiring.month,w.hiring.year)>20:
                print(w.name)

def change_file(name,n):
    inFile = open(name, 'rb')
    outFile = open("Copy", 'wb')
    amount = 0
    for i in range(n):
        w = pickle.load(inFile)
        if amount_of_years(w.hiring.day,w.hiring.month,w.hiring.year)>=1:
            pickle.dump(w,outFile)
            amount += 1
    inFile.close()
    outFile.close()
    remove(name)
    rename("Copy",name)
    print("\nFile successfully changed")
    return amount
