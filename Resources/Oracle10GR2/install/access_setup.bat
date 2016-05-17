@echo Copying Accessibility related files to %SystemRoot%\System32
copy access\JavaAccessBridge.dll %SystemRoot%\System32\JavaAccessBridge.dll
copy access\WindowsAccessBridge.dll %SystemRoot%\System32\WindowsAccessBridge.dll
copy access\JAWTAccessBridge.dll %SystemRoot%\System32\JAWTAccessBridge.dll
@echo Copy complete
@echo Restart Jaws before starting an install session
