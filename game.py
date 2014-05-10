#!/usr/bin/env python3

import cave as cave
import yaml as yaml

data = yaml.load( open('rooms.yaml', 'r') )
mycave = cave.World( data, 'Old Coal Cave' )
print(mycave)
