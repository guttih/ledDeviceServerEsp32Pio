EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Led Device server Esp32"
Date "2021-11-18"
Rev "v1.0"
Comp ""
Comment1 "Repository: https://github.com/guttih/ledDeviceServerEsp32Pio"
Comment2 "https://creativecommons.org/licenses/by/4.0/"
Comment3 "Licence: CC BY 4.0"
Comment4 "Author:Gudjon Holm Sigurdsson"
$EndDescr
$Comp
L ledDeviceServerEsp32Pio:Screw_Terminal_01x02 JAC1
U 1 1 6195CB3B
P 10100 2650
F 0 "JAC1" H 10100 2800 50  0000 C CNN
F 1 "Terminal_AC" H 10100 2400 50  0000 C CNN
F 2 "ledDeviceServerEsp32Pio:Screw_Termianl_01x02" H 10150 2350 50  0001 C CNN
F 3 "~" H 10100 2650 50  0001 C CNN
	1    10100 2650
	1    0    0    -1  
$EndComp
$Comp
L Espressif:ESP32-DevKitC U1
U 1 1 6195EB5A
P 6900 4300
F 0 "U1" H 6975 3035 50  0000 C CNN
F 1 "ESP32-DevKitC" H 6975 3126 50  0000 C CNN
F 2 "Espressif:ESP32-DevKitC" H 6900 3050 50  0001 C CNN
F 3 "https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/hw-reference/esp32/get-started-devkitc.html" H 7050 3050 50  0001 C CNN
	1    6900 4300
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWRGND01
U 1 1 6196187F
P 7950 2200
F 0 "#PWRGND01" H 7955 2027 50  0000 C CNN
F 1 "GND" H 7955 1936 50  0000 C CNN
F 2 "" H 7950 2200 50  0001 C CNN
F 3 "" H 7950 2200 50  0001 C CNN
	1    7950 2200
	1    0    0    -1  
$EndComp
NoConn ~ 5450 3350
NoConn ~ 5450 3450
NoConn ~ 5450 3550
NoConn ~ 5450 3650
NoConn ~ 5450 3750
NoConn ~ 5450 3850
NoConn ~ 5450 3950
NoConn ~ 5450 4250
$Comp
L ledDeviceServerEsp32Pio:HLK-PM01 PS1
U 1 1 61952CC8
P 9050 2650
F 0 "PS1" H 9050 2975 50  0000 C CNN
F 1 "HLK-PM01" H 9050 2884 50  0000 C CNN
F 2 "Converter_ACDC:Converter_ACDC_HiLink_HLK-PMxx" H 9050 2350 50  0001 C CNN
F 3 "http://www.hlktech.net/product_detail.php?ProId=54" H 9450 2300 50  0001 C CNN
	1    9050 2650
	-1   0    0    1   
$EndComp
Wire Wire Line
	8200 5150 8300 5150
Wire Wire Line
	9550 2650 9550 2550
Wire Wire Line
	9550 2550 9450 2550
$Comp
L power:PWR_FLAG #FLGAC_L01
U 1 1 6198571A
P 9750 2950
F 0 "#FLGAC_L01" H 9750 3025 50  0001 C CNN
F 1 "PWR_FLAG" H 9750 3123 50  0000 C CNN
F 2 "" H 9750 2950 50  0001 C CNN
F 3 "~" H 9750 2950 50  0001 C CNN
	1    9750 2950
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLGAC_N01
U 1 1 619860B3
P 9750 2400
F 0 "#FLGAC_N01" H 9750 2475 50  0001 C CNN
F 1 "PWR_FLAG" H 9750 2573 50  0000 C CNN
F 2 "" H 9750 2400 50  0001 C CNN
F 3 "~" H 9750 2400 50  0001 C CNN
	1    9750 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 4550 5450 4550
$Comp
L power:PWR_FLAG #ESP32_3V030101
U 1 1 619969F8
P 8550 5050
F 0 "#ESP32_3V030101" H 8550 5125 50  0001 C CNN
F 1 "PWR_FLAG" H 8400 5200 50  0000 L CNN
F 2 "" H 8550 5050 50  0001 C CNN
F 3 "~" H 8550 5050 50  0001 C CNN
	1    8550 5050
	1    0    0    -1  
