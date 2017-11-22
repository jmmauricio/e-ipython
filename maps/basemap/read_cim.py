# -*- coding: utf-8 -*-
"""
Created on Sun Jan 11 20:21:01 2015

@author: jmmauricio
"""

from lxml import etree


root = etree.fromstring("""
<root>
    <articles>
        <article type="news">
             <content>some text 1</content>
        </article>
        <article type="info">
             <content>some text 2</content>
        </article>
        <article type="news">
             <content>some text 3</content>
        </article>
    </articles>
</root>
""")

print root.xpath("//article[@type='info']/content/text()")


xml_file_tp = '/home/jmmauricio/Documents/public/jmmauricio7/psys/SING_TP.xml'
xml_file_sv = '/home/jmmauricio/Documents/public/jmmauricio7/psys/sdec.txt_SV.xml'
xml_tp = open(xml_file_tp,'r')
xml_sv = open(xml_file_sv,'r')
#
#
namespaces = {'cim': 'http://iec.ch/TC57/2009/CIM-schema-cim14#',
              'rdf':"http://www.w3.org/1999/02/22-rdf-syntax-ns#"}
#
root_tp = etree.fromstring(xml_tp.read())
root_sv = etree.fromstring(xml_sv.read())
names = root_tp.xpath('//cim:TopologicalNode/cim:IdentifiedObject.name/text()',namespaces=namespaces)
ids   = root_tp.xpath('//cim:TopologicalNode/@rdf:ID',namespaces=namespaces)

bus_id = ids[names.index('Crucero 220 B1')]
nodes   = root_sv.xpath('//cim:SvVoltage/cim:SvVoltage.TopologicalNode[@rdf:resource="#{:s}"]'.format(bus_id),namespaces=namespaces)
parent=nodes[0].getparent()
volts   = float(parent.xpath('cim:SvVoltage.v/text()',namespaces=namespaces)[0])


print(volts)

#
#TopologicalNodes = root_tp.findall('cim:TopologicalNode',namespaces=namespaces)
#
#for node in TopologicalNodes:
#    name = node.find('cim:IdentifiedObject.name',namespaces=namespaces)
#    print(node.attrib['{http://www.w3.org/1999/02/22-rdf-syntax-ns#}ID'])
#    if 'Crucero 220 B1'==name.text:
#        print(node.tag)
#    
#    

