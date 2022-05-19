from abc import ABC,abstractmethod

class TFunction:
    @abstractmethod
    def increase(number):
        pass

    @abstractmethod
    def decrease(number):
        pass

    @abstractmethod
    def get_value(x):
        pass

    @abstractmethod
    def displayFunction():
        pass

class LinearFunction(TFunction):
    def __init__(self, A1, A0):
        self.__A1 = A1
        self.__A0 = A0
    
    def increase(self,number):
        self.__A1 += number
        self.__A0 += number

    def decrease(self,number):
        self.__A1 -= number
        self.__A0 -= number

    def get_value(self,x):
        y = self.__A1 * x + self.__A0
        return y

    def displayFunction(self):
        if self.__A1!=0 and self.__A0>0:
            print("y = ",self.__A1,"x + ",self.__A0)
        elif self.__A1!=0 and self.__A0<0:
            print("y = ",self.__A1,"x - ",-1*self.__A0)
        elif self.__A1==0 and self.__A0!=0:
            print("y = ",self.__A0)
        elif self.__A1!=0 and self.__A0==0:
            print("y = ",self.__A1,"x")
        elif self.__A1==0 and self.__A0==0:
            print("y = 0")

class QuadraticFunction(TFunction):
    def __init__(self,B2,B1,B0):
        self.__B2 = B2
        self.__B1 = B1
        self.__B0 = B0
    
    def increase(self,number):
        self.__B2 += number
        self.__B1 += number
        self.__B0 += number

    def decrease(self,number):
        self.__B2 -= number
        self.__B1 -= number
        self.__B0 -= number
    
    def get_value(self,x):
        y = self.__B2 * x**2 + self.__B1 * x + self.__B0
        return y
    
    def displayFunction(self):
        if self.__B2!=0 and self.__B1>0 and self.__B0>0:
            print("y = ",self.__B2,"x^2 + ",self.__B1,"x + ",self.__B0)
        elif self.__B2!=0 and self.__B1>0 and self.__B0<0:
            print("y = ",self.__B2,"x^2 + ",self.__B1,"x - ",-1*self.__B0)
        elif self.__B2!=0 and self.__B1<0 and self.__B0>0:
            print("y = ",self.__B2,"x^2 - ",-1*self.__B1,"x + ",self.__B0)
        elif self.__B2!=0 and self.__B1<0 and self.__B0<0:
            print("y = ",self.__B2,"x^2 - ",-1*self.__B1,"x - ",-1*self.__B0)
        elif self.__B2==0 and self.__B1!=0 and self.__B0>0:
            print("y = ",self.__B1,"x + ",self.__B0)
        elif self.__B2==0 and self.__B1!=0 and self.__B0<0:
            print("y = ",self.__B1,"x - ",-1*self.__B0)
        elif self.__B2!=0 and self.__B1==0 and self.__B0>0:
            print("y = ",self.__B2,"x^2 + ",self.__B0)
        elif self.__B2!=0 and self.__B1==0 and self.__B0<0:
            print("y = ",self.__B2,"x^2 - ",-1*self.__B0)
        elif self.__B2!=0 and self.__B1>0 and self.__B0==0:
            print("y = ",self.__B2,"x^2 + ",self.__B1,"x")
        elif self.__B2!=0 and self.__B1<0 and self.__B0==0:
            print("y = ",self.__B2,"x^2 - ",-1*self.__B1,"x")
        elif self.__B2!=0 and self.__B1==0 and self.__B0==0:
            print("y = ",self.__B2,"x^2")
        elif self.__B2==0 and self.__B1!=0 and self.__B0==0:
            print("y = ",self.__B1,"x")
        elif self.__B2==0 and self.__B1==0 and self.__B0!=0:
            print("y = ",self.__B0)
        elif self.__B2==0 and self.__B1==0 and self.__B0==0:
            print("y = 0")
