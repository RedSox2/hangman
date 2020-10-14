 hangman
 =============
A hangman game.

| hangman.exe | hangman |
| ----------- | ------- |
|WIN executable | mac executable |

How to run
---------------------
### Windows
1. Install [min-GW](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download).  
2. Open the installer and continue through it but choose x86_64 for architecture.
3. Next open the windows search bar and search for "Edit environment variables for your account". Open what comes up.
4. Click the `Path` variable under **account variables**. 
5. Click `edit`.
6. A new window should pop up. Choose `new`. Copy and paste this: `C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin`. 
7. Your all good! Feel free to run your program whenever you feel. 

Mac
--------------------
1. Download the zip.
2. Go to finder and `downloads`.
3. Double click on the hangman-master folder.
4. Press cmd+spacebar.
5. type in `terminal` and press enter.
6. Into terminal type `cd downloads/hangman-master`.
7. Then type `make hangman`. This opens a new window asking you to install something to allow this to run, click `yes`.
8. Once that is installed type `make hangman` and press enter.
9. Finally, into terminal type `./hamgan`. (Or go to finder and open downloads and hangman-master and double-click hangman)