$EndComp
Connection ~ 8300 5150
$Comp
L power:GND #PWRGND02
U 1 1 6199795F
P 8550 3950
F 0 "#PWRGND02" H 8555 3777 50  0000 C CNN
F 1 "GND" H 8555 3686 50  0000 C CNN
F 2 "" H 8550 3950 50  0001 C CNN
F 3 "" H 8550 3950 50  0001 C CNN
	1    8550 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWRGND03
U 1 1 61998113
P 5100 4650
F 0 "#PWRGND03" H 5105 4477 50  0000 C CNN
F 1 "GND" H 5105 4386 50  0000 C CNN
F 2 "" H 5100 4650 50  0001 C CNN
F 3 "" H 5100 4650 50  0001 C CNN
	1    5100 4650
	1    0    0    -1  
$EndComp
Connection ~ 5250 4550
Wire Wire Line
	5250 4550 5100 4550
Wire Wire Line
	5100 4550 5100 4650
Wire Wire Line
	8300 5550 4600 5550
Wire Wire Line
	8300 5150 8300 5550
Wire Wire Line
	8200 3350 8450 3350
Wire Wire Line
	8650 2750 8450 2750
Wire Wire Line
	9550 2650 9750 2650
Wire Wire Line
	9450 2750 9750 2750
Connection ~ 9750 2650
Wire Wire Line
	9750 2650 9900 2650
Connection ~ 9750 2750
Wire Wire Line
	9750 2750 9900 2750
Wire Wire Line
	8300 5150 8550 5150
Wire Wire Line
	8200 3850 8550 3850
Wire Wire Line
	8550 5050 8550 5150
Wire Wire Line
	8550 3950 8550 3850
Wire Wire Line
	8450 2750 8450 3350
Wire Wire Line
	8450 3350 9100 3350
Connection ~ 8450 3350
Connection ~ 4400 2550
Wire Wire Line
	5250 3000 5250 4550
Wire Wire Line
	4400 2550 4400 3050
Wire Wire Line
	4600 4450 4600 5550
Wire Wire Line
	4600 3000 5250 3000
Wire Wire Line
	4600 3050 4600 3000
Text Label 3650 3850 0    50   ~ 0
GND
Text Label 3650 3950 0    50   ~ 0
CLOCK1
Text Label 3650 4050 0    50   ~ 0
DATA1
$Comp
L ledDeviceServerEsp32Pio:LLC_4CH U2
U 1 1 61977BBE
P 4500 3750
F 0 "U2" H 4800 3100 50  0000 C CNN
F 1 "LLC_4CH" H 4850 4400 50  0000 C CNN
F 2 "ledDeviceServerEsp32Pio:LLC_4CH" H 4500 3000 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/txb0104.pdf" H 4610 3845 50  0001 C CNN
	1    4500 3750
	-1   0    0    1   
$EndComp
$Comp
L ledDeviceServerEsp32Pio:Screw_Terminal_01x03 JStrip1
U 1 1 6195D7EF
P 3400 3950
F 0 "JStrip1" H 3500 3950 50  0000 L CNN
F 1 "Terminal_LCDstrip" H 3050 4200 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-3_P5.08mm" H 3350 3650 50  0001 C CNN
F 3 "~" H 3400 3950 50  0001 C CNN
	1    3400 3950
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 2100 7950 2200
Wire Wire Line
	8300 2100 8300 2550
Connection ~ 8300 2550
Wire Wire Line
	8300 2550 8650 2550
Wire Wire Line
	7950 2100 8300 2100
Wire Wire Line
	4400 2550 8300 2550
Wire Wire Line
	9750 2750 9750 2950
Wire Wire Line
	9750 2400 9750 2650
$Comp
L ledDeviceServerEsp32Pio:MountingHole H1
U 1 1 61970074
P 6300 5900
F 0 "H1" H 6400 5946 50  0000 L CNN
F 1 "MountingHole" H 6400 5855 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 6200 5800 50  0001 C CNN
F 3 "~" H 6300 5900 50  0001 C CNN
	1    6300 5900
	1    0    0    -1  
$EndComp
$Comp
L ledDeviceServerEsp32Pio:MountingHole H2
U 1 1 61970FEE
P 6300 6100
F 0 "H2" H 6400 6146 50  0000 L CNN
F 1 "MountingHole" H 6400 6055 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 6200 6000 50  0001 C CNN
F 3 "~" H 6300 6100 50  0001 C CNN
	1    6300 6100
	1    0    0    -1  
