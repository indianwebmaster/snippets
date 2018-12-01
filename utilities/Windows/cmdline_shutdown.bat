set file=%Temp%\tmp_shutdown_cmd.js
echo (new ActiveXObject("Shell.Application")).ShutdownWindows();>%file%
wscript.exe %file%