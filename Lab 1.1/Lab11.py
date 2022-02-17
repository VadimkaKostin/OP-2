def import_text():
    print('While input the text press Enter \
    \nto input new line and \
    \nCtrl+D to finish input \
    \n\nEnter text:')
    import sys
    text=sys.stdin.read()
    text[:len(text)-1]
    return text

def create_file(text,name):
    with open(name,'wt') as fwrite:
        fwrite.write(text)

def output_file(name):
    with open(name,'rt') as fread:
        text=fread.read()
        print("\nFile \"",name,"\":\n",text,sep="")

def create_second_file(name1,name2):
    fread=open(name1,'rt')
    fwrite=open(name2,'wt')

    while True:
        line=fread.readline()
        if not line:
            break
        line=line.strip('\n') + ' ' + str(find_charecter(line))
        fwrite.write(line+'\n')
    
    fread.close()
    fwrite.close()

def find_charecter(line):
    for i in range(len(line)):
        if line[i]==' ' or line[i]=='.' or line[i]==',' or line[i]=='!' or line[i]=='?' or line[i]==':' or line[i]==';':
            return line[i-1]



Name1="Text1.txt"
Name2="Text2.txt"

Text=import_text()
create_file(Text,Name1)
output_file(Name1)

create_second_file(Name1,Name2)
output_file(Name2)

input("Press Enter to continue...")
