After opening files you must set the offset for every grbl file 
	offset: (-10.0000, 86.0000) This has benn inverted.
Select

	Excellon-> ledDeviceServerEsp32Pio-NPTH.drl
	
	
	Tool -> Two sided PCB
		select ledDeviceServerEsp32Pio-B_Cu.gbr
			Mirror operation
				Axis: Y
				Reference: Box
				Reverence object:
						(°) Gerber 
						ledDeviceServerEsp32Pio-Edge_Cuts.gbr
				Click Mirror
			PCB Alignment
				Drill Dia: 3.1250
				Axis: Y
				Shift click to copy coordinates
				Alignment Drill Coordinates: (6.0000, -24.0000),(6.0000, -68.0000),
				Click Create Excellon Object
			
	Select Alignment Drills
		Click tab Properties
		shift click lower left corner of the outline
			paste the copied coordinates to the Offset edit box 
			flip negative number to positive and vise versa.  F.example 10,-86 becomes -10,86 
			Click the Offset button
		Click Drilling Tool
		Parameters for: Tool 1
			Cut Z        : -8  (1.5mm er vídd pcb)
			Travel Z     : 3
			Feedrate Z   : 50
			Spindle speed: 1000
		Common Parameters
			End move Z    : 4
		Click Generate CNCJob object
		Click Save CNC Code
		Save it into the folder hardware\Production\CNCjobs
	
	Tool -> Two sided PCB
		select ledDeviceServerEsp32Pio-B_Cu.gbr
			Mirror operation
				Axis: Y
				Reference: Box
				Reverence object:
						(°) Gerber 
						ledDeviceServerEsp32Pio-Edge_Cuts.gbr
				Click Mirror
	select ledDeviceServerEsp32Pio-B_Cu.gbr 
		click properties tab
		set offset -10,86 and click offset button
		Click Isolation Routing Button
		Tool -> Calculators
			er með 15° 0.1mm bit svo við reiknum breyddina
			Ætla að prófa að hafa gildin svona
			Tip Diameter: 0.1
			Tip angle: 15
			Cut Z: 0.2
			Tool diameter:0,1527
		Click tab Properties
		Add from DB
			Tool Dia:Paste 0,1527 and click + Search and Add Button
		Tools Table
			Delete the other tool (0.1) from the table
		Parameters for: Tool 2
			Passes: 2
			Overlap 20%
		Common Parameters:
			[X] Combine
		Select the tool we created in the Tools Table and
		Click Generate Isolation Geometry button
		
	Now we have a Geometry Object called "ledDeviceServerEsp32Pio-B_Cu.gbr_iso_combined" selected in the properties tab
		Parameters for: Tool 2
			V-Tip Dia   : 0.1
			V-Tip Angle : 15
			Travel Z    : 2
			Feedrate X-Y: 80
			Feedrate Z  : 50
			Spindle speed 1000
		Common Parameters
			End Move Z: 15
		Click Generate CNCJob object
		Click Save CNC Code
		
	Select ledDeviceServerEsp32Pio-F_Cu.gbr and click properties tab
		set offset -10,86 and click offset button
			Click Isolation Routing Button
			Tool -> Calculators
				er með 15° 0.1mm bit svo við reiknum breyddina
				Ætla að prófa að hafa gildin svona
				Tip Diameter: 0.1
				Tip angle: 15
				Cut Z: 0.2
				Tool diameter:0,1527
			Click tab Properties
			Add from DB
				Tool Dia:Paste 0,1527 and click + Search and Add Button
			Tools Table
				Delete the other tool (0.1) from the table
			Parameters for: Tool 2
				Passes: 2
				Overlap 20%
			Common Parameters:
				[X] Combine
			Select the tool we created in the Tools Table and
			Click Generate Isolation Geometry button
	Now we have a Geometry Object called "ledDeviceServerEsp32Pio-F_Cu.gbr_iso_combined" selected in the properties tab
		Parameters for: Tool 2
			V-Tip Dia   : 0.1
			V-Tip Angle : 15
			Travel Z    : 2
			Feedrate X-Y: 80
			Feedrate Z  : 50
			Spindle speed 1000
		Common Parameters
			End Move Z: 15
		Click Generate CNCJob object
		Click Save CNC Code - ledDeviceServerEsp32Pio-F_Cu.gbr_iso_combined_cnc.nc
		
	select ledDeviceServerEsp32Pio-PTH.drl
		set offset -10,86 and click offset button
		Select tools 1 and 2 with diameter 0.7620, 0.8
			click Drilling tool
			Select tools 1 and two
			Parameters for: Tool 1
			Cut Z: -2
			Travel Z: 3
			Feedrate Z: 50
			Spindle speed: 1000
			Click Apply parameters to all Tools Button
			Common Parameters:
				[X] Tool change
				Tool change Z: 15
					End Move Z: 4
			Click Generate CNC Job object
	
	Now, cutting the board
	Select ledDeviceServerEsp32Pio-Edge_Cuts.gbr
		Cutout Tool
			Tool Dia: 1.1
		Tool Parameters:
			Cut Z -1.8
			[X] Multi-Depth: 0.3
			Margin: 0.0
			Gap size: 2.0
		Smella á Generate Geometry, Takkann með kassanum
	Smelltu á properties: (þá selectast "ledDeviceServerEsp32Pio-Edge_Cuts.gbr_cutout" sem þú bjóst til
		Parameters for: Tool 1
			Cut Z: -1.8
			Multi-Depth: 0.3
			Travel Z: 3.0
			Feedrate X-Y: 40
			Feedrate Z: 50
			Spindle speed: 1000
		Common Parameters	
			End move Z: 15
			End move X,Y: None
		Click Generate CNCJob object
		And Click Save CNC Code, Filename: "ledDeviceServerEsp32Pio-Edge_Cuts.gbr_cutout_cnc.nc"
		
			
		
	
		