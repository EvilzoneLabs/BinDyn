# BinDyn
Dynamic Binary Analysis Framework

Requires QT4, gdb, and objdump 

(Last two can be ommited if you disable or dont run the modules, or uh, replaced with windows alternatives if you swing that way)


To compile CD to the main(src) directory then:

qmake -project
qmake
make
make clean

After that ./src & and you're on your own, it's all pretty self explanatory.


Finally please keep in mind this is intended as a framework, you can request features but basically the only part I promise will work is the main window that passes file information to the modules.
You are fully expected to write your own if you please.
I have however included a simple template for you to program your own modules.
See the Files: template.header and template.source in this folder?

I wrote this to make my explorations inside files easier/faster/more fun, if u mad cause I decided to include a reference to gdb instead of writing my own debugger... or something else I did that displeased you, welll...

Just Don't.


