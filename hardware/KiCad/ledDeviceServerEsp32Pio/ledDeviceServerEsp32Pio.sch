EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ledDeviceServerEsp32Pio:HLK-PM01 PS1
U 1 1 61952CC8
P 4450 1250
F 0 "PS1" H 4450 1575 50  0000 C CNN
F 1 "HLK-PM01" H 4450 1484 50  0000 C CNN
F 2 "Converter_ACDC:Converter_ACDC_HiLink_HLK-PMxx" H 4450 950 50  0001 C CNN
F 3 "http://www.hlktech.net/product_detail.php?ProId=54" H 4850 900 50  0001 C CNN
	1    4450 1250
	1    0    0    -1  
$EndComp
$Comp
L ledDeviceServerEsp32Pio:Screw_Terminal_01x02 JAC
U 1 1 6195CB3B
P 3650 1250
F 0 "JAC" H 3650 950 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 3600 1000 50  0000 C CNN
F 2 "ledDeviceServerEsp32Pio:Screw_Termianl_01x02" H 3700 950 50  0001 C CNN
F 3 "~" H 3650 1250 50  0001 C CNN
	1    3650 1250
	-1   0    0    1   
$EndComp
$Comp
L ledDeviceServerEsp32Pio:Screw_Terminal_01x03 JLogic
U 1 1 6195D7EF
P 900 2600
F 0 "JLogic" H 980 2642 50  0000 L CNN
F 1 "Screw_Terminal_01x03" H 980 2551 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-3_P5.08mm" H 850 2300 50  0001 C CNN
F 3 "~" H 900 2600 50  0001 C CNN
	1    900  2600
	1    0    0    -1  
$EndComp
$Comp
L Espressif:ESP32-DevKitC U1
U 1 1 6195EB5A
P 4500 2850
F 0 "U1" H 4575 1585 50  0000 C CNN
F 1 "ESP32-DevKitC" H 4575 1676 50  0000 C CNN
F 2 "Espressif:ESP32-DevKitC" H 4500 1600 50  0001 C CNN
F 3 "https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/hw-reference/esp32/get-started-devkitc.html" H 4650 1600 50  0001 C CNN
	1    4500 2850
	-1   0    0    1   
$EndComp
Wire Wire Line
	4850 1350 6100 1350
Wire Wire Line
	6100 1350 6100 2400
Wire Wire Line
	6100 2400 5800 2400
Wire Wire Line
	4850 1150 5900 1150
Wire Wire Line
	5900 1150 5900 1900
Wire Wire Line
	5900 1900 5800 1900
Wire Wire Line
	3850 1150 4050 1150
Wire Wire Line
	3850 1250 3950 1250
Wire Wire Line
	3950 1250 3950 1350
Wire Wire Line
	3950 1350 4050 1350
$EndSCHEMATC
