@echo off
echo Windows Registry Editor Version 5.00 >>oem.reg
echo [HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\OEMInformation] >>oem.reg
echo @="" >>oem.reg
echo "Logo"="C:\\WINDOWS\\system32\\oemlogo1.bmp" >>oem.reg
echo "SupportPhone"="13988888888" >>oem.reg
echo "SupportURL"="http://" >>oem.reg
echo "SupportHours"="9:00-18:00" >>oem.reg
echo "Manufacturer"="Î¢Èí¹«Ë¾" >>oem.reg
echo "Model"="MSDNÔ­°æ" >>oem.reg


regedit /s /q oem.reg 

del /s /q oem.reg