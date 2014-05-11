class Item:
    """An mitchell mitchell mitchell  object"""

    def __init__(data):
        self.item = data

    def __str___(self):
        return self.item


class Room:
    """A single room"""

    def __init__(self, data):
        self.name = name
        self.description = data['desc']
        self._items = []
        
        for item in data[items]:
            pass
            self._items.append(Item(item))
        self.dirs = {}


    def __str__(self):
        return self.description.format("\n%".join(str(room) for name,room in self.rooms.items()))
        



class Inventory: 
    """The player's inventory"""

    def __init__(self):
        self._inv = []

    def __str__(self):
        str_inv = [str(item) for item in self._inv]
        return str_inv


class Cave:
    """A cave contains one or more rooms"""

    def __init__(self, data, current_name):
        self.rooms = {}
        for key,value in data.items():
            self.rooms[key] = Room(data[key])

        self._current = self.rooms[current_name]

    def __str__(self):
        return "World:\n{0}".format( "\n%%\n".join(
            [ name + ": " + str(room) for name,room in self.rooms.items() ]
        ) )

    @property
    def current(self):
        """returns the current room"""
        return self._current

    def go(self.direction):
        if(self.direction in self.current)
            # then set self._current to the room associated with 'direction'
            #...
        myworld = world.World( ... )

        while True: # command loop
            # get cmd_string from user
            ...
            action, arguments = cmd_string.partition(' ')[::2]

            # call the method associated with the action
            getattr(myworld, action)(arguments)
        else
        myworld = world.World( ... )


while True: # command loop
    # get cmd_string from user
    ...
    action, arguments = cmd_string.partition(' ')[::2]

    # call the method associated with the action
    getattr(myworld, action)(arguments)    raise NoPath(direction)
