from func import *

n = int(input("Enter the amount of workers: "))

file_name = "Katalog.txt"

create_file(file_name,n)
output_file(file_name,n)
output_first_list_of_workers(file_name,n)
output_second_list_of_workers(file_name,n)
n=change_file(file_name,n)
output_file(file_name,n)

input("Press Enter to continue...")
