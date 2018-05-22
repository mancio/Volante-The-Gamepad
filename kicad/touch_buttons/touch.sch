EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:my_lib
LIBS:touch-cache
EELAYER 25 0
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
L Jumper_NO_Small JP1
U 1 1 5AF988CE
P 6050 3050
F 0 "JP1" H 6050 3129 50  0000 C CNN
F 1 "touch" H 6060 2990 50  0000 C CNN
F 2 "Touch_conn:touch" H 6050 3050 50  0001 C CNN
F 3 "" H 6050 3050 50  0001 C CNN
	1    6050 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5AFBC7A9
P 6950 4280
F 0 "#PWR01" H 6950 4030 50  0001 C CNN
F 1 "GND" H 6950 4130 50  0000 C CNN
F 2 "" H 6950 4280 50  0001 C CNN
F 3 "" H 6950 4280 50  0001 C CNN
	1    6950 4280
	1    0    0    -1  
$EndComp
Text Notes 7330 3830 0    47   ~ 0
IN
Text Notes 7320 3930 0    47   ~ 0
GND
Wire Wire Line
	7030 3900 6950 3900
Wire Wire Line
	6950 3900 6950 4280
Wire Wire Line
	7030 3800 6880 3800
Wire Wire Line
	6880 3800 6880 3830
Wire Wire Line
	6880 3830 6410 3830
Wire Wire Line
	6410 3830 6410 3050
Wire Wire Line
	6410 3050 6150 3050
Wire Wire Line
	5950 3050 5670 3050
Wire Wire Line
	5670 3050 5670 4150
Wire Wire Line
	5670 4150 6950 4150
Connection ~ 6950 4150
Wire Notes Line
	6060 2900 6060 2730
Wire Notes Line
	6060 2730 6440 2730
Text Notes 6460 2760 0    47   ~ 0
Finger
Wire Notes Line
	5950 2900 6180 2900
Wire Notes Line
	5950 2900 5950 3180
Wire Notes Line
	5950 3180 6180 3180
Wire Notes Line
	6180 3180 6180 2900
$Comp
L CONN_01X02 J1
U 1 1 5B018E1F
P 7230 3850
F 0 "J1" H 7230 4000 50  0000 C CNN
F 1 "CONN_01X02" H 7310 3680 50  0000 C CNN
F 2 "Touch_conn:touch_conn" H 7230 3850 50  0001 C CNN
F 3 "" H 7230 3850 50  0001 C CNN
	1    7230 3850
	1    0    0    -1  
$EndComp
$EndSCHEMATC
