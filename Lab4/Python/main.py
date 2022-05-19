from classes import LinearFunction, QuadraticFunction
import random

n = int(input("Enter amount of the linear functions: "))
m = int(input("Enter amount of the quadratic functions: "))

linear = []
quadratic = []

print("\nLinear functions:")
for i in range(n):
    a1 = random.randint(-20,20)
    a0 = random.randint(-20,20)
    linear_function = LinearFunction(a1,a0);
    linear.append(linear_function)
    print(i+1, ")", end = "")
    linear_function.displayFunction()

print("\nQuadratic functions:")
for i in range(m):
    b2 = random.randint(-20,20)
    b1 = random.randint(-20,20)
    b0 = random.randint(-20,20)
    quadratic_function = QuadraticFunction(b2,b1,b0);
    quadratic.append(quadratic_function)
    print(i+1, ")", end = "")
    quadratic_function.displayFunction()

print("\nNew linear functions:")
for i in range(n):
    linear[i].increase(3)
    print(i+1, ")", end = "")
    linear[i].displayFunction()

print("\nNew quadratic functions:")
for i in range(m):
    quadratic[i].decrease(2)
    print(i+1, ")", end = "")
    quadratic[i].displayFunction()

x = float(input("\nEnter x: "))

max_linear = linear[0].get_value(x)
pos_linear = 0

print("\nValues of the linear functions:")
for i in range(n):
    print(i+1, ")", linear[i].get_value(x))
    if linear[i].get_value(x) > max_linear:
        max_linear = linear[i].get_value(x)
        pos_linear = i

max_quadratic = quadratic[0].get_value(x)
pos_quadratic = 0

print("\nValues of the quadratic functions:")
for i in range(m):
    print(i+1, ")", quadratic[i].get_value(x))
    if quadratic[i].get_value(x) > max_quadratic:
        max_quadratic = quadratic[i].get_value(x)
        pos_quadratic = i

if max_linear > max_quadratic:
    print("The maximum value has function ", end = "")
    linear[pos_linear].displayFunction()
    print("Value of this function is ",linear[pos_linear].get_value(x))
else:
    print("The maximum value has function ", end = "")
    quadratic[pos_quadratic].displayFunction()
    print("Value of this function is ",quadratic[pos_quadratic].get_value(x))

input("Press Enter to continue...")