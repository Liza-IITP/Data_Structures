import os 
cwd = os.getcwd()
print(f"Current working directory is : {cwd}")

items= os.listdir('.')
print(f"Items in the current directory are : {items}")

dir_name = "folder"
file_name = "file.txt"
full_path = os.path.join(os.getcwd(),dir_name,file_name)
print(f"Path of directory is : {full_path}")

path = 'example.txt'
if os.path.exists(path):
    print(f"File {path} exists")
else:
    print(f"File {path} does not exists")

dir_name = "folder.txt"
if os.path.isdir(dir_name):
    print(f"{dir_name} is a directory")
elif os.path.isfile(dir_name):
    print(f"{dir_name} is a file")
else:
    print(f"{dir_name} is neither a file nor a directory")