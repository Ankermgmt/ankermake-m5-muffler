# Hardware

The PCB is designed using a variety of tools. With the spirit of open hardware, most are free or atleast have hobbiest level licenses (e.g. fusion 360). 

## Software Tools

- FreeCad [Download](https://www.freecadweb.org/downloads.php)
- Java (Required for FreeRouting) [Download](https://adoptium.net/temurin/releases/)
- Free Routing [Download](https://github.com/freerouting/freerouting/releases)
- EasyEDA [Download](https://easyeda.com/page/download)
- Fusion 360 (Optional)

## Workflow

Due to the bias for open/free tools, modifying the PCB will require muliple pieces of software to work together. The workflow is as follows:

### PCB Editing

To edit the PCB in Fusion360 and import into EasyEDA, first confert it to a DXF file with freecad

1. Edit PCB Sketch in Fusion 360 
2. Export PCB Body as STEP file
3. Import STEP file into FreeCad
4. Export FreeCad file as DXF file
5. EasyEDA -> Import DXF -> Import DXF file


### Routing Traces

Due to the unusual shape of the PCB, EasyEDA will always fail to route the traces with the built in autorouter. 
We must export an Autorouter DSN file and use [FreeRouting](https://github.com/freerouting/freerouting/releases) to route the traces.
We can then export a .SES file from FreeRouting and import it back into EasyEDA.

1. EasyEDA -> Autorouter -> Export DSN
2. FreeRouting -> Open DSN file
3. FreeRouting -> Autoroute (wait for autorouting to finish, it may take 10+ minutes)
4. FreeRouting -> Incompletes (verify no incomplete traces are highlighted in pink)
5. FreeRouting -> Violations (verify no violations are highlighted in pink)
6. FreeRouting - Click in the main window to pause autorouting (or else export will fail)
7. FreeRouting -> File -> Export Spectra Session file
8. EasyEDA -> Route -> Import Spectra Session file



### Fonts

The font used by AnkerMake is either "Poppins SemiBold" or "Poppins Bold". [Download font](https://befonts.com/poppins-font-family.html)

1. Import the font into your system font manager
2. In easyEDA, import the font from the system font manager