# BinDyn
Dynamic Binary Analysis Framework

Requires QT4

To compile CD to the main(src) directory then:

make clean (if i forgot to clean it before I push'd)

qmake -project

qmake

make

make clean

After that ./src & and you're on your own, it's all pretty self explanatory.


Also, I have included a simple template for you to program your own modules.
See the Files: template.header and template.source in this folder?
Go get em tiger. 


Finally please keep in mind this is intended as a framework, you can request features but basically the only part I promise will work is the main window that passes file information to the modules.

BUt you are fully expected to write your own if you please.

I wrote this to make my explorations inside files easier/faster/more fun, if u mad cause I decided to include a reference to gdb instead of writing my own debugger... welll...

Don't.