$EndComp
$Comp
L ledDeviceServerEsp32Pio:MountingHole H3
U 1 1 619719BE
P 6300 6300
F 0 "H3" H 6400 6346 50  0000 L CNN
F 1 "MountingHole" H 6400 6255 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 6200 6200 50  0001 C CNN
F 3 "~" H 6300 6300 50  0001 C CNN
	1    6300 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3850 3600 3850
Text Label 3650 3350 0    50   ~ 0
GND
Text Label 3650 3450 0    50   ~ 0
CLOCK2
Text Label 3650 3550 0    50   ~ 0
DATA2
$Comp
L ledDeviceServerEsp32Pio:Screw_Terminal_01x03 JStrip2
U 1 1 619BC866
P 3400 3450
F 0 "JStrip2" H 3500 3450 50  0000 L CNN
F 1 "Terminal_LCDstrip" H 3000 3100 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-3_P5.08mm" H 3350 3150 50  0001 C CNN
F 3 "~" H 3400 3450 50  0001 C CNN
	1    3400 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	3850 3350 3600 3350
Wire Wire Line
	3850 3350 3850 2550
Wire Wire Line
	3050 2550 3850 2550
Wire Wire Line
	3850 3700 3850 3850
Wire Wire Line
	5350 4150 5350 3850
Wire Wire Line
	5350 4150 5450 4150
Wire Wire Line
	4950 3850 5350 3850
Wire Wire Line
	5450 4350 5150 4350
Wire Wire Line
	5150 4350 5150 3650
Wire Wire Line
	5150 3650 4950 3650
Wire Wire Line
	5450 4450 5050 4450
Wire Wire Line
	5050 4450 5050 3450
Wire Wire Line
	5050 3450 4950 3450
Connection ~ 3850 2550
Wire Wire Line
	3850 2550 4400 2550
Wire Wire Line
	3000 2550 3000 3700
Wire Wire Line
	3000 3700 3850 3700
Wire Wire Line
	3600 3450 4050 3450
Wire Wire Line
	3600 3550 3950 3550
Wire Wire Line
	3950 3550 3950 3650
Wire Wire Line
	3950 3650 4050 3650
Wire Wire Line
	3600 3950 3950 3950
Wire Wire Line
	3950 3950 3950 3850
Wire Wire Line
	3950 3850 4050 3850
Wire Wire Line
	4050 4050 3600 4050
$Comp
L ledDeviceServerEsp32Pio:MountingHole H4
U 1 1 61C4DD5F
P 6300 6500
F 0 "H4" H 6400 6546 50  0000 L CNN
F 1 "MountingHole" H 6400 6455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 6200 6400 50  0001 C CNN
F 3 "~" H 6300 6500 50  0001 C CNN
	1    6300 6500
	1    0    0    -1  
$EndComp
$Comp
L ledDeviceServerEsp32Pio:MountingHole H5
U 1 1 61C4E6D4
P 6300 6700
F 0 "H5" H 6400 6746 50  0000 L CNN
F 1 "MountingHole" H 6400 6655 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 6200 6600 50  0001 C CNN
F 3 "~" H 6300 6700 50  0001 C CNN
	1    6300 6700
	1    0    0    -1  
$EndComp
$Comp
L ledDeviceServerEsp32Pio:MountingHole H6
U 1 1 61C4ED3D
P 6300 6900
F 0 "H6" H 6400 6946 50  0000 L CNN
F 1 "MountingHole" H 6400 6855 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 6200 6800 50  0001 C CNN
F 3 "~" H 6300 6900 50  0001 C CNN
	1    6300 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 4450 4400 5700
Wire Wire Line
	9100 3350 9100 5700
NoConn ~ 8200 5050
NoConn ~ 8200 4950
NoConn ~ 8200 4850
NoConn ~ 8200 4750
NoConn ~ 8200 4650
NoConn ~ 8200 4550
NoConn ~ 8200 4450
NoConn ~ 8200 4350
NoConn ~ 8200 4250
NoConn ~ 8200 4150
NoConn ~ 8200 4050
NoConn ~ 8200 3950
NoConn ~ 8200 3750
NoConn ~ 8200 3650
NoConn ~ 8200 3550
NoConn ~ 8200 3450
NoConn ~ 5450 5150
NoConn ~ 5450 5050
NoConn ~ 5450 4950
NoConn ~ 5450 4850
NoConn ~ 5450 4750
NoConn ~ 5450 4650
Wire Wire Line
	4400 5700 9100 5700
Wire Wire Line
	4950 4050 5450 4050
$EndSCHEMATC
