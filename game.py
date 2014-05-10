#!/usr/bin/env python3

import world as world
import yaml as yaml

data = yaml.load( open('rooms.yaml', 'r') )
myworld = world.World( data, 'SURGE 104C' )
print(myworld)
