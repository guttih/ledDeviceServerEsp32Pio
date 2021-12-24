(G-CODE GENERATED BY FLATCAM v8.994 - www.flatcam.org - Version Date: 2020/11/7)

(Name: ledDeviceServerEsp32Pio-NPTH.drl_cnc)
(Type: G-code from Geometry)
(Units: MM)

(Created on Monday, 22 November 2021 at 09:24)

(This preprocessor is the default preprocessor used by FlatCAM.)
(It is made to work with MACH3 compatible motion controllers.)


(TOOLS DIAMETER: )
(Tool: 1 -> Dia: 3.2)

(FEEDRATE Z: )
(Tool: 1 -> Feedrate: 50.0)

(FEEDRATE RAPIDS: )
(Tool: 1 -> Feedrate Rapids: 1500)

(Z_CUT: )
(Tool: 1 -> Z_Cut: -1.7)

(Tools Offset: )
(Tool: 1 -> Offset Z: 0.0)

(Z_MOVE: )
(Tool: 1 -> Z_Move: 3.0)

(Z Toolchange: 15 mm)
(X,Y Toolchange: 0.0000, 0.0000 mm)
(Z Start: None mm)
(Z End: 4.0 mm)
(X,Y End: None mm)
(Steps per circle: 64)
(Preprocessor Excellon: default)

(X range:    2.4000 ...   78.6000  mm)
(Y range:    2.4000 ...    5.6000  mm)

(Spindle Speed: 1000 RPM)
G21
G90
G94

G01 F50.00

M5
G00 Z15.0000
T1
G00 X0.0000 Y0.0000                
M6
(MSG, Change to Tool Dia = 3.2000 ||| Total drills for tool T1 = 3)
M0
G00 Z15.0000

G01 F50.00
M03 S1000
G00 X77.0000 Y4.0000
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X40.5000 Y4.0000
G01 Z-1.7000
G01 Z0
G00 Z3.0000
G00 X4.0000 Y4.0000
G01 Z-1.7000
G01 Z0
G00 Z3.0000
M05
G00 Z4.00


