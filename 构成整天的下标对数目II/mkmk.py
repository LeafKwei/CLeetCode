import os

mkfile = open('Makefile', 'w')
dirs = os.listdir('.')

def append(file, dirs):
    for d in dirs:
        if(d.endswith('.c')):
            file.write(d + ' ')
    file.write('\n')

mkfile.write('all: clean ')
append(mkfile, dirs)
mkfile.write('\tgcc -o run ')
append(mkfile, dirs)
mkfile.write('\nclean: \n')
mkfile.write('\tdel run.exe')
