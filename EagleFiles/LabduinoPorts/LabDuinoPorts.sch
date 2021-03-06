<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.2.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="wirepad">
<description>&lt;b&gt;Single Pads&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="2,54/0,9">
<description>&lt;b&gt;THROUGH-HOLE PAD&lt;/b&gt;</description>
<wire x1="-1.27" y1="1.27" x2="-0.762" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="1.27" x2="-1.27" y2="0.762" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.27" x2="1.27" y2="0.762" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.27" x2="0.762" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.762" x2="1.27" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.27" x2="0.762" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.762" y1="-1.27" x2="-1.27" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.27" x2="-1.27" y2="-0.762" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.635" width="0.1524" layer="51"/>
<pad name="1" x="0" y="0" drill="0.9144" diameter="2.54" shape="octagon"/>
<text x="-1.27" y="1.524" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="0" y="0.6" size="0.0254" layer="27">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="PAD">
<wire x1="-1.016" y1="1.016" x2="1.016" y2="-1.016" width="0.254" layer="94"/>
<wire x1="-1.016" y1="-1.016" x2="1.016" y2="1.016" width="0.254" layer="94"/>
<text x="-1.143" y="1.8542" size="1.778" layer="95">&gt;NAME</text>
<text x="-1.143" y="-3.302" size="1.778" layer="96">&gt;VALUE</text>
<pin name="P" x="2.54" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="2,54/0,9" prefix="PAD" uservalue="yes">
<description>&lt;b&gt;THROUGH-HOLE PAD&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="PAD" x="0" y="0"/>
</gates>
<devices>
<device name="" package="2,54/0,9">
<connects>
<connect gate="1" pin="P" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="VCC">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VCC" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply2">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
Please keep in mind, that these devices are necessary for the
automatic wiring of the supply signals.&lt;p&gt;
The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND">
<wire x1="-1.27" y1="0" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="-1.27" width="0.254" layer="94"/>
<wire x1="0" y1="-1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<text x="-1.905" y="-3.175" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="SUPPLY">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="GND" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0.381" drill="0">
<clearance class="0" value="0.508"/>
</class>
</classes>
<parts>
<part name="S1" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S1+" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S1-" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S2" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S2+" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S2-" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S3" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S3+" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S3-" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S4" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S4+" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S4-" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="V+" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="P+1" library="supply1" deviceset="VCC" device=""/>
<part name="P+2" library="supply1" deviceset="VCC" device=""/>
<part name="P+3" library="supply1" deviceset="VCC" device=""/>
<part name="P+4" library="supply1" deviceset="VCC" device=""/>
<part name="P+5" library="supply1" deviceset="VCC" device=""/>
<part name="SUPPLY1" library="supply2" deviceset="GND" device=""/>
<part name="SUPPLY2" library="supply2" deviceset="GND" device=""/>
<part name="SUPPLY3" library="supply2" deviceset="GND" device=""/>
<part name="SUPPLY4" library="supply2" deviceset="GND" device=""/>
<part name="D1" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="D1+" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="D2" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="D2+" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="D3" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="D3+" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="D4" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="D4+" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="P+6" library="supply1" deviceset="VCC" device=""/>
<part name="P+7" library="supply1" deviceset="VCC" device=""/>
<part name="P+8" library="supply1" deviceset="VCC" device=""/>
<part name="P+9" library="supply1" deviceset="VCC" device=""/>
<part name="V-" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="SUPPLY5" library="supply2" deviceset="GND" device=""/>
<part name="S1-IN" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S2-IN" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S3-IN" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="S4-IN" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="D1-IN" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="D2-IN" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="D3-IN" library="wirepad" deviceset="2,54/0,9" device=""/>
<part name="D4-IN" library="wirepad" deviceset="2,54/0,9" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="S1" gate="1" x="20.32" y="40.64" rot="R270"/>
<instance part="S1+" gate="1" x="17.78" y="43.18" rot="R90"/>
<instance part="S1-" gate="1" x="22.86" y="43.18" rot="R90"/>
<instance part="S2" gate="1" x="40.64" y="38.1" rot="R270"/>
<instance part="S2+" gate="1" x="38.1" y="40.64" rot="R90"/>
<instance part="S2-" gate="1" x="43.18" y="40.64" rot="R90"/>
<instance part="S3" gate="1" x="55.88" y="38.1" rot="R270"/>
<instance part="S3+" gate="1" x="53.34" y="40.64" rot="R90"/>
<instance part="S3-" gate="1" x="58.42" y="40.64" rot="R90"/>
<instance part="S4" gate="1" x="83.82" y="38.1" rot="R270"/>
<instance part="S4+" gate="1" x="81.28" y="40.64" rot="R90"/>
<instance part="S4-" gate="1" x="86.36" y="40.64" rot="R90"/>
<instance part="V+" gate="1" x="-5.08" y="43.18" rot="R270"/>
<instance part="P+1" gate="VCC" x="-5.08" y="38.1" rot="R180"/>
<instance part="P+2" gate="VCC" x="17.78" y="48.26"/>
<instance part="P+3" gate="VCC" x="38.1" y="45.72"/>
<instance part="P+4" gate="VCC" x="53.34" y="45.72"/>
<instance part="P+5" gate="VCC" x="81.28" y="45.72"/>
<instance part="SUPPLY1" gate="GND" x="22.86" y="48.26" rot="R180"/>
<instance part="SUPPLY2" gate="GND" x="43.18" y="45.72" rot="R180"/>
<instance part="SUPPLY3" gate="GND" x="58.42" y="45.72" rot="R180"/>
<instance part="SUPPLY4" gate="GND" x="86.36" y="45.72" rot="R180"/>
<instance part="D1" gate="1" x="12.7" y="25.4" rot="R270"/>
<instance part="D1+" gate="1" x="17.78" y="25.4" rot="R270"/>
<instance part="D2" gate="1" x="27.94" y="25.4" rot="R270"/>
<instance part="D2+" gate="1" x="33.02" y="25.4" rot="R270"/>
<instance part="D3" gate="1" x="43.18" y="25.4" rot="R270"/>
<instance part="D3+" gate="1" x="48.26" y="25.4" rot="R270"/>
<instance part="D4" gate="1" x="60.96" y="25.4" rot="R270"/>
<instance part="D4+" gate="1" x="66.04" y="25.4" rot="R270"/>
<instance part="P+6" gate="VCC" x="17.78" y="20.32" rot="R180"/>
<instance part="P+7" gate="VCC" x="33.02" y="20.32" rot="R180"/>
<instance part="P+8" gate="VCC" x="48.26" y="20.32" rot="R180"/>
<instance part="P+9" gate="VCC" x="66.04" y="20.32" rot="R180"/>
<instance part="V-" gate="1" x="-5.08" y="30.48" rot="R270"/>
<instance part="SUPPLY5" gate="GND" x="-5.08" y="25.4"/>
<instance part="S1-IN" gate="1" x="20.32" y="35.56" rot="R90"/>
<instance part="S2-IN" gate="1" x="40.64" y="33.02" rot="R90"/>
<instance part="S3-IN" gate="1" x="55.88" y="33.02" rot="R90"/>
<instance part="S4-IN" gate="1" x="83.82" y="33.02" rot="R90"/>
<instance part="D1-IN" gate="1" x="12.7" y="20.32" rot="R90"/>
<instance part="D2-IN" gate="1" x="27.94" y="20.32" rot="R90"/>
<instance part="D3-IN" gate="1" x="43.18" y="20.32" rot="R90"/>
<instance part="D4-IN" gate="1" x="60.96" y="20.32" rot="R90"/>
</instances>
<busses>
</busses>
<nets>
<net name="VCC" class="0">
<segment>
<pinref part="V+" gate="1" pin="P"/>
<pinref part="P+1" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="S1+" gate="1" pin="P"/>
<pinref part="P+2" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="S2+" gate="1" pin="P"/>
<pinref part="P+3" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="S3+" gate="1" pin="P"/>
<pinref part="P+4" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="S4+" gate="1" pin="P"/>
<pinref part="P+5" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="D1+" gate="1" pin="P"/>
<pinref part="P+6" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="D2+" gate="1" pin="P"/>
<pinref part="P+7" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="D3+" gate="1" pin="P"/>
<pinref part="P+8" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="D4+" gate="1" pin="P"/>
<pinref part="P+9" gate="VCC" pin="VCC"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="S1-" gate="1" pin="P"/>
<pinref part="SUPPLY1" gate="GND" pin="GND"/>
</segment>
<segment>
<pinref part="S2-" gate="1" pin="P"/>
<pinref part="SUPPLY2" gate="GND" pin="GND"/>
</segment>
<segment>
<pinref part="S3-" gate="1" pin="P"/>
<pinref part="SUPPLY3" gate="GND" pin="GND"/>
</segment>
<segment>
<pinref part="S4-" gate="1" pin="P"/>
<pinref part="SUPPLY4" gate="GND" pin="GND"/>
</segment>
<segment>
<pinref part="V-" gate="1" pin="P"/>
<pinref part="SUPPLY5" gate="GND" pin="GND"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="S1" gate="1" pin="P"/>
<pinref part="S1-IN" gate="1" pin="P"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="S2" gate="1" pin="P"/>
<pinref part="S2-IN" gate="1" pin="P"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="S3" gate="1" pin="P"/>
<pinref part="S3-IN" gate="1" pin="P"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="S4" gate="1" pin="P"/>
<pinref part="S4-IN" gate="1" pin="P"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="D1" gate="1" pin="P"/>
<pinref part="D1-IN" gate="1" pin="P"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="D2" gate="1" pin="P"/>
<pinref part="D2-IN" gate="1" pin="P"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="D3" gate="1" pin="P"/>
<pinref part="D3-IN" gate="1" pin="P"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="D4" gate="1" pin="P"/>
<pinref part="D4-IN" gate="1" pin="P"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
