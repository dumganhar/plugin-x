import sys, string, os
from xml.etree import ElementTree as ET
from xml.dom import minidom

projFile = sys.argv[1]
targetPath = sys.argv[2]

def getLinkElement():
    global targetPath
    ret = ET.Element('link')
    nameEle = ET.Element('name')
    nameEle.text = 'plugin-x'
    typeEle = ET.Element('type')
    typeEle.text = '2'
    locEle = ET.Element('locationURI')
    locEle.text = targetPath
    ret.append(nameEle)
    ret.append(typeEle)
    ret.append(locEle)
    
    return ret

def writeFile(path, elem):
    f = open(path, 'w')
    if f == None:
        return
    
    root_str = ET.tostring(elem, 'UTF-8')
    reparse = minidom.parseString(root_str)
    reparse.writexml(f, '', '\t', '\n', 'UTF-8')
    f.close()

tree = ET.parse(projFile)
root = tree.getroot()
nodeLinkRes = root.find('linkedResources')
if nodeLinkRes != None:
    linkNodes = nodeLinkRes.findall('link')
    haveTarget = False
    if linkNodes != None and len(linkNodes) > 0:
        for node in linkNodes:
            locNode = node.find('locationURI')
            tempText = locNode.text
            tempText = tempText.strip(' \n\r\t')
            if tempText == targetPath:
                haveTarget = True
                break
    if not haveTarget:
        nodeLinkRes.append(getLinkElement())
        writeFile(projFile, root)
else:
    linkResEle = ET.Element('linkedResources')
    linkResEle.append(getLinkElement())
    root.append(linkResEle)
    writeFile(projFile, root)
