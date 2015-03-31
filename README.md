#BinDyn  

Dynamic Binary Analysis Framework
---

###Dependencies  
* `QT5`
* `gdb` 
* `objdump` 

> Both `gdb` and `objdump` dependencies/modules can be omitted for
> compatibility with Windows.  

###Compile

After the necessary dependencies have been correctly installed.  Building 
and executing BinDyn should be rather straightforward:

```
$ cd BinDyn/src/
$ qmake -project
$ qmake
$ make
$ make clean
$ ./src
```

###Issues

On some QT installations, an edit to `BinDyn/src/src.pro` is 
required in order for QT to properly include the necessary 
headers. The altered compilation steps are detailed below:

1. Run `qmake -project && qmake`
2. Open `BinDyn/src/src.pro` in your editor of choice
3. On line 8 (right before the HEADERS block) add this line: <br>`QT += widgets`
4. Continue normal compilation with `make && make clean; ./src`
