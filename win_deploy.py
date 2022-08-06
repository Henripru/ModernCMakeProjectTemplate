import os

os.system("rd /s /q bin")
os.system("rd /s /q lib")
os.system("mkdir build")
os.system("cd ./build && cmake ../ -G\"Visual Studio 17 2022\"")
os.system("cd ./build && cmake --build . --target INSTALL --config Debug")

