(G-CODE GENERATED BY FLATCAM v8.994 - www.flatcam.org - Version Date: 2020/11/7)

(Name: ledDeviceServerEsp32Pio-PTH.drl_cnc)
(Type: G-code from Geometry)
(Units: MM)

(Created on Monday, 22 November 2021 at 09:25)

(This preprocessor is the default preprocessor used by FlatCAM.)
(It is made to work with MACH3 compatible motion controllers.)


(TOOLS DIAMETER: )
(Tool: 1 -> Dia: 0.762)
(Tool: 2 -> Dia: 0.8)
(Tool: 3 -> Dia: 1.0)
(Tool: 4 -> Dia: 1.52)

(FEEDRATE Z: )
(Tool: 1 -> Feedrate: 80.0)
(Tool: 2 -> Feedrate: 80.0)
(Tool: 3 -> Feedrate: 80.0)
(Tool: 4 -> Feedrate: 80.0)

(FEEDRATE RAPIDS: )
(Tool: 1 -> Feedrate Rapids: 1500)
(Tool: 2 -> Feedrate Rapids: 1500)
(Tool: 3 -> Feedrate Rapids: 1500)
(Tool: 4 -> Feedrate Rapids: 1500)

(Z_CUT: )
(Tool: 1 -> Z_Cut: -1.7)
(Tool: 2 -> Z_Cut: -1.7)
(Tool: 3 -> Z_Cut: -1.7)
(Tool: 4 -> Z_Cut: -1.7)

(Tools Offset: )
(Tool: 1 -> Offset Z: 0.0)
(Tool: 2 -> Offset Z: 0.0)
(Tool: 4 -> Offset Z: 0.0)

(Z_MOVE: )
(Tool: 1 -> Z_Move: 3.0)
(Tool: 2 -> Z_Move: 3.0)
(Tool: 3 -> Z_Move: 3.0)
(Tool: 4 -> Z_Move: 3.0)

(Z Toolchange: 15.0 mm)
(X,Y Toolchange: 0.0000, 0.0000 mm)
(Z Start: None mm)
(Z End: 4.0 mm)
(X,Y End: None mm)
(Steps per circle: 64)
(Preprocessor Excellon: default)

(X range:    4.8940 ...   71.3000  mm)
(Y range:   15.5170 ...   62.2670  mm)

(Spindle Speed: 1000 RPM)
G21
G90
G94

G01 F80.00

M5
G00 Z15.0000
T1
G00 X0.0000 Y0.0000                
M6
(MSG, Change to Tool Dia = 0.7620 ||| Total drills for tool T1 = 58)
M0
G00 Z15.0000

G01 F80.00
M03 S1000
G00 X68.1150 Y23.5160
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X58.6150 Y23.5160
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y26.3070
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y28.8470
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y31.3870
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y33.9270
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y36.4670
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y39.0070
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y41.5470
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y44.0870
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y46.6270
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y49.1670
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y51.7070
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y54.2470
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y56.7870
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y59.3270
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y61.8670
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y61.8670
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y59.3270
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X17.5940 Y59.4570
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X17.5940 Y54.3770
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X17.5940 Y49.2970
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y56.7870
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y54.2470
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y51.7070
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y49.1670
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y46.6270
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y44.0870
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y41.5470
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y39.0070
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y36.4670
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y33.9270
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y31.3870
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X17.9750 Y33.4220
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X17.9750 Y43.5820
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X15.4350 Y43.5820
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X12.8950 Y43.5820
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X10.3550 Y43.5820
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X7.8150 Y43.5820
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X5.2750 Y43.5820
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X5.2750 Y33.4220
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X7.8150 Y33.4220
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X10.3550 Y33.4220
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X12.8950 Y33.4220
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X15.4350 Y33.4220
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X15.1810 Y26.4370
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X15.1810 Y21.3570
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X15.1810 Y16.2770
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1980 Y16.1500
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1980 Y18.6900
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y21.2270
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y23.7670
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y26.3070
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X24.1940 Y28.8470
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y23.7670
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y21.2270
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y18.6870
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X49.5940 Y16.1470
G01 Z-1.7000
G01 Z0
G00 Z3.0000
M05
G00 Z4.00


