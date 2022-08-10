@echo off
echo GLSLC
set /p a=Filepath: 
d:\devLib\VulkanSDK\1.3.216.0\Bin\glslc.exe %a% -o %a%.spv
pause
