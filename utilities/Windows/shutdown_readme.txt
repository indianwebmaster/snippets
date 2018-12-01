Bringing Up the Shutdown Dialog Box

Added 1/31/03

Create a new txt file somewhere on your system, open it and put in this one line: 
(new ActiveXObject("Shell.Application")).ShutdownWindows();
Save and Close the file. Change the extension to js and your got it.
You can make a shortcut to that file to make it easy to shut down your system.
	Cmd: C:\Windows\System32\wscript.exe
	Argument: C:\Apps\WinUtils\shutdown.js