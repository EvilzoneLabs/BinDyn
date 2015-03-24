# BinDyn
Dynamic Binary Analysis Framework

Requires QT4

To compile CD to the main(src) directory then:

make clean
qmake -project
qmake
make
make clean

After that ./src & and you're on your own, it's all pretty self explanatory.

Also, I have included a simple template for you to program your own modules.

See the Files: template.header and template.source in this folder?

(named as such to bypass errors thrown by qmake if theres any unused code in the project) 

Go get em tiger. 


Also please keep in mind this is a FRAMEWORK, 
you can request features but basically the only
 part I promise will work is the main window that
 passes file information to the modules. I have programmed a few modules and
have plans for more but thats just how the cookie crumbles. If I don't know you I 
probably wont listen to feature requests.