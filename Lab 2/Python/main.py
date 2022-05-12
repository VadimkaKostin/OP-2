from Classes import TPoint

n = int(input("Enter the amount of points: "))

Array = []

for i in range(n):
    print("\nPoint",i+1)
    X,Y,Z = map(float,input("Enter coordinates of the point: ").split())
    V1,V2,V3 = map(float,input("Enter the coordinates of the vector of the speed: ").split())
    point = TPoint(X,Y,Z,V1,V2,V3)
    Array.append(point)

t = float(input("\nEnter Time: "))

print("\nPoints that reached the first octannt:")
for i in range(n):
    Array[i].change_position(t)
    if Array[i].is_first_octant():
        print("#",i+1, sep="", end=" ")

print()

input("Press Enter to continue..")
